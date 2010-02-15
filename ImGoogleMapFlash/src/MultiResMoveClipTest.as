package 
{
	import flash.display.Sprite;
	
	import flash.net.URLRequest;
	import flash.display.Loader;
	import flash.events.Event;
	import flash.events.ProgressEvent;
	
	public class MultiResMoveClipTest extends Sprite
	{
		public function MultiResMoveClipTest()
		{
			super();
			startLoad();
		}
		
		private function startLoad()
		{
			var mLoader:Loader = new Loader();
			var mRequest:URLRequest = new URLRequest("Main.swf");
			mLoader.contentLoaderInfo.addEventListener(Event.COMPLETE, onCompleteHandler);
			mLoader.contentLoaderInfo.addEventListener(ProgressEvent.PROGRESS, onProgressHandler);
			mLoader.load(mRequest);
		}		

		private function onCompleteHandler(loadEvent:Event)
		{
		        addChild(loadEvent.currentTarget.content);
		}
		
		private function onProgressHandler(mProgress:ProgressEvent)
		{
			var percent:Number = mProgress.bytesLoaded/mProgress.bytesTotal;
			trace(percent);
		}		
	}
}