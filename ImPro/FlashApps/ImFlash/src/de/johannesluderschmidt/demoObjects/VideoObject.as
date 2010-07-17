package de.johannesluderschmidt.demoObjects
{
	
	import flash.display.*;
	import flash.events.Event;
	import flash.media.Video;
	import flash.net.*;
	
	import impro.events.VideoEvent;


	public class VideoObject extends Multitouchable
	{
		public static var counter:Number = 1;
		public var index:Number;

		private var theStage:DisplayObjectContainer;		

		private var imageSprite:Sprite;
		private var background:Sprite;
		private var bitmap:Bitmap;
		private var bitmapData:BitmapData;
		private var imageWidth:Number
		private var imageHeight:Number
		private var url:String;
		private var vid:Video;

		public function VideoObject(url:String, theStage:DisplayObjectContainer)
		{
			index = counter++;
			this.theStage = theStage;
			this.url = url;
			
			background = new Sprite();
			background.alpha = 0;
						
			bitmapData = new BitmapData(320, 240);
			bitmap = new Bitmap(bitmapData);
//			imageSprite = new Sprite();
//			addChild(background);
			addChild(bitmap);	
			
			arrange();			
			
		}

		private function arrange( event:Event = null ):void 
		{							
			this.alpha = 1;

//			var mRequest:URLRequest = new URLRequest("./assets/swf/Conservative.swf");

			var nc:NetConnection = new NetConnection();
			nc.connect(null);
			var ns:NetStream = new NetStream(nc);
			
			vid = new Video(320, 240);
			vid.cacheAsBitmap = true;
//			addChild(vid);
						
			vid.attachNetStream(ns);
			ns.play(url);

			vid.addEventListener(Event.ENTER_FRAME, copyData);

			var netClient:Object = new Object();
			netClient.onMetaData = function(meta:Object)
			{
			        trace(meta.duration);
			};
			ns.client = netClient;
//			
			handleAddedToStage(null);
//			dispatchEvent(new VideoEvent(VideoEvent.VIDEO_LOADED, this));
		}
		
		private function copyData(e:Event):void{
			trace("copy");
//			bitmapData.draw(vid);
			
//			imageSprite.graphics.beginBitmapFill(vid, null, false, true);
//			imageSprite.graphics.lineStyle(0, 0x00, 0);
//            imageSprite.graphics.drawRect(0, 0, 320, 240);
//            imageSprite.graphics.endFill();			
		}

	}
}