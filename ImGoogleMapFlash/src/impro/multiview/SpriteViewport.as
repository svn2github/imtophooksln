package impro.multiview
{
	import flash.display.Bitmap;
	import flash.display.BitmapData;
	import flash.display.Sprite;
	
	import impro.googlemap.ViewportControl;
	
	public class SpriteViewport extends Sprite
	{
		private var parentSprite:Sprite;
		private var screenWidth:Number;
		private var screenHeight:Number;
		private var bitmap:Bitmap;
		private var bitmapData:BitmapData;
		
		private var translatePlate:Sprite;
		private var scalePlate:Sprite;
		private var recenterPlate:Sprite;
		private var maskPlate:Sprite;
		
		public var viewport:ViewportControl;
		
		public function SpriteViewport(parent:Sprite, screenX:Number, screenY:Number, screenWidth:Number, screenHeight:Number, vpCx:Number = 50, vpCy:Number = 50, vpWidth:Number = 100, vpHeight:Number = 100)
		{
			this.parentSprite = parent;
			this.x = screenX;
			this.y = screenY;
			this.screenWidth = screenWidth;
			this.screenHeight = screenHeight;

			bitmapData = new BitmapData(screenWidth, screenHeight);
			bitmap = new Bitmap(bitmapData);
			
			var square:Sprite = new Sprite();
			square.graphics.beginFill(0xff000000);
			square.graphics.drawRect(screenWidth, 0, screenWidth, screenHeight);
			square.graphics.endFill();		
			
			translatePlate = new Sprite();
			scalePlate = new Sprite();
			recenterPlate = new Sprite();
			maskPlate = new Sprite();
			
			translatePlate.x = -screenWidth/2;
			translatePlate.y = -screenHeight/2;
			translatePlate.addChild(bitmap);
			
			scalePlate.scaleX = 1;
			scalePlate.scaleY = 1;
			scalePlate.addChild(translatePlate);			
			
			recenterPlate.x = screenWidth/2;
			recenterPlate.y = screenHeight/2;
			recenterPlate.addChild(scalePlate);
			
			maskPlate.cacheAsBitmap = true;
			maskPlate.mask = square;
			
			maskPlate.addChild(recenterPlate);
			addChild(maskPlate);
			
			viewport = new ViewportControl(updateCallback, vpCx, vpCy, vpWidth, vpHeight);
		}


		
		public function updateCallback():void{
			
			bitmapData.draw(parentSprite);
			
			translatePlate.x = -viewport.x;
			translatePlate.y = -viewport.y;
						
			scalePlate.scaleX = screenWidth / viewport.width;
			scalePlate.scaleY = screenHeight / viewport.height;			
		}
		
		public function getBitmapData():BitmapData{
			return bitmapData;
		}
		
		public function update():void{
			bitmapData.draw(parentSprite);
		}

	}
}