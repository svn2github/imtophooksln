package de.johannesluderschmidt.util{	
		
	import de.johannesluderschmidt.demoObjects.ImageObject;
	
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.net.URLLoader;
	import flash.net.URLRequest;
	import flash.net.URLVariables;
	
	import impro.events.FlickrEvent;

	public class Flickr extends Sprite
	{
		public var photoWidth:Number;
		
		private var index:int = 0;		
		private var rest:URLLoader = null;
		private var flickr:XML = null;
		private var thestage:Sprite;
		private var fetchCount:Number;
		private var allPics:Array;			
		
		public function Flickr(d:Sprite, fetchIn:Number) 
		{
			thestage = d;
			fetchCount = fetchIn;
			
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

//		private function showPics2():void 
//		{	
//			var id:String = null;
//			var secret:String = null;
//			var server:String = null;			
//			var url:String = null;
//			var request:URLRequest = null;			
//			
//			var len:int = flickr..photo.length();
//		
//			if(len > fetchCount)
//				len = fetchCount;
//			
//			for(var i:int=0; i<len; i++)
//			{
//				server = flickr..photo[i].@server.toString();
//				id = flickr..photo[i].@id.toString();
//				secret = flickr..photo[i].@secret.toString();
//				
//				// Assemble the URL and request
//				url = 	"http://static.flickr.com/" + server + "/" + id + "_" + 
//						secret + ".jpg";
//		
//				
//				photo = new ImageObject( url, null);				
//				photo.name="ImageObject_"+i;
//				photo.scaleX = 0.7 + 0.3*Math.random();
//				photo.scaleY = photo.scaleX;
//				allPics.push(photo);
//				
//				thestage.addChild(photo);
//			}
//		}
		
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
				
				var photo:ImageObject = new ImageObject(url, this.stage);				
				photo.name="ImageObject_"+i;
//				photo.scaleX = 0.6;
//				photo.scaleY = 0.6;
//				photo.scaleX = 0.7 + 0.3*Math.random();
//				photo.scaleY = photo.scaleX;
//				photo.x = (Math.random()*plateWidth) - plateWidth/2;
//				photo.y = (Math.random()*plateHeight) - plateHeight/2;
								
				allPics.push(photo);
				thestage.addChild(photo);
			}
		}		
		
		private function photoLoaded(e:FlickrEvent):void{
			trace(e.imgObj.name);
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