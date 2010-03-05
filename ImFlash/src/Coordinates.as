package
{

	import flash.display.Sprite;
	import flash.events.MouseEvent;
	import flash.geom.Point;
	
	import org.openzoom.flash.components.MultiScaleImage;
	import org.openzoom.flash.descriptors.IMultiScaleImageDescriptor;
	
	
	public class Coordinates extends Sprite
	{
		
		private var image:MultiScaleImage;
		
		public function Coordinates()
		{

		    // Create MultiScaleImage component
		    image = new MultiScaleImage()
		
		    // Listen for complete event that marks that the
		    // loading of the image descriptor has finished
//		    image.addEventListener(Event.COMPLETE, image_completeHandler)
		    image.addEventListener(MouseEvent.CLICK, image_clickHandler, false, 0, true);
 		    image.source = "../libs/openzoom/resources/images/deepzoom/billions.xml"
 
                                   
//			MultiScaleImage
//	        id="image"
//	        source="../../../../resources/images/deepzoom/billions.xml"
//	        top="0"
//	        right="0"
//	        bottom="0"
//	        left="0"
		}

        private function image_clickHandler(event:MouseEvent):void
        {
            var componentPoint:Point = image.globalToLocal(new Point(event.stageX, event.stageY))
            trace("Click coordinates in component coordinates:", componentPoint)
            var scenePoint:Point = image.localToScene(componentPoint)

            // Remember: Scene dimensions != image dimensions (scene currently
            // has largest dimension == 16384 (2^14) for best rendering in Flash
            // Player, might change in the future, though).
            // Always normalize (map to [0, 1]) to scene through division by
            // scene dimensions (scene.sceneWidth & scene.sceneHeight) and
            // then map to image coordinates through multiplication with
            // descriptor dimensions (image.source.width & image.source.height)

            var descriptor:IMultiScaleImageDescriptor = image.source as IMultiScaleImageDescriptor
            if (descriptor)
            {
                var imagePoint:Point = scenePoint.clone()
                imagePoint.x /= image.sceneWidth
                imagePoint.y /= image.sceneHeight
                imagePoint.x *= descriptor.width
                imagePoint.y *= descriptor.height

                if (0 <= imagePoint.x && imagePoint.x <= descriptor.width &&
                    0 <= imagePoint.y && imagePoint.y <= descriptor.height)
                {
                    trace("Yay, you've clicked inside the image!")
                    trace("Click coordinates in scene coordinates:", scenePoint)
                    trace("Click coordinates in image coordinates:", imagePoint)
                }
            }
        }

	}
}