package 
{
	import flash.display.Sprite;
	import flash.display.StageDisplayState;
	import flash.events.TUIO;
	
	import impro.Setting;
	import impro.multiview.IMView;
	import impro.NUIPad.*;
	
	[SWF(width="1024", height="768", frameRate="31", backgroundColor="#333333")]
	
	/**
	 * ...
	 * @author Amit
	 * http://amitsarangi.wordpress.com
	 */
	
	public class NUIPad extends Sprite 
	{
		var editor = new MTEditor();
		public function NUIPad():void
		{		
			//--------Connect to TUIO-----------------
	            TUIO.init(new IMView("-1", 0, 0, 1024, 768), this, 'localhost', 3000, "", Setting.DEBUG);
	//            TUIO.init(this,'localhost',3000,'',true);
	            trace("Application Initialized");
	        //----------------------------------------
	//		stage.displayState = StageDisplayState.FULL_SCREEN;
	
			var rect:Sprite= new Sprite();
//			rect.graphics.beginFill(0x333333,1);
//			rect.graphics.drawRect(0,0,900,500);
			this.addChild(rect);
	
			rect.addChild(editor);
			editor.x = 80;
			editor.y = 30;
		}
	}
}