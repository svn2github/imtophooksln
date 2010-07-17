package impro.googlemap
{	
	import com.google.maps.LatLng;
	import com.google.maps.Map;
	import com.google.maps.MapEvent;
	import com.google.maps.MapMoveEvent;
	import com.google.maps.MapOptions;
	import com.google.maps.MapType;
	import com.google.maps.services.ClientGeocoder;
	
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.TUIO;
	import flash.events.TouchEvent;
	import flash.geom.Point;
	import flash.net.XMLSocket;
	import flash.text.TextField;
	import flash.utils.Dictionary;
	
	import impro.Setting;
	import impro.googlemap.events.HResEvent;
	import impro.openzoom.IMLowResEvent;
	
	public class MultiResMap extends Sprite 
	{		
		private var TAIWAN:LatLng = new LatLng(23.69781, 120.960515);

		private var map:TappableMap;
		private var geControlDict:Dictionary;		
		private var viewportDict:Dictionary;				
		private var geocoder:ClientGeocoder;

		private var flashlighDraging:Boolean = false;
	
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		private var DEBUG_TEXT:TextField;		 
		private var ruler:Sprite = new Sprite();

		public function MultiResMap(x:Number, y:Number, width:Number, height:Number, latlng:LatLng = null, zoom:Number = 8, $DEBUG:Boolean = true)
		{
			DEBUG = $DEBUG;
			
	    	if(latlng == null)
	    		latlng = TAIWAN;
			
			geControlDict = new Dictionary();
			viewportDict = new Dictionary();
			map = new TappableMap();
			
//			map.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExRcR7IumtuiL9gAiOhCPfe14dC1HBSpTjOFiyNExylutyalkkjAIFFIZw";
			map.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExR_j1b9FZtV9XbZimSIA_BIot63gxRd534MBVvU4xP-2j78Ek8TfdeHFg";
                       
			map.setSize(new Point(width, height));	
			
			map.addEventListener(MapEvent.MAP_PREINITIALIZE, function(e:Event):void{
			  var myMapOptions:MapOptions = new MapOptions();
//			  myMapOptions.zoom = zoom; // useless if set here
			  myMapOptions.center = latlng;
			  myMapOptions.mapType = MapType.HYBRID_MAP_TYPE;
			  map.setInitOptions(myMapOptions);		
			});
			
			map.addEventListener(MapEvent.MAP_READY, function(e:Event):void{
				map.setZoom(zoom);
			});			

//			map.addEventListener(MapZoomEvent.ZOOM_CHANGED, onMapZoom);			
//			if(Setting.interactiveDrag)
//				map.addEventListener(MapMoveEvent.MOVE_STEP, onMapMove);
//			else
				map.addEventListener(MapMoveEvent.MOVE_END, onMapMove);			

			map.addEventListener(MapEvent.MAPTYPE_CHANGED, onMapTypeChanged);						
			addChild(map);
			
			addEventListener(IMLowResEvent.LRES_UPDATE, imLResMoveEndHandler, false, 0, true);	
			addEventListener(HResEvent.POSE_CHANGE, hresPosChange);	
			TUIO.addIMObjectListener(this);
						
			// add imObject listener

			if(DEBUG){
				ruler.graphics.beginFill(0x0000ff, 1);			
				ruler.graphics.drawRect(map.x, map.height/2, map.width, 1);
				ruler.graphics.drawRect(map.width/2, map.y, 1, map.height);
				ruler.graphics.endFill();
				addChild(ruler);							
			}
		}
		
//		public function addPhoto(gAddress:GoogleAddress, image:Bitmap):void{
// 	        var marker:Marker = new Marker(gAddress.latlng);
// 	        map.addOverlay(marker);
// 	        
//			for each (var viewport:MapViewport in viewportDict) 
//	            viewport.addOverlay(gAddress, image);        			
//		}

		public function dispose():void{
			
			map.dispose();
			map.unload();
			map = null;	
				
			 								
			for each (var geControl:GEControl in geControlDict)
				geControl.dispose();
			geControlDict = null;
			
			for each (var viewport:MapViewport in viewportDict) 
				viewport.dispose();				
			viewportDict = null;
			
			
			geocoder = null;			
		}
		
		public function flyToPlace(place:String):void{
			geocoder.geocode(place);
		}
		
		public function flyToLatlng(latlng:LatLng, zoom:Number):void{
	    	map.setCenter(latlng, zoom);
 	    }		
		
//		private function geoCodingSuccess(event:GeocodingEvent):void{
//          var placemarks:Array = event.response.placemarks;
//          if (placemarks.length > 0) {
//            map.setCenter(placemarks[0].point);
//            var marker:Marker = new Marker(placemarks[0].point);          
//            marker.addEventListener(MapMouseEvent.CLICK, function (event:MapMouseEvent):void {
//                marker.openInfoWindow(new InfoWindowOptions({content: placemarks[0].address}));
//            });
//            map.addOverlay(marker);
//          }			
//		}

//        private function geoCodingFailure(event:GeocodingEvent):void {
//            Alert.show("Geocoding failed");
//            trace(event);
//            trace(event.status);
//        }
		
		public function setIFlashlightBlack(value:Boolean):void{
			if(getViewport(Setting.getiFlashlightIMView().id))
				getViewport(Setting.getiFlashlightIMView().id).setBlackScreen(value);
		}
		public function getIFlashlightBlack():Boolean{			
			if(getViewport(Setting.getiFlashlightIMView().id))				
				return getViewport(Setting.getiFlashlightIMView().id).getBlackScreen();
			return false;
		}
		
		public function getParentMap():Map{
			return map;
		}

	    private function imLResMoveEndHandler(event:IMLowResEvent):void{
	    	updateHResMap();
    	}

		private function hresPosChange(e:Event):void{
			
			var he:HResEvent = e as HResEvent;
			trace(he.ID + ": " + he.rx1 + ", "+ he.ry1 + ", "+ he.rx2 + ", "+ he.ry2);
			
			if(getViewport(String(he.ID))){
				var _vpControl:MapViewport = getViewport(String(he.ID));				
				if(_vpControl.isBeyondStable(he, 5)){
					_vpControl.setViewportBound(he.rx1, he.ry1, he.rx2, he.ry2);			
					_vpControl.setViewportOriPts(he.oriPt1, he.oriPt2, he.oriPt3, he.oriPt4);
					_vpControl.update();					
				}
				
				// for i-m-Flashlight
				if(he.ID == 1 && flashlighDraging){
					// calculate the drag distance
					// move the context map
				}								
			}
		}
		
		private function onTouchDown(e:TouchEvent):void{
			if(e.TUIO_TYPE == "2Dcur"){
				trace("onTouchDown 2Dcur (" + e.ID + ", " + e.localX + ", " + e.localY);
			}			
			if(e.TUIO_TYPE == "2Dobj"){
				trace("onTouchDown 2Dobj (" + e.ID + ", " + e.localX + ", " + e.localY + ", " + e.angle );
			} 
		}
		
		private function onTouchMove(e:TouchEvent):void{
			if(e.TUIO_TYPE == "2Dcur"){
				trace("onTouchMove 2Dcur (" + e.ID + ", " + e.localX + ", " + e.localY);
			}			
			if(e.TUIO_TYPE == "2Dobj"){
				trace("onTouchMove 2Dobj (" + e.ID + ", " + e.localX + ", " + e.localY + ", " + e.angle );
			} 
		}
		
		public function addViewport(id:String, x:Number, y:Number, width:Number, height:Number):MapViewport{			
 			var viewport:MapViewport = new MapViewport(map, x, y, width, height, DEBUG);
			addChild(viewport);			
			viewportDict[id] = viewport;
			
			if(DEBUG)
				addChild(viewport.viewport);	
				
			return viewport;
		}
		
		public function addGeControl(socket:XMLSocket, id:String, x:Number, y:Number):GEControl{
			
			var geControl:GEControl = new GEControl(socket, id, map);
			geControl.x = x;
			geControl.y = y;
			geControlDict[geControl.id] = geControl;	
			if(DEBUG)
				addChild(geControl);		

			return geControl;
		}
		
		public function getGeControl(id:String):GEControl{
			return geControlDict[id] as GEControl;
		}
		
//		public function getGeControl(id:String):GEControl{
//			return geControlDict[id];
//		}
		
		public function removeGeControl(id:String):GEControl{
			var geControl:GEControl = geControlDict[id];
			if(geControl != null){
				removeChild(geControl);
				delete geControlDict[id];
				trace("GEControl[" + id + "] deleted from dictionary");
				
				trace("geDictionary list:");
				for each (var ge:GEControl in geControlDict) 
	                trace(ge.id);
						
			}
			return geControl;
		}
				
		public function getViewport (id:String):MapViewport{
			if(viewportDict == null){
				trace("viewportDict == null");
				return null;
			}
//			if(viewportDict)
				return viewportDict[id];
//			return null;
		}
		
//		public function getMapStage():IMView{
//			return new IMView(-1, 0, 0, map.width, map.height);
//		}
		public function getMapWidth():Number{
			return map.width;
		}
		public function getMapHeight():Number{
			return map.height;
		}
				
//	    private function onMapReady(event:Event):void {	    	
//	    	map.setCenter(TAIWAN, 8);
//	        map.addControl(new MapTypeControl());
//	        map.addControl(new NavigationControl());
//	        
//			geocoder = new ClientGeocoder();
//			geocoder.addEventListener(GeocodingEvent.GEOCODING_SUCCESS, geoCodingSuccess); 
//			geocoder.addEventListener(GeocodingEvent.GEOCODING_FAILURE, geoCodingFailure);				        
//	    }
	    
	    private function onMapTypeChanged(event:MapEvent):void {
	    	var stype:String = event.type;
	    		    	
	    	for each (var viewport:MapViewport in viewportDict){ 
                viewport.setMapType(map.getCurrentMapType());
    			trace("map.getCurrentMapType(): " + map.getCurrentMapType());
    		}
	    }

//	    private function onMapPreinitialize(event:Event):void {
//	      var myMapOptions:MapOptions = new MapOptions();
//	      myMapOptions.zoom = 10;
//	      myMapOptions.center = new LatLng(40.736072,-73.992062);
//	      myMapOptions.mapType = MapType.NORMAL_MAP_TYPE;
//	      map.setInitOptions(myMapOptions);
//	    }
		
		private function updateHResMap():void{
			for each (var viewport:MapViewport in viewportDict) 
                viewport.update();            			

			for each (var geControl:GEControl in geControlDict) 
                geControl.update();                     			
		}
		
//		private function onMapZoom(event:MapZoomEvent):void{
//			var zoom:Number = (event.currentTarget as Map).getZoom();
//						
//			for each (var viewport:MapViewport in viewportDict) 
//                viewport.update();            			
//
//			for each (var geControl:GEControl in geControlDict) 
//                geControl.update();                     
//		}
	
		private function onMapMove(event:MapMoveEvent):void{
			trace("onMapMove");
			//var latlng:LatLng = (event.currentTarget as Map).getCenter();		  
			for each (var viewport:MapViewport in viewportDict) 
                viewport.update();
                
			for each (var geControl:GEControl in geControlDict) 
                geControl.update();                     
		}
			
//	    private function onMap2Ready(event:Event):void {	    	
//	    	map3.setCenter(new LatLng(40.736072,-73.992062), 1);
//	    	map3.addControl(new MapTypeControl());
//	    }
//
//		private function onMap2Preinitialize(event:MapEvent):void{
//	        var mapOptions:MapOptions = new MapOptions();
//	        mapOptions.mapType = MapType.PHYSICAL_MAP_TYPE;
//	        mapOptions.viewMode = View.VIEWMODE_PERSPECTIVE;
//	        mapOptions.zoom = 4;
//	        mapOptions.center = new LatLng(37.362868, 114);
//	        mapOptions.attitude = new Attitude(6.8, 37.8, 0);
//	        map3.setInitOptions(mapOptions);
//	    }
	}
}