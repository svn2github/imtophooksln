package {
	import flash.display.Loader;
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.LocalConnection;
	import flash.net.URLRequest;
	import flash.system.System;
	import flash.utils.Dictionary;
	
	import impro.Setting;
	
	[SWF(width=2400, height=600, frameRate=30)]
	public class LoadSWF extends Sprite
	{
		private var appDict:Dictionary = new Dictionary();
		private var theAppName:String;
		
		private var _swfLoader:Loader;
		private var _swfContent:Sprite;//MovieClip;
		
		public function LoadSWF()
		{
			super();
			if (stage) init(null);  
			else addEventListener(Event.ADDED_TO_STAGE , init);  			
		}
		
		private function init(e:Event):void {
			removeEventListener(Event.ADDED_TO_STAGE, init);  
			//把要做的事寫在這兒  
			//這樣就可以確保 stage 屬性一定有值
			
			TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);
			
			stage.addEventListener(KeyboardEvent.KEY_DOWN, onKey);
			
			
			appDict["32"] = "ImproApps_001.swf";
			appDict["33"] = "ImproApps_002.swf";
			
			launchApp(appDict["32"]);
		}
		
		private function launchApp(app:String):void{
			unloadSWF(null);
			theAppName = app;
			loadSWF(app);	
		}
		
		public function loadSWF(path:String):void {
			var _req:URLRequest = new URLRequest();
			_req.url = path;
			
			_swfLoader = new Loader();
			setupListeners(_swfLoader.contentLoaderInfo);
			
			_swfLoader.load(_req);
		}
		
		public function setupListeners(dispatcher:IEventDispatcher):void {
			dispatcher.addEventListener(Event.COMPLETE, addSWF);
			dispatcher.addEventListener(ProgressEvent.PROGRESS, preloadSWF);
		}
		
		public function preloadSWF(event:ProgressEvent):void {
			var _perc:int = (event.bytesLoaded / event.bytesTotal) * 100;
			// swfPreloader.percentTF.text = _perc + "%";
		}
		
		public function addSWF(event:Event):void {
			event.target.removeEventListener(Event.COMPLETE, addSWF);
			event.target.removeEventListener(ProgressEvent.PROGRESS, preloadSWF);
			
			_swfContent = event.target.content;
			_swfContent.addEventListener("close", unloadSWF);
			
			trace("addSWF before: " + numChildren);
			addChild(_swfContent);
			trace("addSWF after: " + numChildren);
		}
		
		public function unloadSWF(event:Event):void {
			
			if(!_swfLoader)
				return;
			
//			_swfLoader.unloadAndStop(true);
			_swfLoader.unload();
			
			trace("unloadSWF before: " + numChildren);
			removeChild(_swfContent);
			trace("unloadSWF after: " + numChildren);
			_swfContent = null;
			cacheClear();
			
			//			var cnum:Number = stage.numChildren;
			//			for(var i:Number = 0; i<cnum;i++){
			//					
			//				if(stage)
			//					stage.removeChildAt(0);
			//				else
			//					trace("stage==null");
			//			}
			
			//			stage.removeChild(_swfContent);
			//			trace("_swfContent:　" + _swfContent);
			//			 if(stage){
			//				trace("after remove: " + stage.numChildren);
			//			    _swfContent = null;
			//			    cacheClear();
			//				}
		}
		
		private function onKey(event:KeyboardEvent):void{
			// goto next app
			//			if(theAppName != appDict["32"])
			//				launchApp(appDict["32"]);
			//			else if(theAppName != appDict["33"])						
			//				launchApp(appDict["33"]);
			
			launchApp(appDict["32"]);
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
