package 
{
	import flash.display.DisplayObject;
	import flash.display.Loader;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.ProgressEvent;
	import flash.net.URLRequest;
	
	import impro.Setting;
	import impro.multiview.IMView;
	import impro.multiview.IMMultiView;
	
	[SWF(width="1280", height="720", backgroundColor="#000000", frameRate="30")]
	public class MultiResMoveClipTest extends Sprite
	{
		private var multiResSprite:IMMultiView;

		public function MultiResMoveClipTest()
		{
			super();
			startLoad();
		}
		
		private function startLoad()
		{
			var mLoader:Loader = new Loader();
			var mRequest:URLRequest = new URLRequest("./assets/swf/Conservative.swf");
			mLoader.contentLoaderInfo.addEventListener(Event.COMPLETE, onCompleteHandler);
			mLoader.contentLoaderInfo.addEventListener(ProgressEvent.PROGRESS, onProgressHandler);
			mLoader.load(mRequest);
		}		

		private function onCompleteHandler(loadEvent:Event)
		{
//		    addChild(loadEvent.currentTarget.content);
			var content:DisplayObject = loadEvent.currentTarget.content;
			content.x = 0;
			content.y = 0;			
			content.addEventListener(Event.ENTER_FRAME, function(e:Event):void{
				trace("frame");
				if(multiResSprite != null)
					multiResSprite.updateViewport();
			});
			
//			addChild(content);
			// add low resolution view			
			multiResSprite = new IMMultiView(content, 1280, 1024, true, Setting.LRes.stageWidth, Setting.LRes.stageHeight, Setting.DEBUG);						
			
//			// add high resolution views
			for each (var view:IMView in Setting.HRes) 
				multiResSprite.addViewport(view.id, view.stageX, view.stageY, view.stageWidth, view.stageHeight);
//			
			addChild(multiResSprite);
		    
		}
		
		private function onProgressHandler(mProgress:ProgressEvent)
		{
			var percent:Number = mProgress.bytesLoaded/mProgress.bytesTotal;
			trace(percent);
		}		
	}
}