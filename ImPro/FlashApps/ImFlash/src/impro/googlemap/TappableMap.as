package impro.googlemap
{
	import com.google.maps.LatLng;
	import com.google.maps.LatLngBounds;
	import com.google.maps.Map;
	import com.google.maps.MapEvent;
	
	import flash.events.*;
	import flash.geom.Point;
	
	import impro.openzoom.IMLowResEvent;
	
//	import tuio.TUIO;
//	import tuio.TUIOObject;
//	import tuio.TouchEvent;
//	import tuio.TouchEventsManager;

	public class TappableMap extends Map
	{
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
//		private var testSprite:Sprite = new Sprite();
		
		private var STATE_DRAGGING:String = "dragging";
		private var STATE_SCALE:String = "scale";
		private var STATE_NOTHING:String = "nothing";
		private var ZOOM_THRESHOLD:Number = 40;//100;
		
		private var floatZoom:Number;
		private var isMapReady:Boolean = false;
		
		
//		private var markerA:Marker;
		
//		private var centerLat:Number = 0;
//		private var centerLon:Number = 0;

		// new touch reasoning
		private var preFrameIndex:Number = 0;		
		
		public function TappableMap()
		{
			super();
			
			addEventListener(TouchEvent.MOUSE_DOWN, onTouchDown);
			addEventListener(MapEvent.MAP_READY, onMapReady);			
						
//	        Tweener.registerSpecialProperty("centerLat",
//                                        	getCenterLat,
//	                                        setCenterLat,
//	                                        ["centerLat"]);
//	        Tweener.registerSpecialProperty("centerLon",
//                                        	getCenterLon,
//	                                        setCenterLon,
//	                                        ["centerLon"]);
			
		}
		
		public function dispose():void{
			blob1 = null;
			blob2 = null;
			centerPointBlob1Blob2 = null;
			firstPos = null;
			
			removeEventListener(MapEvent.MAP_READY, onMapReady);		
			removeEventListener(TouchEvent.MOUSE_DOWN, onTouchDown);
			removeEventListener(Event.ENTER_FRAME, handleEnterFrame);
		}
//		private function getCenterLat(obj:Object, parameters:Array, extra:Object=null):Number{
//			return obj.centerLat;
//		}
//		private function setCenterLat(obj:Object,
//                                                   value:Number,
//                                                   parameters:Array,
//                                                   extra:Object=null):void{
//			obj.centerLat = value;
//		}
//		private function getCenterLon(obj:Object, parameters:Array, extra:Object=null):Number{
//			return obj.centerLon;
//		}
//		private function setCenterLon(obj:Object,
//                                                   value:Number,
//                                                   parameters:Array,
//                                                   extra:Object=null):void{
//			obj.centerLon = value;
//		}
		
		private function onMapReady(event:MapEvent):void {
			floatZoom = this.getZoom();
			isMapReady = true;
		}
		
		protected function onTouchDown(e:TouchEvent):void 
		{	
			if(!isMapReady)
				return;
			
			//add touch event to global touch array
			TouchEventsManager.getInstance().addActiveEvent(e, this);
			mouseDownCounter=mouseDownCounter+1;
			addEventListener(TouchEvent.MOUSE_UP, localMouseUp);
			addEventListener(Event.ENTER_FRAME, handleEnterFrame);
			
			/*
			var curPt:Point = new Point(e.stageX, e.stageY);
			
			//find out if the contact was with one or with more fingers
			if(mouseDownCounter > 0){
				//we're only dragging
				if(mouseDownCounter == 1){
					state = STATE_DRAGGING;
					blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX:x, myOrigY:y};
				}
				//we're going to scale the map
				if(mouseDownCounter > 1){
					var activeEvents:Array = TouchEventsManager.getInstance().getActiveEvents(this);
					if(activeEvents.length ==1){
						state = STATE_DRAGGING;
						blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: x, myOrigY:y};
//						mouseDownCounter=1;
					}else{
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
							blob1 = {id: e.ID, origX: curPt.x, origY: curPt.y, myOrigX: x, myOrigY:y};
//							mouseDownCounter=1;
						}
					}
				}
			}
			
			//the point in the map where you tapped. you need this for panning in the map.
			firstPos.x = curPt.x;
			firstPos.y = curPt.y;
			*/
		}
		
		//reset everything after removing your finger	    
	    public function mouseUp(e:TouchEvent):void{
			var activeEvents:Array = TouchEventsManager.getInstance().getActiveEvents(this);
			mouseDownCounter = activeEvents.length;
			
			if(mouseDownCounter == 0){
//				state = STATE_NOTHING;
				removeEventListener(TouchEvent.MOUSE_UP, localMouseUp);
				removeEventListener(Event.ENTER_FRAME, handleEnterFrame);
//				isDragging = false;
				
				// dispatch update HRes
				dispatchEvent(new IMLowResEvent(IMLowResEvent.LRES_UPDATE));
			}
			/*
			if(mouseDownCounter == 1){
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
			*/
		}
		
		//take your touch out of the global touch array and
		//reset everything after removing your finger
		public function localMouseUp(e:TouchEvent):void{
			var searchedElementFound:Number;
			searchedElementFound = TouchEventsManager.getInstance().endActiveEvent(e);
			mouseUp(e);
		}
		
//		private function setMapCenter():void{
//		  	this.setCenter(new LatLng(centerLat, centerLon));
//		  	trace("this.setCenter");			
//		}
		
		//handleEnterFrame carries out the panning and zooming activities
		//it is called in every frame while you're touching the screen
		protected function handleEnterFrame(e:Event):void {
			
			trace("handleEnterFrame");
			
			var frameIndex:Number = TUIO.FrameIndex();			
			if(frameIndex == preFrameIndex)
				return;
			preFrameIndex = frameIndex;			

			var translation:Point = TUIO.Translation();
			var zoom:Number = TUIO.Scale();
			var curCenter:Point = TUIO.Center();
			
			//////////////////////////////////////
			// For applying translation
			//////////////////////////////////////
			
//			if(translation.x + translation.y != 0)
			
			//find out how far your finger has moved since the last frame
			var percentPannedX:Number = (translation.x)/getSize().x;
			var percentPannedY:Number = (translation.y)/getSize().y;
						
			//get the bounding box of the map that is currently on screen
			var bounds:LatLngBounds = getLatLngBounds();
			//calculate lat/lon coordinate distance of bounds on screen 
		  	var spanX:Number = bounds.getNorthWest().lng() - bounds.getSouthEast().lng();
		  	var spanY:Number = bounds.getNorthWest().lat() - bounds.getSouthEast().lat();
		  	
		  	//set new map center by adding to the map's center the lat/lon distance multiplied 
		  	//with the amount that your finger has moved on screen 
		  	var newCenterLat:Number = getCenter().lat() + spanY*percentPannedY;
		  	var newCenterLon:Number = getCenter().lng() + spanX*percentPannedX;
		  					  	
		  	this.setCenter(new LatLng(newCenterLat, newCenterLon));
			
			
			///////////////////////////////////
			// For applying zoom
			///////////////////////////////////
			
			//get map's bounding box
			var boundsn:LatLngBounds = getLatLngBounds();
			//calculate lat/lon distances of current map coutout
			var spanXn:Number =  boundsn.getSouthEast().lng()-boundsn.getNorthWest().lng();
		  	var spanYn:Number =  boundsn.getSouthEast().lat()-boundsn.getNorthWest().lat();
			
			//add the zoom amount to the maps lat/lon positions to get the new center
		  	var newCenterLonn:Number = boundsn.getNorthWest().lng() + spanXn*zoom;
		  	var newCenterLatn:Number = boundsn.getNorthWest().lat() + spanYn*zoom;
		  	
		  	floatZoom *= zoom;
			while(floatZoom > getZoom()+1){
				if(getZoom() < this.getMaxZoomLevel())
	  				zoomIn(new LatLng(newCenterLatn,newCenterLonn));
	  			else
	  				floatZoom-=1;		
			}
			while(floatZoom < getZoom()-1){
				if(getZoom() > this.getMinZoomLevel())				
		  			zoomOut(new LatLng(newCenterLatn,newCenterLonn));	
	  			else
	  				floatZoom+=1;				  						
			}

//			var zoomedIn:Boolean = false;
//		  	if(zoomDistance > 0 && zoomDistance > ZOOM_THRESHOLD){
//		  		while(zoomDistance - ZOOM_THRESHOLD > 0){
//		  			this.zoomIn(new LatLng(newCenterLatn,newCenterLonn));
//		  			zoomDistance = zoomDistance-ZOOM_THRESHOLD;
//		  			zoomedIn = true;
//		  		}
//		  	}
//		  	
//		  	if(zoomDistance < 0 && zoomDistance < -ZOOM_THRESHOLD){
//		  		while(zoomDistance+ZOOM_THRESHOLD<0){
//		  			this.zoomOut(new LatLng(newCenterLatn,newCenterLonn));
//		  			zoomDistance = zoomDistance+ZOOM_THRESHOLD;
//		  		}
//		  	}
		  				
			/*
			//make your own TouchEvent object in case that you want to render
			//a TouchEvent.MOUSE_UP (you will want to if you're blob has gone
			//that means you do not touch the screen anymore
			var touchEvent:TouchEvent = new TouchEvent(TouchEvent.MOUSE_UP);
			if(state == STATE_DRAGGING){
//				trace(this, "STATE_DRAGGING");
				//get touch object of your finger
				var tuioobj : TUIOObject = TUIO.getObjectById(blob1.id);
				if(tuioobj){
					trace("tuioobj: " + tuioobj + " from blob1.id: " + blob1.id);
					//find out how far your finger has moved since the last frame
					var percentPannedX:Number = (tuioobj.x - firstPos.x)/getSize().x;
					var percentPannedY:Number = (tuioobj.y - firstPos.y)/getSize().y;
					
					//get the bounding box of the map that is currently on screen
					var bounds:LatLngBounds = getLatLngBounds();
					//calculate lat/lon coordinate distance of bounds on screen 
				  	var spanX:Number = bounds.getNorthWest().lng() - bounds.getSouthEast().lng();
				  	var spanY:Number = bounds.getNorthWest().lat() - bounds.getSouthEast().lat();
				  	
				  	//set new map center by adding to the map's center the lat/lon distance multiplied 
				  	//with the amount that your finger has moved on screen 
				  	var newCenterLat:Number = getCenter().lat() + spanY*percentPannedY;
				  	var newCenterLon:Number = getCenter().lng() + spanX*percentPannedX;
				  					  	
				  	this.setCenter(new LatLng(newCenterLat, newCenterLon));
					
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
//				trace(this,"STATE_SCALE");
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
					var percentZoomedX:Number = centerPointBlob1Blob2.x/getSize().x;
					var percentZoomedY:Number = centerPointBlob1Blob2.y/getSize().y;
					
					//get map's bounding box
					var boundsn:LatLngBounds = getLatLngBounds();
					//calculate lat/lon distances of current map coutout
					var spanXn:Number =  boundsn.getSouthEast().lng()-boundsn.getNorthWest().lng();
				  	var spanYn:Number =  boundsn.getSouthEast().lat()-boundsn.getNorthWest().lat();
				  	
				  	//add the zoom amount to the maps lat/lon positions to get the new center
				  	var newCenterLonn:Number = boundsn.getNorthWest().lng() + spanXn*percentZoomedX;
				  	var newCenterLatn:Number = boundsn.getNorthWest().lat() + spanYn*percentZoomedY;
				  	
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
				  	trace("zoomDistance: " + zoomDistance);
//					markerA.setLatLng(new LatLng(newCenterLatn,newCenterLonn));
					var zoomedIn:Boolean = false;
				  	if(zoomDistance > 0 && zoomDistance > ZOOM_THRESHOLD){
				  		while(zoomDistance - ZOOM_THRESHOLD > 0){
				  			this.zoomIn(new LatLng(newCenterLatn,newCenterLonn));
				  			zoomDistance = zoomDistance-ZOOM_THRESHOLD;
				  			zoomedIn = true;
				  		}
				  	}
				  	
				  	if(zoomDistance < 0 && zoomDistance < -ZOOM_THRESHOLD){
				  		while(zoomDistance+ZOOM_THRESHOLD<0){
				  			this.zoomOut(new LatLng(newCenterLatn,newCenterLonn));
				  			zoomDistance = zoomDistance+ZOOM_THRESHOLD;
				  		}
				  	}
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
			}*/
		}
		
		//calculates the length of the vector between two points
		private function calculateDistance(blob1X:Number, blob1Y:Number, blob2X:Number, blob2Y:Number):Number{
			var initalDistanceX:Number =blob1X - blob2X;
			var initalDistanceY:Number =blob1Y - blob2Y;
			
			var initalDistance:Number = Math.sqrt(initalDistanceX*initalDistanceX + initalDistanceY*initalDistanceY);
			
			return initalDistance;
		}
	}
}