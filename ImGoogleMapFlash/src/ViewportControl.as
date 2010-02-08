package
{
	import flash.display.Bitmap;
	import flash.display.Sprite;
	import flash.events.*;
	import flash.filters.ColorMatrixFilter;

	import app.core.action.RotatableScalable;
	
	public class ViewportControl extends RotatableScalable
	{
		private static var inInd:Number = 0;
		private var id:String = String(inInd++);
		private var theMap:MapViewport;
		private var handle:Sprite = new Sprite();
		private var handleSize:Number = 20;
		private var w:Number;
		private var h:Number;
		private var maskBmp:Bitmap;
		private var invFilter:ColorMatrixFilter = genInvFilter();
//		private var invTransform:ColorTransform = new ColorTransform(0,0,0,0,0,0,0,255);	
		
		public function ViewportControl(smap:MapViewport, cx:Number, cy:Number, w:Number, h:Number)
		{
			super();
			
			this.theMap = smap;
			this.w = w;
			this.h = h;
						
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
			
			this.addEventListener(MouseEvent.MOUSE_DOWN, pickUp);
			this.addEventListener(MouseEvent.MOUSE_MOVE, pickMove);
			this.addEventListener(MouseEvent.MOUSE_UP, dropIt);
			this.addEventListener(MouseEvent.MOUSE_WHEEL, tiltIt);
			
			this.addEventListener(TouchEvent.MOUSE_DOWN, touchPickUp);
			this.addEventListener(TouchEvent.MOUSE_UP, touchDropIt);
			
			setViewport(cx, cy, w, h);
			
//			maskBmp = new Bitmap();			
//			addChild(maskBmp);			
		}
		
//		public function setMask(bitmapData:BitmapData):void{
//			maskBmp.bitmapData = bitmapData;
//			maskBmp.x = -w/2;
//			maskBmp.y = -h/2;
//			maskBmp.width = w;
//			maskBmp.height = h;			
//			maskBmp.bitmapData.applyFilter(maskBmp.bitmapData, maskBmp.bitmapData.rect ,new Point(0,0), invFilter);
//		}

		private function tiltIt(e:MouseEvent):void{
			trace("tilt It: " + e.delta); // amount mouse wheel moved 
			theMap.pitch(e.delta);
		}
		
		public function setViewport(cx:Number, cy:Number, w:Number, h:Number):void{
			this.x = cx;
			this.y = cy;
			this.w = w;
			this.h = h;
			handle.x = w/2-handleSize/2;
			handle.y = h/2-handleSize/2;			
			
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
			theMap.update();
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
				updateControl();
			}
			theMap.update();
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
			
			this.graphics.lineStyle(1, 0xff0000);
			this.graphics.moveTo(-w/2, -h/2);
			this.graphics.lineTo(w/2, -h/2);
			this.graphics.lineTo(w/2, h/2);			
			this.graphics.lineTo(-w/2, h/2);
			this.graphics.lineTo(-w/2, -h/2);			
		}

		private function genInvFilter():ColorMatrixFilter{
            var matrix:Array = new Array();
            matrix = matrix.concat([0, 0, 0, 0, 0]); // red
            matrix = matrix.concat([0, 0, 0, 0, 0]); // green
            matrix = matrix.concat([0, 0, 0, 0, 0]); // blue
            matrix = matrix.concat([0, 0, 0, -1, 255]); // alpha
			return new ColorMatrixFilter(matrix);
		}		
	}
}