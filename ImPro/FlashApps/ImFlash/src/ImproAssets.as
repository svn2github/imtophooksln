package
{
	import flash.display.Bitmap;
	
	public class ImproAssets
	{
		private static var imgLoader:ImagesLoader;		
		
		public static function init(func:Function):void{
			imgLoader = new ImagesLoader(func);
			imgLoader.push("http://ivlab.csie.ntu.edu.tw/imPro/resource/ui/siggraphLogo.png", "siggraphLogo");
			imgLoader.startLoading();
		}
		
		public static function getImage(label:String):Bitmap{
			return imgLoader.getImage(label);			
		}
		

	}
}