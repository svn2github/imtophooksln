package
{
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.KeyboardEvent;
	import flash.events.TUIO;
	import flash.events.TouchEvent;
	
	import impro.IImproApp;
	import impro.Setting;
	
	[SWF(width="2048", height="768", backgroundColor="#000000", frameRate="30")]
	public class ImproApps extends Sprite
	{
		private var theApp:DisplayObject;
		private var btn1:Sprite;
		private var btn2:Sprite;
		
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
			
			TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);
						
			var btnWidth:Number = 60;
			var btnMargin:Number = 1.2;
			btn1 = new Sprite();
			btn1.graphics.beginFill(0xff0000);
			btn1.graphics.drawRect(0,0,btnWidth,btnWidth);
			btn1.graphics.endFill();
			btn1.addEventListener(TouchEvent.MOUSE_UP, tuioUpEvent);
			
			btn1.x = Setting.LRes.stageWidth - btnWidth*btnMargin;
			btn1.y = Setting.LRes.stageHeight - btnWidth*btnMargin*2;

			btn2 = new Sprite();
			btn2.graphics.beginFill(0xffff00);
			btn2.graphics.drawRect(0,0,btnWidth,btnWidth);			
			btn2.graphics.endFill();
			btn2.x = Setting.LRes.stageWidth - btnWidth*btnMargin;
			btn2.y = Setting.LRes.stageHeight - btnWidth*btnMargin;
			btn2.addEventListener(TouchEvent.MOUSE_UP, tuioUpEvent);

			launchApp("1");						
		}

		private function tuioUpEvent(e:TouchEvent):void
		{
			if(e.target == btn1){
				if(!(theApp is GoogleMapTUIO))
					launchApp("1");
			}					
			else if(e.target == btn2){
				if(!(theApp is MultiScaleImageFlashCS3Example))
					launchApp("2");
			}
		}
		
		private function launchApp(app:String):void{
			
			if(theApp!=null){
				stage.removeChild(theApp);
				stage.removeChild(btn1);
				stage.removeChild(btn2);
			}
			
			switch(app){
				case "1":
					theApp = new GoogleMapTUIO();
    				stage.addChild(theApp);
					break;
				case "2":
					theApp = new MultiScaleImageFlashCS3Example();
    				stage.addChild(theApp);
					break;
//				case "3":
//					if(theApp != null)
//						stage.removeChild(theApp);
//					theApp = new MultiResSpriteTest();
//    				stage.addChild(theApp);
//					break;
//				case "4":
//					if(theApp != null)
//						stage.removeChild(theApp);
//					theApp = new MultiResMoveClipTest();
//    				stage.addChild(theApp);
//					break;
					
			}	
			
			stage.addChild(btn1); 
			stage.addChild(btn2); 
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