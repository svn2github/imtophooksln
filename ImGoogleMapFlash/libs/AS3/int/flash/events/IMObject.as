package flash.events
{
	import flash.geom.Point;	
	
	public class IMObject
	{		
		public var rx1:Number;
		public var ry1:Number;
		public var rx2:Number;
		public var ry2:Number;
		internal var ID:int;
		internal var sID:int;

		private var NEW:Boolean;	
		private var EVENT_ARRAY:Array;			

		public function IMObject ($type:String, $id:int, $rx1:Number, $ry1:Number, $rx2:Number, $ry2:Number, $sid:int = -1)
		{
			EVENT_ARRAY = new Array();
			ID = $id;
			rx1 = $rx1;
			ry1 = $ry1;
			rx2 = $rx2;
			ry2 = $ry2;
			sID = $sid;			
		}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// INTERNAL METHODS
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		internal function notifyCreated():void
		{
			try
			{
				trace("IMObject Created");
			
			
			} catch (e:Error)
			{
				trace("Failed : " + e);
			}
		}		
		
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		internal function notifyMoved():void
		{
			//var d:Date = new Date();
			//lastModifiedTime = d.time;
			
			var localPoint:Point;
			for(var i:int=0; i<EVENT_ARRAY.length; i++)
			{
//				localPoint = EVENT_ARRAY[i].parent.globalToLocal(new Point(x, y));			
				//trace("Notify moved"+ localPoint);
				EVENT_ARRAY[i].dispatchEvent(new HResEvent(HResEvent.POSE_CHANGE, true, false, rx1, ry1, rx2, ry2, ID, sID));	
			}			
		}
		
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		internal function addListener(reciever:Object):void
		{
			for(var i:int = 0; i<EVENT_ARRAY.length; i++)
			{
				if(EVENT_ARRAY[i] == reciever)			
					return;
			}
			EVENT_ARRAY.push(reciever);
		}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		internal function removeListener(reciever:Object):void
		{
			for(var i:int = 0; i<EVENT_ARRAY.length; i++)
			{
				if(EVENT_ARRAY[i] == reciever)
					EVENT_ARRAY.splice(i, 1);
			}
		}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	}
}