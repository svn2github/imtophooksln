package
{
	import de.johannesluderschmidt.demoObjects.Multitouchable;

	public class MTSqure extends Multitouchable
	{
		public function MTSqure(w:Number, h:Number)
		{
			super();
			graphics.beginFill(0xff0000, 1);
			graphics.drawRect(0, 0, w, h);
			graphics.endFill();
			
		}
		
	}
}