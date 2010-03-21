package impro.element
{
//	import com.nui.tuio.TouchEvent;
	import flash.events.TouchEvent;
	import flash.events.Event;
	import flash.display.MovieClip;
//	import com.tweener.transitions.Tweener;
		
	public class IMTouchButton extends MovieClip {
	
		public function IMTouchButton()
		{
			alpha = 1;			
//			this.addEventListener(TouchEvent.MOUSE_DOWN, this.tuioDownEvent);						
//			this.addEventListener(TouchEvent.MOUSE_UP, this.tuioUpEvent);									
//			buttonMode = true;
//			useHandCursor = true;
			
		}

		public function tuioDownEvent(e:TouchEvent)
		{
			trace("Button Down");
//			Tweener.addTween(this, {rotation:360, time:0.3, transition:"linear"});		
			//Tweener.addTween(this, {_blur_blurX:50, _blur_quality:2, time:1, transition:"linear"});
		}
		public function tuioUpEvent(e:TouchEvent)
		{
			trace("Button Up");		

		}
//		public function rollOverHandler(e:TouchEvent)
//		{
//			trace("Button Over");		
//			Tweener.addTween(this, {alpha:0.2, time:0.5, transition:"easeinoutquad"});
//		}
//		public function rollOutHandler(e:TouchEvent)
//		{
//			trace("Button Out");
//			Tweener.addTween(this, {alpha:1, time:1, transition:"easeinoutquad"});
//		}		
	}
}