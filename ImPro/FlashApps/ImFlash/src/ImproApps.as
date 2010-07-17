package
{
	import com.chargedweb.utils.ResourceMonitorUtil;
	
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.LocalConnection;
	import flash.system.System;
	import flash.utils.Dictionary;
	
	import impro.IImproApp;
	import impro.Setting;
	import impro.TangibleCardLayer;
	
	[SWF(width=2400, height=600, frameRate=24)]
	public class ImproApps extends Sprite
	{	
		private var appDict:Dictionary = new Dictionary();
		private var theApp:DisplayObject;
		private var theAppName:String;
		private var appContainer:Sprite;		
		private var tangibleCardLayer:TangibleCardLayer;
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
			
			stage.addEventListener(KeyboardEvent.KEY_DOWN, onKey);
			
			TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);
			
			stage.addEventListener(TouchEvent.MOUSE_DOWN, onTangibleDown);			

			appContainer = new Sprite();
//			tangibleCardLayer = new TangibleCardLayer();
			resoureMonitor = new ResourceMonitorUtil();
			resoureMonitor.x = 80;
			stage.addChild(appContainer);
			stage.addChild(resoureMonitor);	
//						
			var index:Number = 32;
			appDict[String(index++)] = "googlemap,sight_Taipei101";
			appDict[String(index++)] = "googlemap,sight_NYTimeSquare";
			appDict[String(index++)] = "googlemap,sight_LACenter";
			appDict[String(index++)] = "river";
			appDict[String(index++)] = "npm_animal_3";
//			appDict[String(index++)] = "npm_animal_7";
			appDict[String(index++)] = "impro_photoset_01";
			appDict[String(index++)] = "moneyNotArt";			

			appDict[String(index++)] = "p1165-baudisch";
			appDict[String(index++)] = "uist2010_impro";
//			appDict["38"] = "pap1072-chan";	
//			
//						
			launchApp(appDict["33"]);
//			launchApp(appDict[String(appIndex++)]);
//			
//			trace("stage.numChildre: " + stage.numChildren);
		}
		
		
		private function onTangibleDown(e:TouchEvent):void{
						
			if(e.TUIO_TYPE == "2Dobj"){
				if(appDict[e.ID] != null){
					launchApp(appDict[e.ID]);
					trace("stage.numChildren: " + stage.numChildren);	
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

			
			if(theApp){
				(theApp as IImproApp).dispose();
				appContainer.removeChild(theApp);
				theApp = null;
				cacheClear();				
			}
			
			theAppName = app;

			if(theAppName.indexOf("googlemap") != -1){
				var place:String = theAppName.split(",")[1];
				theApp = new GoogleMapTUIO(place);
				appContainer.addChild(theApp);					
			}			
			else{
				theApp = new MultiScaleImageApp(theAppName);
				appContainer.addChild(theApp);					
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
			
//			(theApp as GoogleMapTUIO).setIFlashlightBlack(!(theApp as GoogleMapTUIO).getIFlashlightBlack());
			
//			var nextApp:Number = (appNames.indexOf(theAppName)+1)%appNames.length;
//			launchApp("googlemap,sight_Taipei101");		
//			trace("stage.numChildre: " + stage.numChildren);

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