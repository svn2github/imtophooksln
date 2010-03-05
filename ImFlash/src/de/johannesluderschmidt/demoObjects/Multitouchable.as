package de.johannesluderschmidt.demoObjects
{
	import de.johannesluderschmidt.controller.TouchEventsManager;
	import de.johannesluderschmidt.event.BringToFrontEvent;
	import de.johannesluderschmidt.event.BringToBackEvent;
	import de.johannesluderschmidt.event.GenericTapEvent;
	import de.johannesluderschmidt.tuio.*;
	import de.johannesluderschmidt.util.Constants;
	
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.geom.Point;	

	public class Multitouchable extends Sprite
	{
		public static var touchDownCallback:Function;
		public static var touchMoveCallback:Function;
		public static var touchUpCallback:Function;
		
		public var blobs:Array;		// blobs we are currently interacting with
		public var blob1:Object;
		public var blob2:Object;
		public var oldBlob1:Object;
		public var oldBlob2:Object;
		private var state:String;
		private var curScale:Number;
		private var curAngle:Number;
		private var lastPos:Point;
		private var lastPosTime:Number = Number.MIN_VALUE;
		private var firstPos:Point;
		private var isDragging:Boolean;
		
		private var distanceBlob1Blob2:Number;
		private var angleBlob1Blob2:Number;
		
		private var STATE_DRAGGING:String = "dragging";
		private var STATE_ROTATE_SCALE:String = "rotateScale";

		private var initalDistance:Number;
		
		private var mouseDownCounter:Number = 0;
		
		public function Multitouchable()
		{
			blobs = new Array();
			lastPos = new Point();
			firstPos = new Point();
		}
		/**
		 * Listener for stage addition
		 * @param e event
		 */
		protected  function handleAddedToStage(e:Event):void {
			addEventListener(TouchEvent.MOUSE_DOWN, handleMouseDown);
			addEventListener(TouchEvent.MOUSE_UP, localMouseUp);
			addEventListener(Event.ENTER_FRAME, handleEnterFrame);
			removeEventListener(Event.ADDED_TO_STAGE, handleAddedToStage);
			
		}
		
		private function handleMouseDown(e:TouchEvent):void 
		{
			TouchEventsManager.getInstance().addActiveEvent(e);
			mouseDownCounter=mouseDownCounter+1;
			
			var curPt:Point = parent.globalToLocal(new Point(e.stageX, e.stageY));
			if(curPt.x <= lastPos.x+Constants.CLICK_DELTA_LOCATION && curPt.x >= lastPos.x-Constants.CLICK_DELTA_LOCATION
				&& curPt.y <= lastPos.y+Constants.CLICK_DELTA_LOCATION && curPt.y >= lastPos.y-Constants.CLICK_DELTA_LOCATION){
					if((new Date().getTime() - lastPosTime) < Constants.CLICK_DELTA_TIME){
						dispatchEvent(new GenericTapEvent(GenericTapEvent.DOUBLE_TAP));
					}
				}
			lastPos = curPt;
			lastPosTime = new Date().getTime();
			
			if(mouseDownCounter > 0){
				if(mouseDownCounter == 1){
					state = STATE_DRAGGING;
					blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: x, myOrigY:y};
				}
				if(mouseDownCounter > 1){
					var activeEvents:Array = TouchEventsManager.getInstance().getActiveEvents(this);
					if(activeEvents.length ==1){
						state = STATE_DRAGGING;
						blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: x, myOrigY:y};
						mouseDownCounter=1;
					}
					else{
						try{
							state = STATE_ROTATE_SCALE;
							blob1 = {id:activeEvents[0].id, origX:TUIO.getObjectById(activeEvents[0].id).x, origY:TUIO.getObjectById(activeEvents[0].id).y};
							blob2 = {id:activeEvents[1].id, origX:TUIO.getObjectById(activeEvents[1].id).x, origY:TUIO.getObjectById(activeEvents[1].id).y};
							
							distanceBlob1Blob2 = calculateDistance(blob1.origX, blob1.origY, blob2.origX, blob2.origY);
							angleBlob1Blob2 = Math.atan((blob2.origX - blob1.origX)/(blob2.origY - blob1.origY));
						}catch(error:Error){
							state = STATE_DRAGGING;
							blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: x, myOrigY:y};
							mouseDownCounter=1;
						}
					}
				}
				dispatchEvent(new BringToFrontEvent(BringToFrontEvent.DO, this));
			}
			
			firstPos.x = curPt.x - x;
			firstPos.y = curPt.y - y;
		}
		private function localMouseUp (e:TouchEvent) : void
		{
			TouchEventsManager.getInstance().endActiveEvent(e);

//			trace("localMouseUp");
//			if(touchUpCallback!=null)
//				touchUpCallback.call(this as ImageObject);
			
			dispatchEvent(new BringToBackEvent(BringToBackEvent.DO, this));
		}
		public function mouseUp (e : TouchEvent) : void
		{
			mouseDownCounter = mouseDownCounter -1;
			if(mouseDownCounter == 1){
				state = STATE_DRAGGING;
			}
			if(mouseDownCounter > 1){
				state = STATE_ROTATE_SCALE;
			}
			isDragging = false;
			trace("isDragging = false");
		}
		
		private function calculateDistance(blob1X:Number, blob1Y:Number, blob2X:Number, blob2Y:Number):Number{
			var initalDistanceX:Number =blob1X - blob2X;
			var initalDistanceY:Number =blob1Y - blob2Y;
			
			var initalDistance:Number = Math.sqrt(initalDistanceX*initalDistanceX + initalDistanceY*initalDistanceY);
			
			return initalDistance;
		}
		
		/**
		 * Listener for enter frame event
		 * @param e event information
		 */
		private function handleEnterFrame(e:Event):void {
			if(state == STATE_DRAGGING){
				var tuioobj : TUIOObject = TUIO.getObjectById(blob1.id);
				if(tuioobj){
//					trace("dragging");
					x = tuioobj.x - firstPos.x;
					y = tuioobj.y - firstPos.y;
					isDragging = true;
					trace("isDragging = true");
					
					if(touchMoveCallback!=null)
						touchMoveCallback.call();
				}
			}
			
			if(state == STATE_ROTATE_SCALE){
				var tuioobjRS : TUIOObject = TUIO.getObjectById(blob1.id);
				var tuioobj2 : TUIOObject = TUIO.getObjectById(blob2.id);
				if(tuioobjRS && tuioobj2){
//					trace("rotate scale");
					//drag
//					x = tuioobjRS.x - firstPos.x;
//					y = tuioobjRS.y - firstPos.y;
					
					//scale
					var distScaleRatioX:Number = this.scaleX/this.distanceBlob1Blob2;
					var distScaleRatioY:Number = this.scaleY/this.distanceBlob1Blob2;
					
//					var distOldBlob1:Number = -1;
//					if(oldBlob1 != null && oldBlob1.id == blob1.id){
//						distOldBlob1 = calculateDistance(tuioobjRS.x,tuioobjRS.y, oldBlob1.origX, oldBlob1.origY);
//						trace("distOldBlob1",distOldBlob1);
//					}
//					var distOldBlob2:Number = -1;
//					if(oldBlob2 != null && oldBlob2.id == blob2.id){
//						distOldBlob2 = calculateDistance(tuioobj2.x,tuioobj2.y, oldBlob2.origX, oldBlob2.origY);
//						trace("distOldBlob2",distOldBlob2);
//					}
					
					var blobMiddleX:Number = tuioobjRS.x + (tuioobj2.x - tuioobjRS.x)/2 -x;
					var blobMiddleY:Number = tuioobjRS.y + (tuioobj2.y - tuioobjRS.y)/2 -y;
//					trace("blobMiddleX",blobMiddleX,"blobMiddleY",blobMiddleY,"width",width,"height",height);
					
					var blobMiddleXWidth:Number = blobMiddleX / width;  
					var blobMiddleYHeight:Number = blobMiddleY / height;
					
					var oldScaleX:Number = this.scaleX; 
					var oldScaleY:Number = this.scaleY;
					var oldWidth:Number = this.width;
					var oldHeight:Number = this.height;
					
					var distanceBlob1Blob2Temp:Number = calculateDistance(tuioobjRS.x,tuioobjRS.y,tuioobj2.x, tuioobj2.y); 
					
					//set size
					this.scaleX = distScaleRatioX*distanceBlob1Blob2Temp;
					this.scaleY = distScaleRatioY*distanceBlob1Blob2Temp;
					
					var scaleDistX:Number = this.scaleX/oldScaleX;
					var scaleDistY:Number = this.scaleY/oldScaleY;
					
					var newBlobMiddleX:Number = blobMiddleX*scaleDistX;
					var newBlobMiddleY:Number = blobMiddleY*scaleDistY;
					
					var distBlobMiddleX:Number = newBlobMiddleX-blobMiddleX;
					var distBlobMiddleY:Number = newBlobMiddleY-blobMiddleY;
					
					//set position
					this.x = this.x - distBlobMiddleX;
					this.y = this.y - distBlobMiddleY;
//					trace("distBlobMiddleX",distBlobMiddleX);
					
					distanceBlob1Blob2 = distanceBlob1Blob2Temp;
					
					//rotate
					var angleBlob1Blob2Temp:Number = Math.atan((tuioobj2.x - tuioobjRS.x)/(tuioobj2.y - tuioobjRS.y));
					
					var oldX:Number = this.x;
					var oldY:Number = this.y;
					
					var rotAngle:Number = (angleBlob1Blob2Temp-angleBlob1Blob2)%2*Math.PI;
					trace(rotAngle);
					
					var newBlobMiddleXRot:Number = blobMiddleX*Math.cos(rotAngle);
					var newBlobMiddleYRot:Number = blobMiddleY*Math.sin(rotAngle);
					var distBlobMiddleXRot:Number = newBlobMiddleXRot-blobMiddleX;
					var distBlobMiddleYRot:Number = newBlobMiddleYRot-blobMiddleY;
//					trace("distBlobMiddleXRot", distBlobMiddleXRot,"distBlobMiddleYRot",distBlobMiddleYRot);
					//rotate around middle
//					this.x = this.x + Math.cos(rotAngle);//distBlobMiddleXRot;
//					this.y = this.y + Math.sin(rotAngle);//distBlobMiddleYRot;
					
//					this.rotation = this.rotation - rotAngle*180/Math.PI;
					
					
					angleBlob1Blob2 = angleBlob1Blob2Temp;
					
					oldBlob1 = {id:blob1.id, origX:TUIO.getObjectById(blob1.id).x, origY:TUIO.getObjectById(blob1.id).y};
					oldBlob2 = {id:blob2.id, origX:TUIO.getObjectById(blob2.id).x, origY:TUIO.getObjectById(blob2.id).y};				
				}
			}
			
		}
	}
}