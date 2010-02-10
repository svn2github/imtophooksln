package flash.events
{
	import flash.geom.Point;	
	
	public class IMObject
	{		
		public var rx1:Number;
		public var ry1:Number;
		public var rx2:Number;
		public var ry2:Number;
		
		public var oriPt1:Point = new Point();
		public var oriPt2:Point = new Point();
		public var oriPt3:Point = new Point();
		public var oriPt4:Point = new Point();
		
		internal var ID:int;
		internal var sID:int;

		private var NEW:Boolean;	
		private static var EVENT_ARRAY:Array = new Array();			

		public function IMObject ($type:String, $id:int, $rx1:Number, $ry1:Number, $rx2:Number, $ry2:Number, $sid:int = -1)
		{
			//EVENT_ARRAY = new Array();
			ID = $id;
			rx1 = $rx1;
			ry1 = $ry1;
			rx2 = $rx2;
			ry2 = $ry2;
			sID = $sid;			
		}
		
		public function setOrignialPts(px1:Number, py1:Number, px2:Number, py2:Number, px3:Number, py3:Number, px4:Number, py4:Number):void{
			oriPt1.x = px1;
			oriPt1.y = py1;
			oriPt2.x = px2;
			oriPt2.y = py2;
			oriPt3.x = px3;
			oriPt3.y = py3;
			oriPt4.x = px4;
			oriPt4.y = py4;
			
			trace("IMObject[" + ID + "] SetOriginalPts");
		}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// INTERNAL METHODS
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		internal function notifyCreated():void
		{
			try
			{
				trace("IMObject[" + ID + "] Created");
			
			
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
			
			trace("IMObject[" + ID + "] Moved");
			
			var localPoint:Point;
			for(var i:int=0; i<EVENT_ARRAY.length; i++)
			{
//				localPoint = EVENT_ARRAY[i].parent.globalToLocal(new Point(x, y));			
				//trace("Notify moved"+ localPoint);
				EVENT_ARRAY[i].dispatchEvent(new HResEvent(HResEvent.POSE_CHANGE, true, false, rx1, ry1, rx2, ry2, oriPt1, oriPt2, oriPt3, oriPt4, ID, sID));	
			}
		}
		
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		public static function addListener(reciever:Object):void
		{
			for(var i:int = 0; i<EVENT_ARRAY.length; i++)
			{
				if(EVENT_ARRAY[i] == reciever)			
					return;
			}
			EVENT_ARRAY.push(reciever);
		}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		public static function removeListener(reciever:Object):void
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