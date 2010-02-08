package
{
	import flash.display.*;
	import flash.events.*;
	import flash.geom.*;
	import flash.net.*;	
	
//	[SWF(width=1366, height=500, frameRate=24, backgroundColor=0xEB7F00)]
	public class MyTouchApp2 extends Sprite {//allows it to be scaled around
		
		private var sq:Sprite = new Sprite();
		
		public function MyTouchApp2()
		{
			//--------connect to TUIO-----------------
			TUIO.init(this,'localhost',3000,'',true);
			trace("MyTouchApp Initialized");
			//----------------------------------------        
			
			var map:TappableMap = new TappableMap();
			map.key = "ABQIAAAA1Xc_0qFDwhVg0qsY959yExRcR7IumtuiL9gAiOhCPfe14dC1HBSpTjOFiyNExylutyalkkjAIFFIZw";
			map.setSize(new Point(500,500));
			this.addChild(map);
			
			sq.graphics.beginFill(0xff0000);
			sq.graphics.drawRect(0,0,100,100);
			sq.graphics.endFill();
			sq.x = sq.y = 150;
			this.addChild(sq);			
			
			var ssq:SquareMT = new SquareMT();
			ssq.x = sq.y = 50;
			this.addChild(ssq);
			
			sq.addEventListener(TouchEvent.MOUSE_DOWN, this.sqTouchDown, false, 0, true);
			sq.addEventListener(TouchEvent.MOUSE_OVER, this.sqTouchOver, false, 0, true);
			sq.addEventListener(TouchEvent.MOUSE_UP, this.sqTouchUp, false, 0, true);
			
			this.addEventListener(TouchEvent.MOUSE_MOVE, this.touchDown, false, 0, true);			
			this.addEventListener(TouchEvent.MOUSE_DOWN, this.touchDown, false, 0, true);		
		}

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