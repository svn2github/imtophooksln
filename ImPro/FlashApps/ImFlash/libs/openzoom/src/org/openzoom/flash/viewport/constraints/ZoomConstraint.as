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
package org.openzoom.flash.viewport.constraints
{

import org.openzoom.flash.core.openzoom_internal;
import org.openzoom.flash.viewport.IViewportConstraint;
import org.openzoom.flash.viewport.IViewportTransform;

use namespace openzoom_internal;

/**
 * Provides a way to limit the minimum and maximum zoom the viewport can reach.
 */
public final class ZoomConstraint implements IViewportConstraint
{
	include "../../core/Version.as"

    //--------------------------------------------------------------------------
    //
    //  Class constants
    //
    //--------------------------------------------------------------------------

    private static const DEFAULT_MIN_ZOOM:Number = 0.000001
    private static const DEFAULT_MAX_ZOOM:Number = 10000000

    //--------------------------------------------------------------------------
    //
    //  Constructor
    //
    //--------------------------------------------------------------------------

    /**
     * Constructor.
     */
    public function ZoomConstraint()
    {
    }

    //--------------------------------------------------------------------------
    //
    //  Properties
    //
    //--------------------------------------------------------------------------

    //----------------------------------
    //  minZoom
    //----------------------------------

    private var _minZoom:Number = DEFAULT_MIN_ZOOM

    /**
     * Minimum zoom the viewport can reach.
     */
    public function get minZoom():Number
    {
        return _minZoom
    }

    public function set minZoom(value:Number):void
    {
        _minZoom = value
    }

    //----------------------------------
    //  maxZoom
    //----------------------------------

    private var _maxZoom:Number = DEFAULT_MAX_ZOOM


    /**
     * Maximum zoom the viewport can reach.
     */
    public function get maxZoom():Number
    {
        return _maxZoom
    }

    public function set maxZoom(value:Number):void
    {
       _maxZoom = value
    }

    //--------------------------------------------------------------------------
    //
    //  Methods: IViewportConstraint
    //
    //--------------------------------------------------------------------------

    /**
     * @inheritDoc
     */
    public function validate(transform:IViewportTransform,
                             target:IViewportTransform):IViewportTransform
    {
        // FIXME
        // Prevent from moving when the zoom limit are reached
//        if (transform.zoom == minZoom || transform.zoom == maxZoom)
//        {
////          target.panTo(transform.x, transform.y)
//            return target
//        }

        // validate zoom
        if (transform.zoom > maxZoom)
            transform.zoomTo(maxZoom)

        if (transform.zoom < minZoom)
            transform.zoomTo(minZoom)

        // return validated transform
        return transform
    }
}

}
