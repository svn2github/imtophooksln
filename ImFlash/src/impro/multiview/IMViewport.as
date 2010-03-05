package impro.multiview
{
	import flash.display.Bitmap;
	import flash.display.BitmapData;
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.geom.Matrix;
	import flash.geom.Point;
	import flash.geom.Rectangle;
	
	import impro.googlemap.ViewportControl;
	
	public class IMViewport extends Sprite
	{
		private var parentSprite:DisplayObject
		private var screenWidth:Number;
		private var screenHeight:Number;
		private var plateWidth:Number;
		private var plateHeight:Number;

		private var bitmap:Bitmap;
		private var bitmapData:BitmapData;
		
//		private var translatePlate:Sprite;
//		private var scalePlate:Sprite;
//		private var recenterPlate:Sprite;
		private var maskPlate:Sprite;				
		private var ruler:Sprite;
		private var fullRect:Rectangle;
		public var viewport:ViewportControl;
						
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;	
				
		public function IMViewport(parent:DisplayObject, plateWidth:Number, plateHeight:Number, screenX:Number, screenY:Number, screenWidth:Number, screenHeight:Number, vpCx:Number = 50, vpCy:Number = 50, vpWidth:Number = 100, vpHeight:Number = 100, $DEBUG:Boolean = true)
		{
			super();
			DEBUG = $DEBUG;
			
			this.parentSprite = parent;
			this.x = screenX;
			this.y = screenY;
			this.screenWidth = screenWidth;
			this.screenHeight = screenHeight;
			this.plateWidth = plateWidth;
			this.plateHeight = plateHeight;
			
			fullRect = new Rectangle(0, 0, screenWidth, screenHeight);			
			bitmapData = new BitmapData(plateWidth, plateHeight);
			bitmap = new Bitmap(bitmapData);		
			
			var square:Sprite = new Sprite();
			square.graphics.beginFill(0xff000000);
			square.graphics.drawRect(screenX, screenY, screenWidth, screenHeight);
			square.graphics.endFill();		

			maskPlate = new Sprite();
//			maskPlate.cacheAsBitmap = true;			
			maskPlate.mask = square;			
			maskPlate.addChild(bitmap);
			addChild(maskPlate);
			
			if(DEBUG){
				ruler = new Sprite();
				ruler.graphics.clear();
				ruler.graphics.beginFill(0x0000ff, 1);			
				ruler.graphics.drawRect(0, screenHeight/2, screenWidth, 5);
				ruler.graphics.drawRect(screenWidth/2, 0, 5, screenHeight);
				ruler.graphics.endFill();							
				addChild(ruler);
			}
			
			viewport = new ViewportControl("id", updateCallback, vpCx, vpCy, vpWidth, vpHeight, DEBUG);
		}

		public function setViewportBound(rx1:Number, ry1:Number, rx2:Number, ry2:Number):void{
			viewport.setViewportBound(rx1, ry1, rx2, ry2);
		}
		public function setViewportOriPts(pt1:Point, pt2:Point, pt3:Point, pt4:Point):void{
			viewport.setViewportOriPts(pt1, pt2, pt3, pt4);
		}
		
		public function updateCallback():void{
			
			var scaleX:Number = screenWidth / viewport.w;
			var scaleY:Number = screenHeight / viewport.h;			

			var tmatrix:Matrix = new Matrix(1, 0, 0, 1, -viewport.x, -viewport.y);
			var smatrix:Matrix = new Matrix(scaleX, 0, 0, scaleY, 0, 0);
			var tmatrix2:Matrix = new Matrix(1, 0, 0, 1, screenWidth/2, screenHeight/2);
			tmatrix.concat(smatrix);
			tmatrix.concat(tmatrix2);
			
			bitmapData.fillRect(fullRect, 0xff000000);			
			bitmapData.draw(parentSprite, tmatrix);
			
			//new Matrix(			
//			translatePlate.x = -viewport.x;
//			translatePlate.y = -viewport.y;						
//			scalePlate.scaleX = screenWidth / viewport.width;
//			scalePlate.scaleY = screenHeight / viewport.height;			
		}
		
		public function getBitmapData():BitmapData{
			return bitmapData;
		}
		
		public function update():void{
			updateCallback();
		}

	}
}