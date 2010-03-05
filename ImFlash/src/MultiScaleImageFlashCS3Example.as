﻿/*    MultiScaleImage Component    OpenZoom SDK Example    http://openzoom.org/    Developed by Daniel Gasienica <daniel@gasienica.ch>    License: MPL 1.1/GPL 3/LGPL 3*/package{//import fl.controls.Button;import caurina.transitions.Tweener;import flash.display.GradientType;import flash.display.Graphics;import flash.display.SpreadMethod;import flash.display.Sprite;import flash.events.*;import flash.geom.Matrix;import flash.utils.Dictionary;import impro.Setting;import impro.googlemap.ViewportControl;import impro.openzoom.IMLowResEvent;import impro.openzoom.IMMultiScaleContainer;import org.openzoom.flash.descriptors.IImagePyramidDescriptor;import org.openzoom.flash.descriptors.deepzoom.DeepZoomImageDescriptor;import org.openzoom.flash.renderers.images.ImagePyramidRenderer;import org.openzoom.flash.viewport.constraints.ScaleConstraint;import org.openzoom.flash.viewport.controllers.IMTouchController;import org.openzoom.flash.viewport.transformers.TweenerTransformer;[SWF(width=1200, height=768, frameRate=24)]public class MultiScaleImageFlashCS3Example extends Sprite{	private var viewportWidth:Number = 600;	private var viewportHeight:Number = 450;	private var vpControl:ViewportControl;	private var containerDict:Dictionary = new Dictionary();	    private var scaleConstraint:ScaleConstraint;	private var toNextTransform:Function;    public function MultiScaleImageFlashCS3Example()    {    // Setup stage//    stage.align = StageAlign.TOP_LEFT;//    stage.scaleMode = StageScaleMode.NO_SCALE;//    stage.addEventListener(Event.RESIZE, stage_resizeHandler);				stage.addEventListener(KeyboardEvent.KEY_DOWN, onKey);		//Type of Gradient we will be using		var fType:String =  GradientType.LINEAR;		//Colors of our gradient in the form of an array		var colors:Array = [ 0xF1F1F1, 0xEB7F00 ];		//Store the Alpha Values in the form of an array		var alphas:Array = [ 1, 1 ];		//Array of color distribution ratios.  		//The value defines percentage of the width where the color is sampled at 100%		var ratios:Array = [ 0, 255 ];		//Create a Matrix instance and assign the Gradient Box		var matr:Matrix = new Matrix();		    matr.createGradientBox( 600, 450, -90*Math.PI/180, 0, 0 );		//SpreadMethod will define how the gradient is spread. Note!!! Flash uses CONSTANTS to represent String literals		var sprMethod:String = SpreadMethod.PAD;		//Start the Gradietn and pass our variables to it		var sprite:Sprite = new Sprite();		//Save typing + increase performance through local reference to a Graphics object		var g:Graphics = sprite.graphics;		    g.beginGradientFill( fType, colors, alphas, ratios, matr, sprMethod );		    g.drawRect( 0, 0, 600, 450 );		addChild( sprite );						addContainers();				var lResContainer:IMMultiScaleContainer = (containerDict["container1"] as IMMultiScaleContainer);		var height:Number = lResContainer.sceneHeight/2 - 4620/2; 				var path:String = "I:/bigPic"; 		addRender(path + "/k2a00111003/dzc_output.xml", 25000*(2), height, 25000, 4620);		addRender(path + "/k2a00111004/dzc_output.xml", 25000*(1), height, 25000, 4620);		addRender(path + "/k2a00111002/dzc_output.xml", 25000*(3), height, 25000, 4620);		addRender(path + "/k2a00111005/dzc_output.xml", 25000*(0), height, 25000, 4620);		addRender(path + "/k2a00111001/dzc_output.xml", 25000*(4), height, 24800, 4620);				// easing options: http://hosted.zeh.com.br/tweener/docs/en-us/misc/transitions.html	    var transformer:TweenerTransformer = new TweenerTransformer();	    transformer.easing = "easeOutQuint"; //"easeOutQuint";	    transformer.duration = 3; // seconds	    lResContainer.transformer = transformer;	    	    toNextTransform = function():void{		    var transformer:TweenerTransformer = new TweenerTransformer();		    transformer.easing = "easeOutQuint"; //"easeOutQuint";		    transformer.duration = 0.2; // seconds		    (containerDict["container1"] as IMMultiScaleContainer).transformer = transformer;	    };	    Tweener.addTween(this, {time:3, onComplete:toNextTransform});	    		lResContainer.zoomBy(14);	    this.addEventListener(IMLowResEvent.LRES_UPDATE,	                                   imLResUpdateHandler,	                                   false, 0, true)//imLResUpdateHandler		//		addRender("../libs/openzoom/resources/images/deepzoom/billions.xml", 0, 0, 3872, 2592);//		addRender("../libs/openzoom/resources/images/deepzoom/ilamp01.xml", 0, 0, 4128, 2752);//		addRender("../libs/openzoom/resources/images/bigPic/Exported Data/girlset01/GeneratedImages/dzc_output_images/girls1.xml", 0, 0, 25000, 2863);	//		addRender("http://seadragon.com/content/images/bike.dzi", 4300, 0, 2600, 2000);//		addRender("http://seadragon.com/content/images/milwaukee.dzi", 0, 2900, 3872, 1300);//		addRender("http://seadragon.com/content/images/angkorwat.dzi", 4000, 2100, 3872, 800);//		addRender("http://seXadragon.com/content/images/BlueMarble.dzi", 0, 4300, 2600, 1300);		//		addRender("http://seadragon.com/content/images/YosemitePano1.dzi", 4000, 3000, 2100, 250);//		addRender("http://seadragon.com/content/images/colorflower.dzi", 4000, 3300, 2592, 2592);							    vpControl = new ViewportControl("container2", updateCallback, 300, 250, 100, 100);		addChild(vpControl);			//	    var square:Sprite = new Sprite();//	    square.graphics.beginFill(0xff0000, 0.3);//	    square.graphics.drawRect(0, 0, viewportWidth, viewportHeight);//	    square.graphics.endFill();//	    square.x = viewportWidth;//		addChild(square);	//    renderer.x = 20;//    renderer.y = 0;    }        // impro    private function imLResUpdateHandler(event:IMLowResEvent):void{//    	trace("imLResMovedHandler(event:IMLowResEvent)");    	updateHResViews(vpControl);    }	private function onKey(event:KeyboardEvent):void{		trace("keydown");//		(containerDict["container1"] as IMMultiScaleContainer).zoomBy(2);		this.updateHResViews(vpControl);			}        private function addContainers():void{		var container1:IMMultiScaleContainer = genContainer(0, viewportWidth, viewportHeight, true);        containerDict["container1"] = container1;//		container1.controllers = [new IMMouseController()];		container1.controllers = [new IMTouchController()];	    //		container1.constraint = new ScaleConstraint();//		var visibilityConstraint:VisibilityConstraint = new VisibilityConstraint();//		visibilityConstraint.visibilityRatio = 0.6;//		container1.constraint = visibilityConstraint;                 	var container2:IMMultiScaleContainer = genContainer(viewportWidth, viewportWidth, viewportHeight, false);	    containerDict["container2"] = container2;	    	        	//	    (containerDict["container1"] as IMMultiScaleContainer).zoomBy(2);//	    container1.zoomBy(2);//	    container2.zoomBy(2);	            addChild(container1);	    addChild(container2);    		TUIO.init(Setting.LRes, this, 'localhost', 3000, '', Setting.DEBUG);    }        private function genContainer(windowX:Number, viewportWidth:Number, viewportHeight:Number, isLResView:Boolean = true):IMMultiScaleContainer {	    var container: IMMultiScaleContainer = new IMMultiScaleContainer(isLResView);	    //	    if(containerDict["container1"])//	    	(containerDict["container1"] as IMMultiScaleContainer).zoomBy(2);	    	    container.setActualSize(viewportWidth, viewportHeight);	    container.x = windowX;	    var mask:Sprite = new Sprite();	    mask.graphics.beginFill(0x000000);	    mask.graphics.drawRect(windowX, 0, viewportWidth, viewportHeight);	    mask.graphics.endFill();		container.mask = mask;		return container;    	    }        private function addRender(path:String, imageX:Number, imageY:Number, imageWidth:Number, imageHeight:Number):void{    	    	for each (var container:IMMultiScaleContainer in containerDict){		    var photoDescriptor:IImagePyramidDescriptor;		    var descriptorXML:XML = <Image TileSize="256" Overlap="1" Format="jpg" xmlns="http://schemas.microsoft.com/deepzoom/2009">			                            <Size Width={imageWidth} Height={imageHeight}/>		                            </Image>;		    photoDescriptor = DeepZoomImageDescriptor.fromXML(path, descriptorXML);		    var renderer:ImagePyramidRenderer;		    renderer = new ImagePyramidRenderer();		    renderer.x = imageX;		    renderer.y = imageY;		    renderer.width = imageWidth;		    renderer.height = imageHeight;		    renderer.source = photoDescriptor;    			    		    container.addChild(renderer);    		    	}     }        public function updateHResViews(_vpControl:ViewportControl):void{		var container1:IMMultiScaleContainer = containerDict["container1"];		var vp1X:Number = container1.viewportX;		var vp1Y:Number = container1.viewportY;		var vp1W:Number = container1.viewportWidth;		var vp1H:Number = container1.viewportHeight;		var vp1Z:Number = container1.zoom;    	var dx:Number = (_vpControl.x - _vpControl.w /2) / viewportWidth / vp1Z;    	var dy:Number = (_vpControl.y - _vpControl.h /2) / viewportHeight / vp1Z;    	    	var dw:Number = _vpControl.w / viewportWidth / vp1Z;    	var dh:Number = _vpControl.h / viewportHeight / vp1Z;				// High Res				var container:IMMultiScaleContainer = containerDict[_vpControl.getID()];    	container.viewportX = vp1X + dx;    	container.viewportY = vp1Y + dy;    	    	var value:Number = Math.max(dw, dh);    	container.viewportWidth = value;    	    	if(dw > dh){    		container.scaleX = 1;    		container.scaleY = dw / dh;    	}else{    		container.scaleX = dh / dw;    		container.scaleY = 1;    	}    	    }        public function updateCallback(_vpControl:ViewportControl):void{    	updateHResViews(_vpControl);    	    }        // Event handlers    private function stage_resizeHandler(event:Event):void    {//        layout();    }    private function image_completeHandler(event:Event):void    {//        var descriptor:IMultiScaleImageDescriptor = image.source as IMultiScaleImageDescriptor;////        if (descriptor)//        {//            scaleConstraint.maxScale = descriptor.width / image.sceneWidth;//                                 // or descriptor.height / image.sceneHeight,//                                 // as they're supposed to be the same//        }    }    private function zoomOutButton_clickHandler(event:Event):void    {        // Zoom out by a factor of 2//        image.zoom /= 2;    }    private function zoomInButton_clickHandler(event:Event):void    {        // Zoom in by a factor of 1.8//        image.zoom *= 1.8;    }    private function showAllButton_clickHandler(event:Event):void    {//        image.showAll();    }    // Layout    private function layout():void    {//        if (image)//        {//            image.width = stage.stageWidth/3;//            image.height = stage.stageHeight;//        }//        //        if(image2){//        	image2.x = stage.stageWidth/2;//        	image2.y = 0;//            image2.width = stage.stageWidth/2;//            image2.height = stage.stageHeight;//        }////        zoomInButton.x = stage.stageWidth - zoomInButton.width - 10//        zoomInButton.y = stage.stageHeight - zoomInButton.height - 10////        zoomOutButton.x = zoomInButton.x - zoomOutButton.width - 4//        zoomOutButton.y = zoomInButton.y////        showAllButton.x = zoomOutButton.x - showAllButton.width - 4//        showAllButton.y = zoomOutButton.y    }}}