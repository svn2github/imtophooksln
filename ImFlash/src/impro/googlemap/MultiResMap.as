package impro.googlemap
{	
	import com.google.maps.LatLng;
	import com.google.maps.Map;
	import com.google.maps.MapType;
	import com.google.maps.MapEvent;
	import com.google.maps.MapMoveEvent;
	import com.google.maps.MapZoomEvent;
	import com.google.maps.controls.MapTypeControl;
	import com.google.maps.controls.NavigationControl;
	import com.google.maps.overlays.Marker;
	import com.google.maps.services.ClientGeocoder;
	import com.google.maps.services.GeocodingEvent;
	
	import flash.display.Bitmap;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.TUIO;
	import flash.geom.Point;
	import flash.net.XMLSocket;
	import flash.text.TextField;
	import flash.utils.Dictionary;
	
	import impro.element.GoogleAddress;
	import impro.googlemap.events.HResEvent;
	
	public class MultiResMap extends Sprite 
	{		
		private var TAIWAN:LatLng = new LatLng(23.69781, 120.960515);
		
		private var stageWidth:Number = 1366;//+1280;
		private var stageHeight:Number = 500;//768;	
		
		private var map:TappableMap = new TappableMap();
//		private var map:Map = new  Map();		

 
		
		private var geControlDict:Dictionary = new Dictionary();		
		private var viewportDict:Dictionary = new Dictionary();				
		private var geocoder:ClientGeocoder;


	
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		private var DEBUG_TEXT:TextField;		 
		private var ruler:Sprite = new Sprite();

		public function MultiResMap(x:Number, y:Number, width:Number, height:Number, $DEBUG:Boolean = true)
		{
			DEBUG = $DEBUG;
			
			map.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExRcR7IumtuiL9gAiOhCPfe14dC1HBSpTjOFiyNExylutyalkkjAIFFIZw";
//			map.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExR_j1b9FZtV9XbZimSIA_BIot63gxRd534MBVvU4xP-2j78Ek8TfdeHFg";
			map.setSize(new Point(width, height));			
			map.addEventListener(MapEvent.MAP_READY, onMapReady);
			map.addEventListener(MapZoomEvent.ZOOM_CHANGED, onMapZoom);
			map.addEventListener(MapMoveEvent.MOVE_STEP, onMapMove);
			addChild(map);
			
			this.addEventListener(HResEvent.POSE_CHANGE, hresPosChange);
			TUIO.addIMObjectListener(this);
			
			if(DEBUG){
//				var format:TextFormat = new TextFormat("Verdana", 10, 0xFFFFFF);
//				DEBUG_TEXT = new TextField();
//				DEBUG_TEXT.autoSize = TextFieldAutoSize.LEFT;
//				DEBUG_TEXT.background = true;	
//				DEBUG_TEXT.backgroundColor = 0x000000;	
//				DEBUG_TEXT.border = true;	
//				DEBUG_TEXT.borderColor = 0x333333;							
//				DEBUG_TEXT.text = "DEBUG";
//				DEBUG_TEXT.x = 200;
//				DEBUG_TEXT.y = 200;				
//				addChild(DEBUG_TEXT);
			}
			
			// add imObject listener

			if(DEBUG){
				ruler.graphics.beginFill(0x0000ff, 1);			
				ruler.graphics.drawRect(map.x, map.height/2, map.width, 1);
				ruler.graphics.drawRect(map.width/2, map.y, 1, map.height);
				ruler.graphics.endFill();
				addChild(ruler);							
			}
		}
		
		public function addPhoto(gAddress:GoogleAddress, image:Bitmap):void{
 	        
 	        var marker:Marker = new Marker(gAddress.latlng);
 	        map.addOverlay(marker);
 	        
			for each (var viewport:MapViewport in viewportDict) 
	            viewport.addOverlay(gAddress, image);
        			
		}
		
		public function flyToPlace(place:String):void{
			geocoder.geocode(place);
		}
		
		public function flyToLatlng(latlng:LatLng, zoom:Number):void{
	    	map.setCenter(latlng, zoom);
 	        
			// Create our "tiny" marker icon
// 	        var marker:Marker = new Marker(latlng);
// 	        map.addOverlay(marker); 	
		}		
		
		private function geoCodingSuccess(event:GeocodingEvent):void{
//          var placemarks:Array = event.response.placemarks;
//          if (placemarks.length > 0) {
//            map.setCenter(placemarks[0].point);
//            var marker:Marker = new Marker(placemarks[0].point);          
//            marker.addEventListener(MapMouseEvent.CLICK, function (event:MapMouseEvent):void {
//                marker.openInfoWindow(new InfoWindowOptions({content: placemarks[0].address}));
//            });
//            map.addOverlay(marker);
//          }			
		}

        private function geoCodingFailure(event:GeocodingEvent):void {
//            Alert.show("Geocoding failed");
            trace(event);
            trace(event.status);
        }
		
		
		public function getParentMap():Map{
			return map;
		}

		private function hresPosChange(e:Event):void{
			
			var he:HResEvent = e as HResEvent;
			for each (var viewport:MapViewport in viewportDict){
				viewport.setViewportBound(he.rx1, he.ry1, he.rx2, he.ry2);			
				viewport.setViewportOriPts(he.oriPt1, he.oriPt2, he.oriPt3, he.oriPt4);
				viewport.update();
   			}
//			trace(he.ID + ": " + he.rx1 + ", "+ he.ry1 + ", "+ he.rx2 + ", "+ he.ry2);			
//			getViewport(he.ID).setViewportBound(he.rx1, he.ry1, he.rx2, he.ry2);			
//			getViewport(he.ID).setViewportOriPts(he.oriPt1, he.oriPt2, he.oriPt3, he.oriPt4);
//			getViewport(he.ID).update();
		}
		
		public function addViewport(id:String, x:Number, y:Number, width:Number, height:Number):MapViewport{			
 			var viewport:MapViewport = new MapViewport(map, x, y, width, height, DEBUG);
			addChild(viewport);			
			viewportDict[id] = viewport;
			
			if(DEBUG)
				addChild(viewport.viewport);	
				
			return viewport;
		}
		
		public function addGeControl(socket:XMLSocket, x:Number, y:Number):GEControl{
			
			var geControl:GEControl = new GEControl(socket, map, DEBUG);
			geControl.x = x;
			geControl.y = y;
			geControlDict[geControl.id] = geControl;	
//			if(DEBUG)
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
				
		public function getViewport (id:Number):MapViewport{
			return viewportDict[id];
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
				
	    private function onMapReady(event:Event):void {	    	
	    	map.setCenter(TAIWAN, 8);	        
	        map.addControl(new MapTypeControl());
	        map.addControl(new NavigationControl());
	        
			geocoder = new ClientGeocoder();
			geocoder.addEventListener(GeocodingEvent.GEOCODING_SUCCESS, geoCodingSuccess); 
			geocoder.addEventListener(GeocodingEvent.GEOCODING_FAILURE, geoCodingFailure);				        
	    }
	    
	    private function onMapTypeChanged(event:MapEvent):void {
	    	var stype:String = event.type;
	    		    	
	    	for each (var viewport:MapViewport in viewportDict) 
                viewport.setMapType(map.getCurrentMapType());
	    }

//	    private function onMapPreinitialize(event:Event):void {
//	      var myMapOptions:MapOptions = new MapOptions();
//	      myMapOptions.zoom = 10;
//	      myMapOptions.center = new LatLng(40.736072,-73.992062);
//	      myMapOptions.mapType = MapType.NORMAL_MAP_TYPE;
//	      map.setInitOptions(myMapOptions);
//	    }
		
		private function onMapZoom(event:MapZoomEvent):void{
			var zoom:Number = (event.currentTarget as Map).getZoom();
						
			for each (var viewport:MapViewport in viewportDict) 
                viewport.update();            			

			for each (var geControl:GEControl in geControlDict) 
                geControl.update();                     
		}
	
		private function onMapMove(event:MapMoveEvent):void{
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