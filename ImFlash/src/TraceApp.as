package
{
	import flash.display.Sprite;	
	
	public class TraceApp extends Sprite
	{
		public function TraceApp() 
		{
			trace("Debug Initialized");
			TUIO.init( this, 'localhost', 3000, '', true );
			var naturalTrace = new TraceCanvas();
			this.addChild(naturalTrace);
		}

	}
}