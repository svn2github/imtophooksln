package
{
	import flash.display.Sprite;
	import flash.events.*;

	public class TouchCardApp extends Sprite
	{
		public function TouchCardApp()
		{
			super();
			
			this.addEventListener(TouchEvent.MOUSE_MOVE, this.moveHandler, false, 0, true);			
			this.addEventListener(TouchEvent.MOUSE_DOWN, this.downEvent, false, 0, true);						
			this.addEventListener(TouchEvent.MOUSE_UP, this.upEvent, false, 0, true);									
			this.addEventListener(TouchEvent.MOUSE_OVER, this.rollOverHandler, false, 0, true);									
			this.addEventListener(TouchEvent.MOUSE_OUT, this.rollOutHandler, false, 0, true);															
			
		}

		
		public function downEvent(e:TouchEvent)
		{		
		}
		
		public function upEvent(e:TouchEvent)
		{		
				
		}		

		public function moveHandler(e:TouchEvent)
		{
		}
		
		public function rollOverHandler(e:TouchEvent)
		{
		}
		
		public function rollOutHandler(e:TouchEvent)
		{
		
		}	
		
	}
}