////////////////////////////////////////////////////////////////////////////////
//
//  OpenZoom SDK
//
//  Version: MPL 1.1/GPL 3/LGPL 3
//
//  The contents of this file are subject to the Mozilla Public License Version
//  1.1 (the "License"); you may not use this file except in compliance with
//  the License. You may obtain a copy of the License at
//  http://www.mozilla.org/MPL/
//
//  Software distributed under the License is distributed on an "AS IS" basis,
//  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
//  for the specific language governing rights and limitations under the
//  License.
//
//  The Original Code is the OpenZoom SDK.
//
//  The Initial Developer of the Original Code is Daniel Gasienica.
//  Portions created by the Initial Developer are Copyright (c) 2007-2009
//  the Initial Developer. All Rights Reserved.
//
//  Contributor(s):
//    Daniel Gasienica <daniel@gasienica.ch>
//
//  Alternatively, the contents of this file may be used under the terms of
//  either the GNU General Public License Version 3 or later (the "GPL"), or
//  the GNU Lesser General Public License Version 3 or later (the "LGPL"),
//  in which case the provisions of the GPL or the LGPL are applicable instead
//  of those above. If you wish to allow use of your version of this file only
//  under the terms of either the GPL or the LGPL, and not to allow others to
//  use your version of this file under the terms of the MPL, indicate your
//  decision by deleting the provisions above and replace them with the notice
//  and other provisions required by the GPL or the LGPL. If you do not delete
//  the provisions above, a recipient may use your version of this file under
//  the terms of any one of the MPL, the GPL or the LGPL.
//
////////////////////////////////////////////////////////////////////////////////
package org.openzoom.flash.renderers.images
{

import flash.display.BitmapData;
import flash.display.Graphics;
import flash.display.Shape;
import flash.display.Sprite;
import flash.events.Event;
import flash.geom.Matrix;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.utils.getTimer;

import org.openzoom.flash.core.openzoom_internal;
import org.openzoom.flash.descriptors.IImagePyramidDescriptor;
import org.openzoom.flash.descriptors.IImagePyramidLevel;
import org.openzoom.flash.descriptors.deepzoom.DeepZoomImageDescriptor;
import org.openzoom.flash.events.ViewportEvent;
import org.openzoom.flash.net.INetworkQueue;
import org.openzoom.flash.scene.IMultiScaleScene;
import org.openzoom.flash.scene.IReadonlyMultiScaleScene;
import org.openzoom.flash.utils.Cache;
import org.openzoom.flash.utils.IDisposable;
import org.openzoom.flash.utils.MortonOrder;
import org.openzoom.flash.viewport.INormalizedViewport;

use namespace openzoom_internal;

//[ExcludeClass]
/**
 * @private
 *
 * Manages the rendering of all image pyramid renderers on stage.
 */
public final class ImagePyramidRenderManager implements IDisposable
{
	include "../../core/Version.as"
	
	
    //--------------------------------------------------------------------------
    //
    //  Class constants
    //
    //--------------------------------------------------------------------------

    private static const TILE_SHOW_DURATION:Number = 500 // milliseconds

    private static const MAX_CACHE_SIZE:uint = 140
    

    private static const MAX_DOWNLOADS_STATIC:uint = 4
    private static const MAX_DOWNLOADS_DYNAMIC:uint = 2

    //--------------------------------------------------------------------------
    //
    //  Constructor
    //
    //--------------------------------------------------------------------------

    /**
     * Constructor.
     */
    public function ImagePyramidRenderManager(owner:Sprite,
                                              scene:IMultiScaleScene,
                                              viewport:INormalizedViewport,
                                              loader:INetworkQueue)
    {
        this.owner = owner
        this.scene = scene
        this.viewport = viewport
        this.loader = loader

        tileCache = new Cache(MAX_CACHE_SIZE)

        tileLoader = new TileLoader(this,
                                    loader,
                                    tileCache,
                                    MAX_DOWNLOADS_STATIC)

        this.viewport.addEventListener(ViewportEvent.TRANSFORM_UPDATE,
                                       viewport_transformUpdateHandler,
                                       false, 0, true)

        this.viewport.addEventListener(ViewportEvent.TRANSFORM_START,
                                       viewport_transformStartHandler,
                                       false, 0, true)

        this.viewport.addEventListener(ViewportEvent.TRANSFORM_END,
                                       viewport_transformEndHandler,
                                       false, 0, true)
    }

    //--------------------------------------------------------------------------
    //
    //  Variables
    //
    //--------------------------------------------------------------------------

    private var renderers:Array /* of ImagePyramidRenderer */ = []

    private var owner:Sprite
    private var viewport:INormalizedViewport
    private var scene:IMultiScaleScene
    private var loader:INetworkQueue
    private var tileLoader:TileLoader

    private var tileCache:Cache

    //--------------------------------------------------------------------------
    //
    //  Methods: Validation/Invalidation
    //
    //--------------------------------------------------------------------------

    private var invalidateDisplayListFlag:Boolean = true

    /**
     * @private
     */
    public function invalidateDisplayList():void
    {
        if (!invalidateDisplayListFlag)
            invalidateDisplayListFlag = true
    }

    /**
     * @private
     */
    public function validateDisplayList():void
    {
        if (invalidateDisplayListFlag)
        {
            invalidateDisplayListFlag = false
			
			var index:Number = 0;
			
			// for each image in the renderers (each renderer represents an image)
            for each (var renderer:ImagePyramidRenderer in renderers){
                updateDisplayList(index, renderer)
            }
        }
    }

    //--------------------------------------------------------------------------
    //
    //  Methods
    //
    //--------------------------------------------------------------------------
	
	// input: ImagePyramidRenderer (viewport), 
	
    /**
     * @private
     */
    private function updateDisplayList(index:Number, renderer:ImagePyramidRenderer):void
    {
        // Abort if we're not visible
        if (!renderer.visible)
            return;

        var descriptor:IImagePyramidDescriptor = renderer.source;

        // Abort if we have no descriptor
        if (!descriptor)
            return;

        var viewport:INormalizedViewport = renderer.viewport;
        var scene:IReadonlyMultiScaleScene = renderer.scene;

        // Is renderer on scene?
        if (!viewport)
            return;

        // Compute normalized scene bounds of renderer
        var sceneBounds:Rectangle = renderer.getBounds(scene.targetCoordinateSpace);
            sceneBounds.x /= scene.sceneWidth;
            sceneBounds.y /= scene.sceneHeight;
            sceneBounds.width /= scene.sceneWidth;
            sceneBounds.height /= scene.sceneHeight;

        // Visibility test
        var visible:Boolean = viewport.intersects(sceneBounds);
//		trace(">> viewport: " + viewport);
//		trace(">> sceneBounds: " + sceneBounds);

        if (!visible)
            return;

        // Get viewport bounds (normalized)
        var viewportBounds:Rectangle = viewport.getBounds();

        // Compute normalized visible bounds in renderer coordinate system
        var localBounds:Rectangle = sceneBounds.intersection(viewportBounds);
        localBounds.offset(-sceneBounds.x, -sceneBounds.y);
        localBounds.x /= sceneBounds.width;
        localBounds.y /= sceneBounds.height;
        localBounds.width /= sceneBounds.width;
        localBounds.height /= sceneBounds.height;
		
//		trace(index + ":: " + viewport);
//		trace(index + " viewport: " + viewportBounds.toString());
//		trace(index + " sceneBounds: " + sceneBounds.toString());

        // Determine optimal level
        var stageBounds:Rectangle = renderer.getBounds(renderer.stage);
        var optimalLevel:IImagePyramidLevel = descriptor.getLevelForSize(stageBounds.width,
                                                                         stageBounds.height);

		
//		trace("optimalLevel: " + optimalLevel.index);
//		trace("localBounds: " + localBounds.toString());

		
        // Render image pyramid from bottom up
        var currentTime:int = getTimer();

        var toLevel:int;
        var fromLevel:int;

        toLevel = 0;
        fromLevel = optimalLevel.index;

        var level:IImagePyramidLevel;
        var nextTile:ImagePyramidTile;
        var renderingQueue:Array = [];

        // Iterate over levels
        for (var l:int = fromLevel; l >= toLevel; --l)
        {
            var done:Boolean = true;
            level = descriptor.getLevelAt(l);

            // Load or draw visible tiles
            var fromPoint:Point = new Point(localBounds.left * level.width,
                                            localBounds.top * level.height);
//            var toPoint:Point = new Point((localBounds.right+1) * level.width,
//                                          localBounds.bottom * level.height);
			// impro: localBounds.right+1
//            var toPoint:Point = new Point((localBounds.right+1) * level.width,
//                                          localBounds.bottom * level.height);
            var toPoint:Point = new Point(localBounds.right * level.width,
                                          localBounds.bottom * level.height);
            var fromTile:Point = descriptor.getTileAtPoint(l, fromPoint);

            var toTile:Point = descriptor.getTileAtPoint(l, toPoint);

            // FIXME: Currently center, calculate true origin
            var t:Point = new Point(0.5, 0.5); // viewport.transform.origin
            var origin:Point = new Point((1 - t.x) * fromTile.x + t.x * toTile.x,
                                         (1 - t.y) * fromTile.y + t.y * toTile.y);
	
            // Iterate over columns
            for (var c:int = fromTile.x; c <= toTile.x; c++)
            {
                // Iterate over rows
                for (var r:int = fromTile.y; r <= toTile.y; r++)
                {
                    var tile:ImagePyramidTile = renderer.openzoom_internal::getTile(l, c, r);

                    if (!tile)
                       continue;

                    if (!tile.source)
                    {
                        if (tileCache.contains(tile.url))
                        {
                            var sourceTile:SourceTile = tileCache.get(tile.url) as SourceTile;
                            tile.source = sourceTile;
                            tile.loading = false;
                        }
                    }

                    var dx:Number = tile.column - origin.x;
                    var dy:Number = tile.row - origin.y;
                    var distance:Number = dx*dx + dy*dy;
                    tile.distance = distance;

                    if (!tile.loaded)
                    {
                        if (!tile.loading && (!nextTile || tile.compareTo(nextTile) >= 0))
                            nextTile = tile;

                        done = false;
                        continue;
                    }

                    // Prepare alpha bitmap
                    if (tile.fadeStart == 0)
                        tile.fadeStart = currentTime;

                    tile.source.lastAccessTime = currentTime;

                    var duration:Number = TILE_SHOW_DURATION;
                    var currentAlpha:Number = (currentTime - tile.fadeStart) / duration;
                    tile.alpha = Math.min(1, currentAlpha);

                    if (tile.alpha < 1)
                        done = false;

                    renderingQueue.push(tile);
               }
            }

            if (done)
                break;
        }

        if (nextTile)
        {
            tileLoader.loadTile(nextTile);
            invalidateDisplayList();
        }

        // Prepare tile layer
        var tileLayer:Shape = renderer.openzoom_internal::tileLayer;
        var g:Graphics = tileLayer.graphics;
        g.clear();
        g.beginFill(0xFF0000, 0);
        g.drawRect(0, 0, descriptor.width, descriptor.height);
        g.endFill();
        
//        trace("renderingQueue.length: " + renderingQueue.length );
		
        tileLayer.width = renderer.width;
        tileLayer.height = renderer.height;
		
        while (renderingQueue.length > 0)
        {
            tile = renderingQueue.pop();

            var textureMap:BitmapData;

            if (tile.alpha < 1)
            {
            	
                invalidateDisplayList();

                textureMap = new BitmapData(tile.bitmapData.width,
                                            tile.bitmapData.height);

                var alphaMultiplier:uint = (tile.alpha * 256) << 24;
                var alphaMap:BitmapData;

                alphaMap = new BitmapData(tile.bitmapData.width,
                                          tile.bitmapData.height,
                                          true,
                                          alphaMultiplier | 0x00000000);

                textureMap.copyPixels(tile.bitmapData,
                                      tile.bitmapData.rect,
                                      ZERO_POINT,
                                      alphaMap);
            }
            else
            {

                textureMap = tile.bitmapData;
            }

            // Draw tiles
            level = descriptor.getLevelAt(tile.level);
            var matrix:Matrix = new Matrix();
            var sx:Number;
            var sy:Number;
            var dziDescriptor:DeepZoomImageDescriptor = descriptor as DeepZoomImageDescriptor;

            if (dziDescriptor &&
                dziDescriptor.collection &&
                tile.level <= dziDescriptor.collection.maxLevel)
            {
                // Deep Zoom collection
                var levelSize:uint = 1 << tile.level;
                var position:Point = MortonOrder.getPosition(dziDescriptor.mortonNumber);
                var tileSize:uint = dziDescriptor.collection.tileSize;
                var offsetX:uint = (position.x * levelSize) % tileSize;
                var offsetY:uint = (position.y * levelSize) % tileSize;
                sx = descriptor.width / level.width;
                sy = descriptor.height / level.height;
                matrix.createBox(sx, sy, 0, -offsetX * sx, -offsetY * sy);
            }
            else
            {
                // Normal
                sx = descriptor.width / level.width;
                sy = descriptor.height / level.height;
                var w:Number = tile.bounds.x * sx;
                var h:Number = tile.bounds.y * sy;
                matrix.createBox(sx, sy, 0, w, h);
            }

            g.beginBitmapFill(textureMap,
                              matrix,
                              false, /* repeat */
                              true /* smoothing */);
            g.drawRect(tile.bounds.x * sx,
                       tile.bounds.y * sy,
                       tile.bounds.width * sx,
                       tile.bounds.height * sy);
            g.endFill();
        }
    }

    private static const ZERO_POINT:Point = new Point(0, 0)

    //--------------------------------------------------------------------------
    //
    //  Event handler
    //
    //--------------------------------------------------------------------------

    /**
     * @private
     */
    private function enterFrameHandler(event:Event):void
    {
        // Rendering loop
        validateDisplayList()
    }

    /**
     * @private
     */
    private function viewport_transformUpdateHandler(event:ViewportEvent):void
    {
        invalidateDisplayList()
    }

    /**
     * @private
     */
    private function viewport_transformStartHandler(event:ViewportEvent):void
    {
        if (tileLoader)
            tileLoader.maxDownloads = MAX_DOWNLOADS_DYNAMIC
    }

    /**
     * @private
     */
    private function viewport_transformEndHandler(event:ViewportEvent):void
    {
        if (tileLoader)
            tileLoader.maxDownloads = MAX_DOWNLOADS_STATIC

        // FIXME
        invalidateDisplayList()
    }

    //--------------------------------------------------------------------------
    //
    //  Methods: Renderer management
    //
    //--------------------------------------------------------------------------

    /**
     * @private
     */
    public function addRenderer(renderer:ImagePyramidRenderer):ImagePyramidRenderer
    {
    	
        if (renderers.indexOf(renderer) != -1)
            throw new ArgumentError("[ImagePyramidRenderManager] " +
                                    "Renderer already added.")

        if (renderers.length == 0)
            owner.addEventListener(Event.ENTER_FRAME,
                                   enterFrameHandler,
                                   false, 0, true)

        renderers.push(renderer)
        invalidateDisplayList()

        return renderer
    }

    /**
     * @private
     */
    public function removeRenderer(renderer:ImagePyramidRenderer):ImagePyramidRenderer
    {
        var index:int = renderers.indexOf(renderer)
        if (index == -1)
            throw new ArgumentError("[ImagePyramidRenderManager] " +
                                    "Renderer does not exist.")

        renderers.splice(index, 1)

        if (renderers.length == 0)
            owner.removeEventListener(Event.ENTER_FRAME,
                                      enterFrameHandler)

        return renderer
    }


    //--------------------------------------------------------------------------
    //
    //  Methods: IDisposable
    //
    //--------------------------------------------------------------------------

    public function dispose():void
    {
        // Remove render loop
        owner.removeEventListener(Event.ENTER_FRAME,
                                  enterFrameHandler)

        owner = null
        scene = null
        viewport = null
        loader = null

        tileCache.dispose()
        tileCache = null
    }
}

}
