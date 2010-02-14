package de.johannesluderschmidt.event
{
	import flash.events.Event;

	public class GenericTapEvent extends Event
	{
		public static var DOUBLE_TAP = "onDoubleTap";
		
		public function GenericTapEvent(type:String)
		{
			super(type, true);
		}
		
	}
}