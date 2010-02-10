package impro.googlemap.events
{
	import flash.events.Event;
	import flash.geom.Point;
	
	public class HResEvent extends Event
	{
		public var TUIO_TYPE:String;
		public var sID:int;
		public var ID:int;
		public var rx1:Number;
		public var ry1:Number;
		public var rx2:Number;
		public var ry2:Number;
		public var oriPt1:Point;
		public var oriPt2:Point;
		public var oriPt3:Point;
		public var oriPt4:Point;
		
		public static const POSE_CHANGE:String = "impor.events.HResEvent.POSE_CHANGE";		

		
//---------------------------------------------------------------------------------------------------------------------------------------------	
// CONSTRUCTOR
//---------------------------------------------------------------------------------------------------------------------------------------------

		public function HResEvent(type:String, bubbles:Boolean = false, cancelable:Boolean = false, rx1:Number=0, ry1:Number=0, rx2:Number=0, ry2:Number=0, oriPt1:Point=null, oriPt2:Point=null, oriPt3:Point=null, oriPt4:Point=null, ID:int = -1, sID:int = -1)
		{
			this.TUIO_TYPE = TUIO_TYPE;
			this.sID = sID;
			this.ID = ID;		
			this.rx1 = rx1;
			this.ry1 = ry1;
			this.rx2 = rx2;
			this.ry2 = ry2;
			this.oriPt1 = oriPt1;
			this.oriPt2 = oriPt2;
			this.oriPt3 = oriPt3;
			this.oriPt4 = oriPt4;
			
			super(type, bubbles, cancelable);						
			//super(type, bubbles, cancelable, localX, localY, relatedObject, ctrlKey, altKey, shiftKey, buttonDown, delta);	
		}
		
//---------------------------------------------------------------------------------------------------------------------------------------------

	}
}