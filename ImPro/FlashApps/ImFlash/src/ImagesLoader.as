package
{
	import flash.display.Bitmap;
	import flash.display.Loader;
	import flash.events.Event;
	import flash.net.URLRequest;
	
	public class ImagesLoader
	{
		private var loadImageNum:Number = 0;
		private var imageDB:Object = new Object;  // as a reposity
		private var imagesInfo:Array = new Array();				
		private var onLoaded:Function;
		
		public function ImagesLoader(onLoaded:Function)
		{
			this.onLoaded = onLoaded;
		}
		
		public function push(url:String, label:String):void{
			imagesInfo.push({ url: url, label: label});
//			loadImage(url, label);
		}
		
		public function startLoading():void{
			for each(var object:Object in imagesInfo){
				loadImage(object.url, object.label);
			}	
		}
		
		private function loadImage(url:String, label:String):void{
		    var imgLoader:Loader = new Loader();
		    imgLoader.contentLoaderInfo.addEventListener(Event.COMPLETE, function(e:Event):void{
		    	trace(url + " loaded.");
		    	imageDB[label] = new Bitmap(Bitmap(e.target.content).bitmapData);
		    	loadImageNum++;
		    	if(loadImageNum == imagesInfo.length){
		    		trace("call onLoaded()");
		    		onLoaded();
		    	}
		    });
		    imgLoader.load(new URLRequest(url));				
		}
		
		public function getImage(label:String):Bitmap{
			return imageDB[label] as Bitmap;
		}
	}
}