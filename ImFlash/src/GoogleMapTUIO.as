package {
	
	import com.google.maps.LatLng;
	
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.XMLSocket;
	import flash.ui.Keyboard;
	import flash.utils.Dictionary;
	
	import impro.IImproApp;
	import impro.NUIPad.MTEditor;
	import impro.Setting;
	import impro.element.GoogleAddress;
	import impro.element.ImageButton;
	import impro.googlemap.*;
	import impro.multiview.IMView;
	
	[SWF(width=1600, height=600, frameRate=24, backgroundColor=0xEB7F00)]
	public class GoogleMapTUIO extends Sprite implements IImproApp
	{
		private var multiResMap:MultiResMap;			
		private	var editor:MTEditor;
		private var socket:XMLSocket;

		private var sights:Dictionary;
		private var imgLoader:ImagesLoader;
		private var arrowLoader:ImagesLoader;
		private var panoramioLoader:ImagesLoader;
		
		private var loadLocal:Boolean = true;
		private var sights_101:Dictionary;
		private var imgLoader_101:ImagesLoader;
		private var sights_NY:Dictionary;
		private var imgLoader_NY:ImagesLoader;

		
		public function GoogleMapTUIO()
		{									
		   trace(stage);  
		   //如果直接執行該swf, stage是有值的  
		   //但如果是被載入, stage一開始是null  
		   //要避免這樣的問題, 就直接偵聽 AddedToStage 事件即可     
		   if (stage) init(null);  
		   else addEventListener(Event.ADDED_TO_STAGE , init);  			
		}

		private function init(e:Event):void {
			removeEventListener(Event.ADDED_TO_STAGE, init);  
			//把要做的事寫在這兒  
			//這樣就可以確保 stage 屬性一定有值
			
			//Connect to FLOSC to recieve touch input
//			this.stage.stageWidth = 500;
			
			// add multi-resolution map
			addMultiResMap();

			// add keyborad widget
//			addKeyboardWidget();
			
			// add google earth client
			addGoogleEarthClient(2);			
			
			// add sightSeeing buttons
			addSightSeeings();
				   		
//			addChild(new FPSMonitor());
			//add stage listener 
//			stage.addEventListener(MouseEvent.MOUSE_DOWN, touchDown);
//			stage.addEventListener(TouchEvent.CLICK, touchDown);
			
//			stage.addEventListener(KeyboardEvent.KEY_DOWN, function(e:KeyboardEvent):void{
//				if(e.keyCode == Keyboard.LEFT)
//					geControl.moveLeft();
//				else if(e.keyCode == Keyboard.RIGHT)
//					geControl.moveRight();
//				else if(e.keyCode == Keyboard.UP)
//					geControl.moveUp();
//				else if(e.keyCode == Keyboard.DOWN)
//					geControl.moveDown();							
//			});  
			
			add101Infomation();
			addNYInfomation();
			
//			var iview:IMView = multiResMap.getMapStage();
			
			TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);
			  
		}  
		
		private function add101Infomation():void{
			
 			sights_101 = new Dictionary;
 			sights_101["sights_101_1"] = new GoogleAddress("sights_101_1", new LatLng(25.033700, 121.565899), 16); 			
			sights_101["sights_101_2"] = new GoogleAddress("sights_101_2", new LatLng(25.033073, 121.559209), 16);
			sights_101["sights_101_3"] = new GoogleAddress("sights_101_3", new LatLng(25.041020, 121.559322), 16);
			sights_101["sights_101_4"] = new GoogleAddress("sights_101_4", new LatLng(25.039503, 121.565748), 16);
 			sights_101["sights_101_5"] = new GoogleAddress("sights_101_5", new LatLng(25.033739, 121.565094), 16); 			
			sights_101["sights_101_6"] = new GoogleAddress("sights_101_6", new LatLng(25.032859, 121.568012), 16);
			sights_101["sights_101_7"] = new GoogleAddress("sights_101_7", new LatLng(25.033865, 121.561553), 16);
			sights_101["sights_101_8"] = new GoogleAddress("sights_101_8", new LatLng(25.033501, 121.560784), 16);
 			sights_101["sights_101_9"] = new GoogleAddress("sights_101_9", new LatLng(25.032806, 121.564021), 16); 			
			sights_101["sights_101_10"] = new GoogleAddress("sights_101_10", new LatLng(25.033473, 121.566113), 16);
			sights_101["sights_101_11"] = new GoogleAddress("sights_101_11", new LatLng(25.031571, 121.565480), 16);
			sights_101["sights_101_12"] = new GoogleAddress("sights_101_12", new LatLng(25.035741, 121.562798), 16);
			sights_101["sights_101_13"] = new GoogleAddress("sights_101_13", new LatLng(25.036045, 121.562274), 16);			
			sights_101["sights_101_14"] = new GoogleAddress("sights_101_14", new LatLng(25.033297, 121.559815), 16);
			sights_101["sights_101_15"] = new GoogleAddress("sights_101_15", new LatLng(25.037734, 121.557112), 16);
			sights_101["sights_101_16"] = new GoogleAddress("sights_101_16", new LatLng(25.040038, 121.566896), 16);
			sights_101["sights_101_17"] = new GoogleAddress("sights_101_17", new LatLng(25.043489, 121.556371), 16);			
			sights_101["sights_101_18"] = new GoogleAddress("sights_101_18", new LatLng(25.040329, 121.553786), 16);
			sights_101["sights_101_19"] = new GoogleAddress("sights_101_19", new LatLng(25.041904, 121.545053), 16);
			sights_101["sights_101_20"] = new GoogleAddress("sights_101_20", new LatLng(25.026094, 121.558082), 16);
			

			imgLoader_101 = new ImagesLoader(function():void{});			
			for each (var value:Object in sights_101) {
				var location:String = (value as GoogleAddress).location;
				if(loadLocal)
					imgLoader_101.push("c:/imProResource/sightseeings/sights_101/"+location+".jpg", location);
				else
					imgLoader_101.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/sightseeings/sights_101/"+location+".jpg", location);								
			}
			imgLoader_101.startLoading();
		}

		private function addNYInfomation():void{
			
 			sights_NY = new Dictionary;
 			sights_NY["sights_NY_1"] = new GoogleAddress("sights_NY_1", new LatLng(40.755986, -73.986622), 16); 			
			sights_NY["sights_NY_2"] = new GoogleAddress("sights_NY_2", new LatLng(40.756652, -73.986762), 16);
			sights_NY["sights_NY_3"] = new GoogleAddress("sights_NY_3", new LatLng(40.741404, -73.989530), 16);
			sights_NY["sights_NY_4"] = new GoogleAddress("sights_NY_4", new LatLng(40.756490, -73.987684), 16);
 			sights_NY["sights_NY_5"] = new GoogleAddress("sights_NY_5", new LatLng(40.757099, -73.986686), 16); 			
			sights_NY["sights_NY_6"] = new GoogleAddress("sights_NY_6", new LatLng(40.758075, -73.987899), 16);
			sights_NY["sights_NY_7"] = new GoogleAddress("sights_NY_7", new LatLng(40.758782, -73.986424), 16);
			sights_NY["sights_NY_8"] = new GoogleAddress("sights_NY_8", new LatLng(40.756490, -73.985538), 16);
 			sights_NY["sights_NY_9"] = new GoogleAddress("sights_NY_9", new LatLng(40.762211, -73.985969), 16); 			
			sights_NY["sights_NY_10"] = new GoogleAddress("sights_NY_10", new LatLng(40.764161, -73.978844), 16);
 			sights_NY["sights_NY_11"] = new GoogleAddress("sights_NY_11", new LatLng(40.760322, -73.984938), 16); 			
			sights_NY["sights_NY_12"] = new GoogleAddress("sights_NY_12", new LatLng(40.756847, -73.993778), 16);
			sights_NY["sights_NY_13"] = new GoogleAddress("sights_NY_13", new LatLng(40.753239, -73.987770), 16);
			sights_NY["sights_NY_14"] = new GoogleAddress("sights_NY_14", new LatLng(40.753174, -73.980131), 16);
 			sights_NY["sights_NY_15"] = new GoogleAddress("sights_NY_15", new LatLng(40.752816, -73.977127), 16);
			sights_NY["sights_NY_16"] = new GoogleAddress("sights_NY_16", new LatLng(40.756019, -73.984036), 16);
			sights_NY["sights_NY_17"] = new GoogleAddress("sights_NY_17", new LatLng(40.754084, -73.992126), 16);
			sights_NY["sights_NY_18"] = new GoogleAddress("sights_NY_18", new LatLng(40.751971, -73.988113), 16);
 			sights_NY["sights_NY_19"] = new GoogleAddress("sights_NY_19", new LatLng(40.753869, -73.983956), 16); 			
			sights_NY["sights_NY_20"] = new GoogleAddress("sights_NY_20", new LatLng(40.758302, -73.983790), 16);

			imgLoader_NY = new ImagesLoader(function():void{});			
			for each (var value:Object in sights_NY) {
				var location:String = (value as GoogleAddress).location;
				if(loadLocal)
					imgLoader_NY.push("c:/imProResource/sightseeings/sights_NY/"+location+".jpg", location);
				else
					imgLoader_NY.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/sightseeings/sights_NY/"+location+".jpg", location);								
			}
			imgLoader_NY.startLoading();
		}
		
		private function addSightSeeings():void{
 			
 			sights = new Dictionary;
// 			sights["sight_Eiffel"] = new GoogleAddress("sight_Eiffel", new LatLng(48.85780097266282, 2.295967680887427), 16); 			
//			sights["sight_Christ"] = new GoogleAddress("sight_Christ", new LatLng(-22.950407157676, -43.20953574843956), 16);
//			sights["sight_Canyon"] = new GoogleAddress("sight_Canyon", new LatLng(36.14936973429993, -111.839335188889), 16);
//			sights["sight_Forbidden"] = new GoogleAddress("sight_Forbidden", new LatLng(39.91379916102216, 116.3908088768237), 16);
//			sights["sight_Fuji"] = new GoogleAddress("sight_Fuji", new LatLng(35.34063009043844, 138.7818265722904), 16);
//			sights["sight_Peters"] = new GoogleAddress("sight_Peters", new LatLng(41.90238356414683, 12.45863229278517), 16);
//			sights["sight_London"] = new GoogleAddress("sight_London", new LatLng(51.50295856070689, -0.1208037863755851), 16);
			sights["sight_Taipei101"] = new GoogleAddress("sight_Taipei101", new LatLng(25.03403, 121.564643), 16);		
			sights["sight_NYTimeSquare"] = new GoogleAddress("sight_NYTimeSquare", new LatLng(40.755852,-73.986386), 16);			
						
			imgLoader = new ImagesLoader(sightImageLoaded);			
			for each (var value:Object in sights) {
				var location:String = (value as GoogleAddress).location;
//				imgLoader.push("assets/sightseeings/"+location+".png", location);
				if(loadLocal)
					imgLoader.push("c:/imProResource/sightseeings/"+location+".png", location);
				else
					imgLoader.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/sightseeings/"+location+".png", location);								
			}
			imgLoader.startLoading();
		}

		
		private function sightImageLoaded():void{
			var btnWidth:Number = 60;
			var btnMarginX:Number = 1.5;
			var btnMarginY:Number = 1.1;
			
			var i:Number = 1;
			var row:Number = 3;
			for each (var value:Object in sights) {
				var gAddress:GoogleAddress = value as GoogleAddress;
				var sightBtn:ImageButton = new ImageButton(gAddress.location, imgLoader.getImage(gAddress.location), btnWidth, btnWidth);
				sightBtn.addEventListener(TouchEvent.MOUSE_UP, tuioUpEvent);
				sightBtn.addEventListener(MouseEvent.MOUSE_UP, mouseUpEvent);
				sightBtn.x = Setting.LRes.stageWidth - btnWidth*btnMarginX*(Math.floor(i/row)+1);
				sightBtn.y = Setting.LRes.stageHeight - btnWidth*btnMarginY*(i%row+1);
				addChild(sightBtn);				
				i++;
			}			
		}		

		private function tuioUpEvent(e:TouchEvent):void{
			var location:String = e.currentTarget.name;
			var gAdress:GoogleAddress = sights[location] as GoogleAddress;
			gotoSightseeing(gAdress);
		}
		
		private function mouseUpEvent(e:MouseEvent):void{
			var location:String = e.currentTarget.name;
			var gAdress:GoogleAddress = sights[location] as GoogleAddress;
			gotoSightseeing(gAdress);
			
			var value:Object;
			var gAddress:GoogleAddress;
			if(location == "sight_Taipei101"){
				for each (value in sights_101) {
					gAddress = value as GoogleAddress;
					multiResMap.addPhoto(gAddress, imgLoader_101.getImage(gAddress.location));
				}							
			}
			else if(location == "sight_NYTimeSquare"){
				for each (value in sights_NY) {
					gAddress = value as GoogleAddress;
					multiResMap.addPhoto(gAddress, imgLoader_NY.getImage(gAddress.location));
				}											
			}
		}
		
		private function gotoSightseeing(gAdress:GoogleAddress):void{						
			multiResMap.flyToLatlng(gAdress.latlng, gAdress.zoom);
//			queryPanoramio(gAdress);			
		} 
		
		/*
//		private function queryPanoramio(gAdress:GoogleAddress):void  
//		{  
//			
//		    var panoramioURL:String = "http://www.panoramio.com/map/get_panoramas.php?order=popularity&set=public&from=0&to=50&minx=-180&miny=-90&maxx=180&maxy=90&size=medium";  
//		    var request:URLRequest = new URLRequest(panoramioURL);  
//		    var loader:URLLoader = new URLLoader(request);  
//		    loader.addEventListener(Event.COMPLETE, panoramioQueryComplete);  
//		    loader.addEventListener(  
//		        IOErrorEvent.IO_ERROR,  
//		        function(event:Event):void  
//		        {  		             
//		            trace("There was an IO error contacting Panoramio");
////		            Alert.show("There was an IO error contacting Panoramio");  
//		        }  
//		    );  
//		    loader.addEventListener(		      
//		        SecurityErrorEvent.SECURITY_ERROR,  
//		        function(event:Event):void  
//		        {		        	 
//		        	trace("There was a security error contacting Panoramio");
////		            Alert.show("There was a security error contacting Panoramio");  
//		        }  
//		    );  
//		}
	
	
//		private function panoramioQueryComplete(event:Event):void  
//		{  
//			panoramioLoader = new ImagesLoader(panoramioLoaded);
//			
//		    var response:URLLoader = URLLoader(event.target);  
//		    var responseData:Object = JSON.decode(response.data);  
//		  	var locx:Number = 100;
//		  	var index:Number = 1;
//		  	for each (var image:Object in responseData.photos)  
//		    {  	
//		    	if(index <= 5){
//			    	trace("photo_file_url: " + image.photo_file_url);
//			    	trace("width: " + image.width);
//			    	trace("height: " + image.height);
//			    	trace("longitude: "+ image.longitude);
//			    	trace("latitude: " + image.latitude);
//			    	
//			    	panoramioLoader.push(image.photo_file_url, "panoramio_" + index);				
//	//		    	multiResMap.overlayPhoto(image.latitude, image.longitude, image.photo_file_url);
//					index++;		    		
//		    	}  
//		    }
//		    panoramioLoader.startLoading();
//		}
		
		private function panoramioLoaded():void{
			for(var i:Number = 1;i<=5;i++){
				var bitmap:Bitmap = panoramioLoader.getImage("panoramio_" + i);
				if(bitmap!=null){
					bitmap.x = 50;
					bitmap.y = i*100;
					bitmap.scaleX = bitmap.scaleY = 100/bitmap.width; 					 
					addChild(bitmap);					
				}
			}			
		}
		*/
		
		public function close():void{			
		}		

		private function addMultiResMap():void{	
			
			// add low resolution views
			var lres:IMView = Setting.LRes;
			multiResMap = new MultiResMap(0, 0, lres.stageWidth, lres.stageHeight, Setting.DEBUG);
			// add high resolution views
			for each (var view:IMView in Setting.HRes)
				multiResMap.addViewport(view.id, view.stageX, view.stageY, view.stageWidth, view.stageHeight) 
			addChild(multiResMap);	
		}
		
		private function addKeyboardWidget():void{
			editor = new MTEditor(800, 330);
//			editor.scaleX = 1;
//			editor.scaleY = 1;
			editor.enterCallback = onKeyEnter;
			addChild(editor);			
		}
		
		private function addGoogleEarthClient(number:Number):void{
			// add ge delegate control
			setupSocket();
			
			for(var i:Number=0;i<number;i++){
				var ge:GEControl = multiResMap.addGeControl(socket, 100*(i+1), 100*(i+1));
				trace("ge.id: " + ge.id);
			}
			
//			var ge1:GEControl = multiResMap.addGeControl(socket, 150, 150);
//			var ge2:GEControl = multiResMap.addGeControl(socket, 250, 250);
//			trace("ge1.id: " + ge1.id);		
//			trace("ge2.id: " + ge2.id);
			
			// load GE arrows
			arrowLoader = new ImagesLoader(function():void{
				var ge0:GEControl = multiResMap.getGeControl("tabletGE_0");
				var ge1:GEControl = multiResMap.getGeControl("tabletGE_1");
				var ge2:GEControl = multiResMap.getGeControl("tabletGE_2");
				if(ge0!=null)	ge0.setArrowIcon(arrowLoader.getImage("red"));
				if(ge1!=null)	ge1.setArrowIcon(arrowLoader.getImage("green"));
				if(ge2!=null)	ge2.setArrowIcon(arrowLoader.getImage("blue"));
				
				if(ge0!=null)	ge0.setPositionHeading(100, 100, 60);
				if(ge1!=null)	ge1.setPositionHeading(200, 200, 120);
				if(ge2!=null)	ge2.setPositionHeading(300, 300, 180);
			});
			arrowLoader.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/ui/redArrow.png", "red");
			arrowLoader.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/ui/greenArrow.png", "green");
			arrowLoader.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/ui/blueArrow.png", "blue");
			arrowLoader.startLoading();
		}
		
		private function setupSocket():void{
											
			socket = new XMLSocket();
			socket.addEventListener(Event.CONNECT, function(event:Event):void{
				socket.send("11,flashGE");								
//				socket.send("14,flashGE-login"); // broadcast
			});
			
            socket.addEventListener(DataEvent.DATA, dataHandler);
			socket.addEventListener(Event.CONNECT, onConnect);
            socket.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
			socket.addEventListener(Event.CLOSE, onDisconnect);
			socket.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);

			socket.connect(Setting.ServerIP, Setting.ServerPort);			
		}	

		private  function dataHandler(e:DataEvent):void{
			var msg:String = e.data;
			var data:Array = msg.split(',');
			var from:String = data[2];
			var cmd:String = data[3];
			if(cmd=="geLogin"){
//				var geControl:GEControl = multiResMap.addGeControl(socket, 150, 150);				
//				socket.send("15," + from + ",flashGE," + "assignID," + geControl.id);
//				trace("assignID: " + geControl.id);				
				
			}else if(cmd=="geDebug"){
				var vspaceX:Number = Number(data[4]);
				var vspaceY:Number = Number(data[5]);
				var heading:Number = Number(data[6]);
				heading = (heading + 180) % 360;

				var ge:GEControl = multiResMap.getGeControl(from);
				if(ge!=null){
					var lresX:Number = vspaceX * Setting.LRes.stageWidth;
					var lresY:Number = vspaceY * Setting.LRes.stageHeight;
					
					var radius:Number = 0;
					if(lresX < 0)	radius = Math.abs(lresX);
					if(lresX > Setting.LRes.stageWidth)
						radius = Math.max(radius, lresX - Setting.LRes.stageWidth);						
					if(lresY < 0)	radius = Math.max(radius, -lresY);
					if(lresY > Setting.LRes.stageHeight)
						radius = Math.max(radius, lresY - Setting.LRes.stageHeight);
						
					ge.setPositionHeading(lresX, lresY, heading, radius);
				}
			}else if(cmd=="clientLogin"){
				var who:String = data[4];
				trace(who + " login");
				
				var ge:GEControl = multiResMap.getGeControl(who);
				if(ge != null)
					ge.update();			
				
			}else if(cmd=="clientLogout"){
//				var who:String = data[4];
//				multiResMap.removeGeControl(who);
			}
		}
		private function onConnect(e:Event):void{
            trace("connectHandler: " + e);
		}		
		private function onDisconnect(e:Event):void{
            trace("closeHandler: " + e);			
		}
        private function ioErrorHandler(event:IOErrorEvent):void {
            trace("ioErrorHandler: " + event);
        }
        private function securityErrorHandler(event:SecurityErrorEvent):void {
            trace("securityErrorHandler: " + event);
        }
        
        public function updateView():void{
        	
        }
        
		private function onKeyEnter(place:String):void{
			multiResMap.flyToPlace(place);
		}
				
		private function onKey(event:KeyboardEvent):void{
			trace("Key Pressed: " + String.fromCharCode(event.charCode) + 
        		" (key code: " + event.keyCode + " character code: " 
        		+ event.charCode + ")");			
			
			if(event.keyCode == Keyboard.LEFT){
			
			}
				
		}
				
		private function touchDown(e:Event):void
		{			
			trace("touchDown");
		}				
		
	}
}
