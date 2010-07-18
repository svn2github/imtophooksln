package
{
	import com.chargedweb.utils.ResourceMonitorUtil;
	
	import flash.display.Bitmap;
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.LocalConnection;
	import flash.net.XMLSocket;
	import flash.system.System;
	import flash.utils.Dictionary;
	
	import impro.IImproApp;
	import impro.Setting;
	import impro.TangibleCardLayer;
	import impro.multiview.IMView;

	[SWF(width=2400, height=600, frameRate=24)]
	public class ImproApps extends Sprite
	{	
		private var appDict:Dictionary = new Dictionary();
		
//		private var preApp:IImproApp; // preApp for not crash, when removing curApp which is running animation
		private var curApp:IImproApp;
		
		private var theAppName:String;
		private var appContainer:Sprite;		
		
		private var socket:XMLSocket;
			
		private var iFlashlightDraging:Boolean = false;
		private var iFlashlightBlackScreen:Sprite = new Sprite();

		private var tangibleCardLayer:TangibleCardLayer;
		private var siggraphLogo:Sprite;
		
		private var resoureMonitor:ResourceMonitorUtil;		
					
		public function ImproApps()
		{
			super();
			if (stage) init(null);  
			else addEventListener(Event.ADDED_TO_STAGE , init);  			

		}

		public function timerHandler(event:TimerEvent):void {  
			trace("Total memory in use by flash: " + Math.floor(System.totalMemory/1024/1024) + "MB");
		}  

		private function init(e:Event):void {
			removeEventListener(Event.ADDED_TO_STAGE, init);  
			//把要做的事寫在這兒  
			//這樣就可以確保 stage 屬性一定有值
			
			// load images for the use of the application
			ImproAssets.init(loadComplete);	
			
			stage.addEventListener(KeyboardEvent.KEY_DOWN, onKey);			
			TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);			
			stage.addEventListener(TouchEvent.MOUSE_DOWN, onTangibleDown);			

			// setup socket connection, for GoogleMapTUIO.as & iFlashlightDrag
			setupSocket();
			
			appContainer = new Sprite();
//			tangibleCardLayer = new TangibleCardLayer();
			resoureMonitor = new ResourceMonitorUtil();
			resoureMonitor.x = 80;
			stage.addChild(appContainer);
			stage.addChild(resoureMonitor);	
			
			setupIFlashlightBlackScreen(); // (double-click to switch)
			stage.addChild(iFlashlightBlackScreen);						
			
			siggraphLogo = new Sprite();
			siggraphLogo.x = Setting.getiFlashlightIMView().stageX + Setting.getiFlashlightIMView().stageWidth/2;
			siggraphLogo.y = Setting.getiFlashlightIMView().stageY + Setting.getiFlashlightIMView().stageHeight/2;
			stage.addChild(siggraphLogo);
			
			setupApps();
			
			launchApp(appDict["36"]);
		}		

		private function setupApps():void{
			
			var index:Number = 36;
			appDict[String(index++)] = "googlemap,sight_Taipei101";
			appDict[String(index++)] = "googlemap,sight_NYTimeSquare";
			appDict[String(index++)] = "googlemap,sight_LACenter";
			appDict[String(index++)] = "river";
			appDict[String(index++)] = "uist2010_impro";
			
//			appDict[String(index++)] = "npm_animal_3";
//			appDict[String(index++)] = "npm_animal_7";
//			appDict[String(index++)] = "impro_photoset_01";
//			appDict[String(index++)] = "moneyNotArt";			
//			appDict[String(index++)] = "p1165-baudisch";
//			appDict["38"] = "pap1072-chan";				
		}
        		
		private function loadComplete():void{
			var bmp:Bitmap = ImproAssets.getImage("siggraphLogo");
			bmp.scaleX = 0.7;
			bmp.scaleY = 0.7;
			bmp.x = -bmp.width/2;
			bmp.y = -bmp.height/2;
			siggraphLogo.addChild(bmp);	
			siggraphLogo.visible = false;
		}
		
		private function onTangibleDown(e:TouchEvent):void{
						
			if(e.TUIO_TYPE == "2Dobj"){
				if(appDict[e.ID] != null){
					launchApp(appDict[e.ID]);
				}
			}
		}

	
		private function launchApp(app:String):void{
			
			// if the app is not googleMap, check the same app -> return
//			if(theAppName && 
//				theAppName.indexOf("googlemap") == -1 && 
//				theAppName == app)
//				return;
			
			if(theAppName == app){
				trace("return");
				return;
			}

//			if(preApp){
//				(preApp as IImproApp).dispose();
//				preApp = null;
//				cacheClear();	
//			}
//			
//			if(curApp){
//				preApp = curApp;
//				appContainer.removeChild(curApp as DisplayObject);
//				curApp = null;
//			}

			if(curApp){
				(curApp as IImproApp).dispose();
				appContainer.removeChild(curApp as DisplayObject);
				curApp = null;
				cacheClear();					
			}
			
			theAppName = app;

			if(theAppName.indexOf("googlemap") != -1){
				var place:String = theAppName.split(",")[1];
				curApp = new GoogleMapTUIO(place, socket);
				appContainer.addChild(curApp as DisplayObject);					
			}			
			else{
				curApp = new MultiScaleImageApp(theAppName);
				appContainer.addChild(curApp as DisplayObject);					
			}
		}
		
		private function onKey(event:KeyboardEvent):void{
			// goto next app

//			if(event.keyCode == 67){  // close
//				
//				(theApp as IImproApp).dispose();								
//				appContainer.removeChild(theApp);
//				theApp = null;
//				cacheClear();				
//			}
			
			if(event.keyCode == 76){  // load
				
//				launchApp(appDict[String(appIndex++)]);
//				launchApp(appDict["35"]);
			}
			
			
			iFlashlightBlackScreen.visible = !iFlashlightBlackScreen.visible; 
			
			
//			var nextApp:Number = (appNames.indexOf(theAppName)+1)%appNames.length;
//			launchApp("googlemap,sight_Taipei101");		
//			trace("stage.numChildre: " + stage.numChildren);

		}
		
		private function setupIFlashlightBlackScreen():void{
			if(Setting.getiFlashlightIMView()){
				trace("Setting.getiFlashlightIMView().stageWidth: " + Setting.getiFlashlightIMView().stageWidth);
				trace("Setting.getiFlashlightIMView().stageHeight: " + Setting.getiFlashlightIMView().stageHeight);

				var imView:IMView = Setting.getiFlashlightIMView();
				iFlashlightBlackScreen.graphics.beginFill(0x000000);				
				iFlashlightBlackScreen.graphics.drawRect(imView.stageX,imView.stageY,imView.stageWidth, imView.stageHeight);
				iFlashlightBlackScreen.graphics.endFill();
				iFlashlightBlackScreen.visible = false;				
			}			
		}
		
		private function setupSocket():void{
											
			socket = new XMLSocket();
			socket.addEventListener(Event.CONNECT, function(event:Event):void{

				socket.send("11,flashGE");				

				if(curApp is GoogleMapTUIO)
					(curApp as GoogleMapTUIO).updateHResMap();		

//				socket.send("14,flashGE-login"); // broadcast
			});
			
            socket.addEventListener(DataEvent.DATA, dataHandler);
			socket.addEventListener(Event.CONNECT, connectHandler);
            socket.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
			socket.addEventListener(Event.CLOSE, closeHandler);
			socket.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);

			socket.connect(Setting.ServerIP, Setting.ServerPort);			
		}	
		
		private  function dataHandler(e:DataEvent):void{
			var msg:String = e.data;
			var data:Array = msg.split(',');
			var from:String = data[2];
			var cmd:String = data[3];

			if(cmd=="geLogin"){
				// it will send latlng coordinate info to iView clients
				trace("client[" + from +  "] login");
				if(curApp is GoogleMapTUIO)
					(curApp as GoogleMapTUIO).updateHResMap();		
			}

//			else if(cmd=="geDebug"){
//				var vspaceX:Number = Number(data[4]);
//				var vspaceY:Number = Number(data[5]);
//				var heading:Number = Number(data[6]);
//				heading = (heading + 180) % 360;
//
//				var ge:GEControl = multiResMap.getGeControl(from);
//				if(ge!=null){
//					var lresX:Number = vspaceX * Setting.LRes.stageWidth;
//					var lresY:Number = vspaceY * Setting.LRes.stageHeight;
//					
//					var radius:Number = 0;
//					if(lresX < 0)	radius = Math.abs(lresX);
//					if(lresX > Setting.LRes.stageWidth)
//						radius = Math.max(radius, lresX - Setting.LRes.stageWidth);						
//					if(lresY < 0)	radius = Math.max(radius, -lresY);
//					if(lresY > Setting.LRes.stageHeight)
//						radius = Math.max(radius, lresY - Setting.LRes.stageHeight);
//						
//					ge.setPositionHeading(lresX, lresY, heading, radius);
//				}
//			}
//			else if(cmd=="clientLogin"){
//				var who:String = data[4];
//				trace(who + " login");
//				var ge:GEControl = multiResMap.getGeControl(who);
//				if(ge != null)
//					ge.update();				
//			}
			else if(cmd=="clientLogout"){
//				var who:String = data[4];
//				multiResMap.removeGeControl(who);
			}

			else if(cmd=="mouseDown"){
				// show siggraph icon
				siggraphLogo.visible = true;
			}
			else if(cmd=="mouseUp"){
				// hide siggraph icon
				siggraphLogo.visible = false;
			}
			else if(cmd=="doubleClick"){
				// turn on/off iFlashlight black screen
				iFlashlightBlackScreen.visible = !iFlashlightBlackScreen.visible; 
			}			
		}
		private function connectHandler(e:Event):void{
            trace("connectHandler: " + e);
		}		
		private function closeHandler(e:Event):void{
            trace("closeHandler: " + e);			
		}
        private function ioErrorHandler(event:IOErrorEvent):void {
            trace("ioErrorHandler: " + event);
        }
        private function securityErrorHandler(event:SecurityErrorEvent):void {
            trace("securityErrorHandler: " + event);
        }
		
		
		
		/**
		 * Explicitly invoke the garbage collector
		 * @return	nothing
		 */
		public function cacheClear():void
		{
//			if(debug)
			{
				trace("Cache.clear() called :: memory usage exceeded ::");
				trace("\tmemory usage: "+getCurrentRamUsage()+"mb");
			}
			try
			{
             	var hlcp:LocalConnection = new LocalConnection();
             	var hlcs:LocalConnection = new LocalConnection();
             	hlcp.connect('name');
              	hlcs.connect('name');
       		}
       		catch (e:Error)
			{
				flash.system.System.gc();
				flash.system.System.gc();
			}
//			if(debug)
				trace("\tmemory usage [after clean()]: "+getCurrentRamUsage()+"mb");
		}
		
		private function getCurrentRamUsage():Number
		{
			return Math.floor(System.totalMemory/(1024*1024)*100)/100;
		}				
	}
}