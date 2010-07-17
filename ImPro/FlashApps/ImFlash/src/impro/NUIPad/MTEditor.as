package impro.NUIPad  
{
	import app.core.action.RotatableScalable;
	import flash.events.TouchEvent;
	import flash.net.FileReference;
		
	import flash.display.Sprite;
	import flash.text.TextField;
	import flash.text.TextFormat;
	import flash.text.TextFieldAutoSize;
	import flash.events.KeyboardEvent;

	/**
	 * ...
	 * @author Amit    http://amitsarangi.wordpress.com

	 * @version 0.1
	 * 	 */
	
	public class MTEditor extends RotatableScalable
	{
		public var enterCallback:Function;
		
	// Embeding fonts
		[Embed(source="./embed/VERDANA.TTF",fontWeight='normal',fontName="Verdana",mimeType="application/x-font-truetype")] var Verdana:Class;
		[Embed(source="./embed/VERDANAB.TTF" ,fontWeight='bold',fontName="Verdana",mimeType="application/x-font-truetype")] var Verdanab:Class;
		[Embed(source='./embed/VERDANAI.TTF',fontStyle='italic' ,fontName="Verdana",mimeType="application/x-font-truetype")] var Verdanai:Class;
		[Embed(source = './embed/VERDANAZ.TTF', fontWeight = 'bold', fontStyle = 'italic' , fontName = "Verdana", mimeType = "application/x-font-truetype")] var Verdanaib:Class;
		
		var field:TextField; // the main field where we write stuffs
		var format:TextFormat = new TextFormat(); // The TextFoemat object to format the text that we write
		var sizeInfoTextFormat:TextFormat; // the formatter used to format the sizeInfo textfield
		var background:Sprite = new Sprite(); //background sprite
		var _width:Number; //width and height
		var _height:Number;
		var fontSize:int; //initial Font Size will be replaced in constructer
		
		// buttons to control editor and its text
		var closeButton:MTButton = new MTButton(" X ", 40, 30, new TextFormat("Verdana", null, randomColor(), true));
		var boldButton:MTButton = new MTButton("B", 40, 30, new TextFormat("Verdana", null, 0x000000, true));
		var italicButton:MTButton = new MTButton("I", 40, 30, new TextFormat("Verdana", null, 0x000000, false, true));
		var ulButton:MTButton = new MTButton("U", 40, 30, new TextFormat("Verdana", null, 0x000000, false, false, true));
		var sizeUpButton:MTButton = new MTButton("+", 40, 30, new TextFormat("Verdana", null, 0x000000));
		var sizeDownButton:MTButton = new MTButton("-", 40, 30, new TextFormat("Verdana", null, 0x000000));
		var saveButton:MTButton = new MTButton("save", 40, 30, new TextFormat("Verdana", null, 0x000000));
		var keyboardButton:MTButton = new MTButton("Keyboard", 100, 30, new TextFormat("Verdana", null, 0x000000));
		
		var keyboard:MTKeyboard; // the keyboard object

		var sizeInfo:TextField = new TextField(); // textfield about the information of size
		var textInfo:TextField = new TextField();// textfield about the information of how the text is going to look
		
		public function MTEditor(_width:Number=800,_height:Number=350,fontSize:Number=40) 
		{
			this._width = _width;
			this._height = _height;
			this.fontSize = fontSize;
			this.sizeInfoTextFormat = new TextFormat("Verdana", fontSize);
			
			this.keyboard = new MTKeyboard(_width-150, _height-80); // the keyboard object
			
		//Draw		
			createBackGround();
			createEditor();
			addButtons();
			addEventListener(KeyboardEvent.KEY_DOWN, processText);
			//---------------------------------BUGS TO REMOVE------------------------------------
			
			keyboard.getButtonByName("Shift").visible = false;    // The Shift Bug based on the bug on TUOIObject class
			
			//-----------------------------------------------------------------------------------
		}
		
		// Setting field properties
		private function createEditor():void
		{
			field= new TextField();
			field.border = true;
			field.background = true;
//			field.multiline = true;
			field.wordWrap = true;
			field.text = " ";
//			field.selectable = false;
			field.embedFonts = true;
			field.x = 20;
			field.y = 5;
			field.width = _width - 5;
			field.height = 50;
//			field.height = _height - 50;
			format.font = "Verdana";
			format.size = fontSize;	
			format.leading = 4;
			format.leftMargin = 10;
			format.rightMargin = 10;
			field.setTextFormat(format);
			this.addChild(field);
			}
		// Process the text with the keyboard event that you receive
		private function processText(event:KeyboardEvent):void
		{
			if (event.charCode == 8)
			{
				if (field.length > 0)
				{	
					field.replaceText(field.length - 1, field.length, "");
				//field.text = field.text.slice(0, field.text.length - 1);
				}
			}
			else if (event.charCode == 13)
			{
//				field.appendText("\n");
				if(enterCallback!=null)
					enterCallback.call(event, field.text);
				field.text = "";				
			}
			else if (!event.shiftKey)
			{
			field.appendText(String.fromCharCode(event.charCode).toLowerCase());
			field.setTextFormat(format, field.length - 1, field.length);
			}
			else
			{
			field.appendText(String.fromCharCode(event.charCode));
			field.setTextFormat(format, field.length - 1, field.length);
			}
		}
		// creates the background . i.e the random colored one 
		private function createBackGround():void
		{
//			background.graphics.beginFill(randomColor(),0.5);
			background.graphics.beginFill(0x000000,0.5);
			background.graphics.drawRoundRect(0, 0,_width, _height, 15);
			background.graphics.endFill();
			addChild(background);
		}
		// Adds the buttons to the editor one by one, button can be guessed from the variable names
		private function addButtons():void   //Add Buttons and set their properties
		{
			/*
			this.addChild(saveButton);           
			saveButton.x =10;
			saveButton.y = _height - 37;
			saveButton.noMove = true;
			saveButton.noRotate = true;
			saveButton.noScale = true;
			saveButton.addEventListener(TouchEvent.MOUSE_DOWN,saveThis);
			
			this.addChild(closeButton);
			closeButton.x = _width-50;
			closeButton.y = _height-37;
			closeButton.noMove = true;
			closeButton.noRotate = true;
			closeButton.noScale = true;
			closeButton.addEventListener(TouchEvent.MOUSE_DOWN, closeThis);
			
			this.addChild(boldButton);
			boldButton.x = 60;
			boldButton.y = _height - 37;
			boldButton.noMove = true;
			boldButton.noRotate = true;
			boldButton.noScale = true;
			boldButton.addEventListener(TouchEvent.MOUSE_DOWN, toggleBold);
			
			this.addChild(italicButton);
			italicButton.x = 120;
			italicButton.y = _height - 37;
			italicButton.noMove = true;
			italicButton.noRotate = true;
			italicButton.noScale = true;
			italicButton.addEventListener(TouchEvent.MOUSE_DOWN, toggleItalic);
		
			this.addChild(ulButton);
			ulButton.x = 180;
			ulButton.y = _height - 37;
			ulButton.noMove = true;
			ulButton.noRotate = true;
			ulButton.noScale = true;
			ulButton.addEventListener(TouchEvent.MOUSE_DOWN, toggleUl);		
			
			
			this.addChild(sizeUpButton);
			sizeUpButton.x =240;
			sizeUpButton.y = _height - 37;
			sizeUpButton.noMove = true;
			sizeUpButton.noRotate = true;
			sizeUpButton.noScale = true;
			sizeUpButton.addEventListener(TouchEvent.MOUSE_DOWN, sizeUp);		
		
			this.addChild(sizeDownButton);
			sizeDownButton.x =300;
			sizeDownButton.y = _height - 37;
			sizeDownButton.noMove = true;
			sizeDownButton.noRotate = true;
			sizeDownButton.noScale = true;
			sizeDownButton.addEventListener(TouchEvent.MOUSE_DOWN, sizeDown);	
		
			this.addChild(textInfo);
			textInfo.x = 360;
			textInfo.y = _height - 37;
			textInfo.width = 40;
			textInfo.height = 30;
			textInfo.selectable = false;
			textInfo.background = true;
			textInfo.backgroundColor = 0x999999;
			textInfo.border = true;
			textInfo.embedFonts = true;
			textInfo.autoSize = TextFieldAutoSize.CENTER;
			textInfo.text = "A";
			textInfo.setTextFormat(format);
			
			this.addChild(sizeInfo);
			sizeInfo.x = 420;
			sizeInfo.y = _height - 37;
			sizeInfo.width = 40;
			sizeInfo.height = 30;
			sizeInfo.selectable = false;
			sizeInfo.embedFonts = true;
			sizeInfo.background = true;
			sizeInfo.backgroundColor = 0x999999;
			sizeInfo.border = true;
			sizeInfo.text = fontSize.toString();
			sizeInfo.setTextFormat(sizeInfoTextFormat);

			this.addChild(keyboardButton);
			keyboardButton.noMove = true;
			keyboardButton.noRotate = true;
			keyboardButton.noScale = true;
			keyboardButton.x = 470;
			keyboardButton.y = _height - 37;
//			keyboardButton.y = _height - 37;
			keyboardButton.addEventListener(TouchEvent.MOUSE_DOWN, toggleKeyboard);
			*/
						
			this.addChild(keyboard);
			keyboard.x = (this.width-keyboard.width)/2;
			keyboard.y = field.y + field.height + 10;
//			keyboard.y = _height-keyboard.height-70;
			keyboard.visible = true;
			keyboard.noMove = true;
			
			field.x = keyboard.x;
			field.width = keyboard.width;
		}
		
		// toggle the visibility of keyboard
		private function toggleKeyboard(event:TouchEvent)
		{
			keyboard.visible = !keyboard.visible;
		}
		
		//Closes this editor
		private function closeThis(event:TouchEvent):void
		{
			this.parent.removeChild(this);
		}
		
		// Generates random color
		private function randomColor():uint
		{
			return Math.random() * 0xFFFFFF;
		}
		
		// Saves this (Not yet implemented)
		private function saveThis(event:TouchEvent):void
		{
//			var file:FileReference = new FileReference();
//			var filename:String;
//			if (field.length > 3)
//			{
//			 filename= field.text.substring(0, 3)+".txt";
//			}
//			else 
//			{
//			 filename= field.text.substring(0, field.length)+".txt";
//			}
//			file.save(field.text ,filename);
			
			
//			trace(field.text);
//			trace("TO DO: Implement Save");
		}
		// toggles bold format
		private function toggleBold(event:TouchEvent):void
		{
			format.bold = !format.bold;
			updateInfo();
		}
		// toggles italic format
		private function toggleItalic(event:TouchEvent=null):void
		{
			format.italic = !format.italic;
			updateInfo();
		}
		// toggles underlining format
		private function toggleUl(event:TouchEvent):void
		{
			format.underline = !format.underline;
			updateInfo();
		}
		// Sizes up text i.e increase the font size
		private function sizeUp(event:TouchEvent):void
		{
			fontSize++;
			format.size = fontSize;
			updateInfo();
		}
		// Drcreases font size
		private function sizeDown(event:TouchEvent):void
		{
			fontSize--;
			format.size = fontSize;
			updateInfo();
		}
		// Update the information around the info textFields i.e sizeInfo and textInfo
		private function updateInfo():void
		{
			textInfo.setTextFormat(format);
			sizeInfo.text = fontSize.toString();
			sizeInfo.setTextFormat(sizeInfoTextFormat);
		}		
	}
}