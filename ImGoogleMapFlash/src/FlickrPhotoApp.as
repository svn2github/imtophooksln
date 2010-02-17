package {
	
	import de.johannesluderschmidt.demoObjects.ImageObject;
	import de.johannesluderschmidt.demoObjects.Multitouchable;
	import de.johannesluderschmidt.demoObjects.VideoObject;
	import de.johannesluderschmidt.event.BringToBackEvent;
	import de.johannesluderschmidt.event.BringToFrontEvent;
	import de.johannesluderschmidt.tuio.TUIO;
	import de.johannesluderschmidt.util.Flickr;
	
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	
	import impro.IImproApp;
	import impro.Setting;
	import impro.events.FlickrEvent;
	import impro.multiview.IMMultiView;
	import impro.multiview.IMView;


	[SWF(width="1280", height="720", backgroundColor="#000000", frameRate="30")]
	public class FlickrPhotoApp extends Sprite implements IImproApp
	{
		public static var photoWidth:Number = 100;
		private var FlickrQuality:Number = 2;
		private var FlickrPhotoNum:Number = 40;			

		private var multiResSprite:IMMultiView;
		private var showAll:Boolean = true;		
				
		private var flickr:Flickr;
		private var flickrPlate:Sprite;
		private var flickrPlateWidth:Number;
		private var flickrPlateHeight:Number;

		private var margin:Number = 20;
		private var curX:Number = margin;
		private var curY:Number = margin;
		private var maxHeightInRow:Number = 0;
		
		var vid:VideoObject;
		
		public function FlickrPhotoApp(){
			
//			stage.addEventListener (KeyboardEvent.KEY_DOWN, keyDown);			
			addEventListener(BringToBackEvent.DO, bringToBack);
			addEventListener(BringToFrontEvent.DO, bringToFront);
			
			// flickr parameters
			
			// prepare the flickr sprite			
			flickrPlateWidth = Setting.LRes.stageWidth * 3;
			flickrPlateHeight = Setting.LRes.stageHeight * 3;
			flickrPlate = new Sprite();			
			flickr = new Flickr(flickrPlate, FlickrPhotoNum);
//			flickr.fetch(true);
			flickr.fetch(false, "Siggraph");
			
//			vid = new VideoObject("file:///C:/flv/test.flv", this);
//			vid.x = 100;
//			vid.y = 100;
////			addChild(vid);
//			flickrPlate.addChild(vid);
			
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

			addEventListener(FlickrEvent.PHOTO_LOADED, function (e:FlickrEvent):void{
				addPics(e.imgObj);
				multiResSprite.updateViewport();				
			});
			
			
		}
		
		public function close():void{
//			TUIO.stopSocket();	
		}
		
		private function addPics(obj:ImageObject):void{
			
			var imObj:ImageObject = obj;
			var imgW:Number = imObj.getImageWidth();
			var imgH:Number = imObj.getImageHeight();
			var scale:Number = photoWidth / imgW;
			imObj.scaleX = scale;
			imObj.scaleY = scale;
			
			if((curX + photoWidth) > flickrPlateWidth){
				curX = margin;
				curY += (maxHeightInRow + margin);
				maxHeightInRow = 0;
			}else{
				maxHeightInRow = Math.max(imgH*scale, maxHeightInRow); 
			}
			
			imObj.x = curX;
			imObj.y = curY;						
			curX += (photoWidth + margin);
//			flickrPlate.addChild(imObj);
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
		
		public function updateView ():void {	
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
