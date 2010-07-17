package impro.element
{
	import flash.display.Sprite;
	import flash.display.Bitmap;
	
	public class ImageButton extends Sprite
	{
		
		public function ImageButton(name:String, bitmap:Bitmap, w:Number, h:Number)
		{
			super();
			this.name = name
			bitmap.width = w;
			bitmap.height = h;
			addChild(bitmap);
			trace(name);			
		}		
	}
}