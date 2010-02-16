package {
	
	import de.johannesluderschmidt.controller.TouchEventsManager;
	import de.johannesluderschmidt.demoObjects.ImageObject;
	import de.johannesluderschmidt.demoObjects.Multitouchable;
	import de.johannesluderschmidt.event.BringToBackEvent;
	import de.johannesluderschmidt.event.BringToFrontEvent;
	import de.johannesluderschmidt.tuio.TUIO;
	import de.johannesluderschmidt.tuio.TouchEvent;
	import de.johannesluderschmidt.util.Flickr;
	
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.events.KeyboardEvent;
	
	import impro.multiview.IMView;
	import impro.Setting;
	import impro.multiview.IMMultiView;
	

	[SWF(width="1280", height="720", backgroundColor="#000000", frameRate="30")]
	public class FlickrPhotoApp extends Sprite
	{
		public static var photoWidth:Number = 100;
		private var FlickrQuality:Number = 2;
		private var FlickrPhotoNum:Number = 40;			


		private var multiResSprite:IMMultiView;
		private var showAll:Boolean = true;		
				
		private var flickr:Flickr;
		private var flickrPlate:Sprite;
		
		public function FlickrPhotoApp(){
			
//			stage.addEventListener (KeyboardEvent.KEY_DOWN, keyDown);			
			addEventListener(BringToBackEvent.DO, bringToBack);
			addEventListener(BringToFrontEvent.DO, bringToFront);
			
			// flickr parameters
			
			// prepare the flickr sprite			
			var flickrPlateWidth:Number = Setting.LRes.stageWidth * FlickrQuality;
			var flickrPlateHeight:Number = Setting.LRes.stageHeight * FlickrQuality;
			flickrPlate = new Sprite();			
			flickr = new Flickr(flickrPlate, flickrPlateWidth, flickrPlateHeight, FlickrPhotoNum, photoWidth, photoLoadComplete);
//			flickr.fetch(true);
			flickr.fetch(false, "Siggraph");
			
			// add low resolution view
			multiResSprite = new IMMultiView(flickrPlate, flickrPlateWidth, flickrPlateHeight, false, Setting.LRes.stageWidth, Setting.LRes.stageHeight, Setting.DEBUG);						

			// add high resolution views
			for each (var view:IMView in Setting.HRes) 
				multiResSprite.addViewport(view.id, view.stageX, view.stageY, view.stageWidth, view.stageHeight);
			
			addChild(multiResSprite);
			
			// add keyborad widget
			TUIO.init(new IMView(-2, 0, 0, flickrPlateWidth, flickrPlateHeight), flickrPlate, 'localhost', 3000, '', Setting.DEBUG );
			Multitouchable.touchMoveCallback = touchMoveCallback;
//			Multitouchable.touchDownCallback = touchDownCallback;
//			Multitouchable.touchUpCallback = touchUpCallback;
		}
		
		private function photoLoadComplete():void{
			multiResSprite.updateViewport();			
		}

		private function onKeyEnter(place:String):void{
//			photoPlate.fetch(place);
//			multiResSprite.fetch("flower");
		}
		
//		private function touchDownCallback(imgObj:ImageObject):void{
////			imgObj.highlight(true);
//			photoPlate.updateViewport();
//			trace("down");
//		}		
		private function touchMoveCallback():void{
			multiResSprite.updateViewport();
			trace("toMove");
		}
//		private function touchUpCallback(imgObj:ImageObject):void{
////			imgObj.highlight(false);
//			photoPlate.updateViewport();
//			trace("up");
//		}
		
		private function keyDown (e:KeyboardEvent):void {
			
			multiResSprite.updateViewport();
			
			if(Setting.DEBUG){
				showAll = !showAll;
				if(showAll)
					multiResSprite.showAll();
				else		
					multiResSprite.hideAll();
			}
		}

		private function updateCallback():void{
			multiResSprite.updateViewport();
		}
		
		private function bringToFront(event:BringToFrontEvent):void
		{
			(event.toFrontObject as ImageObject).highlight(true);
			flickrPlate.swapChildren(event.toFrontObject as DisplayObject, flickrPlate.getChildAt(flickrPlate.numChildren-1));
//			trace("toFront");
		}
		private function bringToBack(event:BringToBackEvent):void
		{
			(event.toBackObject as ImageObject).highlight(false);
//			trace("toBack");
		}
//		private function touchDown (e : TouchEvent) : void
//		{
//			TouchEventsManager.getInstance().endActiveEvent(e);			
//		}
//
//		private function touchUp (e : TouchEvent) : void
//		{
//			TouchEventsManager.getInstance().endActiveEvent(e);
//		}
	}
}
