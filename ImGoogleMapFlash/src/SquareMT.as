package
{
	import app.core.action.RotatableScalable;

	public class SquareMT extends RotatableScalable
	{
		public function SquareMT()
		{
			super();
			
			this.graphics.beginFill(0xff0000);
			this.graphics.drawRect(0,0,100,100);
			this.graphics.endFill();
		}
		
	}
}