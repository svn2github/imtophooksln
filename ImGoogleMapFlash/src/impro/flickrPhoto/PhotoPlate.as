package impro.flickrPhoto
{
	import de.johannesluderschmidt.util.Flickr;
	
	import flash.display.Sprite;
	import flash.utils.Dictionary;
	
	import impro.IMStage;
	import impro.multiview.SpriteViewport;
	

	public class PhotoPlate extends Sprite
	{
		private var imStage:IMStage;
		private var flickr:Flickr;
		private var photoplate:Sprite;
		private var viewportDict:Dictionary = new Dictionary();
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		
		public function PhotoPlate(imStage:IMStage, $DEBUG:Boolean = true)
		{
			super();
			DEBUG = $DEBUG;
			
			this.imStage = imStage;						
			this.graphics.beginFill(0x00ff00, 128);
			this.graphics.drawRect(0, 0, imStage.stageWidth, imStage.stageHeight);
			this.graphics.endFill();

			var square:Sprite = new Sprite();
			square.graphics.beginFill(0xff000000);
			square.graphics.drawRect(0, 0, imStage.stageWidth, imStage.stageHeight);
			square.graphics.endFill();
			
			photoplate = new Sprite();
			photoplate.cacheAsBitmap = true;
			photoplate.mask = square;
			addChild(photoplate);
			
			// load photos from Flickr
			flickr = new Flickr(photoplate, imStage.stageWidth, imStage.stageHeight, 15);
			flickr.fetch("72157606319650635");				
		}
			
		public function addViewport(id:Number, x:Number, y:Number, width:Number, height:Number):void{
			
			var viewport:SpriteViewport = new SpriteViewport(photoplate, x, y, width, height);
			viewportDict[id] = viewport; 
			addChild(viewport);
			
			if(DEBUG)
				addChild(viewport.viewport);				
		}
		
		public function updateViewport():void{
			for each (var viewport:SpriteViewport in viewportDict) 
                viewport.update();
		}

		public function getViewport (id:Number):SpriteViewport{
			return viewportDict[id];
		}				
	}
}