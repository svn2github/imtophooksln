package impro.NUIPad
{
	import flash.events.TouchEvent;
	import flash.events.KeyboardEvent;
	
  	/**
	 * ...
	 * @author Amit 	http://amitsarangi.wordpress.com
	 * @version 0.1
	 * 
	 **/
	
	public class MTKeyboard extends MTCustomKeyboard   // Extends the custom keyboard class which extends RotatableScalable. See custom keyboard class for more
	{
		// Alphabets to be added in the keyboard
		var alphabet:Array = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"];
		
		//Numberpad
		var numbers:Array = ["`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "[", "]", "\\", ";", "'", ",", ".", "/"];
		
		// Numbers to appear when Shift key is pressed (For now it is replaced by Caps key)
		var numbersReplaceText:Array = ["~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "{", "}", "|", ":", "\"", "&lt;", ">", "?"];
		
		//The keys those do not type the letters on the buttons
		var specialKeys:Array = ["Tab", "Caps", "Shift", "Enter", "Ctrl", "Alt", "Ctrl ", "Alt ", " ", "Up", "Down", "Left", "Right", "<--"];
		
		//Are the number keys replaced by replacement letters (i.e does ! appear in place of 1)
		var numbersReplaced:Boolean = false;
		
		public var shift:Boolean = false; // Is shift key pressed ?
		public var ctrl:Boolean = false; //Is ctrl key pressed ?
		public var alt:Boolean = false; //Is alt key pressed ?
		public var capslk:Boolean = false; //Is caps lock On ?
		
		public function MTKeyboard(_width:Number=650,_height:Number=260)
		{
			
// args variable defined in the CustomKeyboard class which this class inherits . These do not include the special keys and the ones whose keys are of different length
			var args:Array = ["`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "&lt;--", "[", "]", "\\", ";", "'", ",", ".", "/"];
			
			super(args, _width, _height);
			
			keyboardBase.removeChild(key_fix_btn);  // Removing key fix button because in a full keyboard we can not unfix the keys to change its position
			keyboardBase.removeChild(keyboard_fix_btn);
			
//Special Keys Adding look @ addKey method
			addKey("Tab", 40, 40);	
			addKey("Caps", 64, 40);		
			addKey("Enter", 64, 40);
			addKey("Shift", 84, 40);
			addKey("Ctrl", 64, 40);
			addKey("Alt", 64, 40);
			addKey("Ctrl ", 64, 40); //Added a " " character in the end to have two Ctrl Keys
			addKey("Alt ", 64, 40);	 //Added a " " character in the end to have two Alt Keys
			addKey(" ", 210, 40); // Spacebar
			addKey("Up", 40, 40);
			addKey("Down", 40, 40);
			addKey("Left", 40, 40);
			addKey("Right", 40, 40);
//Special Keys Adding End

// Aligns keys in the keyboard acc to their position in the actual keyboard
			alignKeys();
			
			for (var i:Number = 0; i < args.length;i++ )
			{
				// Setting all the button's noRotate,noMcale and noMove property
				
				getButtonByName(args[i]).noRotate = true;
				getButtonByName(args[i]).noMove = true;
				getButtonByName(args[i]).noScale = true;
				
				//Adding event listenner so that on press this will send the keyboard event required
				getButtonByName(args[i]).addEventListener(TouchEvent.MOUSE_DOWN, dispacthMTdownEvent);
			}
//Adding event listener to special keys 			
			getButtonByName("Shift").addEventListener(TouchEvent.MOUSE_DOWN,ShiftKeyDown);
			getButtonByName("Shift").addEventListener(TouchEvent.MOUSE_UP,ShiftKeyUp);
			
		    getButtonByName("Ctrl").addEventListener(TouchEvent.MOUSE_DOWN, CtrlKey);
			getButtonByName("Ctrl").addEventListener(TouchEvent.MOUSE_UP,CtrlKey);
			getButtonByName("Ctrl ").addEventListener(TouchEvent.MOUSE_DOWN, CtrlKey);
			getButtonByName("Ctrl ").addEventListener(TouchEvent.MOUSE_UP, CtrlKey);
			
			getButtonByName("Alt").addEventListener(TouchEvent.MOUSE_DOWN, AltKey);
			getButtonByName("Alt").addEventListener(TouchEvent.MOUSE_UP,AltKey);
			getButtonByName("Alt ").addEventListener(TouchEvent.MOUSE_DOWN, AltKey);
			getButtonByName("Alt ").addEventListener(TouchEvent.MOUSE_UP,AltKey);

			getButtonByName("Caps").addEventListener(TouchEvent.MOUSE_DOWN, CapsLockKey);
// Adding Event listener finished
		}

// A public function to get the buttons on the keyboard as Array. This returns an Array of MTButton instances
		public function getAllButtons():Array
		{
			return buttons;
		}

//The event handler to send keyboard events 
		private function dispacthMTdownEvent(event:TouchEvent)
		{
			var buttonText:String = event.currentTarget.getText();// The text on MTButton's textfield
			
			if (specialKeys.indexOf(buttonText)==-1) // if not a sepcial key send the keyboard event with charcode=the charcode of buttonText
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,buttonText.charCodeAt(0),0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Tab") // Similarly for tab
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,9,0,0,ctrl,alt,shift));
			}
			else if (buttonText==" ") // For spacebar
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,32,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="<--") // For backspace
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,8,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Up") // For up key
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,38,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Down") // For down key
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,40,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Left") // Left key
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,37,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Right") // Right key
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,39,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Ctrl") // Ctrl key
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,17,0,0,ctrl,alt,shift));
			}
			else if (buttonText=="Ctrl ") // Ctrl key (alternative)
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,17,0,0,ctrl,alt,shift));
			}		
			else if (buttonText=="Enter") // Enter key
			{
			dispatchEvent(new KeyboardEvent(KeyboardEvent.KEY_DOWN,true,false,13,0,0,ctrl,alt,shift));
			}
		}
		
/*		
		private function replaceAll():void
		{
			replaceNumbers();
			for each(var key:String in alphabet)
			{
				var text:String;
				if (!alphabetsReplaced)
				{
					text = key.toLowerCase();
				}
				else
				{
					text = key;
				}
				getButtonByName(key).replaceText(text);
			//	trace(text);
			}
			numbersReplaced = !numbersReplaced;
		}
*/
		
//		Replaces numbers in the keypad with the value When SHIFT key is pressed (now when Caps is pressed)
		private function replaceNumbers():void
		{
			for each(var key:String in numbers)
			{
				// Replace numbers from the numbersReplaceText Array
				if (!numbersReplaced)
				{
				getButtonByName(key).replaceText(numbersReplaceText[numbers.indexOf(key)]);
				}
				else
				{
				getButtonByName(key).replaceText(key);
				}
			}
			numbersReplaced = !numbersReplaced;  // toggle the numbersReplaced variable
		}
		
//Function to allign all the keys	
		public function alignKeys():void
		{
			// 1st,2nd,3rd,4th,5th row in the keyboard
			var firstRow:Array = ["`","1","2","3","4","5","6","7","8","9","0","-","=","&lt;--"];
			var secondRow:Array = ["Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\"];
			var thirdRow:Array = ["Caps","A", "S", "D", "F", "G", "H", "J", "K", "L",";","'","Enter"];
			var fourthRow:Array = ["Shift","Z", "X", "C", "V", "B", "N", "M", ",", ".", "/","Up"];
			var fifthRow:Array = ["Ctrl", "Alt", " ", "Alt ", "Ctrl ","Left","Down","Right"]; // Mark the space added in the 2nd Ctrl and Alt key ;)
		
		
// Aligning
//First Row Starts
			var _x = 20;
			var _y = 20;
			for each(var key:String in firstRow)
			{
			getButtonByName(key).y = _y;
			getButtonByName(key).x = _x;
			_x += getButtonByName(key).getWidth()+4;
			}
//First Row Ends
			
//Second Row Starts
			_x = 20;
			_y += 44;
			
			for each(var key:String in secondRow)
			{
			getButtonByName(key).y = _y;
			getButtonByName(key).x = _x;
			_x += getButtonByName(key).getWidth()+4;
			}
//Second Row Ends
			
// Third Row Starts
			_x = 20;
			_y += 44;	
			
			for each(var key:String in thirdRow)
			{
			getButtonByName(key).y = _y;
			getButtonByName(key).x = _x;
			_x += getButtonByName(key).getWidth() + 4;
			}
//Third Row Ends

//Fourth Row Starts
			_x = 20;
			_y += 44;	

			for each(var key:String in fourthRow)
			{
			getButtonByName(key).y = _y;
			getButtonByName(key).x = _x;
			_x += getButtonByName(key).getWidth()+4;
			}
//Fourth Row Ends

//Fourth Row Starts
			_x = 20;
			_y += 44;	

			for each(var key:String in fifthRow)
			{
			getButtonByName(key).y = _y;
			getButtonByName(key).x = _x;
			_x += getButtonByName(key).getWidth()+4;
			}
//Fourth Row Ends

//Aligning normal keys end
		}

//Key Functionalities

// Bug to be removed, ShiftKey bug
		private function ShiftKeyDown(event:TouchEvent):void
		{
			trace(event.ID);
/*			if (event.ID != shiftDownID)
			{
			trace("Shift Key DOWN");
			replaceNumbers();
			this.shift = true;
			shiftDownID = event.ID;
//event.stopPropagation();
			}*/
		}
		
		private function ShiftKeyUp(event:TouchEvent):void
		{
//			trace(event.ID);
/*			if (event.ID != shiftDownID)
			{
			trace(event.ID);
			trace("Shift Key UP");
//			replaceNumbers();
//			this.shift = false;
			shiftUpID = event.ID;
//event.stopPropagation();
			trace(shiftUpID+" shiftupid at Up method ");
			trace(shiftDownID+" shiftdownid at Up method ");
			}*/
		}

//Set the ctrl variable according to the key press
		private function CtrlKey(event:TouchEvent):void
		{
			this.ctrl = !this.ctrl;
			trace(this.ctrl);
			event.stopPropagation();
		}

//Set the alt variable according to the key press
		private function AltKey(event:TouchEvent):void
		{
			this.alt = !this.alt;
		}
		
//Set the shift variable according to the key press and replace the numbers
		private function CapsLockKey(event:TouchEvent):void
		{
			this.capslk = !this.capslk;
			this.shift = !this.shift;
			replaceNumbers();
		}
		
	}
}