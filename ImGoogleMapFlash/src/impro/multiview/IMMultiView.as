package impro.multiview
{
	import flash.display.Sprite;
	import flash.utils.Dictionary;

	public class IMMultiView extends Sprite
	{
		private var renderTarget:Sprite;
		private var spriteMask:Sprite;
		
		private var viewportDict:Dictionary = new Dictionary();
		//-------------------------------------- DEBUG VARS			
		private var DEBUG:Boolean;				
		
		private var lresWidth:Number;
		private var lresHeight:Number;
		private var sourceScale:Number;
		private var renderTargetWidth:Number;
		private var renderTargetHeight:Number;				
		
		public function IMMultiView(renderTarget:Sprite, renderTargetWidth:Number, renderTargetHeight:Number, lresWidth:Number, lresHeight:Number, $DEBUG:Boolean = true)
		{
			super();
			DEBUG = $DEBUG;
				
			this.renderTarget = renderTarget;
			this.renderTargetWidth = renderTargetWidth;
			this.renderTargetHeight = renderTargetHeight;
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
			
			spriteMask = new Sprite();
			spriteMask.graphics.beginFill(0x000000);
			spriteMask.graphics.drawRect(0, 0, renderTargetWidth, renderTargetHeight);
			spriteMask.graphics.endFill();
			addChild(spriteMask);
			
			// add itself as the full view
			addViewport(-1, 0, 0, lresWidth, lresHeight, renderTargetWidth/2, renderTargetHeight/2, renderTargetWidth, renderTargetHeight);
		}	
						
		public function addViewport(id:Number, x:Number, y:Number, width:Number, height:Number, vpCx:Number = 50, vpCy:Number = 50, vpWidth:Number = 100, vpHeight:Number = 100):void{			
			var viewport:IMViewport = new IMViewport(renderTarget, renderTargetWidth, renderTargetHeight, x, y, width, height, vpCx, vpCy, vpWidth, vpHeight, DEBUG);			
			viewportDict[id] = viewport; 
			addChild(viewport);
			
			if(DEBUG){
				viewport.viewport.disableTouchListeners();
				addChild(viewport.viewport);				
			}				
		}
		
		public function hideAll():void{
			spriteMask.alpha = 0;
			for each (var viewport:IMViewport in viewportDict) 
                viewport.alpha = 0;			
		}
		public function showAll():void{
			spriteMask.alpha = 1;
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