package de.johannesluderschmidt.tuio
{
	import flash.events.MouseEvent;		import flash.display.Sprite;
	import flash.display.DisplayObject;	
	import flash.geom.Point;

	public class TUIOObject 
	{
		public var x:Number;
		public var y:Number;
		public var oldX:Number;
		public var oldY:Number;		
		public var dX:Number;
		public var dY:Number;		
		public var area:Number = 0;	
		public var width:Number = 0;
		public var height:Number = 0;		
		public var TUIOClass:String;
		public var sID:int;
		public var ID:int;
		public var angle:Number;		
		public var pressure:Number;		
		private var isNew:Boolean;
		public var isAlive:Boolean;		
		public var obj:DisplayObject;
		public var spr:Sprite;
		public var trlx:Sprite;		
		public var color:int;
		public var startTime:Number;
		public var lastModifiedTime:Number;
		
		
		private var aListeners:Array;

		public function TUIOObject (cls:String, id:int, px:Number, py:Number, dx:Number, dy:Number, sid:int = -1, ang:Number = 0, ht:Number=0.0, wd:Number=0.0, o:Object = null)
		{
			aListeners = new Array();
			TUIOClass = cls;
			ID = id;
			x = px;
			y = py;
			oldX = px;
			oldY = py;
			dX = dx;
			dY = dy;
			sID = sid;
			angle = ang;
			isAlive = true;			
			width = wd;
			height = ht;
			area = ht * wd;

			spr = new TUIOCursor(ID.toString(),0xFFFFFF, int(area/-100000), int(ht/10000), int(ht/10000));			
			
			spr.x = x;
			spr.y = y;  		
			
			try {
 	 			obj = DisplayObject(o);
			} catch (e : Error)
			{
				obj = null;
			}
			
			isNew = true;
			
			var d:Date = new Date();
			
			startTime = d.time;
			lastModifiedTime = startTime;

		}
		
		public function notifyCreated() : void
		{
			if(obj)
			{
				try
				{
					var localPoint:Point = obj.parent.globalToLocal(new Point(x, y));				
//					trace("Down x: " + ((int)(x)) + ", Down y: " + y);
//					trace("Down localPoint.x: " + ((int)(localPoint.x)) + ", Down localPoint.y: " + localPoint.y);
					obj.dispatchEvent(new MouseEvent("click"));
					obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_DOWN, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));									
					obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_OVER, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));																		
				
					TUIOEventWatcher.getInstance().addTUIOObj(this);	
					
				} catch (e : Error)
				{
					trace("Failed : " + e);
//					trace(obj.name);
					obj = null;
				}
			}		
		}

		public function setObjOver(o:DisplayObject) : void
		{
			var localPoint:Point;
			try {
				
				if(obj == null)
				{
					obj = o;				
					if(obj) 
					{
						localPoint = obj.parent.globalToLocal(new Point(x, y));				
						obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_OVER, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));					
					}
				} else if(obj != o) 
				{

					localPoint = obj.parent.globalToLocal(new Point(x, y));
					obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_OUT, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));
					if(o)
					{
						localPoint = obj.parent.globalToLocal(new Point(x, y));
						o.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_OVER, true, false, ((int)(x)), ((int)(y)), localPoint.x, localPoint.y, 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));
					}
					obj = o;
				}
			} catch (e : Error)
			{
//				trace("ERROR " + e);
			}
		}
		
		public function addListener(reciever:Object) : void
		{
			for(var i:int = 0; i<aListeners.length; i++)
			{
				if(aListeners[i] == reciever)			
					return;
			}
			
			aListeners.push(reciever);
		}
		public function removeListener(reciever:Object) : void
		{
			for(var i:int = 0; i<aListeners.length; i++)
			{
				if(aListeners[i] == reciever)
					aListeners.splice(i, 1);
			}
		}
		
		public function kill() : void
		{
			TUIOEventWatcher.getInstance().removeTUIOObj(this);
			var localPoint:Point;			
			if(obj && obj.parent)
			{				
				localPoint = obj.parent.globalToLocal(new Point(x, y));				
				obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_OUT, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));				
				obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_UP, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle));									
			}			

			for(var i:int=0; i<aListeners.length; i++)
			{
				if(aListeners[i] != obj)
				{
					localPoint = aListeners[i].parent.globalToLocal(new Point(x, y));				
					aListeners[i].dispatchEvent(new TouchEvent(TouchEvent.MOUSE_UP, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, aListeners[i], false,false,false, true, 0, TUIOClass, ID, sID, angle));								
				}
			}

			obj = null;			
			
			aListeners = new Array();
		}
		
		public function notifyMoved() : void
		{
			//var d:Date = new Date();
			//lastModifiedTime = d.time;
			TUIOEventWatcher.getInstance().addTUIOObj(this);
			
			var localPoint:Point;
			for(var i:int=0; i<aListeners.length; i++)
			{
				localPoint = aListeners[i].parent.globalToLocal(new Point(x, y));			
				//trace("Notify moved"+ localPoint);
				aListeners[i].dispatchEvent(new TouchEvent(TouchEvent.MOUSE_MOVE, true, false, ((int)(x)),((int) (y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, aListeners[i], false,false,false, true, 0, TUIOClass, ID, sID, angle));	
			}			
		}
		
		// FIXME: we could use this function to replace a bunch of the stuff above.. 
		public function getTouchEvent(szeventname:String):TouchEvent
		{
			var localPoint:Point;
			
			if(obj && obj.parent)
			{
				localPoint = obj.parent.globalToLocal(new Point(x, y));							
			} else {
				localPoint = new Point(x, y);
			}
			

			return new TouchEvent(szeventname, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), 0, 0, obj, false,false,false, true, 0, TUIOClass, ID, sID, angle);
		}
	}
}