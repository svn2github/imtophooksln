package 
{
	import app.core.action.RotatableScalable;

	import flash.display.DisplayObject;
	import flash.display.Loader;
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.URLRequest;
	
	import impro.Setting;
	import impro.IImproApp;
	import impro.multiview.IMView;
	import impro.multiview.IMMultiView;
	
	[SWF(width="1280", height="720", backgroundColor="#000000", frameRate="30")]
	public class MultiResMoveClipTest extends Sprite implements IImproApp
	{
		private var multiResSprite:IMMultiView;
		private var showAll:Boolean = true;
		
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

		public function close():void{
			
		}

		public function updateView():void{
			multiResSprite.updateViewport();			
			if(Setting.DEBUG){
				showAll = !showAll;
				if(showAll)
					multiResSprite.showAll();
				else		
					multiResSprite.hideAll();
			}			
		}

		private function onCompleteHandler(loadEvent:Event)
		{
//		    addChild(loadEvent.currentTarget.content);
			var content:DisplayObject = loadEvent.currentTarget.content;
			content.addEventListener(Event.ENTER_FRAME, function(e:Event):void{
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
		    
		    TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);
		}
		
		private function onProgressHandler(mProgress:ProgressEvent)
		{
			var percent:Number = mProgress.bytesLoaded/mProgress.bytesTotal;
			trace(percent);
		}		
	}
}