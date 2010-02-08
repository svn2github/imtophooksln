package {
	
	import app.core.canvas.RippleCanvas;
	
	import flash.display.Sprite;
	import flash.events.*;
	import flash.ui.Keyboard;
		
	[SWF(width=1366, height=500, frameRate=24, backgroundColor=0xEB7F00)]
	public class GoogleMapTUIO extends Sprite
	{
		private var subobj:RippleCanvas;
		
		private var stageWidth:Number = 1366;
		private var stageHeight:Number = 500;
		private var movieURL:String;
		
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
			
			// add high-resolution views
			var multiResMap:MultiResMap = new MultiResMap(0, 0, stageWidth/3, stageHeight);
			(multiResMap.addViewport(stageWidth/3, 0, stageWidth/3, stageHeight)).viewport.x = 120;
			(multiResMap.addViewport(2*stageWidth/3, 0, stageWidth/3, stageHeight)).viewport.x = 230;
			
			// add ge delegate control
			var geControl:GEControl = multiResMap.addGeControl(150, 150);
			geControl.x = geControl.y = 150;
			
			addChild(multiResMap);
						
			//Connect to FLOSC to recieve touch input
//			TUIO.init( this, 'localhost', 3000, '', true, multiResMap.getMapWidth(), multiResMap.getMapHeight());
//			TUIO2.init(this, 'localhost', 3000, '', true);
			TUIO.init(this, 'localhost', 3000, '', true);
			
			//add stage listener 
			stage.addEventListener(MouseEvent.MOUSE_DOWN, touchDown);
			stage.addEventListener(TouchEvent.CLICK, touchDown);
			stage.addEventListener(HResEvent.POSE_CHANGE, hresPosChange);
			  
			stage.addEventListener(KeyboardEvent.KEY_DOWN, function(e:KeyboardEvent):void{
				if(e.keyCode == Keyboard.LEFT)
					geControl.moveLeft();
				else if(e.keyCode == Keyboard.RIGHT)
					geControl.moveRight();
				else if(e.keyCode == Keyboard.UP)
					geControl.moveUp();
				else if(e.keyCode == Keyboard.DOWN)
					geControl.moveDown();							
			});  
			  
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
		
		private function hresPosChange(e:Event):void{
			
			var he:HResEvent = e as HResEvent;
			trace(he.ID + ": " + he.regionX + ", "+ he.regionY + ", "+ he.regionWidth + ", "+ he.regionHeight); 
		}
	}
}
