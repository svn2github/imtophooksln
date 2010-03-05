package impro.events
{
	import de.johannesluderschmidt.demoObjects.VideoObject;
	import flash.events.Event;

	public class VideoEvent extends Event
	{
		public static var VIDEO_LOADED:String = "video_loaded";
		public var vidObj:VideoObject;
		
		public function VideoEvent(type:String, vidObj:VideoObject)
		{
			super(type, true);
			this.vidObj = vidObj;						
		}
		
	}
}