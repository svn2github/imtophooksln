package impro.googlemap
{
	
	import com.google.maps.LatLng;
	import com.google.maps.LatLngBounds;
	import com.google.maps.Map;
	import com.google.maps.Map3D;
	import com.google.maps.MapEvent;
	import com.google.maps.MapOptions;
	import com.google.maps.MapType;
	import com.google.maps.geom.Attitude;
	import com.google.maps.interfaces.IMapType;
	import com.google.maps.overlays.GroundOverlay;
	import com.google.maps.overlays.Marker;
	
	import flash.display.Bitmap;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.geom.Point;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;
	
	import impro.Setting;
	import impro.element.GoogleAddress;
	import impro.googlemap.events.HResEvent;

	public class MapViewport extends Sprite
	{			
		private var parentMap:Map;
		private var childMap:Map3D;
		private var screenWidth:Number;
		private var screenHeight:Number;	
		
		public var viewport:ViewportControl;
		private var ruler:Sprite = new Sprite();		
		private var mapPanel:Sprite = new Sprite();		
		private var mapReady:Boolean = false;
		
		private var blackScreen:Sprite = new Sprite();
		
//		private var imgLoader:Loader;
//		private var maskBmp:Bitmap;
		
//		private var stableViewportX:Number = 0;
//		private var stableViewportY:Number = 0;
//		private var stableViewportW:Number = 0;
//		private var stableViewportH:Number = 0;

		// for stablization
		private var herx1:Number = 0;
		private var hery1:Number = 0;
		private var herx2:Number = 0;
		private var hery2:Number = 0;
		
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		private var DEBUG_TEXT:TextField;			
		private var TYPE_BUTTON:Sprite;
		private var TYPE_INDEX:Number = 0;
				
		public function MapViewport(parentMap:Map, screenX:Number, screenY:Number, screenWidth:Number, screenHeight:Number, $DEBUG:Boolean = true, 
								vpCx:Number = 50, vpCy:Number = 50, vpWidth:Number = 100, vpHeight:Number = 100)
		{
			super();
			
			DEBUG = $DEBUG;
			
			this.parentMap = parentMap;
			this.x = screenX;
			this.y = screenY;
			this.screenWidth = screenWidth;
			this.screenHeight = screenHeight;
			
			childMap = new Map3D();			
//			childMap.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExRcR7IumtuiL9gAiOhCPfe14dC1HBSpTjOFiyNExylutyalkkjAIFFIZw";
			childMap.setSize(new Point(screenWidth, screenHeight));			

			childMap.addEventListener(MapEvent.MAP_READY, function(e:Event):void{
				mapReady = true;
				update();
			});
			
			childMap.addEventListener(MapEvent.MAP_PREINITIALIZE, function(e:Event):void{
			  var myMapOptions:MapOptions = new MapOptions();
			  myMapOptions.zoom = parentMap.getZoom()+2;
			  myMapOptions.center = parentMap.getCenter();
			  myMapOptions.mapType = MapType.HYBRID_MAP_TYPE;
			  childMap.setInitOptions(myMapOptions);
 			 
 			 });			
			
//			childMap.addEventListener(MapEvent.MAP_PREINITIALIZE, function(e:Event):void{
//		        var mapOptions:MapOptions = new MapOptions();
//		        mapOptions.viewMode = View.VIEWMODE_PERSPECTIVE;		        
//		        childMap.setInitOptions(mapOptions);					
//			});			
			mapPanel.addChild(childMap);

			blackScreen.graphics.beginFill(0x000000);
			blackScreen.graphics.drawRect(0,0,screenWidth, screenHeight);
			blackScreen.graphics.endFill();
			blackScreen.visible = false;
			mapPanel.addChild(blackScreen);
									
			addChild(mapPanel);
			mapPanel.scaleX = 1;
			mapPanel.scaleY = 1;

			viewport = new ViewportControl("id", updateCallback, vpCx, vpCy, vpWidth, vpHeight, Setting.DEBUG);
			
			if(DEBUG)
			{
				ruler.graphics.clear();
				ruler.graphics.beginFill(0x0000ff, 1);			
				ruler.graphics.drawRect(0, childMap.height/2, childMap.width, 1);
				ruler.graphics.drawRect(childMap.width/2, 0, 1, childMap.height);
				ruler.graphics.endFill();
				mapPanel.addChild(ruler);

	  			var format:TextFormat = new TextFormat("Verdana", 10, 0xFFFFFF);
				DEBUG_TEXT = new TextField();       
				DEBUG_TEXT.defaultTextFormat = format;
				DEBUG_TEXT.autoSize = TextFieldAutoSize.LEFT;
				DEBUG_TEXT.background = true;	
				DEBUG_TEXT.backgroundColor = 0x000000;	
				DEBUG_TEXT.border = true;	
				DEBUG_TEXT.borderColor = 0x333333;							
				DEBUG_TEXT.x = 85;
				DEBUG_TEXT.y = 25;
				DEBUG_TEXT.text = "DEBUG_TEXT";
//				addChild( DEBUG_TEXT );						
	//			this.setChildIndex(DEBUG_TEXT, this.numChildren-1);
				
				TYPE_BUTTON = new Sprite();
				TYPE_BUTTON.x = 60; 
				TYPE_BUTTON.y = 25;
				TYPE_BUTTON.graphics.beginFill(0x0000ff);
				TYPE_BUTTON.graphics.drawRect(0, 0, 20, 20);
				TYPE_BUTTON.graphics.endFill();
				TYPE_BUTTON.alpha = 0.85;
				TYPE_BUTTON.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent):void{
					childMap.setMapType(MapType.DEFAULT_MAP_TYPES[(++TYPE_INDEX)%4]);
				});
				this.addChild( TYPE_BUTTON );						
	//			this.setChildIndex(TYPE_BUTTON, this.numChildren-1);
			} 			
		}
		
		public function setBlackScreen(value:Boolean):void{
			blackScreen.visible = value;				
		}
		public function getBlackScreen():Boolean{
			return blackScreen.visible;
		}
		
		public function dispose():void{						
			
			if(childMap)
				childMap.unload();
			childMap = null;
			
			ruler = null;
			mapPanel = null;
				
			viewport.dispose();
			viewport = null;
		}
				
		public function addOverlay(gAddress:GoogleAddress, image:Bitmap):void{
 	        var marker:Marker = new Marker(gAddress.latlng);
 	        childMap.addOverlay(marker);

 	        var ll:LatLng = new LatLng(gAddress.latlng.lat()+0.001, gAddress.latlng.lng()+0.001);
			var groundOverlay:GroundOverlay = new GroundOverlay(
			        image, new LatLngBounds	(gAddress.latlng, ll));
			childMap.addOverlay(groundOverlay); 				
		}
		
		public function updateCallback(vpControl:ViewportControl):void{
			this.update();
		}
		
		public function setViewportBound(rx1:Number, ry1:Number, rx2:Number, ry2:Number):void{
			viewport.setViewportBound(rx1, ry1, rx2, ry2);
		}
		public function setViewportOriPts(pt1:Point, pt2:Point, pt3:Point, pt4:Point):void{
			viewport.setViewportOriPts(pt1, pt2, pt3, pt4);
		}
		
		public function setViewport(cx:Number, cy:Number, w:Number, h:Number):void{
			viewport.setViewport(cx, cy, w, h);
		}
		
		public function isBeyondStable(he:HResEvent, stableThre:Number):Boolean{

			var	beyondStable:Boolean = false;
			if(Math.abs(herx1 - he.rx1) > stableThre)	beyondStable = true;
			if(Math.abs(hery1 - he.ry1) > stableThre)	beyondStable = true;
			if(Math.abs(herx2 - he.rx2) > stableThre)	beyondStable = true;
			if(Math.abs(hery2 - he.ry2) > stableThre)	beyondStable = true;			
			if(beyondStable){
				herx1 = he.rx1;
				hery1 = he.ry1;
				herx2 = he.rx2;
				hery2 = he.ry2;				
			}
			
			return beyondStable;	
		}		
				
		public function pitch(delta:Number):void{
			var yaw:Number = childMap.getAttitude().yaw;
			var pitch:Number = childMap.getAttitude().pitch;
			childMap.setAttitude(new Attitude(yaw,pitch+delta,0));
			update();		
		}
		
		public function update():void{
			
			if(!mapReady)
				return;
			
			updateMap();
			
			if(DEBUG){
				updateRuler();
				
				DEBUG_TEXT.text = 
				" zoom: " + childMap.getZoom() + 
				"\n pitch: " + childMap.getAttitude().pitch;
			}
			
			// scale the map to match the viewport size
			mapPanel.scaleX = screenWidth / childMap.width;
			mapPanel.scaleY = screenHeight/ childMap.height;							
		}
		
		private function updateRuler():void{
			ruler.graphics.clear();
			ruler.graphics.beginFill(0x0000ff, 1);			
			ruler.graphics.drawRect(0, childMap.height/2, childMap.width, 1);
			ruler.graphics.drawRect(childMap.width/2, 0, 1, childMap.height);
			ruler.graphics.endFill();							
		}
				
		private function updateMap(useBestZoom:Boolean = true):void{
			if(!childMap)
				return;
				
			// for stablization
//			var stablization:Number = 4;
//			var dx:Number = Math.abs((stableViewportX - viewport.x));
//			var dy:Number = Math.abs((stableViewportY - viewport.y));
//			var dw:Number = Math.abs((stableViewportW - viewport.w));
//			var dh:Number = Math.abs((stableViewportH - viewport.h));
//			if(dx > stablization || dy > stablization || dw > stablization || dh > stablization){
//				stableViewportX = viewport.x;
//				stableViewportY = viewport.y;
//				stableViewportW = viewport.w;
//				stableViewportH = viewport.h;				
//			}
//			// get target latlng
//			var toLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(stableViewportX, stableViewportY));

			// get target latlng
			var toLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(viewport.x, viewport.y));
			
			// calculate best zoom level regarding the screen resolution
			if(useBestZoom){
				var bestZoom:Number = calBestZoom(viewport.w, viewport.h, screenWidth, screenHeight);
				childMap.setZoom(parentMap.getZoom() + bestZoom - 1);
			}
			
			var pow:Number = Math.pow(2, childMap.getZoom() - parentMap.getZoom());			
			var w:Number = viewport.w * pow; 
			var h:Number = viewport.h * pow;			
			
			/*
			// get target latlng
			var toLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(viewport.x, viewport.y));
			
			// calculate best zoom level regarding the screen resolution
			if(useBestZoom){
				var bestZoom:Number = calBestZoom(viewport.w, viewport.h, screenWidth, screenHeight);
				childMap.setZoom(parentMap.getZoom() + bestZoom -2);				
			}
			
			var pow:Number = Math.pow(2, childMap.getZoom() - parentMap.getZoom());			
			var w:Number = viewport.w * pow; 
			var h:Number = viewport.h * pow;
			*/
			
			// apply to map
			if(childMap != null && toLatlng != null){
				childMap.setCenter(toLatlng);
				childMap.setSize(new Point(w, h));						
			}
		}
		
		public function setMapType(type:IMapType):void{
			childMap.setMapType(type);
		}
				
		private function calBestZoom(fromW:Number, fromH:Number, toW:Number, toH:Number):Number{
			var wzoomLevel:Number = 0;			
			while(fromW* Math.pow(2, wzoomLevel) < toW)
				wzoomLevel++;	
			
			var hzoomLevel:Number = 0;			
			while(fromH* Math.pow(2, hzoomLevel) < toH)
				hzoomLevel++;	
			
			return Math.min(wzoomLevel, hzoomLevel);
		}
				
//		public function setMapZoom(z:Number):void{
//			map.setZoom(z);
//		}		
//		public function getMap():Map{
//			return map;
//		}		
//		private function onMapReady(event:Event):void {	    	
//	    	map.setCenter(new LatLng(40.736072,-73.992062), mapZoom, MapType.NORMAL_MAP_TYPE);	        
//	    }
//	    private function onMapPreinitialize(event:Event):void {
//	      var myMapOptions:MapOptions = new MapOptions();
//	      myMapOptions.mapType = MapType.SATELLITE_MAP_TYPE;
//	      map.setInitOptions(myMapOptions);
//	    }
		 
	}
}