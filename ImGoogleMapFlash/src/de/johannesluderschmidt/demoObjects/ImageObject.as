package de.johannesluderschmidt.demoObjects
{

	import flash.display.*;
	import flash.events.Event;
	import flash.events.IOErrorEvent;
	import flash.net.URLRequest;
	import flash.system.LoaderContext;
	
	public class ImageObject extends Multitouchable 
	{		
		
		public static var counter:Number = 1;
		public var index:Number;
		
		public var doubleTapEnabled: Boolean;
		
		private var progressBar:Sprite = new Sprite();	
		private var photoLoader:Loader = null;		
		
		private var _isFullscreen:Boolean = false;
		private var oldPosX:Number;
		private var oldPosY:Number;
		private var oldSizeX:Number;
		private var oldSizeY:Number;
		
		private var imageSprite:Sprite;
		private var background:Sprite;
		
		private var onLoadComplete:Function;		
		private var imageWidth:Number
		private var imageHeight:Number
		
		public function ImageObject (url:String, onLoadComplete:Function)
		{
			index = counter++;
			this.onLoadComplete = onLoadComplete;
			
			photoLoader = new Loader();		

//			photoLoader.contentLoaderInfo.addEventListener( ProgressEvent.PROGRESS, onProgressHandler);	
			photoLoader.contentLoaderInfo.addEventListener( Event.COMPLETE, arrange, false, 0, true);	
			photoLoader.contentLoaderInfo.addEventListener( IOErrorEvent.IO_ERROR, onIOError);
			var context:LoaderContext = new LoaderContext();
			context.checkPolicyFile = true;
			
//			progressBar.graphics.beginFill(0xFFFFFF,1);
//			progressBar.graphics.drawRect(0, 0, 25, 100);
//			progressBar.graphics.endFill();				
			    
			var request:URLRequest = new URLRequest( url );				
	
			photoLoader.unload();
			photoLoader.load( request , context);		
			
			background = new Sprite();
			background.alpha = 0;
						
			imageSprite = new Sprite();
			addChild(background);
			addChild(imageSprite);				
			
			/*
			addEventListener(GenericTapEvent.DOUBLE_TAP,function(event:Event):void{
				trace("double tap");
				if(!_isFullscreen){
					showFullscreen();
				}else{
					hideFullscreen();
				}
				_isFullscreen = !_isFullscreen;
				
				
			});
			*/
						
		}
//		private function onProgressHandler(mProgress:ProgressEvent)
//		{	
//		var percent:Number = -100*(mProgress.target.bytesLoaded/mProgress.target.bytesTotal);
//		//progressBar.alpha=percent;			
//		///trace(percent);
//		}
		
		public function highlight(DO:Boolean):void{
			if(DO){
				background.alpha = 1;
			}else{
				background.alpha = 0;
			}
		}
		
		public function getImageWidth():Number{
			return imageWidth;
		}
		public function getImageHeight():Number{
			return imageHeight;
		}
		
		private function arrange( event:Event = null ):void 
		{							
			this.alpha = 1;
//			photoLoader.x = -photoLoader.width/2;
//			photoLoader.y = -photoLoader.height/2;			
			
			var image:Bitmap = Bitmap(photoLoader.content);
			image.smoothing=true;
			
			var myBitmap : BitmapData = new BitmapData(image.width, image.height,false,0xffffffff);
//			var myBitmap : BitmapData = new BitmapData(Flickr.photoWidth, Flickr.photoHeight, false,0xffffffff);			
			myBitmap.draw(image);
			
			var m:Number = 4;
			var m2:Number = m*2;			
//			background.graphics.beginFill(0xffffff);
//			background.graphics.drawRect(-m, -m, image.width+m2, image.height+m2);
//			background.graphics.drawRect(-m, -m, myBitmap.width, myBitmap.height+m2);
//			background.graphics.endFill();

//			imageSprite.addChild(image);
			imageSprite.graphics.beginBitmapFill(myBitmap, null, false, true);
			imageSprite.graphics.lineStyle(0, 0x00, 0);
			var min:Number = Math.min(image.width, image.height)
            imageSprite.graphics.drawRect(0, 0, image.width, Math.min(image.width, image.height));
            imageSprite.graphics.endFill();
			
//			var m:Number = 4;
//			var m2:Number = m*2;			
//			graphics.beginFill(0x646464);
//			graphics.drawRect(-m, -m, image.width+m2, image.height+m2);
//			graphics.endFill();			
//			graphics.beginFill(0xffffff);
//			graphics.drawRect(-m, -m, image.width+m2, image.height+m2);
//			graphics.endFill();
			

			
//			graphics.beginBitmapFill(myBitmap,null,true,true);
//			graphics.lineStyle(0, 0x00, 0);
//            graphics.drawRect(0, 0, image.width, image.height);
//            graphics.endFill();
			
			handleAddedToStage(null);
			
			
			this.imageWidth = image.width;
//			this.imageHeight = image.height;
			this.imageHeight = Math.min(image.width, image.height);
			onLoadComplete.call(this, this);
		}				
		
		/*
		private function showFullscreen():void{
			oldPosX = x;
			oldPosY = y;
			oldSizeX = width;
			oldSizeY = height;
					
			var t : Transitioner = new Transitioner(0.5);
			
			var targetX:Number = 0;
			var targetY:Number = 0;
			var targetWidth:Number;
			var targetHeight:Number;
			if(width > height){
				var factor:Number = Constants.STAGE_WIDTH/width;
				targetWidth = Constants.STAGE_WIDTH;
				targetHeight = height*factor;
				targetX = 0;
				targetY = Constants.STAGE_HEIGHT/2-targetHeight/2;
			}else{
				var factorHeight:Number = Constants.STAGE_HEIGHT/height;
				targetWidth = width * factorHeight;
				targetHeight = Constants.STAGE_HEIGHT;
				targetX = Constants.STAGE_WIDTH/2 - targetWidth/2;
				targetY=0;
			}
			t.$(this).alpha = 1;
			t.$(this).x = targetX;
			t.$(this).y = targetY;
			t.$(this).width = targetWidth;
			t.$(this).height = targetHeight; 
			t.play();
		}
		private function hideFullscreen():void{
			var t : Transitioner = new Transitioner(0.5);
			t.$(this).alpha = 1;
			t.$(this).x = oldPosX;
			t.$(this).y = oldPosY;
			t.$(this).width = oldSizeX;
			t.$(this).height = oldSizeY; 
			t.play();
		}
		*/
		
		function onIOError(e:Event)
		{
			trace(e);
		}
	}
}