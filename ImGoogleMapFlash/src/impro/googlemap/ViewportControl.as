package impro.googlemap
{
	import app.core.action.RotatableScalable;
	
	import flash.display.Sprite;
	import flash.events.*;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;
	
	import flash.geom.Point;
	
	public class ViewportControl extends RotatableScalable
	{
		private static var inInd:Number = 0;
		private var id:String = String(inInd++);
//		private var theMap:MapViewport;
		private var handle:Sprite = new Sprite();
		private var handleSize:Number = 20;
		private var w:Number;
		private var h:Number;
		
		private var oriPt1:Point = new Point();
		private var oriPt2:Point = new Point();
		private var oriPt3:Point = new Point();
		private var oriPt4:Point = new Point();
		
		private var updateCallback:Function;

		
//		private var maskBmp:Bitmap;
//		private var invFilter:ColorMatrixFilter = genInvFilter();
//		private var invTransform:ColorTransform = new ColorTransform(0,0,0,0,0,0,0,255);	

		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		private var DEBUG_TEXT:TextField;			
		
//		public function ViewportControl(smap:MapViewport, cx:Number, cy:Number, w:Number, h:Number)
		public function ViewportControl(callback:Function, cx:Number, cy:Number, w:Number, h:Number, $DEBUG:Boolean = true)
		{
			super();
			
			DEBUG = $DEBUG;
				
			this.updateCallback = callback;
			this.w = w;
			this.h = h;
			
			if(DEBUG)
			{
	  			var format:TextFormat = new TextFormat("Verdana", 10, 0xFFFFFF);
				DEBUG_TEXT = new TextField();       
				DEBUG_TEXT.defaultTextFormat = format;
				DEBUG_TEXT.autoSize = TextFieldAutoSize.LEFT;
				DEBUG_TEXT.background = true;	
				DEBUG_TEXT.backgroundColor = 0x000000;	
				DEBUG_TEXT.border = true;	
				DEBUG_TEXT.borderColor = 0x333333;							
				DEBUG_TEXT.x = 0;			
				DEBUG_TEXT.y = this.h /2;
				DEBUG_TEXT.text = "DEBUG_TEXT";
				addChild(DEBUG_TEXT);						
			}			
			
			setViewport(cx, cy, w, h);
							
			// draw handle			
			handle.graphics.beginFill(0xffffff, 0.5);
			handle.graphics.drawRect(-handleSize/2, -handleSize/2, handleSize, handleSize);
			handle.graphics.endFill();
			
			// draw handle outline
			handle.graphics.lineStyle(1, 0x000000);
			handle.graphics.moveTo(-handleSize/2, -handleSize/2);
			handle.graphics.lineTo(handleSize/2, -handleSize/2);
			handle.graphics.lineTo(handleSize/2, handleSize/2);			
			handle.graphics.lineTo(-handleSize/2, handleSize/2);
			handle.graphics.lineTo(-handleSize/2, -handleSize/2);
			handle.graphics.moveTo(-handleSize/2, -handleSize/2);
			handle.graphics.lineTo(handleSize/2, handleSize/2);			
			handle.graphics.moveTo(handleSize/2, -handleSize/2);
			handle.graphics.lineTo(-handleSize/2, handleSize/2);
			addChild(handle);
			
			handle.addEventListener(MouseEvent.MOUSE_DOWN, pickUp);
			handle.addEventListener(MouseEvent.MOUSE_MOVE, pickMove);
			handle.addEventListener(MouseEvent.MOUSE_UP, dropIt);
			
			addEventListener(MouseEvent.MOUSE_DOWN, pickUp);
			addEventListener(MouseEvent.MOUSE_MOVE, pickMove);
			addEventListener(MouseEvent.MOUSE_UP, dropIt);
//			this.addEventListener(MouseEvent.MOUSE_WHEEL, tiltIt);
			
			addEventListener(TouchEvent.MOUSE_DOWN, touchPickUp);
			addEventListener(TouchEvent.MOUSE_UP, touchDropIt);								
			
//			maskBmp = new Bitmap();			
//			addChild(maskBmp);			
		}
		
		public function disableTouchListeners():void{
			removeEventListener(TouchEvent.MOUSE_DOWN, touchPickUp);
			removeEventListener(TouchEvent.MOUSE_UP, touchDropIt);					
		}
		
//		public function setMask(bitmapData:BitmapData):void{
//			maskBmp.bitmapData = bitmapData;
//			maskBmp.x = -w/2;
//			maskBmp.y = -h/2;
//			maskBmp.width = w;
//			maskBmp.height = h;			
//			maskBmp.bitmapData.applyFilter(maskBmp.bitmapData, maskBmp.bitmapData.rect ,new Point(0,0), invFilter);
//		}

//		private function tiltIt(e:MouseEvent):void{
//			trace("tilt It: " + e.delta); // amount mouse wheel moved 
//			theMap.pitch(e.delta);
//		}
		
		public function setViewport(cx:Number, cy:Number, w:Number, h:Number):void{
			this.x = cx;
			this.y = cy;
			this.w = w;
			this.h = h;
			handle.x = w/2-handleSize/2;
			handle.y = h/2-handleSize/2;			
			
			updateControl();
		}
		
		public function setViewportBound(rx1:Number, ry1:Number, rx2:Number, ry2:Number):void{
			this.w = rx2-rx1;
			this.h = ry2-ry1;
			this.x = rx1 + this.w/2;
			this.y = ry1 + this.h/2;
			handle.x = w/2-handleSize/2;
			handle.y = h/2-handleSize/2;						
			updateControl();
		}
		
		public function setViewportOriPts(pt1:Point, pt2:Point, pt3:Point, pt4:Point):void{
			oriPt1.x = pt1.x - this.x;
			oriPt1.y = pt1.y - this.y;
			oriPt2.x = pt2.x - this.x;
			oriPt2.y = pt2.y - this.y;
			oriPt3.x = pt3.x - this.x;
			oriPt3.y = pt3.y - this.y;
			oriPt4.x = pt4.x - this.x;
			oriPt4.y = pt4.y - this.y;
			updateControl();
		}

		private function touchPickUp(event:TouchEvent):void {
//		    (event.target as Sprite).startDrag(false);
		    event.target.startDrag(false);
		    trace(id + ": touchPickUp");
		}
		
		private function touchDropIt(event:TouchEvent):void {
			event.target.stopDrag();
			trace(id + ":touchDropIt");
//			if(event.target == handle){
//				w = Math.abs(handle.x)*2 + handleSize;
//				h = Math.abs(handle.y)*2 + handleSize;
//				updateControl();
//			}
			updateCallback.call(this);
//			theMap.update();
		}

		private function pickUp(event:MouseEvent):void {
		    event.target.startDrag(false);
		}
		private function pickMove(event:MouseEvent):void {
		}
		private function dropIt(event:MouseEvent):void {
			event.target.stopDrag();
			
			if(event.target == handle){
				w = Math.abs(handle.x)*2 + handleSize;
				h = Math.abs(handle.y)*2 + handleSize;					
			}

			updateControl();
			updateCallback.call(this);
		}
		
		private function updateControl():void{
			// clear drawing
			this.graphics.clear();
			
			// draw transparent area
			this.graphics.beginFill(0xff0000, 0.1);
			this.graphics.drawRect(-w/2, -h/2, w, h);			
			this.graphics.endFill();
			
			// draw cross line
			this.graphics.beginFill(0xff0000, 1);
			this.graphics.drawRect(0, -h/2, 1, h);
			this.graphics.drawRect(-w/2, 0, w, 1);			
			this.graphics.endFill();
			
			// draw bounding box
			this.graphics.lineStyle(1, 0xff0000);
			this.graphics.moveTo(-w/2, -h/2);
			this.graphics.lineTo(w/2, -h/2);
			this.graphics.lineTo(w/2, h/2);			
			this.graphics.lineTo(-w/2, h/2);
			this.graphics.lineTo(-w/2, -h/2);	
			
			// draw original points
			this.graphics.lineStyle(1, 0xff0000);
			this.graphics.moveTo(oriPt1.x, oriPt1.y);
			this.graphics.lineTo(oriPt2.x, oriPt2.y);
			this.graphics.lineTo(oriPt3.x, oriPt3.y);			
			this.graphics.lineTo(oriPt4.x, oriPt4.y);
			this.graphics.lineTo(oriPt1.x, oriPt1.y);
			
			if(DEBUG){
				DEBUG_TEXT.y = this.h /2; 
				DEBUG_TEXT.text = x + ", " + y;
			}
			trace(">> " + x + ", " + y);			
		}

//		private function genInvFilter():ColorMatrixFilter{
//            var matrix:Array = new Array();
//            matrix = matrix.concat([0, 0, 0, 0, 0]); // red
//            matrix = matrix.concat([0, 0, 0, 0, 0]); // green
//            matrix = matrix.concat([0, 0, 0, 0, 0]); // blue
//            matrix = matrix.concat([0, 0, 0, -1, 255]); // alpha
//			return new ColorMatrixFilter(matrix);
//		}		
	}
}