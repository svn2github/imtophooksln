package impro.googlemap
{	
	import com.google.maps.LatLng;
	import com.google.maps.Map;
	import com.google.maps.MapEvent;
	import com.google.maps.MapMoveEvent;
	import com.google.maps.MapZoomEvent;
	import com.google.maps.controls.MapTypeControl;
	import com.google.maps.controls.NavigationControl;
	import com.google.maps.services.ClientGeocoder;
	import com.google.maps.services.GeocodingEvent;
	
	import flash.display.Sprite;
	import flash.events.*;
	import flash.geom.Point;
	import flash.text.TextField;
	import flash.utils.Dictionary;
	import flash.net.XMLSocket;

	import impro.googlemap.events.HResEvent;
	import impro.multiview.IMView;
	
	public class MultiResMap extends Sprite 
	{		
		private var TAIWAN:LatLng = new LatLng(23.69781, 120.960515);
		
		private var stageWidth:Number = 1366;//+1280;
		private var stageHeight:Number = 500;//768;	
		
		private var map:TappableMap = new TappableMap();
//		private var map:Map = new  Map();		

		private var ruler:Sprite = new Sprite();
		private var zoomText:TextField = new TextField(); 
		
		private var geControlDict:Dictionary = new Dictionary();		
		private var viewportDict:Dictionary = new Dictionary();				
		private var geocoder:ClientGeocoder;


		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		 
		public function MultiResMap(x:Number, y:Number, width:Number, height:Number, $DEBUG:Boolean = true)
		{
			DEBUG = $DEBUG;
			
			map.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExRcR7IumtuiL9gAiOhCPfe14dC1HBSpTjOFiyNExylutyalkkjAIFFIZw";
			map.setSize(new Point(width, height));			
			map.addEventListener(MapEvent.MAP_READY, onMapReady);
			map.addEventListener(MapZoomEvent.ZOOM_CHANGED, onMapZoom);
			map.addEventListener(MapMoveEvent.MOVE_STEP, onMapMove);
			map.addEventListener(MapEvent.MAPTYPE_CHANGED, onMapTypeChanged);						
			addChild(map);
			
			this.addEventListener(HResEvent.POSE_CHANGE, hresPosChange);
			
			
			// add imObject listener
			TUIO.addIMObjectListener(this);

			if(DEBUG){
				ruler.graphics.beginFill(0x0000ff, 1);			
				ruler.graphics.drawRect(map.x, map.height/2, map.width, 1);
				ruler.graphics.drawRect(map.width/2, map.y, 1, map.height);
				ruler.graphics.endFill();
				addChild(ruler);							
			}
		}
		
		public function flyToPlace(place:String):void{
			geocoder.geocode(place);
		}
		
		private function geoCodingSuccess(event:GeocodingEvent):void{
          var placemarks:Array = event.response.placemarks;
          if (placemarks.length > 0) {
            map.setCenter(placemarks[0].point);
//            var marker:Marker = new Marker(placemarks[0].point);          
//            marker.addEventListener(MapMouseEvent.CLICK, function (event:MapMouseEvent):void {
//                marker.openInfoWindow(new InfoWindowOptions({content: placemarks[0].address}));
//            });
//            map.addOverlay(marker);
          }			
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
			trace(he.ID + ": " + he.rx1 + ", "+ he.ry1 + ", "+ he.rx2 + ", "+ he.ry2);
						
			getViewport(he.ID).setViewportBound(he.rx1, he.ry1, he.rx2, he.ry2);			
			getViewport(he.ID).setViewportOriPts(he.oriPt1, he.oriPt2, he.oriPt3, he.oriPt4);
			getViewport(he.ID).update();
		}
		
		public function addViewport(id:Number, x:Number, y:Number, width:Number, height:Number):MapViewport{			
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
			geControlDict[id] = geControl;	
			if(DEBUG)
				addChild(geControl);		


			return geControlDict[id];
		}
		
		public function getViewport (id:Number):MapViewport{
			return viewportDict[id];
		}
		
		public function getMapStage():IMView{
			return new IMView(-1, 0, 0, map.width, map.height);
		}
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
	        zoomText.text = ""+map.getZoom();
	        
			geocoder = new ClientGeocoder();
			geocoder.addEventListener(GeocodingEvent.GEOCODING_SUCCESS, geoCodingSuccess); 
			geocoder.addEventListener(GeocodingEvent.GEOCODING_FAILURE, geoCodingFailure);				        
	    }
	    
	    private function onMapTypeChanged(event:MapEvent):void {
	    	var stype:String = event.type;
	    	
//	    	trace(map.getCurrentMapType());
	    	
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
			zoomText.text = ""+zoom;
						
			for each (var viewport:MapViewport in viewportDict) 
                viewport.update();            			
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