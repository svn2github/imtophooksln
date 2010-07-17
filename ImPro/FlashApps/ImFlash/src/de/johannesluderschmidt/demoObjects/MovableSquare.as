package de.johannesluderschmidt.demoObjects
{
	import de.johannesluderschmidt.controller.TouchEventsManager;
	import de.johannesluderschmidt.event.BringToFrontEvent;
	
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.geom.Point;
	
	public class MovableSquare extends Multitouchable
	{
		
		
		public function MovableSquare(color:Number = 0xcccccc)
		{
			graphics.beginFill(color,0.8)
			graphics.drawRect(0,0,100,100);
			graphics.endFill();
			
			addEventListener(Event.ADDED_TO_STAGE, handleAddedToStage);
		}
	}
}