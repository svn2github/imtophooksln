package
{
    //------------------------------------------------------------------
    //
    //  Imports
    //
    //------------------------------------------------------------------

    import caurina.transitions.Tweener;
    
    import com.adobe.webapis.flickr.FlickrService;
    import com.adobe.webapis.flickr.PagedPhotoList;
    import com.adobe.webapis.flickr.Photo;
    import com.adobe.webapis.flickr.events.FlickrResultEvent;
    
    import flash.display.DisplayObject;
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.events.KeyboardEvent;
    import flash.geom.Point;
    
    import mx.events.FlexEvent;
    
    import org.openzoom.flash.components.MultiScaleContainer;
    import org.openzoom.flash.components.MultiScaleImage;
    import org.openzoom.flash.descriptors.IImagePyramidDescriptor;
    import org.openzoom.flash.descriptors.deepzoom.DeepZoomImageDescriptor;
    import org.openzoom.flash.renderers.images.ImagePyramidRenderer;
    import org.openzoom.flash.utils.ExternalMouseWheel;

	public class FlickrDeepZoom extends Sprite
	{
		
            //------------------------------------------------------------------
            //
            //  Constants
            //
            //------------------------------------------------------------------

            // From: http://www.flickr.com/services/api/flickr.people.getPublicPhotos.html
            private static const USER_ID:String = "72389028@N00";
            private static const EXTRAS:String = "o_dims, original_format";

            // From: http://www.flickr.com/services/api/misc.urls.html
//          private static const IMAGE_SIZE:Number = 240
//          private static const IMAGE_SUFFIX:String = "_m"
//          private static const IMAGE_SIZE:Number = 500
//          private static const IMAGE_SUFFIX:String = ""
            private static const IMAGE_SIZE:Number = 1024;
            private static const IMAGE_SUFFIX:String = "_b";

            private static const NUM_PHOTOS:uint = 500;

            //------------------------------------------------------------------
            //
            //  Variables
            //
            //------------------------------------------------------------------

            private var flickr:FlickrService;

            //------------------------------------------------------------------
            //
            //  Event handlers
            //
            //------------------------------------------------------------------
            		
//        private var container:MultiScaleImage;

		private var container:MultiScaleContainer;            		

		// Put your Flickr API key here...
		public static const FLICKR_API_KEY : String = "b2fa4d8feda11be321d8cd3ac9ee9178";
		
		// Put your Djakota resolver URL here...
//		public static const DJAKOTA_RESOLVER_URL : String = "http://localhost:8080/adore-djatoka/resolver"
            	
		public function FlickrDeepZoom()
		{			
			super();
						
			container = new MultiScaleContainer();
			container.sceneWidth = 48000;
			container.sceneHeight = 48000;
			addChild(container);
			applicationCompleteHandler(null);			
		}		
		
        private function applicationCompleteHandler(event:FlexEvent):void
        {
            // Enable mouse wheel support on Mac OS
            ExternalMouseWheel.initialize(stage);

            flickr = new FlickrService(FLICKR_API_KEY);
            flickr.addEventListener(FlickrResultEvent.PEOPLE_GET_PUBLIC_PHOTOS,
                                    flickr_peopleGetPublicPhotosHandler,
                                    false, 0, true);
            flickr.people.getPublicPhotos(USER_ID, EXTRAS, NUM_PHOTOS, 5);

            numColumns = container.sceneWidth / (IMAGE_SIZE * spacing);
        }

		private function flickrLoad(event:FlickrResultEvent):void{
            
//            if (!event.success)
//                return;
            			
            var photos:Array = PagedPhotoList(event.data.photos).photos as Array;
            addPhotos(photos);
            
            

            var page:uint = event.data.photos.page;
            var numPages:uint = event.data.photos.pages;
		}


        private function flickr_peopleGetPublicPhotosHandler(event:FlickrResultEvent):void
        {
            if (!event.success)
                return;

            if (!init)
            {
                stage.addEventListener(KeyboardEvent.KEY_DOWN, stage_keyDownHandler);
                init = true;                	
            }

            var photos:Array = PagedPhotoList(event.data.photos).photos as Array;
            addPhotos(photos);

            var page:uint = event.data.photos.page;
            var numPages:uint = event.data.photos.pages;

            trace("Page", page, "of", numPages);
            trace("Done.");
        }

        private var init:Boolean = false;
        private var column:int = 0;
        private var row:int  = 0;
        private var spacing:Number = 1.02;
        private var numColumns:int;

        private function addPhotos(photos:Array):void
        {
            for (var i:int = 0; i < photos.length; i++)
            {
                var photo:Photo = photos[i] as Photo;

                // Flickr photo URL:
                // http://farm{farm-id}.static.flickr.com/{server-id}/{id}_{o-secret}_o.(jpg|gif|png)

                var url:String = ["http://farm", photo.farmId,
                                  ".static.flickr.com/", photo.server, "/",
                                  photo.id, "_", photo.secret, IMAGE_SUFFIX, ".jpg"].join("");

                if (isNaN(photo.originalWidth) || isNaN(photo.originalHeight))
                    continue;

                var aspectRatio:Number = photo.originalWidth / photo.originalHeight;

                var imageWidth:Number = photo.originalWidth;
                var imageHeight:Number = photo.originalHeight;

                var photoDescriptor:IImagePyramidDescriptor;

                // http://static.gasi.ch/images/3128884923/image.xml 
                var descriptorXML:XML = <Image TileSize="256" Overlap="1" Format="jpg" xmlns="http://schemas.microsoft.com/deepzoom/2008">
                                            <Size Width={imageWidth} Height={imageHeight}/>
                                        </Image>;

                var path:String = "http://static.gasi.ch/images/" + photo.id + "/image.dzi";
                photoDescriptor = DeepZoomImageDescriptor.fromXML(path, descriptorXML);

                var scale:Number = 0.2;
                var renderer:ImagePyramidRenderer;
                renderer = new ImagePyramidRenderer();
                renderer.width = imageWidth * scale;
                renderer.height = imageHeight * scale;
                renderer.source = photoDescriptor;

                var size:Number = IMAGE_SIZE;
                var position:Point = new Point();
                position.x = column * size * spacing + (IMAGE_SIZE - renderer.width) / 2;
                position.y = row * size * spacing + (IMAGE_SIZE - renderer.height) / 2;

                renderer.x = position.x;
                renderer.y = position.y;

                container.addChild(renderer);

                if (++column >= numColumns)
                {
                    column = 0;
                    row++;
                }
            }
        }

        private function stage_keyDownHandler(event:KeyboardEvent):void
        {
            if (event.keyCode != 82) // R
                return;

            var options:Array = [arrangeRandomly,
                                 arrangeInCircle,
                                 arrangeInColumns,
                                 arrangeInRows];

            var index:uint = Math.floor(Math.random() * 1000) % options.length;
            var f:Function = options[index] as Function;
            f();
        }

        private function arrangeRandomly():void
        {
            for (var i:int = 0; i < container.numChildren; i++)
            {
                var child:DisplayObject = container.getChildAt(i);
                var position:Point = new Point();

                position.x = Math.random() * (container.sceneWidth - child.width);
                position.y = Math.random() * (container.sceneHeight - child.height);

                Tweener.addTween(child, {x: position.x,
                                         y: position.y,
                                         time: 0.5,
                                         transition: "easeOutQuad",
                                         delay: Math.random() * 0.15});
            }
        }

        private function arrangeInCircle():void
        {
            for (var i:int = 0; i < container.numChildren; i++)
            {
                var child:DisplayObject = container.getChildAt(i);
                var position:Point = new Point();

                // Circular
                var center:Point = new Point(container.sceneWidth / 2,
                                             container.sceneHeight / 2);
                var distance:Number = (0.5 + Math.random() * 0.5)
                                            * Math.min(container.sceneWidth - child.width,
                                                       container.sceneHeight - child.height);
                var angle:Number = Math.random() * 2 * Math.PI;
                position.x = center.x + Math.cos(angle) * distance / 3;
                position.y = center.y + Math.sin(angle) * distance / 3;

                Tweener.addTween(child, {x: position.x,
                                         y: position.y,
                                         time: 0.5,
                                         transition: "easeOutQuad",
                                         delay: Math.random() * 0.15});
            }
        }

        private function arrangeInColumns():void
        {
            var column:int = 0;
            var row:int = 0;
            var spacing:Number = 1.1;
            var numColumns:int = container.sceneWidth / (IMAGE_SIZE * spacing);

            for (var i:int = 0; i < container.numChildren; i++)
            {
                var child:DisplayObject = container.getChildAt(i);
                var position:Point = new Point();

                var size:Number = IMAGE_SIZE;
                position.x = column * size * spacing + (IMAGE_SIZE - child.width) / 2;
                position.y = row * size * spacing + (IMAGE_SIZE - child.height) / 2;

                Tweener.addTween(child, {x: position.x,
                                         y: position.y,
                                         time: 0.5,
                                         transition: "easeOutQuad",
                                          delay: Math.random() * 0.15});

                if (++column >= numColumns)
                {
                    column = 0;
                    row++;
                }
            }
        }

        private function arrangeInRows():void
        {
            var column:int = 0;
            var row:int  = 0;
            var spacing:Number = 1.05;
            var numRows:int = container.sceneHeight / (IMAGE_SIZE * spacing);

            for (var i:int = 0; i < container.numChildren; i++)
            {
                var child:DisplayObject = container.getChildAt(i);
                var position:Point = new Point();

                var size:Number = IMAGE_SIZE;
                position.x = column * size * spacing + (IMAGE_SIZE - child.width) / 2;
                position.y = row * size * spacing + (IMAGE_SIZE - child.height) / 2;

                Tweener.addTween(child, {x: position.x,
                                         y: position.y,
                                         time: 0.5,
                                         transition: "easeOutQuad",
                                         delay: Math.random() * 0.15});

                if (++row >= numRows)
                {
                    row = 0;
                    column++;
                }
            }
        }

        private function shakeItButton_clickHandler(event:Event):void
        {
            arrangeRandomly();
        }

        private function circularLayoutButton_clickHandler(event:Event):void
        {
            arrangeInCircle();
        }

        private function gridColumnsButton_clickHandler(event:Event):void
        {
            arrangeInColumns();
        }

        private function gridRowsButton_clickHandler(event:Event):void
        {
            arrangeInRows();
        }		
		
	}
}