////////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2010 Julius Loa | jloa@chargedweb.com
//  All Rights Reserved.
//  license: GNU {http://www.opensource.org/licenses/gpl-2.0.php}
//  notice: just keep the header plz
//
////////////////////////////////////////////////////////////////////////////////

package com.chargedweb.utils
{
	import flash.display.JointStyle;
	import flash.display.Shape;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.TimerEvent;
	import flash.system.System;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;
	import flash.utils.Timer;

	/**
	 * <p>ResourceMonitorUtil class provides the fps and used memory information <a href="http://chargedweb.com/labs/2010/05/06/resourcemonitor-v2-resourcemonitorutil/" target="_blank">more info online</a></p>
	 * @author			Julius Loa aka jloa, jloa@chargedweb.com
	 * @availability 	flash/flex, as3
	 * @version 		2.0
	 * 
	 * <p>Class usage:</p>
	 * @example Flex sample:
	 * <listing version="3.0">
	 * import com.chargedweb.utils.ResourceMonitorUtil;
	 * 
	 * rawChildren.addChild(new ResourceMonitorUtil());
	 * </listing>
	 * 
	 * @example Flash sample:
	 * <listing version="3.0">
	 * import com.chargedweb.utils.ResourceMonitorUtil;
	 * 
	 * addChild(new ResourceMonitorUtil());
	 * </listing>
	 */
	public class ResourceMonitorUtil extends Sprite
	{
		////////////////
		//
		//	Infos
		//
		////////////////
		
		/**
		 * Fps info text
		 * %fps% replaced by the current fps value
		 * %fpsMax% replaced by the current fpsMax value
		 */
		public static var FPS_INFO:String = "Fps: %fps%/%fpsMax%";
		
		/**
		 * Fps average info text %fpsAVG% replaced by the current average fps value
		 */
		public static var FPS_AVG_INFO:String = "FpsAVG: %fpsAVG%";
		
		/**
		 * Memory info text
		 * %memory% replaced by the current memory value [mb]
		 * %memoryMax% replaced by the current memoryMax value [mb]
		 */
		public static var MEMORY_INFO:String = "Ram: %memory%/%memoryMax% mb";
		
		/**
		 * Memory average info text %memoryUsedAVG% replaced by the current average memory value [mb]
		 */
		public static var MEMORY_AVG_INFO:String = "RamAVG: %memoryAVG% mb";
		
		////////////////
		//
		//	Styles
		//
		////////////////
		
		// grid color
		private var _gridColor:uint = 0xFFFFFF;
		
		// grid alpha
		private var _gridAlpha:Number = .25;
		
		// background color
		private var _backgroundColor:uint = 0x000000;
		
		// background alpha
		private var _backgroundAlpha:Number = 1;
		
		// fps line size
		private var _fpsLineSize:int = 2;
		
		// fps line color
		private var _fpsLineColor:int = 0xFFCC00;
		
		// memory line size
		private var _memoryLineSize:int = 2;
		
		// memory line color
		private var _memoryLineColor:int = 0x00CCFF;
		
		////////////////
		//
		//	Misc
		//
		////////////////
		
		// maximum memory value [bytes]
		private var _memoryMax:int = 500*1024*1024;
		
		// current memory used [bytes]
		private var _memory:int = 0;
		
		// current average memory used [bytes]
		private var _memoryAVG:int = 0;
		
		// max fps value
		private var _fpsMax:int = 0;
		
		// current fps value
		private var _fps:int = 0;
		
		// current average fps value
		private var _fpsAVG:int = 0;
		
		// whether to show the average fps value
		private var _showFpsAVG:Boolean = true;
		
		// whether to show the average memory value
		private var _showMemoryAVG:Boolean = true;
		
		// whether to show the grid
		private var _showGrid:Boolean = true;
		
		// whether to show the text field
		private var _showText:Boolean = true;
		
		// history {fps:int, memory:Number}
		private var _history:Array;
		
		// history length
		private var _historyLength:int = 20;
		
		// monitor timer
		private var _monitorTimer:Timer;
			
		// text format
		private var _format:TextFormat = new TextFormat("Verdana", 10, 0x000000);
		
		// textfield instance
		private var _tf:TextField;
		private var _tfbg:Sprite;
		
		// background
		private var _bg:Sprite;
		
		// fps graph
		private var _bgFps:Shape;
		
		// memory graph
		private var _bgMemory:Shape;
		
		// grid
		private var _grid:Shape;
		
		// frames counter
		private var _frames:int = 0;
		
		// width holder
		private var _width:int = 150;
		
		// height holder
		private var _height:int = 120;
		
		////////////////
		//
		//	PUBLIC
		//
		////////////////
		
		/**
		 * Converts value from kilobytes to megabytes
		 * @param	value:int			kilobytes to convert
		 * @param	fractionDigits:int	an integer between 0 and 20, inclusive, that represents the desired number of decimal places @default 2
		 */
		public static function kbToMb(value:int, fractionDigits:int = 2):Number
		{
			if(fractionDigits < 0 || fractionDigits > 20) throw new Error("fractionDigits values must be between 0 and 20", 0);
			return Number((value/(1024*1024)).toFixed(fractionDigits));
		}
		
		/**
		 * Constructor
		 * @return	nothing
		 */
		public function ResourceMonitorUtil()
		{
			super();			
			addEventListener(Event.ADDED_TO_STAGE, onAddedToStage);
		}
		
		/**
		 * Starts monitoring resource usage @see #stop()
		 * @return	nothing
		 */
		public function monitor():void
		{
			_monitorTimer.start();
			if(!hasEventListener(Event.ENTER_FRAME)) addEventListener(Event.ENTER_FRAME, onFpsTimer);
			dispatchEvent(new Event(Event.INIT));
		}
		
		/**
		 * Stops monitoring resource usage @see #monitor()
		 * @return 	nothing
		 */
		public function stop():void
		{
			_monitorTimer.stop();
			if(hasEventListener(Event.ENTER_FRAME)) removeEventListener(Event.ENTER_FRAME, onFpsTimer);
		}
		
		/**
		 * Redraws everything
		 * @return	nothing
		 */
		public function redraw():void
		{
			redrawTextField();
			redrawBackground();
			redrawGrid();
			redrawFpsGraph();
			redrawMemoryGraph();
		}
		
		////////////////////////////////
		//
		//	SETTERS/GETTERS
		//
		////////////////////////////////
		
		/**
		 * Overriden width property
		 * @param	value:Number	new width value
		 * @return	Number			current width value
		 */
		override public function set width(value:Number):void
		{
			_width = value;
			redraw();
		}
		override public function get width():Number
		{
			return _width;
		}
		
		/**
		 * Overriden height property
		 * @param	value:Number	new height value
		 * @return	Number			current height value
		 */
		override public function set height(value:Number):void
		{
			_height = value;
			redraw();
		}
		override public function get height():Number
		{
			return _height;
		}
		
		/**
		 * Sets/gets the textFormat for the TextField @default new TextFormat("Verdana", 10, 0x000000);
		 * @param	value:TextFormat	new text format
		 * @return	TextFormat			current text format
		 */
		public function set textFormat(value:TextFormat):void
		{
			_format = value;
			redraw();
		}
		public function get textFormat():TextFormat
		{
			return _format;
		}
		
		/**
		 * Returns the history array of objects {fps:int, memory:Number}
		 * memory in bytes
		 * @return	Array		current history array
		 */
		public function get history():Array
		{
			return _history;
		}
		
		/**
		 * Sets/gets the history length (number of records to store in the history array) value @default 20
		 * @param	value:int	new history length value
		 * @return	int			current history length value
		 */
		public function set historyLength(value:int):void
		{
			_historyLength = value;
			initHistory();
			redraw();
		}
		public function get historyLength():int
		{
			return _historyLength;
		}
		
		/**
		 * Returns the current fps value
		 * @return	int		current fps value
		 */
		public function get fps():int
		{
			return _fps;
		}
		
		/**
		 * Returns the current average fps value
		 * @return	int		current average fps value
		 */
		public function get fpsAVG():int
		{
			return _fpsAVG;
		}
		
		/**
		 * Returns the max fps value
		 * @return	int		max fps value
		 */
		public function get fpsMax():int
		{
			return _fpsAVG;
		}
		
		/**
		 * Returns the current memory used value [bytes]
		 * @return	int		current memory used value [bytes]
		 */
		public function get memory():int
		{
			return _memory;
		}
		
		/**
		 * Returns the current average memory used value [bytes]
		 * @return	int		current average memory used value [bytes]
		 */
		public function get memoryAVG():int
		{
			return _memoryAVG;
		}
		
		/**
		 * Sets/gets the max memory value @default 500*1024*1024
		 * @param	value:int	new max memory value [bytes]
		 * @return	int			current max memory value [bytes]
		 */
		public function set memoryMax(value:int):void
		{
			_memoryMax = value;
			redraw();
		}
		public function get memoryMax():int
		{
			return _memoryMax;
		}
		
		/**
		 * Sets/gets whether to show or not the average fps @default true
		 * @param	value:Boolean	new value
		 * @return	Boolean			current value
		 */
		public function set showFpsAVG(value:Boolean):void
		{
			_showFpsAVG = value;
			redraw();
		}
		public function get showFpsAVG():Boolean
		{
			return _showFpsAVG;
		}
		
		/**
		 * Sets/gets whether to show or not the average memory @default true
		 * @param	value:Boolean	new value
		 * @return	Boolean			current value
		 */
		public function set showMemoryAVG(value:Boolean):void
		{
			_showMemoryAVG = value;
			redraw();
		}
		public function get showMemoryAVG():Boolean
		{
			return _showMemoryAVG;
		}
		
		/**
		 * Sets/gets whether to show or not the textField info @default true
		 * @param	value:Boolean	new value
		 * @return	Boolean			current value
		 */
		public function set showText(value:Boolean):void
		{
			_showText = value;
			redraw();
		}
		public function get showText():Boolean
		{
			return _showText;
		}
		
		/**
		 * Sets/gets whether to show or not the grid @default true
		 * @param	value:Boolean	new value
		 * @return	Boolean			current value
		 */
		public function set showGrid(value:Boolean):void
		{
			_showGrid = value;
			redrawGrid();
		}
		public function get showGrid():Boolean
		{
			return _showGrid;
		}
		
		/**
		 * Sets/gets the grid color @default 0xFFFFFF
		 * @param	value:uint	new grid color value
		 * @return	uint		current grid color value
		 */
		public function set gridColor(value:uint):void
		{
			_gridColor = value;
			redrawGrid();
		}
		public function get gridColor():uint
		{
			return _gridColor;
		}
		
		/**
		 * Sets/gets the grid alpha @default 0.25
		 * @param	value:Number	new grid alpha value
		 * @return	Number			current grid alpha value
		 */
		public function set gridAlpha(value:Number):void
		{
			_gridAlpha = value;
			redrawGrid();
		}
		public function get gridAlpha():Number
		{
			return _gridAlpha;
		}
		
		/**
		 * Sets/gets the background color @default 0x000000
		 * @param	value:uint	new background color value
		 * @return	uint		current background color value
		 */
		public function set backgroundColor(value:uint):void
		{
			_backgroundColor = value;
			redrawBackground();
		}
		public function get backgroundColor():uint
		{
			return _backgroundColor;
		}
		
		/**
		 * Sets/gets the background alpha @default 1
		 * @param	value:Number	new background alpha value
		 * @return	Number			current background alpha value
		 */
		public function set backgroundAlpha(value:Number):void
		{
			_backgroundAlpha = value;
			redrawBackground();
		}
		public function get backgroundAlpha():Number
		{
			return _backgroundAlpha;
		}
		
		/**
		 * Sets/gets the fps line size @default 2
		 * @param	value:int	new fps line size value
		 * @return	int			current fps line size value
		 */
		public function set fpsLineSize(value:int):void
		{
			_fpsLineSize = value;
			redrawFpsGraph();
		}
		public function get fpsLineSize():int
		{
			return _fpsLineSize;
		}
		
		/**
		 * Sets/gets the fps line color @default 0xFFCC00
		 * @param	value:uint	new fps line color value
		 * @return	uint		current fps line color value
		 */
		public function set fpsLineColor(value:uint):void
		{
			_fpsLineColor = value;
			redrawFpsGraph();
		}
		public function get fpsLineColor():uint
		{
			return _fpsLineColor;
		}
		
		/**
		 * Sets/gets the memory line size @default 2
		 * @param	value:int	new memory line size value
		 * @return	int			current memory line size value
		 */
		public function set memoryLineSize(value:int):void
		{
			_memoryLineSize = value;
			redrawMemoryGraph();
		}
		public function get memoryLineSize():int
		{
			return _memoryLineSize;
		}
		
		/**
		 * Sets/gets the memory line color @default 0x00CCFF
		 * @param	value:uint	new memory line color value
		 * @return	uint		current memory line color value
		 */
		public function set memoryLineColor(value:uint):void
		{
			_memoryLineColor = value;
			redrawMemoryGraph();
		}
		public function get memoryLineColor():uint
		{
			return _memoryLineColor;
		}
		
		////////////////
		//
		//	PRIVATE
		//
		////////////////
		
		/**
		 * @private Inits the history array
		 * @return 	nothing
		 */
		private function initHistory():void
		{
			_history = new Array();
			
			for(var i:int = 0; i < _historyLength; i++)
				_history.push({fps: _fpsMax, memory: 0});
		}
		
		/**
		 * @private Creates children
		 * @return nothing
		 */
		private function createChildren():void
		{
			
			_tfbg = new Sprite();
			this.addChild(_tfbg);
			
			_tf = new TextField();
			_tf.defaultTextFormat = _format;
			_tf.autoSize = TextFieldAutoSize.LEFT;
			_tf.multiline = true;
			_tf.wordWrap = true;
			_tf.selectable = false;
			this.addChild(_tf);
			
			_bg = new Sprite();
			this.addChild(_bg);
			
			_grid = new Shape();
			_bg.addChild(_grid);
			
			_bgFps = new Shape();
			_bg.addChild(_bgFps);
			
			_bgMemory = new Shape();
			_bg.addChild(_bgMemory);
			
			redraw();
			monitor();
		}
		
		/**
		 * @private Redraws the textField
		 * @return	nothing
		 */
		private function redrawTextField():void
		{
			if(!_tf) return;
			_tf.width = _width;

			if(!_tfbg) return;
			_tfbg.graphics.clear();
			_tfbg.graphics.beginFill(0xffffff, 0.8);
			_tfbg.graphics.drawRect(0, 0, _width, int(_tf.height));
			_tfbg.graphics.endFill();
			
			if(_showText)
			{
				_tf.text = FPS_INFO.replace("%fps%", _fps).replace("%fpsMax%", _fpsMax);
				if(_showFpsAVG) _tf.appendText("\n"+FPS_AVG_INFO.replace("%fpsAVG%", _fpsAVG));
				_tf.appendText("\n"+MEMORY_INFO.replace("%memory%", kbToMb(_memory)).replace("%memoryMax%", kbToMb(_memoryMax)));
				if(_showMemoryAVG) _tf.appendText("\n"+MEMORY_AVG_INFO.replace("%memoryAVG%", kbToMb(_memoryAVG)));
			}else{
				_tf.text = "";
			}
		}
		
		/**
		 * @private Redraws the background
		 * @return	nothing
		 */
		private function redrawBackground():void
		{
			if(!_bg) return;
			_bg.x = 0;
			_bg.y = int(_tf.height);
			_bg.graphics.clear();
			_bg.graphics.beginFill(_backgroundColor, _backgroundAlpha);
			_bg.graphics.drawRect(0, 0, _width, _height - _bg.y);
			_bg.graphics.endFill();
		}
		
		/**
		 * @private Redraws the grid
		 * @return	nothing
		 */
		private function redrawGrid():void
		{
			if(!_grid) return;
			var step:Number = _width/_historyLength;
			
			_grid.graphics.clear();
			_grid.visible = _showGrid;
			if(!_showGrid) return;
			
			for(var i:int = 0; i < _historyLength; i++)
			{
				_grid.graphics.lineStyle(1, _gridColor, _gridAlpha, false, "normal", "none", JointStyle.MITER);
				_grid.graphics.moveTo(i*step, 0);
				_grid.graphics.lineTo(i*step, _height - _bg.y);
				_grid.graphics.endFill();
			}			
		}
		
		/**
		 * @private Redraws the fps graph
		 * @return	nothing
		 */
		private function redrawFpsGraph():void
		{
			if(!_bgFps) return;
			var step:Number = _width/_historyLength;
			var h:int = _height - _bg.y;
			
			_bgFps.graphics.clear();
			_bgFps.graphics.lineStyle(_fpsLineSize, _fpsLineColor, 1, false, "normal", "none", JointStyle.MITER);
			
			for(var i:int = 0; i < _historyLength; i++)
			{
				if(i == 0) _bgFps.graphics.moveTo(step*i, (_history[i].fps/_fpsMax)*h);
				else _bgFps.graphics.lineTo(step*i, (_history[i].fps/_fpsMax)*h);
			}
			
			_bgFps.graphics.endFill();
		}
		
		/**
		 * @private Redraws the memory graph
		 * @return	nothing
		 */
		private function redrawMemoryGraph():void
		{
			if(!_bgMemory) return;
			var step:Number = _width/_historyLength;
			var h:int = _height - _bg.y;
			
			_bgMemory.graphics.clear();
			_bgMemory.graphics.lineStyle(_memoryLineSize, _memoryLineColor, 1, false, "normal", "none", JointStyle.MITER);
			
			for(var i:int = 0; i < _historyLength; i++)
			{
				if(i == 0) _bgMemory.graphics.moveTo(step*i, h - (_history[i].memory/_memoryMax)*h);
				else _bgMemory.graphics.lineTo(step*i, h - (_history[i].memory/_memoryMax)*h);
			}
			
			_bgMemory.graphics.endFill();
		}
		
		/**
		 * @private Counts the current average fps value
		 * @return	int		current average fps value
		 */
		private function countFpsAVG():int
		{
			var f:int = 0;
			var n:int = 0
			for(var i:int = 0; i < _historyLength; i++)
			{
				f += _history[i].fps;
				if(_history[i].fps > 0) n++;
			}
			
			return (f/n > 0) ? (f/n) : 0;
		}
		
		/**
		 * @private Counts the current average memory value
		 * @return	int		current average memory value
		 */
		private function countMemoryAVG():int
		{
			var f:int = 0;
			var n:int = 0
			for(var i:int = 0; i < _historyLength; i++)
			{
				f += _history[i].memory;
				if(_history[i].memory > 0) n++;
			}
			
			return (f/n > 0) ? (f/n) : 0;
		}
		
		/**
		 * @private Monitor timer handler
		 * @return	nothing
		 */
		private function onMonitorTimer(event:TimerEvent):void
		{
			_fpsMax = stage.frameRate;
			_fps = (_frames > _fpsMax) ? _fpsMax : _frames;
			_fpsAVG = countFpsAVG();
			_memory = System.totalMemory;
			_memoryAVG = countMemoryAVG();
			_frames = 0;
			
			_history.splice(0,1);
			_history.push({fps: _fps, memory: _memory});
			
			redraw();
			dispatchEvent(new Event(Event.CHANGE));
		}
		
		/**
		 * @private Fps timer handler
		 * @return	nothing
		 */
		private function onFpsTimer(event:Event):void
		{
			_frames++;
		}
		
		/**
		 * @private ADDED_TO_STAGE handler
		 * @param	event:Event		event
		 * @return	nothing
		 */
		private function onAddedToStage(event:Event):void
		{
			if(!_monitorTimer)
			{
				_monitorTimer = new Timer(1000);
				_monitorTimer.addEventListener(TimerEvent.TIMER, onMonitorTimer);
			}
			
			if(!hasEventListener(Event.ENTER_FRAME)) addEventListener(Event.ENTER_FRAME, onFpsTimer);
			
			_fpsMax = stage.frameRate;
			initHistory();
			createChildren();
			removeEventListener(Event.ADDED_TO_STAGE, onAddedToStage);
		}
	}
}