package impro.multiview
{
	public class IMView
	{
		public var id:String;
		public var stageX:Number;
		public var stageY:Number;
		public var stageWidth:Number;
		public var stageHeight:Number;
		
		public function IMView(id:String, stageX:Number, stageY:Number, stageWidth:Number, stageHeight:Number)
		{
			this.id = id;
			this.stageX = stageX;
			this.stageY = stageY;
			this.stageWidth = stageWidth;
			this.stageHeight = stageHeight;
		}
	}
}