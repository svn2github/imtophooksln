package flash.events {
	
	import flash.display.Sprite;
	//import flash.text.TextFormat;
	//import flash.text.TextField;
	//import flash.text.TextFieldAutoSize;

	internal class TUIOCursor extends Sprite
	{
		//private var DEBUG_TEXT:TextField;	
//---------------------------------------------------------------------------------------------------------------------------------------------	
// CONSTRUCTOR
//---------------------------------------------------------------------------------------------------------------------------------------------	
		public function TUIOCursor($text:int, $color:int, $pressure:Number, $width:Number, $height:Number)
		{
			// FIXME: DO NOT!!!! PUT A FILL ON THIS CAUSE IT WILL CAUSE BUG IN UP/OVER/OUT Events... ------------------------
			super();
			if (TUIO.DEBUG) { 			

				this.blendMode="invert";
				graphics.beginFill(0xFF00FF , 1);	
				graphics.drawCircle(0 ,0, 15);	
				graphics.endFill();

				// Draw a cross and filled circle with random color
				//graphics.beginFill(color , 1);
//				var random_color:Number = Math.random() * 0xffffff;
//				graphics.beginFill(random_color , 0.6);	
//				graphics.drawCircle(0 ,0, 15);	
//				graphics.lineStyle( 2, 0x000000 );
//				graphics.moveTo( 0, -10 );
//				graphics.lineTo( 0, 10 );
//				graphics.moveTo( -10, 0 );
//				graphics.lineTo( 10, 0 );
//				graphics.endFill();

				/*	
				* if(pressure > 0 && pressure != null){			
					this.graphics.drawCircle(0 ,0, pressure+10);
				} else {					
				}
				*/

			
			/*
			if ($text != '' || $text != null)
			{	
			//TODO: GET ID/X/Y/Area Data into this text ------------------------
				var format:TextFormat = new TextFormat();
				DEBUG_TEXT = new TextField();
	        	format.font = 'Verdana';
	     		format.color = 0x000000;
	       	 	format.size = 10;
				DEBUG_TEXT.defaultTextFormat = format;
				DEBUG_TEXT.autoSize = TextFieldAutoSize.LEFT;
				DEBUG_TEXT.background = true;	
				DEBUG_TEXT.backgroundColor = 0x000000;	
				DEBUG_TEXT.border = true;	
				DEBUG_TEXT.text = '';
				DEBUG_TEXT.appendText(' '+$text+'  ');				
				DEBUG_TEXT.x = 12;
				DEBUG_TEXT.y = -13;  				
				addChild(DEBUG_TEXT);
			}*/
		} else {			
			// HIDE CURSOR
			   }	
		}		
//---------------------------------------------------------------------------------------------------------------------------------------------	
	}
}