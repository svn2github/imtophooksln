package impro.multiview
{
	import flash.display.DisplayObject;
	import flash.display.Sprite;
	import flash.utils.Dictionary;
	import flash.events.Event;

	import impro.googlemap.events.HResEvent;
	import de.johannesluderschmidt.tuio.TUIO;
	
	public class IMMultiView extends Sprite
	{
		private var renderTarget:DisplayObject;
		private var renderTargetMask:Sprite;
		
		private var viewportDict:Dictionary = new Dictionary();
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		
		private var lresWidth:Number;
		private var lresHeight:Number;
		private var sourceScale:Number;
		private var renderTargetWidth:Number;
		private var renderTargetHeight:Number;				
		private var renderTargetAsLRes:Boolean;
		
		public function IMMultiView(renderTarget:DisplayObject, renderTargetWidth:Number, renderTargetHeight:Number, useRenderTargetAsLRes:Boolean, lresWidth:Number, lresHeight:Number, $DEBUG:Boolean = true)
		{
			super();
			DEBUG = $DEBUG;
				
			this.renderTarget = renderTarget;
			this.renderTargetWidth = renderTargetWidth;
			this.renderTargetHeight = renderTargetHeight;
			this.renderTargetAsLRes = useRenderTargetAsLRes;
			this.lresWidth = lresWidth;
			this.lresHeight = lresHeight;
			
			//			
//			if(DEBUG){
//				theSprite.graphics.beginFill(0x0000ff, 1);			
//				theSprite.graphics.drawRect(0, spriteHeight/2, spriteWidth, 5);
//				theSprite.graphics.drawRect(spriteWidth/2, 0, 5, spriteHeight);
//				theSprite.graphics.endFill();
//			}									
						
			addChild(renderTarget);
			
			if(useRenderTargetAsLRes){
				if(renderTarget.width !=0 && renderTarget.height != 0){
					var scaleX:Number = lresWidth / renderTarget.width; 
					var scaleY:Number = lresHeight / renderTarget.height
					renderTarget.scaleX = scaleX;
					renderTarget.scaleY = scaleY;
				}
			}
			else
			{
			// add itself as the full view
				renderTargetMask = new Sprite();
				renderTargetMask.graphics.beginFill(0x000000);
				renderTargetMask.graphics.drawRect(0, 0, renderTargetWidth, renderTargetHeight);
				renderTargetMask.graphics.endFill();
				addChild(renderTargetMask);				
				addViewport(-1, 0, 0, lresWidth, lresHeight, renderTargetWidth/2, renderTargetHeight/2, renderTargetWidth, renderTargetHeight);				
			}
			
			this.addEventListener(HResEvent.POSE_CHANGE, hresPosChange);
			TUIO.addIMObjectListener(this);
						
		}	
		
		private function hresPosChange(e:Event):void{
			
			var he:HResEvent = e as HResEvent;
//			trace(he.ID + ": " + he.rx1 + ", "+ he.ry1 + ", "+ he.rx2 + ", "+ he.ry2);
			getViewport(he.ID).setViewportBound(he.rx1, he.ry1, he.rx2, he.ry2);			
			getViewport(he.ID).setViewportOriPts(he.oriPt1, he.oriPt2, he.oriPt3, he.oriPt4);
			getViewport(he.ID).update();
		}		
						
		public function addViewport(id:Number, x:Number, y:Number, width:Number, height:Number, vpCx:Number = 50, vpCy:Number = 50, vpWidth:Number = 100, vpHeight:Number = 100):void{			
			var viewport:IMViewport = new IMViewport(renderTarget, renderTargetWidth, renderTargetHeight, x, y, width, height, vpCx, vpCy, vpWidth, vpHeight, DEBUG);			
			viewportDict[id] = viewport; 
			addChild(viewport);
			
			if(DEBUG){
//				viewport.viewport.disableTouchListeners();
				addChild(viewport.viewport);				
			}				
		}
		
		public function hideAll():void{
			if(renderTargetMask!=null)
				renderTargetMask.alpha = 0;
			for each (var viewport:IMViewport in viewportDict) 
                viewport.alpha = 0;			
		}
		public function showAll():void{
			if(renderTargetMask!=null)
				renderTargetMask.alpha = 1;
			for each (var viewport:IMViewport in viewportDict) 
                viewport.alpha = 1;			
		}
				
		public function updateViewport():void{
			for each (var viewport:IMViewport in viewportDict) 
                viewport.updateCallback();
		}

		public function getViewport (id:Number):IMViewport{
			return viewportDict[id];
		}				
	}
}