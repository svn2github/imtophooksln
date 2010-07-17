package de.johannesluderschmidt.event
{
	import flash.events.Event;

	public class BringToFrontEvent extends Event
	{
		public static var DO:String = "bringToFront";
		public var toFrontObject:Object;
		
		public function BringToFrontEvent(type:String, toFrontObject:Object)
		{
			super(type, true);
			this.toFrontObject = toFrontObject; 
		}
		
	}
}