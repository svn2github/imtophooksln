package 
{
	import flash.display.DisplayObject;
	import flash.events.Event;	
	
	public class HResEvent extends Event
	{
		public var TUIO_TYPE:String;
		public var sID:int;
		public var ID:int;
		public var regionX:Number;
		public var regionY:Number;
		public var regionWidth:Number;
		public var regionHeight:Number;
		
		public static const POSE_CHANGE:String = "impor.events.HResEvent.POSE_CHANGE";		

		
//---------------------------------------------------------------------------------------------------------------------------------------------	
// CONSTRUCTOR
//---------------------------------------------------------------------------------------------------------------------------------------------
		public function HResEvent(type:String, bubbles:Boolean = false, cancelable:Boolean = false, regionX:Number=0, regionY:Number=0, regionWidth:Number=0, regionHeight:Number=0, ID:int = -1, sID:int = -1)
		{
			this.TUIO_TYPE = TUIO_TYPE;
			this.sID = sID;
			this.ID = ID;		
			this.regionX = regionX;
			this.regionY = regionY;
			this.regionWidth = regionWidth;
			this.regionHeight = regionHeight;
			
			super(type, bubbles, cancelable);						
			//super(type, bubbles, cancelable, localX, localY, relatedObject, ctrlKey, altKey, shiftKey, buttonDown, delta);	
		}
//---------------------------------------------------------------------------------------------------------------------------------------------

	}
}