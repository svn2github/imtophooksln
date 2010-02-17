package
{
	import de.johannesluderschmidt.demoObjects.MovableSquare;
	import de.johannesluderschmidt.tuio.TUIO;
	
	import flash.display.Sprite;
	import flash.text.TextField;
	import flash.text.TextFormat;
	
	import impro.IImproApp;
	import impro.Setting;
	import impro.multiview.IMMultiView;
	import impro.multiview.IMView;
	
	[SWF(width="1280", height="720", backgroundColor="#000000", frameRate="30")]
	public class MultiResSpriteTest extends Sprite implements IImproApp
	{
		private var multiResSprite:IMMultiView;
		private var showAll:Boolean = true;
		
		public function MultiResSpriteTest()
		{			
//			stage.addEventListener (KeyboardEvent.KEY_DOWN, keyDown);
			
			
//	        textField.embedFonts = true;
//			textField.selectable = false;
//			textField.height = textField.textHeight+5;
			
			var forSubmissionsTitle:String = "Call for Submissions";
			var forSubmissionsText:String = "Welcome to the SIGGRAPH 2010 Call for Submissions. Here you will find everything you need to submit your work to the world's pre-eminent conference on computer graphics and interactive techniques. No matter if this is your 1st or 31st SIGGRAPH, this 37th edition is guaranteed to instill WONDER in you like you've never experienced before. This year we are honoring The People Behind the Pixels, everyone who has a hand in inspiring, creating, producing, or teaching computer graphics and interactive techniques." +  
					"\nDowntown Los Angeles has also undergone a dramatic transformation since we were there in 2008, so look forward to more surprises after-hours as well. Make your plans now to submit your best work to SIGGRAPH 2010 and become one of The People Behind the Pixels!" + 
					"\n\n\nTerrence Masson" + 
					"\nSIGGRAPH 2010 Conference Chair" + 
					"\nNortheastern University";
			
			var forVolunteersTitle:String = "Call for Volunteers";
			var forVolunteersText:String = "ACM SIGGRAPH is a volunteer-driven organization, and the SIGGRAPH conference is a volunteer-driven conference. We welcome motivated and enthusiastic people who enjoy helping others, working with exceptional and supportive colleagues, and contributing to the vitality and ongoing development of the field of computer graphics and interactive techniques. Volunteering for SIGGRAPH is also a wonderful opportunity for personal and professional growth." + 
					"\n\nGraphicsNet" + 
					"\nPutting on a SIGGRAPH conference requires a level of networking beyond the norm for conferences and trade shows, and this infrastructure is created by the GraphicsNet team. GraphicsNet is always open to network engineers who love computer graphics and the energy and experience that is a SIGGRAPH conference." + 
					"n\nStudent Volunteers" + 
					"\nThis unique opportunity is available to high school, college, post-secondary, or post-graduate students who want to volunteer behind the scenes of a world-class conference. Student Volunteers dedicate 18 or 30 hours in exchange for full conference access (when not on duty) and additional exclusive student-volunteer-only mentoring and professional development events." + 
					"\n\nFuture Conference Committees" + 
					"\nThe conference chair, conference directors, program chairs, project leads, committee members, jurors, and reviewers are all volunteers. They are members and leaders of the computer graphics community who value SIGGRAPH and want to give back to it.";
			
			var forAttendeesTitle:String = "For Attendees"; 
			var forAttendeesText:String = "SIGGRAPH 2010 in Los Angeles: the best place in the world to experience the explosive evolution of computer graphics and interactive techniques. See, meet, and interact with the People Behind the Pixels who are creating the next wave of international excellence in research, animation, art, software, visualization, hardware, games, visual effects, and education. Gain amazing insights, enrich your skill set, and expand your worldwide contacts." + 
					"\nCheck back here often for updates. Program details will be available here beginning in April." + 
					"\n\nTerrence Masson" +
					"\nSIGGRAPH 2010 Conference Chair" + 
					"\nNortheastern University";
			
			var forMediaTitle:String = "For the Media";
			var forMediaText:String = "Welcome to the media section of the SIGGRAPH 2010 web site. As conference plans develop, this is the best source for all the information you need:" + 
					"\nNews releases, fact sheets, exhibitor news, media-only events, media registration, travel, and housing." + 
					"\nPlease bookmark this page and check it often for updates." + 
					"\nFrequent updates are also available via Twitter and RSS.";

			var callForSubmissions:Sprite = CallFOrSomething(600, 400, forSubmissionsTitle, forSubmissionsText);
			var callForVolunteers:Sprite = CallFOrSomething(600, 400, forVolunteersTitle, forVolunteersText);
			callForVolunteers.x = 50 + callForSubmissions.x + callForSubmissions.width
			var callForAttendees:Sprite = CallFOrSomething(600, 400, forAttendeesTitle, forAttendeesText);
			callForAttendees.x = callForSubmissions.x;
			callForAttendees.y = callForSubmissions.y + callForSubmissions.height;
			var forMedia:Sprite = CallFOrSomething(600, 400, forMediaTitle, forMediaText);
			forMedia.x = callForVolunteers.x;
			forMedia.y = callForVolunteers.y + callForVolunteers.height;
			
			var plate:Sprite = new Sprite();
			
//			var content:Multitouchable = new Multitouchable();
//			var content:MovableSquare = new MovableSquare(0x0000ff);
			var content:Sprite = new Sprite();
			content.graphics.beginFill(0x00ff00);
			content.graphics.drawRect(0,0,50,50);
			content.graphics.endFill();
			content.addChild(callForSubmissions);
			content.addChild(callForVolunteers);
			content.addChild(callForAttendees);
			content.addChild(forMedia);
			
			plate.addChild(content);
//			
//			// add low resolution view			
			multiResSprite = new IMMultiView(plate, 1366, 768, false, Setting.LRes.stageWidth, Setting.LRes.stageHeight, Setting.DEBUG);						

			// add high resolution views
			for each (var view:IMView in Setting.HRes) 
				multiResSprite.addViewport(view.id, view.stageX, view.stageY, view.stageWidth, view.stageHeight);
			
			addChild(multiResSprite);			
			
			multiResSprite.updateViewport();
			
			TUIO.init(new IMView(-2, 0, 0, 1366, 768), this, 'localhost', 3000, '', Setting.DEBUG);
		}
		
		public function close():void{
			TUIO.startSocket();	
		}
				
		public function updateView():void{
			multiResSprite.updateViewport();			
			if(Setting.DEBUG){
				showAll = !showAll;
				if(showAll)
					multiResSprite.showAll();
				else		
					multiResSprite.hideAll();
			}			
		}
		
//		private function keyDown (e:KeyboardEvent):void {			
//			multiResSprite.updateViewport();			
//			if(Setting.DEBUG){
//				showAll = !showAll;
//				if(showAll)
//					multiResSprite.showAll();
//				else		
//					multiResSprite.hideAll();
//			}
//		}
		
		private function CallFOrSomething(_width:Number, _height:Number, title:String, content:String):Sprite{
			var callforSprite:Sprite = new Sprite();			
			var callforTitle:TextField = new TextField();
			callforTitle.text = title;
			callforTitle.setTextFormat(new TextFormat("Verdana", 20, 0xFFFFFF, true));
			callforTitle.wordWrap = true;
			callforTitle.border = true;
			callforTitle.x = 10;
			callforTitle.y = 10;
			callforTitle.width = _width;
			
			var callforText:TextField = new TextField();
			callforText.text = content;					
			callforText.setTextFormat(new TextFormat("Verdana", 14, 0xFFFFFF, true));
			callforText.x = callforTitle.x;
			callforText.y = callforTitle.y + 40;			
			callforText.border = true;
			callforText.background = false;
			callforText.multiline = true;
			callforText.wordWrap = true;
			callforText.width = _width;
			callforText.height = _height;
						
			callforSprite.addChild(callforTitle);
			callforSprite.addChild(callforText);
			return callforSprite;
		}
		
	}
}