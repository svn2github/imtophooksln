package
{
	import app.core.action.RotatableScalable;
	
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.KeyboardEvent;

	public class ImproApps extends Sprite
	{
		private var theApp:DisplayObject;
		private var button:RotatableScalable;
		
		public function ImproApps()
		{
			super();
		   if (stage) init(null);  
		   else addEventListener(Event.ADDED_TO_STAGE , init);  			

		}

		private function init(e:Event):void {
			removeEventListener(Event.ADDED_TO_STAGE, init);  
			//把要做的事寫在這兒  
			//這樣就可以確保 stage 屬性一定有值
			
			stage.addEventListener(KeyboardEvent.KEY_DOWN, onKey);
			
			launchApp("1");
			
		}
		
		private function launchApp(app:String):void{

			switch(app){
				case "1":
					if(theApp != null)
						stage.removeChild(theApp);
					theApp = new GoogleMapTUIO();
    				stage.addChild(theApp);
					break;
				case "2":
					if(theApp != null)
						stage.removeChild(theApp);
					theApp = new FlickrPhotoApp();
    				stage.addChild(theApp);
					break;
			}	
		}
		
		private function onKey(event:KeyboardEvent):void{
//			trace("Key Pressed: " + String.fromCharCode(event.charCode) + 
//        		" (key code: " + event.keyCode + " character code: " 
//        		+ event.charCode + ")");
			        		
        	launchApp(String.fromCharCode(event.charCode));        	
		}
	}
}