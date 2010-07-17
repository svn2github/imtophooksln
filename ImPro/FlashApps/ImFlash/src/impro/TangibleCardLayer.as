package impro
{
	import flash.display.Sprite;
	import flash.events.*;

	public class TangibleCardLayer extends Sprite
	{
		
//		private var tangibleDownCounter:Number = 0;
		private var tangibles:Array = new Array();
//		private var tangibleDict:Dictionary = new Dictionary();	
		
		public function TangibleCardLayer()
		{
			super();

			addEventListener(TouchEvent.MOUSE_DOWN, onTangibleDown);			
			
			
			
			this.graphics.beginFill(0xff0000, 0.5);
			this.graphics.drawRect(0,0,200,200);
			this.graphics.endFill();
			
		}
		
		private function onTangibleDown(e:TouchEvent):void{
			if(e.TUIO_TYPE == "2Dobj"){
				trace("onTangibleDown 2Dobj " + e.ID);
								
				// test if contain.. 
				if(!isTangibleAdded(e.ID)){
					var tangible:Object;
					tangible = {id: e.ID, x: e.localX, y:e.localY, sid:e.sID, a:e.angle};				
					tangibles.push(tangible);				
					addEventListener(Event.ENTER_FRAME, handleEnterFrame);					
				}				
				trace("tangibles.length: " + tangibles.length);	
			}			
		}
		
		private function isTangibleAdded(id:Number):Boolean{
			var exist:Boolean = false;
			for each(var tangible:Object in tangibles)
				if(!exist && tangible.id == id)
					exist = true;
				
			return exist;
		}
		
		protected function handleEnterFrame(e:Event):void {
			trace("handleEnterFrame");
			
			if(!tangibles)
				return;
			trace("tangibles.length: " + tangibles.length);		
			if(tangibles.length == 2){
				trace("tangibles.length == 2");
			}
			
			for each(var tangible:Object in tangibles){
				trace(tangible.id);
				
				var tuioobj : TUIOObject = TUIO.getObjectById(tangible.id);
				if(tuioobj){
					trace("tangible[" + tangible.id+"] exist");
				}else{
					trace("tangible["+ tangible.id+"] removed");
					TUIO.getObjectById(tangible.id);
					var index:Number = tangibles.indexOf(tangible);
					tangibles.splice(index, 1);
					trace("after remove tangibles.length: " + tangibles.length);	
				}
			}
			
			if(tangibles.length == 0){
//				removeEventListener(TouchEvent.MOUSE_UP, localMouseUp);
				removeEventListener(Event.ENTER_FRAME, handleEnterFrame);				
			}
		}
	}
}