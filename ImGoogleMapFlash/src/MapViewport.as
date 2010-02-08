package
{
	
	import com.google.maps.LatLng;
	import com.google.maps.Map;
	import com.google.maps.Map3D;
	import com.google.maps.MapEvent;
	import com.google.maps.MapOptions;
	import com.google.maps.MapType;
	import com.google.maps.View;
	import com.google.maps.controls.NavigationControl;
	import com.google.maps.geom.Attitude;
	
	import flash.display.Bitmap;
	import flash.display.Loader;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.geom.Point;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;

	public class MapViewport extends Sprite
	{			
		private var parentMap:Map;
		private var childMap:Map3D;
		private var screenWidth:Number;
		private var screenHeight:Number;	
		
		public var viewport:ViewportControl;
		private var ruler:Sprite = new Sprite();
		
		private var mapPanel:Sprite = new Sprite();
				
		private var imgLoader:Loader;
		private var maskBmp:Bitmap;

		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		private var DEBUG_TEXT:TextField;			
		private var TYPE_BUTTON:Sprite;
		private var TYPE_INDEX:Number = 0;
				
		public function MapViewport(parentMap:Map, screenX:Number, screenY:Number, screenWidth:Number, screenHeight:Number, 
								vpCx:Number = 50, vpCy:Number = 50, vpWidth:Number = 100, vpHeight:Number = 100, $DEBUG:Boolean = true)
		{
			super();
			
			DEBUG = $DEBUG;
			
			this.parentMap = parentMap;
			this.x = screenX;
			this.y = screenY;
			this.screenWidth = screenWidth;
			this.screenHeight = screenHeight;
			
			childMap = new Map3D();			
			childMap.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExRcR7IumtuiL9gAiOhCPfe14dC1HBSpTjOFiyNExylutyalkkjAIFFIZw";
			childMap.setSize(new Point(screenWidth, screenHeight));			
			childMap.addEventListener(MapEvent.MAP_READY, function(e:Event):void{
				childMap.setCenter(parentMap.getCenter(), parentMap.getZoom()+2, MapType.NORMAL_MAP_TYPE);
//				childMap.addControl(new NavigationControl());
				update();
			});
			
			childMap.addEventListener(MapEvent.MAP_PREINITIALIZE, function(e:Event):void{
		        var mapOptions:MapOptions = new MapOptions();
		        mapOptions.viewMode = View.VIEWMODE_PERSPECTIVE;		        
		        childMap.setInitOptions(mapOptions);					
			});			
			mapPanel.addChild(childMap);

			ruler.graphics.clear();
			ruler.graphics.beginFill(0x0000ff, 1);			
			ruler.graphics.drawRect(0, childMap.height/2, childMap.width, 1);
			ruler.graphics.drawRect(childMap.width/2, 0, 1, childMap.height);
			ruler.graphics.endFill();
			mapPanel.addChild(ruler);
						
			addChild(mapPanel);
			mapPanel.scaleX = 1;
			mapPanel.scaleY = 1;
			
			viewport = new ViewportControl(this, vpCx, vpCy, vpWidth, vpHeight);
			
			// for mask
//			maskBmp = new Bitmap();			
//			addChild(maskBmp);
//		 	imgLoader = new Loader();
//			imgLoader.contentLoaderInfo.addEventListener(Event.COMPLETE, function(e:Event):void{
//				maskBmp.bitmapData = (e.target.content as Bitmap).bitmapData.clone();
//				maskBmp.width = screenWidth;
//				maskBmp.height = screenHeight;
//				viewport.setMask(maskBmp.bitmapData.clone());
//			});
//			imgLoader.load(new URLRequest("assets/mask/mask101.png"));
			
			if(DEBUG)
			{
				activateDebugMode();					
			} 
			
		}
		
		private function activateDebugMode():void{
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
			this.addChild( DEBUG_TEXT );						
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
		
		public function setViewport(cx:Number, cy:Number, w:Number, h:Number):void{
			viewport.setViewport(cx, cy, w, h);
		}
				
		public function pitch(delta:Number):void{
			var yaw:Number = childMap.getAttitude().yaw;
			var pitch:Number = childMap.getAttitude().pitch;
			childMap.setAttitude(new Attitude(yaw,pitch+delta,0));
			update();		
		}
		
		public function update():void{
			updateMap();
			updateRuler();
			
			if(DEBUG){
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
			
			// get target latlng
			var toLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(viewport.x, viewport.y));
			
			// calculate best zoom level regarding the screen resolution
			if(useBestZoom){
				var bestZoom:Number = calBestZoom(viewport.width, viewport.height, screenWidth, screenHeight);
				childMap.setZoom(parentMap.getZoom() + bestZoom);				
			}
			
			var pow:Number = Math.pow(2, childMap.getZoom() - parentMap.getZoom());			
			var w:Number = viewport.width * pow; 
			var h:Number = viewport.height * pow;
			
			// apply to map
			childMap.setCenter(toLatlng);
			childMap.setSize(new Point(w, h));		
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