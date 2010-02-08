package
{
	import app.core.canvas.*;
	import app.demo.*;
	
	import flash.display.Sprite;
	import flash.events.TUIO;
	
    public class MyTouchApp extends Sprite {
 
		private var naturalPaint:PaintCanvas;

		public function MyTouchApp() {
		
//			TUIO.init( this, 'localhost', 3000, '', true );
			
//			this.addChild(new MyTouchApp2());
			this.addChild(new PaintCanvas());
//			this.addChild(new RippleCanvas());
//			this.addChild(new TouchCardApp());
			

		}
     }

}