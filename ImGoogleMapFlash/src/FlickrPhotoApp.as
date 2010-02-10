package {
	
	import de.johannesluderschmidt.controller.TouchEventsManager;
	import de.johannesluderschmidt.event.BringToFrontEvent;
	import de.johannesluderschmidt.tuio.TUIO;
	import de.johannesluderschmidt.tuio.TouchEvent;
	
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	
	import impro.IMStage;
	import impro.flickrPhoto.PhotoPlate;
	import impro.googlemap.ViewportControl;

	[SWF(width="1280", height="720", backgroundColor="#000000", frameRate="30")]
	public class FlickrPhotoApp extends Sprite
	{
		private var square:Sprite;
		
		private var squareTapped:Boolean;
		private var squareDownX:Number;
		private var squareDownY:Number;
		
		private var imStage:IMStage = new IMStage(500, 500);
		
		private var photoPlate:PhotoPlate;
		private var hresView:Sprite;
		 

		public function FlickrPhotoApp(){
//			TUIO.init(this, new IMStage(1280, 720), 'localhost', 3000, '', true );



			TUIO.init(imStage, this, 'localhost', 3000, '', true );
			
			var bg:Sprite = new Sprite();			
			bg.graphics.beginFill(0x00FFFF, 0);
			bg.graphics.drawRect(0, 0, 1280, 720);
			bg.graphics.endFill();			
			addChild(bg);
			bg.addEventListener(TouchEvent.MOUSE_UP, touchUp);
			bg.addEventListener(TouchEvent.MOUSE_DOWN, touchDown);
			
//			for(var i:Number = 0; i < 10; i++){
//				var movableSquare:MovableSquare = new MovableSquare(0x000000+0x22*i);
//				movableSquare.x=200;
//				movableSquare.y=200;
//				movableSquare.rotation = i*-36;
//				addChild(movableSquare);				
//			}
			addEventListener(BringToFrontEvent.DO, bringToFront);
			
			

			
//			var subobj:Sprite = new Sprite();
//			this.addChild(subobj);
			
//			flickrLoader.width = 400;
//			flickrLoader.height = 500;

			photoPlate = new PhotoPlate(imStage, true);
			this.addChild(photoPlate);
			
			photoPlate.addViewport(0, imStage.stageWidth, 0, imStage.stageWidth, imStage.stageHeight);
						
		}
		
		private function updateCallback():void{
			photoPlate.updateViewport();
		}
		
		private function bringToFront(event:BringToFrontEvent):void{
			swapChildren(event.toFrontObject as DisplayObject,getChildAt(numChildren-1));
		}
		private function touchDown (e : TouchEvent) : void
		{
			TouchEventsManager.getInstance().endActiveEvent(e);			
		}

		private function touchUp (e : TouchEvent) : void
		{
//			TouchEventsManager.getInstance().endActiveEvent(e);
		}
	}
}
