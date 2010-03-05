package de.johannesluderschmidt.event
{
	import flash.events.Event;

	public class BringToBackEvent extends Event
	{
		public static var DO:String = "bringToBack";
		public var toBackObject:Object;
		
		public function BringToBackEvent(type:String, toBackObject:Object)
		{
			super(type, true);
			this.toBackObject = toBackObject; 
		}
		
	}
}