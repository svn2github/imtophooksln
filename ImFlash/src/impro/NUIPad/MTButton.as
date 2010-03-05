package impro.NUIPad
{
	
  import app.core.action.RotatableScalable;
  import flash.filters.DropShadowFilter;
  import flash.display.*
  import flash.text.*;
  import flash.events.*;
  
  	/**
	 * ...
	 * @author Amit 	http://amitsarangi.wordpress.com
	 * @version 0.1
	 * 
	 **/
	
	
	public class MTButton extends RotatableScalable {
// Embed the fonts required		
		[Embed(source="./embed/VERDANA.TTF",fontWeight='normal',fontName="Verdana",mimeType="application/x-font-truetype")] var Verdana:Class;
		[Embed(source="./embed/VERDANAB.TTF" ,fontWeight='bold',fontName="Verdana",mimeType="application/x-font-truetype")] var Verdanab:Class;
		[Embed(source='./embed/VERDANAI.TTF',fontStyle='italic' ,fontName="Verdana",mimeType="application/x-font-truetype")] var Verdanai:Class;
		[Embed(source='./embed/VERDANAZ.TTF',fontWeight='bold',fontStyle='italic' ,fontName="Verdana",mimeType="application/x-font-truetype")] var Verdanaib:Class;
		
    // The text to appear on the button
    private var _text:String;
	private var replacementText:String;
	private var replaced:Boolean = false;
    // Save the width and height of the rectangle
    private var _width:Number;
    private var _height:Number;

	//The formatter supplied in the parameter
	private var buttonTextField:TextField;
	var format:TextFormat = new TextFormat(  );

	//A public variable stating the state of the button i.e upstate,downstate,overstate,outstate
	public var buttonState:String;
	    
    public function MTButton( htmlText:String, width:Number, height:Number,formatter:TextFormat=null,replacementText:String=null )
	{
//    Save the values to use them to create the button states
      this._text = htmlText;
      this._width = width;
      this._height = height;
	  if (replacementText == null)
	  {
		replacementText = htmlText;
	  }
	  else
	  {
		  this.replacementText = replacementText;
	  }
	  
	  if (formatter!=null)
	  {
		this.format = formatter;
	  }
		
	  this.noRotate = true;
	  this.noScale = true;
	  this.mouseChildren = false;
      
//    Create the button states based on width, height, and text value
		
	  addChild(createUpState(  ));
	  buttonState = "upstate";
	  
	  this.addEventListener(TouchEvent.MOUSE_DOWN,MouseDown);
      this.addEventListener(TouchEvent.MOUSE_UP,MouseUp)
	  this.addEventListener(TouchEvent.MOUSE_OVER,MouseOver);
	  this.addEventListener(TouchEvent.MOUSE_OUT, MouseOut);
	  
    }
	
	private function MouseDown(event:TouchEvent):void
	{
		
//		trace("MouseDown");
		addChild(createDownState());
		buttonState = "downstate";
		event.stopPropagation();
		
	}

	private function MouseUp(event:TouchEvent):void
	{
		
//		trace("MouseUp");
		addChild(createUpState());
		buttonState = "upstate";
		event.stopPropagation();

	}
	private function MouseOver(event:TouchEvent):void
	{
		
//		trace("MouseOver");
		addChild(createOverState());
		buttonState = "overstate";
		event.stopPropagation();
	}
	
	private function MouseOut(event:TouchEvent):void
	{
		
//		trace("MouseOut");
		addChild(createUpState());
		buttonState = "upstate";
		event.stopPropagation();
	}
	
    // Create the display object for the button's up state
    private function createUpState(  ):Sprite 
	{
		
		var sprite:Sprite = new Sprite(  );
      
		var background:Sprite = createdColoredRectangle( 0xFFFFFF );
		buttonTextField = createTextField(false);
		
		sprite.addChild(background);
		sprite.addChild(buttonTextField);
		return sprite;
		
    }
    
    // Create the display object for the button's up state
    private function createOverState(  ):Sprite 
	{
		
		var sprite:Sprite = new Sprite(  );
      
		var background:Sprite = createdColoredRectangle( 0xdfdfdf);
		buttonTextField = createTextField( false );
            
		sprite.addChild( background );
		sprite.addChild( buttonTextField );
		
		return sprite;
	  
    }
    
    // Create the display object for the button's down state
    private function createDownState(  ):Sprite 
	{
		
		var sprite:Sprite = new Sprite(  );
      
		var background:Sprite = createdColoredRectangle( 0xCCCCCC );
		buttonTextField = createTextField( true );
      
		sprite.addChild( background );
		sprite.addChild( buttonTextField );
      
		return sprite;
	  
    }
//	 Create a rounded rectangle with a specific fill color
    private function createdColoredRectangle( color:uint ):Sprite 
	{
		
		var rect:Sprite = new Sprite(  );
		rect.graphics.lineStyle( 1, 0x000000 );
		rect.graphics.beginFill(color);
		rect.graphics.drawRoundRect( 0, 0, _width, _height, 15 );
		rect.graphics.endFill();
//		rect.filters = [new DropShadowFilter(2)];
		return rect;
	  
    }
//	 Create the text field to display the text of the button
    private function createTextField( downState:Boolean ):TextField 
	{
		
		var textField:TextField = new TextField();
		if (!replaced)
		{
		textField.htmlText = _text;
		}
		else if (replaced)
		{
			textField.htmlText = replacementText;
		}
		textField.width = _width;
        textField.embedFonts = true;
            
//	Center the text horizontally
		
		format.align = TextFormatAlign.CENTER;
		format.font = "Verdana";
		textField.selectable = false;
		textField.height = textField.textHeight+5;
		textField.setTextFormat(format);
      
//	Center the text vertically
		textField.y = ( _height - textField.textHeight ) / 2;
		textField.y -= 2;  // Subtract 2 pixels to adjust for offset
		
// The down state places the text down and to the right
// further than the other states
		if (downState) 
		{
		textField.x += 1;
		textField.y += 1;
		}
     
		return textField;
	  
    }
	
//Gets Width of the Button
	public function getWidth():Number
	{
		return this._width;
	}
	
//Gets Height of the Button
	public function getHeight():Number
	{
		return this._width;
	}
	
//	Changes the text of the Button's Textfield
	public function setText(replacementText:String):void
	{
		
		buttonTextField.htmlText = replacementText;
		buttonTextField.setTextFormat(format);
		
	}
	
//	Gets the text of the Button's Textfield
	public function getText():String
	{
		
		return buttonTextField.text;
		
	}
	
//Replaces the text on the button by a different text provided in the constructor arguments or in the function argument
	public function replaceText(text:String=null):void
	{
		
		if (text==null)
		{
			if (!replaced)
			{
			this.setText(replacementText);
			}
			else
			{
				this.setText(_text);
			}
		}
		else
		{
			this.setText(text);
			replacementText = text;
		}
			replaced = !replaced;
	}
  }
}