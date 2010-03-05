package impro.events
{
	import de.johannesluderschmidt.demoObjects.ImageObject;
	
	import flash.events.Event;

	public class FlickrEvent extends Event
	{
		public static var PHOTO_LOADED:String = "photo_loaded";
		public var imgObj:ImageObject;
		
		
		public function FlickrEvent(type:String, imgObj:ImageObject)
		{
//			super(type, bubbles, cancelable);
			super(type, true);
			this.imgObj = imgObj;			
		}		
	}
}