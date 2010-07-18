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
package org.openzoom.flash.viewport.controllers
{

import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.events.*;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.utils.Timer;

import impro.googlemap.TouchEventsManager;

import org.openzoom.flash.core.openzoom_internal;
import org.openzoom.flash.viewport.IViewportController;

use namespace openzoom_internal;

/**
 * Mouse controller for viewports.
 */
public final class IMTouchController extends ViewportControllerBase
                                   implements IViewportController
{
	include "../../core/Version.as"

	private var mouseDownCounter:Number = 0;
	public var blob1:Object;
	private var state:String;
	public var blob2:Object;
	private var distanceBlob1Blob2:Number;
	private var oldDistanceBlob1Blob2:Number = 0;
	private var angleBlob1Blob2:Number;
	private var centerPointBlob1Blob2:Point;
	private var zoomDistance:Number = 0;
	private var isDragging:Boolean;
	private var firstPos:Point=new Point();
	private var testSprite:Sprite = new Sprite();
	private var STATE_DRAGGING:String = "dragging";
	private var STATE_SCALE:String = "scale";
	private var STATE_NOTHING:String = "nothing";
	private var ZOOM_THRESHOLD:Number = 100;
	
	private var preFrameIndex:Number = 0;
	
	private var eventListener:Sprite = new Sprite();

    //--------------------------------------------------------------------------
    //
    //  Class constants
    //
    //--------------------------------------------------------------------------

    private static const CLICK_THRESHOLD_DURATION:Number = 500 // milliseconds
    private static const CLICK_THRESHOLD_DISTANCE:Number = 8 // pixels

    private static const DEFAULT_CLICK_ZOOM_IN_FACTOR:Number = 2.0
    private static const DEFAULT_CLICK_ZOOM_OUT_FACTOR:Number = 0.3

    private static const DEFAULT_MOUSE_WHEEL_ZOOM_FACTOR:Number = 1.11

    //--------------------------------------------------------------------------
    //
    //  Constructor
    //
    //--------------------------------------------------------------------------


    /**
     *  Constructor.
     */
    public function IMTouchController()
    {
    	
        createClickTimer()
    }

    //--------------------------------------------------------------------------
    //
    //  Variables
    //
    //--------------------------------------------------------------------------

    private var clickTimer:Timer
    private var click:Boolean = false
    private var mouseDownPosition:Point

    private var viewDragVector:Rectangle = new Rectangle()
    private var viewportDragVector:Rectangle = new Rectangle()
    private var panning:Boolean = false

    //----------------------------------
    //  minMouseWheelZoomInFactor
    //----------------------------------

    public var minMouseWheelZoomInFactor:Number = 1

    //----------------------------------
    //  minMouseWheelZoomOutFactor
    //----------------------------------

    public var minMouseWheelZoomOutFactor:Number = 1

    //----------------------------------
    //  smoothPanning
    //----------------------------------

    public var smoothPanning:Boolean = true

    //----------------------------------
    //  clickEnabled
    //----------------------------------

    public var clickEnabled:Boolean = true

    //----------------------------------
    //  clickZoomInFactor
    //----------------------------------

	private var _minZoomFactor:Number = 0.5;
	private var _maxZoomFactor:Number = 20;


    private var _clickZoomInFactor:Number = DEFAULT_CLICK_ZOOM_IN_FACTOR

    public function set minZoomFactor(value:Number):void
    {
        _minZoomFactor = value
    }
    public function set maxZoomFactcor(value:Number):void
    {
        _maxZoomFactor = value
    }


    /**
     * Factor for zooming into the scene through clicking.
     *
     * @default 2.0
     */
    public function get clickZoomInFactor():Number
    {
        return _clickZoomInFactor
    }

    public function set clickZoomInFactor(value:Number):void
    {
        _clickZoomInFactor = value
    }

    //----------------------------------
    //  clickZoomOutFactor
    //----------------------------------

    private var _clickZoomOutFactor:Number = DEFAULT_CLICK_ZOOM_OUT_FACTOR

    /**
     * Factor for zooming out of the scene through Shift-/Ctrl-clicking.
     *
     * @default 0.3
     */
    public function get clickZoomOutFactor():Number
    {
        return _clickZoomOutFactor
    }

    public function set clickZoomOutFactor(value:Number):void
    {
        _clickZoomOutFactor = value
    }

    //----------------------------------
    //  mouseWheelZoomFactor
    //----------------------------------

    private var _mouseWheelZoomFactor:Number = DEFAULT_MOUSE_WHEEL_ZOOM_FACTOR

    /**
     * Factor for zooming the scene through the mouse wheel.
     *
     * @default 0.05
     */
    public function get mouseWheelZoomFactor():Number
    {
        return _mouseWheelZoomFactor
    }

    public function set mouseWheelZoomFactor(value:Number):void
    {
        _mouseWheelZoomFactor = value
    }

    //--------------------------------------------------------------------------
    //
    //  Methods: Internal
    //
    //--------------------------------------------------------------------------

    /**
     * @private
     */
    private function createClickTimer():void
    {
        clickTimer = new Timer(CLICK_THRESHOLD_DURATION, 1)
        clickTimer.addEventListener(TimerEvent.TIMER_COMPLETE,
                                    clickTimer_completeHandler,
                                    false, 0, true)
    }

    //--------------------------------------------------------------------------
    //
    //  Overridden methods: ViewportControllerBase
    //
    //--------------------------------------------------------------------------

    /**
     * @private
     */
    override protected function view_addedToStageHandler(event:Event):void
    {

        // panning listeners
//        view.addEventListener(MouseEvent.MOUSE_DOWN,
//                              view_mouseDownHandler,
//                              false, 0, true)
//        view.addEventListener(MouseEvent.ROLL_OUT,
//                              view_rollOutHandler,
//                              false, 0, true)
//        view.stage.addEventListener(Event.MOUSE_LEAVE,
//                                    stage_mouseLeaveHandler,
//                                    false, 0, true)

        // zooming listeners
//        view.addEventListener(MouseEvent.MOUSE_WHEEL,
//                              view_mouseWheelHandler,
//                              false, 0, true)

		view.addEventListener(TouchEvent.MOUSE_DOWN, onTouchDown);
		
		// add eventListener
		(view as DisplayObjectContainer).addChild(eventListener);
    }

	public function onTouchDown(e:TouchEvent):void{
		
		if(e.TUIO_TYPE == "2Dobj")
			return;
		
		//add touch event to global touch array
		TouchEventsManager.getInstance().addActiveEvent(e, eventListener);
		
		mouseDownCounter = mouseDownCounter + 1;
		view.addEventListener(TouchEvent.MOUSE_UP, localMouseUp);
		
		eventListener.addEventListener(Event.ENTER_FRAME, handleEnterFrame);
		
		
		var curPt:Point = new Point(e.stageX, e.stageY);
		
		//find out if the contact was with one or with more fingers
		if(mouseDownCounter > 0){
			//we're only dragging
			if(mouseDownCounter == 1){
				state = STATE_DRAGGING;
				
//				var origX:Number = (view as IMMultiScaleContainer).viewportX;
//				var origY:Number = (view as IMMultiScaleContainer).viewportY;
				blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX:0, myOrigY:0};			
//				blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX:x, myOrigY:y};
				
				
				//////////////////////////////////////////////////////////////
				mouseDownPosition = new Point(curPt.x, curPt.y);

		        // assume mouse down is a click
		        click = true;
		
		        // start click timer
		        clickTimer.reset();
		        clickTimer.start();
		
		        // register where we are in the view as well as in the viewport
		        viewDragVector.topLeft = new Point(curPt.x, curPt.y);
		        viewportDragVector.topLeft = new Point(viewport.transformer.target.x,
		                                               viewport.transformer.target.y);
				
		        beginPanning();
//		        trace(">>>>>>>>>>>>>>>>>> beginPanning");
				//////////////////////////////////////////////////////////////
				


			}
			//we're going to scale the map
			if(mouseDownCounter > 1){
				var activeEvents:Array = TouchEventsManager.getInstance().getActiveEvents(eventListener);
				if(activeEvents.length ==1){
					state = STATE_DRAGGING;
//					var origX:Number = (view as IMMultiScaleContainer).viewportX;
//					var origY:Number = (view as IMMultiScaleContainer).viewportY;
					blob1 = {id:e.ID, origX:curPt.x, origY:curPt.y, myOrigX:0, myOrigY:0};					
//					blob1 = {id:e.ID, origX:curPt.x, origY:curPt.y, myOrigX:x, myOrigY:y};
					//mouseDownCounter=1;
				}else{
//					trace("activeEvents.length",activeEvents.length)
					
					try{
						state = STATE_SCALE;
						blob1 = {id:activeEvents[0].id, origX:TUIO.getObjectById(activeEvents[0].id).x, origY:TUIO.getObjectById(activeEvents[0].id).y};
						blob2 = {id:activeEvents[1].id, origX:TUIO.getObjectById(activeEvents[1].id).x, origY:TUIO.getObjectById(activeEvents[1].id).y};
						
						//calculate initial distance of the blobs to see later on in handleEnterFrame if you want to 
						//zoom in (distanceBlob1Blob2 gets bigger) or out (distanceBlob1Blob2 gets smaller)
						distanceBlob1Blob2 = calculateDistance(blob1.origX, blob1.origY, blob2.origX, blob2.origY);
					}catch(error:Error){
						trace("catch error. activeEvents.length",activeEvents.length)
						state = STATE_DRAGGING;

//						var origX:Number = (view as IMMultiScaleContainer).viewportX;
//						var origY:Number = (view as IMMultiScaleContainer).viewportY;						
						blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: 0, myOrigY:0};						
//						blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: x, myOrigY:y};
						//mouseDownCounter=1;
					}
				}
			}
		}
		
		//the point in the map where you tapped. you need this for panning in the map.
		firstPos.x = curPt.x;
		firstPos.y = curPt.y;
	} 

	//reset everything after removing your finger	    
    public function mouseUp(e:TouchEvent):void{
    	
		var activeEvents:Array = TouchEventsManager.getInstance().getActiveEvents(eventListener);
		mouseDownCounter = activeEvents.length;
		
		if(mouseDownCounter == 0){
			state = STATE_NOTHING;
			
			if(view)
				view.removeEventListener(TouchEvent.MOUSE_UP, localMouseUp);
			eventListener.removeEventListener(Event.ENTER_FRAME, handleEnterFrame);

			stopPanning();
			
			// issue event
			if(	viewport)	
				viewport.touchEndTransform();
			
//			isDragging = false;
//			trace("isDragging = false;");
		}
		if(mouseDownCounter == 1){
			// one finger lifted, still have another finger on dragging
			state = STATE_DRAGGING;
		}
		if(mouseDownCounter < 2){
			oldDistanceBlob1Blob2 = 0;
			distanceBlob1Blob2 = 0;
			zoomDistance = 0;
		}
		if(mouseDownCounter > 1){
			state = STATE_SCALE;
		}
	}

	//take your touch out of the global touch array and
	//reset everything after removing your finger
	public function localMouseUp(e:TouchEvent):void{
		
		var searchedElementFound:Number;
		searchedElementFound = TouchEventsManager.getInstance().endActiveEvent(e);

//		trace("localMouseUp ActiveEvents.length: " + TouchEventsManager.getInstance().getActiveEvents(eventListener).length);
		mouseUp(e);
//		trace("mouseUp ActiveEvents.length: " + TouchEventsManager.getInstance().getActiveEvents(eventListener).length);
		
				
	}

		//handleEnterFrame carries out the panning and zooming activities
		//it is called in every frame while you're touching the screen
		protected function handleEnterFrame(e:Event):void {
			
		  	if(!viewport){
		  		trace("viewport == null");
		  		return;
		  	}
			
			
			
			
			// apply translation & sclae to application
			if(!panning)
				return;
			
			var frameIndex:Number = TUIO.FrameIndex();			
			if(frameIndex == preFrameIndex)
				return;
			preFrameIndex = frameIndex;
				
			var translation:Point = TUIO.Translation();
			var zoom:Number = TUIO.Scale();
			var curCenter:Point = TUIO.Center();
			
				        
	        var distanceX:Number = translation.x / viewport.viewportWidth;
	        var distanceY:Number = translation.y / viewport.viewportHeight;	
//	        var targetX:Number = curCenter.x - (distanceX * viewport.width);
//	        var targetY:Number = curCenter.y - (distanceY * viewport.height);
			
			trace("viewport.width: " + viewport.width);
			

//			if(distanceX + distanceY != 0)
			{
	//        	viewport.panTo(targetX, targetY, !smoothPanning);
				viewport.panBy(-distanceX*viewport.width, -distanceY*viewport.height, !smoothPanning);				
			}
						
			if(zoom > 0){
				trace(">>> zoom: " + zoom);
	  			viewport.zoomBy(zoom,  
		  			curCenter.x / view.width,
	                curCenter.y / view.height);	
				
//				if(viewport.zoom < _minZoomFactor){
//					viewport.zoomBy(_minZoomFactor/viewport.zoom);
//				}
//				if(viewport.zoom > _maxZoomFactor){
//					viewport.zoomBy(_maxZoomFactor/viewport.zoom);
//				}	                			
			}
			
			
			
			
			/*						
			//trace(this, "handleEnterFrame");
			//make your own TouchEvent object in case that you want to render
			//a TouchEvent.MOUSE_UP (you will want to if you're blob has gone
			//that means you do not touch the screen anymore
			var touchEvent:TouchEvent = new TouchEvent(TouchEvent.MOUSE_UP);
			if(state == STATE_DRAGGING){
				//trace(this, "STATE_DRAGGING");
				//get touch object of your finger
				trace("blob1.id: " + blob1.id);
				var tuioobj : TUIOObject = TUIO.getObjectById(blob1.id);
				if(tuioobj){
					//find out how far your finger has moved since the last frame
//					var getSizeX:Number = (view as IMMultiScaleContainer).viewportWidth;
//					var getSizeY:Number = (view as IMMultiScaleContainer).viewportHeight;
//					var getSizeX:Number = 600;
//					var getSizeY:Number = 450;
//					var percentPannedX:Number = (tuioobj.x - firstPos.x)/getSizeX;
//					var percentPannedY:Number = (tuioobj.y - firstPos.y)/getSizeY;
//					var percentPannedX:Number = (tuioobj.x - firstPos.x)/getSize().x;
//					var percentPannedY:Number = (tuioobj.y - firstPos.y)/getSize().y;
					
					
					//////////////////////////////////////////////////////////////
					
			        if (!panning)
			            return;

			        // update view drag vector
			        viewDragVector.bottomRight = new Point(tuioobj.x, tuioobj.y);
					
			        var distanceX:Number;
			        var distanceY:Number;
			        var targetX:Number;
			        var targetY:Number;
			
			        distanceX = viewDragVector.width / viewport.viewportWidth;
			        distanceY = viewDragVector.height / viewport.viewportHeight;
			
			        targetX = viewportDragVector.x - (distanceX * viewport.width);
			        targetY = viewportDragVector.y - (distanceY * viewport.height);
			
			        // FIXME: Zoom skipping when smoothPanning = false
//			        if(viewport)
			        	viewport.panTo(targetX, targetY, !smoothPanning)
			        			        
			        //////////////////////////////////////////////////////////////			        					
					
					
					//get the bounding box of the map that is currently on screen
//					var bounds:LatLngBounds = getLatLngBounds();
					//calculate lat/lon coordinate distance of bounds on screen 
//				  	var spanX:Number = bounds.getNorthWest().lng() - bounds.getSouthEast().lng();
//				  	var spanY:Number = bounds.getNorthWest().lat() - bounds.getSouthEast().lat();
				  	
				  	//set new map center by adding to the map's center the lat/lon distance multiplied 
				  	//with the amount that your finger has moved on screen 
//				  	var newCenterLat:Number = getCenter().lat() + spanY*percentPannedY;
//				  	var newCenterLon:Number = getCenter().lng() + spanX*percentPannedX;
//				  	this.setCenter(new LatLng(newCenterLat, newCenterLon));
					
					// do something here
					
					//set the position of your finger in this frame as the initial position for the next
					//frame
				  	firstPos.x = tuioobj.x;
					firstPos.y = tuioobj.y;
				}else{
					//if the touch could not be found anymore you have removed your finger and a mouseUp 
					//must be rendered
					
					touchEvent.ID = blob1.id;
					localMouseUp(touchEvent);
					
				}
			}
			if(state == STATE_SCALE){
				//trace(this,"STATE_SCALE");
				//get touch objects of your fingers
				var tuioobjRS : TUIOObject = TUIO.getObjectById(blob1.id);
				var tuioobj2 : TUIOObject = TUIO.getObjectById(blob2.id);
				if(tuioobjRS && tuioobj2){
					var zoomScale:Number;
					//find out distance of your fingers in this frame
					var distanceBlob1Blob2Enter:Number = calculateDistance(tuioobjRS.x,tuioobjRS.y, tuioobj2.x, tuioobj2.y);
					//find out where the center of your fingers is. this is the point where you want to 
					//zoom in later!
					centerPointBlob1Blob2 = new Point(tuioobjRS.x+(tuioobj2.x - tuioobjRS.x)/2, tuioobjRS.y+(tuioobj2.y - tuioobjRS.y)/2);
					
					//find out how much your fingers have moved since last frame
//					var getSizeX:Number = (view as IMMultiScaleContainer).viewportWidth;
//					var getSizeY:Number = (view as IMMultiScaleContainer).viewportHeight;
//					var getSizeX:Number = 600;
//					var getSizeY:Number = 450;
//					var percentZoomedX:Number = centerPointBlob1Blob2.x/getSizeX;
//					var percentZoomedY:Number = centerPointBlob1Blob2.y/getSizeY;
//					var percentZoomedX:Number = centerPointBlob1Blob2.x/getSize().x;
//					var percentZoomedY:Number = centerPointBlob1Blob2.y/getSize().y;
					
					//get map's bounding box
//					var boundsn:LatLngBounds = getLatLngBounds();
					//calculate lat/lon distances of current map coutout
//					var spanXn:Number =  boundsn.getSouthEast().lng()-boundsn.getNorthWest().lng();
//				  	var spanYn:Number =  boundsn.getSouthEast().lat()-boundsn.getNorthWest().lat();
				  	
				  	//add the zoom amount to the maps lat/lon positions to get the new center
//				  	var newCenterLonn:Number = boundsn.getNorthWest().lng() + spanXn*percentZoomedX;
//				  	var newCenterLatn:Number = boundsn.getNorthWest().lat() + spanYn*percentZoomedY;
				  	
				  	//this is the really tricky part:
				  	//google maps has only ~22 zoom steps. there is no continous zooming but 
					//you can only set one of those steps. that means you cannot set the next 
					//step after your fingers have moved a bit away from each other but you have
					//to check if they have moved a certain distance (i took ZOOM_THRESHOLD for this
					//certain distance). that means that i have to add every little bit (distanceToLastFrame) 
					//that the 
					//fingers have moved away from each other to zoomDistance in every frame. if zoomDistance
					//is eventually bigger or smaller (zoom in or out) than ZOOM_THRESHOLD i can zoom in
					//or out one step.
				  	var distanceToLastFrame:Number = distanceBlob1Blob2Enter-distanceBlob1Blob2;
				  	zoomDistance = zoomDistance + distanceToLastFrame;				  	

				  	var littleZoom:Number = distanceBlob1Blob2Enter / distanceBlob1Blob2;
				  	
//				  	trace("===================");
//				  	trace("viewport.zoom:" + viewport.zoom);
//				  	trace("littleZoom:" + littleZoom); 				  	
				  	
		  			viewport.zoomBy(littleZoom, 
			  			centerPointBlob1Blob2.x / view.width,
                        centerPointBlob1Blob2.y / view.height);
						
//					if(viewport.zoom < _minZoomFactor){
//						(view as IMMultiScaleContainer).illegalZoom();
//						viewport.zoomBy(_minZoomFactor/viewport.zoom);
//					}
//					if(viewport.zoom > _maxZoomFactor){
//						(view as IMMultiScaleContainer).illegalZoom();						
//						viewport.zoomBy(_maxZoomFactor/viewport.zoom);
//					}
					
				  	trace("viewport.zoom:" + viewport.zoom);
				  	  
					distanceBlob1Blob2 = distanceBlob1Blob2Enter;
				}else{
					//render mouse ups if your fingers are not on the screen anymore
					if(!tuioobjRS){
						touchEvent.ID = blob1.id;
						localMouseUp(touchEvent);
					}
					if(!tuioobj2){
						touchEvent.ID = blob2.id;
						localMouseUp(touchEvent);
					}
				}
			}
			*/
		}

	//calculates the length of the vector between two points
	private function calculateDistance(blob1X:Number, blob1Y:Number, blob2X:Number, blob2Y:Number):Number{
		var initalDistanceX:Number =blob1X - blob2X;
		var initalDistanceY:Number =blob1Y - blob2Y;
		
		var initalDistance:Number = Math.sqrt(initalDistanceX*initalDistanceX + initalDistanceY*initalDistanceY);
		
		return initalDistance;
	}


    /**
     * @private
     */
//    override protected function view_removedFromStageHandler(event:Event):void
//    {
//    	if (view)
//    	{
//	        // panning listeners
//	        view.removeEventListener(MouseEvent.MOUSE_DOWN,
//	                                 view_mouseDownHandler)
//	        view.removeEventListener(MouseEvent.ROLL_OUT,
//	                                 view_rollOutHandler)
//	                                 
//            if (view.stage) 
//		        view.stage.removeEventListener(Event.MOUSE_LEAVE,
//		                                       stage_mouseLeaveHandler)
//	
//	        // zooming listeners
////	        view.removeEventListener(MouseEvent.MOUSE_WHEEL,
////	                                 view_mouseWheelHandler)
//    	}
//    }

    //--------------------------------------------------------------------------
    //
    //  Event Handlers: Zooming
    //
    //--------------------------------------------------------------------------

    /**
     * @private
     */
//    private function view_mouseWheelHandler(event:MouseEvent):void
//    {
//        // prevent zooming when panning
//        if (panning)
//            return
//
//        // FIXME: Supposedly prevents unwanted scrolling in browsers
//        event.stopPropagation()
//
//        // TODO: React appropriately to different platforms and/or browsers,
//        // as they at times report completely different mouse wheel deltas.
//        var factor:Number = clamp(Math.pow(mouseWheelZoomFactor, event.delta), 0.5, 3)
//
//        // TODO: Refactor
//        if (factor < 1)
//            factor = Math.min(factor, minMouseWheelZoomOutFactor)
//        else
//            factor = Math.max(factor, minMouseWheelZoomInFactor)
//
//        // compute normalized origin of mouse relative to viewport.
//        var originX:Number = view.mouseX / view.width
//        var originY:Number = view.mouseY / view.height
//
//        // transform viewport
//        viewport.zoomBy(factor, originX, originY)
//
//        // TODO
//        event.updateAfterEvent()
//    }

    //--------------------------------------------------------------------------
    //
    //  Event Handlers: Panning
    //
    //--------------------------------------------------------------------------

    /**
     * @private
     */
    private function clickTimer_completeHandler(event:TimerEvent):void
    {
        click = false
        clickTimer.reset()
    }

    /**
     * @private
     */
//    private function view_mouseDownHandler(event:MouseEvent):void
//    {   	
//    	trace(">>>   >>>   in view_mouseDownHandler!!");
//        view.addEventListener(MouseEvent.MOUSE_UP,
//                              view_mouseUpHandler,
//                              false, 0, true)
//		
////		trace("Mouse: " + view.mouseX + ", " +  view.mouseY);
//		
//        // remember mouse position
//        mouseDownPosition = new Point(view.mouseX, view.mouseY)
//
//        // assume mouse down is a click
//        click = true
//
//        // start click timer
//        clickTimer.reset()
//        clickTimer.start()
//
//        // register where we are in the view as well as in the viewport
//        viewDragVector.topLeft = new Point(view.mouseX, view.mouseY)
//        viewportDragVector.topLeft = new Point(viewport.transformer.target.x,
//                                               viewport.transformer.target.y)
//
//        beginPanning()
//    }

    /**
     * @private
     */
//    private function view_mouseMoveHandler(event:MouseEvent):void
//    {
//        if (!panning)
//            return;
//		
////		(view as IMMultiScaleContainer).viewportX += 0.01;
////		trace("move: " + (view as IMMultiScaleContainer).viewportX);
//
//		
//        // update view drag vector
//        viewDragVector.bottomRight = new Point(view.mouseX, view.mouseY)
//
//        var distanceX:Number
//        var distanceY:Number
//        var targetX:Number
//        var targetY:Number
//
//        distanceX = viewDragVector.width / viewport.viewportWidth
//        distanceY = viewDragVector.height / viewport.viewportHeight
//
//        targetX = viewportDragVector.x - (distanceX * viewport.width)
//        targetY = viewportDragVector.y - (distanceY * viewport.height)
//
//        // FIXME: Zoom skipping when smoothPanning = false
//        viewport.panTo(targetX, targetY, !smoothPanning)
//        
//    }

    /**
     * @private
     */
//    private function view_mouseUpHandler(event:MouseEvent):void
//    {
//    	
//        view.removeEventListener(MouseEvent.MOUSE_UP, view_mouseUpHandler)
//
//        var mouseUpPosition:Point = new Point(view.mouseX, view.mouseY)
//        var dx:Number = mouseUpPosition.x - mouseDownPosition.x
//        var dy:Number = mouseUpPosition.y - mouseDownPosition.y
//
//        var distance:Number = Math.sqrt(dx * dx + dy * dy)
//
//        if (clickEnabled && click && distance < CLICK_THRESHOLD_DISTANCE)
//        {
//            var factor:Number
//
//            if (event.shiftKey || event.ctrlKey)
//                factor = clickZoomOutFactor
//            else
//                factor = clickZoomInFactor
//
//            viewport.zoomBy(factor,
//                            view.mouseX / view.width,
//                            view.mouseY / view.height)
//        }
//
//        click = false
//        clickTimer.reset()
//
//        stopPanning()
//        trace(">>>>>>>>>>>>>>>>>> stopPanning");
//    }

    /**
     * @private
     */
    private function beginPanning():void
    {
        // begin panning
        panning = true
        
        // add by me
		viewport.touchBeginTransform();
		
        // register for mouse move events
//        view.addEventListener(MouseEvent.MOUSE_MOVE,
//                              view_mouseMoveHandler,
//                              false, 0, true)
    }

    /**
     * @private
     */
    private function stopPanning():void
    {
        // unregister from mouse move events
        // FIXME
//        if (view)
//            view.removeEventListener(MouseEvent.MOUSE_MOVE,
//                                     view_mouseMoveHandler)

        panning = false
    }

    /**
     * @private
     */
//    private function stage_mouseLeaveHandler(event:Event):void
//    {
//        stopPanning()
//    }

    /**
     * @private
     */
//    private function view_rollOutHandler(event:MouseEvent):void
//    {
//        stopPanning()
//    }
}

}
