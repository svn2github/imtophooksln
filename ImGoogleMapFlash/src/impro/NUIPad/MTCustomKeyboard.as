package impro.NUIPad
{
	import app.core.action.RotatableScalable;
	import flash.display.Sprite;
	import flash.events.*;
	
  	/**
	 * ...
	 * @author Amit 	http://amitsarangi.wordpress.com
	 * @version 0.1
	 * 
	 **/
	
	public class MTCustomKeyboard extends RotatableScalable
	{
		public static const TOGGLE_KEY_TEXT:String = "Fix KeyBoard";
		public static const FIX_KEY_TEXT:String = "Fix Keys";
		
		// The base which holds all the Buttons ,basically the parent container of all the buttons
		var keyboardBase:Sprite = new Sprite(); 
		//Keyboard fix Button
		var keyboard_fix_btn:MTButton = new MTButton(TOGGLE_KEY_TEXT, 110, 30);
		// Key Fix Button
		var key_fix_btn:MTButton = new MTButton(FIX_KEY_TEXT, 110, 30);
		//variable holding the value of all the letters of the keys on the keyboard
		var keys:Array;
		//variable holding thr value of all the Buttons on the keyboard
		var buttons:Array=new Array;

		public function MTCustomKeyboard(args:Array,_width:Number=650,_height:Number=260) 
		{
			
//Draw the base
			keyboardBase.graphics.beginFill(0xffffff, 0.4);
			keyboardBase.graphics.lineStyle( 1, 0x000000 );
			keyboardBase.graphics.drawRoundRect( 0, 0, _width, _height , 15 );
			addChild(keyboardBase);
			
			this.x = 100;
			this.y = 100;
			
			keyboard_fix_btn.x = 680;
			keyboard_fix_btn.y = 30;
			keyboard_fix_btn.noMove = true;
			keyboard_fix_btn.noRotate = true;
			keyboard_fix_btn.noScale = true;
			keyboardBase.addChild(keyboard_fix_btn);
			keyboard_fix_btn.addEventListener(TouchEvent.MOUSE_DOWN, toggleKeyboardFix);
			
			key_fix_btn.x = 680;
			key_fix_btn.y = 100;
			key_fix_btn.noMove = true;
			key_fix_btn.noRotate = true;
			key_fix_btn.noScale = true;
			keyboardBase.addChild(key_fix_btn);
			key_fix_btn.addEventListener(TouchEvent.MOUSE_DOWN,toggleKeyFix);
			
			keys = args;
			for (var i:Number=0; i < keys.length;i++ )
			{
				//Creating buttons and adding it to the keyboard base and setting their x,y coordinate
				buttons[i] = new MTButton(keys[i], 40, 40);
				keyboardBase.addChild(buttons[i]);
//				buttons[i].x = Math.random() * (_width-160);
//				buttons[i].y = Math.random() * (_height-80);
			}
		}

		// Toggles the keyboard fix . i.e sets the noMove property of the keyboard
		private function toggleKeyboardFix(event:TouchEvent):void
		{
			this.noMove = !this.noMove;
		}
		// Toggles the buttons fix . i.e sets the noMove property of the buttons os that they can be made movable or not movable
		private function toggleKeyFix(event:TouchEvent):void
		{
			for (var i:Number = 0; i < buttons.length;i++ )
			{
			buttons[i].noMove = !buttons[i].noMove;
			}
		}
		
		// Gets button instance by name of the button , So that you can set the 
		public function getButtonByName(name:String):MTButton
		{
			return buttons[keys.indexOf(name)];
		}
		
		// A Private function to addKey which can be used in the classes extending the present class (Like MTFullKeyboard)
		public function addKey(key:String,_width:Number,_height:Number):void
		{
			buttons.push(new MTButton(key, _width, _height));
			keys.push(key);
			keyboardBase.addChild(buttons[buttons.length-1])
		}
	}
}