package
{
	import de.johannesluderschmidt.demoObjects.VideoObject;
	
	import flash.display.*;
	import flash.events.*;
	import flash.geom.*;
	import flash.net.*;
	
	import impro.googlemap.*;
	import impro.multiview.IMView;
	
//	[SWF(width=1366, height=500, frameRate=24, backgroundColor=0xEB7F00)]
	public class MyTouchApp2 extends Sprite {//allows it to be scaled around
		
		private var sq:Sprite = new Sprite();
		
		var bitmap:Bitmap;
		var bitmapData:BitmapData;
		var vid:VideoObject;
		
		public function MyTouchApp2()
		{
			//--------connect to TUIO-----------------
			TUIO.init(new IMView(-1, 0, 0, 1024, 768) , this, 'localhost',3000,'',true);
			trace("MyTouchApp Initialized");
			//----------------------------------------        
			
			
			vid = new VideoObject("file:///C:/flv/test.flv", this);
//			this.addChild(vid);
			
			
			bitmapData = new BitmapData(320, 240);			
			bitmap = new Bitmap(bitmapData);
			addChild(bitmap);
						
			this.addEventListener(Event.ENTER_FRAME, function(e:Event):void{
				bitmapData.draw(vid);
			});
			

			
//			var mRequest:URLRequest = new URLRequest("./assets/swf/Conservative.swf");
//			var netClient:Object = new Object();
//			netClient.onMetaData = function(meta:Object)
//			{
//			        trace(meta.duration);
//			};
//			ns.client = netClient;
//			
//			ns.addEventListener(NetStatusEvent.NET_STATUS, netstat);
			
		}

		function netstat(stats:NetStatusEvent)
		{
    		trace(stats.info.code);
		};

		public function sqTouchOver(e:TouchEvent):void{
			trace("touch sq");
		}

		public function sqTouchDown(e:TouchEvent):void{
			trace("touch sq down");
			e.target.startDrag(false);
		}
		
		public function sqTouchUp(e:TouchEvent):void{
			trace("touch sq up");
			e.target.stopDrag();
		}		
		
		public function touchDown(e:TouchEvent):void {
 
//			var curPt:Point=parent.globalToLocal(new Point(e.stageX,e.stageY));//convert touch points to x,y                
//			var circle:Sprite = new Sprite();//create a new sprite
// 
//			circle.graphics.lineStyle(10, 0xff0000);//set line width to 10px and red
//			circle.graphics.drawCircle(0,0,40);// draw a 40px circle
//			circle.x=curPt.x;//put it where touch is (x cord)
//			circle.y=curPt.y;//put it where touch is (y cord)
//			addChild(circle);//add the circle where touch happened
		}
	}
}