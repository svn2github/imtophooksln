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
package org.openzoom.flash.descriptors
{

import org.openzoom.flash.core.openzoom_internal;

use namespace openzoom_internal;

//[ExcludeClass]
/**
 * @private
 *
 * Base class for MultiScaleImageLevel.
 */
public class ImagePyramidLevelBase
{
	include "../core/Version.as"

    //--------------------------------------------------------------------------
    //
    //  Constructor
    //
    //--------------------------------------------------------------------------

    /**
     * Constructor.
     */
    public function ImagePyramidLevelBase(index:int,
                                          width:uint,
                                          height:uint,
                                          numColumns:int,
                                          numRows:int)
    {
        _index = index

        _width = width
        _height = height

        _numColumns = numColumns
        _numRows = numRows
    }


    //--------------------------------------------------------------------------
    //
    //  Properties
    //
    //--------------------------------------------------------------------------

    //----------------------------------
    //  index
    //----------------------------------

    private var _index:int

    /**
     * @copy org.openzoom.flash.descriptors.IMultiScaleImageLevel#index
     */
    public function get index():int
    {
        return _index
    }

    //----------------------------------
    //  width
    //----------------------------------

    private var _width:uint

    /**
     * @copy org.openzoom.flash.descriptors.IMultiScaleImageLevel#width
     */
    public function get width():uint
    {
        return _width
    }

    //----------------------------------
    //  height
    //----------------------------------

    private var _height:uint

    /**
     * @copy org.openzoom.flash.descriptors.IMultiScaleImageLevel#height
     */
    public function get height():uint
    {
        return _height
    }

    //----------------------------------
    //  numColumns
    //----------------------------------

    private var _numColumns:int

    /**
     * @copy org.openzoom.flash.descriptors.IMultiScaleImageLevel#numColumns
     */
    public function get numColumns():int
    {
        return _numColumns
    }

    //----------------------------------
    //  numRows
    //----------------------------------

    private var _numRows:int

    /**
     * @copy org.openzoom.flash.descriptors.IMultiScaleImageLevel#numRows
     */
    public function get numRows():int
    {
        return _numRows
    }

    //--------------------------------------------------------------------------
    //
    //  Methods: Debug
    //
    //--------------------------------------------------------------------------

    /**
     * @inheritDoc
     */
    public function toString():String
    {
        return "index:" + index + "\n" +
               "width:" + width + "\n" +
               "height:" + height + "\n" +
               "numRows:" + numRows + "\n" +
               "numColumns:" + numColumns + "\n"
    }
}

}
