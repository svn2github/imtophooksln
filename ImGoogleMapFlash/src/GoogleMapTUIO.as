package {
	
	import flash.display.Sprite;
	import flash.events.*;
	import flash.ui.Keyboard;
	
	import impro.multiview.IMView;
	import impro.NUIPad.MTEditor;
	import impro.Projection;
	import impro.googlemap.*;
	
	[SWF(width=1024, height=768, frameRate=24, backgroundColor=0xEB7F00)]
	public class GoogleMapTUIO extends Sprite
	{		
		private var multiResMap:MultiResMap;			
		private	var editor:MTEditor;
		
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
			
			// add multi-resolution map
			addMultiResMap();
			
			// add google earth client
			addGoogleEarthClient();
			
			// add keyborad widget
			addKeyboardWidget();
			
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

			TUIO.init(multiResMap.getMapStage(), this, 'localhost', 3000, '', Projection.DEBUG);
			  
		}  
		
		private function addMultiResMap():void{
			// add low resolution views
			var lres:IMView = Projection.LRes;
			multiResMap = new MultiResMap(lres.id, 0, lres.stageWidth, lres.stageHeight, Projection.DEBUG);
			// add high resolution views
			for each (var view:IMView in Projection.HRes)
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
		
		private function addGoogleEarthClient():void{
			// add ge delegate control
			var geControl:GEControl = multiResMap.addGeControl("GE1", 150, 150);
			geControl.x = geControl.y = 150;			
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
