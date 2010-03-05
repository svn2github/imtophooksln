package impro.openzoom
{
	import flash.events.Event;
	
	public class IMLowResEvent extends Event
	{
		public static var LRES_UPDATE:String = "lowResUpdate";
//		public var toBackObject:Object;
		
    	public function IMLowResEvent(type:String,
                                  bubbles:Boolean=false,
                                  cancelable:Boolean=false)
		{
			super(type, true); 
		}
		
	    /**
	     * @inheritDoc
	     */
	    override public function clone():Event
	    {
	        return new IMLowResEvent(type, bubbles, cancelable)
	    }			
	}
}