package
{
	import app.core.action.RotatableScalable;
	
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.KeyboardEvent;
	
	import impro.IImproApp;
	
	[SWF(width="2048", height="768", backgroundColor="#000000", frameRate="30")]
	public class ImproApps extends Sprite
	{
		private var theApp:DisplayObject;
		
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
			
			launchApp("2");			
		}
		
		private function launchApp(app:String):void{

			switch(app){
				case "1":
					if(theApp != null){
						(theApp as IImproApp).close();
						stage.removeChild(theApp);
					}
					theApp = new GoogleMapTUIO();
    				stage.addChild(theApp);
					break;
				case "2":
					if(theApp != null){
						(theApp as IImproApp).close();
						stage.removeChild(theApp);
					}						
					theApp = new FlickrPhotoApp();
    				stage.addChild(theApp);
					break;
				case "3":
					if(theApp != null)
						stage.removeChild(theApp);
					theApp = new MultiResSpriteTest();
    				stage.addChild(theApp);
					break;
				case "4":
					if(theApp != null)
						stage.removeChild(theApp);
					theApp = new MultiResMoveClipTest();
    				stage.addChild(theApp);
					break;
					
			}	
		}
		
		private function onKey(event:KeyboardEvent):void{
//			trace("Key Pressed: " + String.fromCharCode(event.charCode) + 
//        		" (key code: " + event.keyCode + " character code: " 
//        		+ event.charCode + ")");
			(theApp as IImproApp).updateView();
        	launchApp(String.fromCharCode(event.charCode));        	
		}
	}
}