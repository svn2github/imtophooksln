﻿package de.johannesluderschmidt.util{	
	
	
	import de.johannesluderschmidt.demoObjects.ImageObject;
	
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.net.URLLoader;
	import flash.net.URLRequest;
	import flash.net.URLVariables;

	import com.greensock.*;
	import com.greensock.easing.*;

	public class Flickr extends Sprite
	{
		public var photoWidth:Number;
		
		private var index:int = 0;		
		private var rest:URLLoader = null;
		private var flickr:XML = null;
		private var thestage:Sprite;
		private var fetchCount:Number;
		private var allPics:Array;	
		public var photo:ImageObject;
		private var plateWidth:Number;
		private var plateHeight:Number;
		
		private var margin:Number = 20;
		private var curX:Number = margin;
		private var curY:Number = margin;
		private var maxHeightInRow:Number = 0;
		
		public function Flickr(d:Sprite, width:Number, height:Number, fetchIn:Number, photoWidth:Number) 
		{
			thestage = d;
			fetchCount = fetchIn;
			this.plateWidth = width;
			this.plateHeight = height;
			this.photoWidth = photoWidth;
			allPics = new Array();
		
		}
		
		//type:String, 
		public function fetch(getRecent:Boolean = true, tags:String = null):void 
		{			
			clearPics();
			var request:URLRequest = 
			new URLRequest( "http://api.flickr.com/services/rest/" );
			var variables:URLVariables = new URLVariables();
//			variables.api_key = "566c6aa058a2b4aa13f1b6ddc9bfd582";
			variables.api_key = "b2fa4d8feda11be321d8cd3ac9ee9178";

			if(getRecent)
			{
				variables.method = "flickr.photos.getRecent";
			} 
			else 
			{
//				variables.method = "flickr.photosets.getPhotos";
//				variables.photoset_id = type;
//				variables.method = "flickr.photos.getRecent";
				variables.method = "flickr.photos.search";
//				variables.method = "flickr.photos.search";
				variables.machine_tag_mode = "any";
//				variables.user_id = "47459528@N04";
//				variables.tags = "moneyNotArt";

				if(tags!=null)
					variables.tags = tags;
			}
			request.data = variables;
			rest = new URLLoader();
			rest.addEventListener( "complete", parse , false, 0, true);
			rest.load( request );
		}
			
		private function parse( event:Event ):void 
		{			
			flickr = new XML( rest.data );
			showPics();
		}

		private function showPics2():void 
		{	
			var id:String = null;
			var secret:String = null;
			var server:String = null;			
			var url:String = null;
			var request:URLRequest = null;			
			
			var len:int = flickr..photo.length();
		
			if(len > fetchCount)
				len = fetchCount;
			
			for(var i:int=0; i<len; i++)
			{
				server = flickr..photo[i].@server.toString();
				id = flickr..photo[i].@id.toString();
				secret = flickr..photo[i].@secret.toString();
				
				// Assemble the URL and request
				url = 	"http://static.flickr.com/" + server + "/" + id + "_" + 
						secret + ".jpg";
		
				
				photo = new ImageObject( url, addPics);				
				photo.name="ImageObject_"+i;
				photo.scaleX = 0.7 + 0.3*Math.random();
				photo.scaleY = photo.scaleX;
				photo.x = (Math.random()*plateWidth) - plateWidth/2;
				photo.y = (Math.random()*plateHeight) - plateHeight/2;								
				allPics.push(photo);
				
				thestage.addChild(photo);
			}
		}
		
		private function showPics():void 
		{	
			var id:String = null;
			var secret:String = null;
			var server:String = null;			
			var url:String = null;
			var request:URLRequest = null;		
			
			var len:int = flickr..photo.length();
		
			if(len > fetchCount)
				len = fetchCount;
			
			var margin:Number = 20;
			var _x:Number = margin;
			var _y:Number = margin;
			var _imgW:Number = 400;
			
			for(var i:int=0; i<len; i++)
			{
				server = flickr..photo[i].@server.toString();
				id = flickr..photo[i].@id.toString();
				secret = flickr..photo[i].@secret.toString();
				
				// Assemble the URL and request
				url = 	"http://static.flickr.com/" + server + "/" + id + "_" + 
						secret + ".jpg";
								
				photo = new ImageObject( url, addPics);				
				photo.name="ImageObject_"+i;
//				photo.scaleX = 0.6;
//				photo.scaleY = 0.6;
//				photo.scaleX = 0.7 + 0.3*Math.random();
//				photo.scaleY = photo.scaleX;
//				photo.x = (Math.random()*plateWidth) - plateWidth/2;
//				photo.y = (Math.random()*plateHeight) - plateHeight/2;
				
//				if((_x+_imgW) > plateWidth){
//					_x = margin;
//					_y += (_imgW + margin);
//				}
				
//				photo.x = _x;
//				photo.y = _y;
				
//				_x += (_imgW + margin);
								
//				allPics.push(photo);				
//				thestage.addChild(photo);
			}
		}		
		
		private function addPics(obj:Object):void{
			
			var imObj:ImageObject = obj as ImageObject;
			var imgW:Number = imObj.getImageWidth();
			var imgH:Number = imObj.getImageHeight();
			var scale:Number = photoWidth / imgW;
			imObj.scaleX = scale;
			imObj.scaleY = scale;
			
			if((curX + photoWidth) > plateWidth){
				curX = margin;
				curY += (maxHeightInRow + margin);
				maxHeightInRow = 0;
			}else{
				maxHeightInRow = Math.max(imgH*scale, maxHeightInRow); 
			}
			
//			curX += margin;
//			imObj.x = curX;
//			imObj.y = curY;
			imObj.x = 0;
			imObj.y = 0;
//			TweenLite.to(imObj, 4, {x:curX, y:curY, ease:Elastic.easeOut});
						
			curX += (photoWidth + margin);

			trace("addPics[" + imObj.name + "]: (" + imObj.x + ", " + imObj.y + ")");

			allPics.push(imObj);				
			thestage.addChild(imObj);
			
			
		}
		
		public function clearPics():void
		{
			for(var i:int = 0; i<allPics.length; i++)
			{
				thestage.removeChild(allPics[i]);
			}			
			allPics = new Array();
		}
		
//		public function getAllPics():Array{
//			return allPics;
//		}

	}
}