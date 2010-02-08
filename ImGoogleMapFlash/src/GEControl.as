package
{
	import com.google.maps.LatLng;
	import com.google.maps.Map;
	
	import flash.display.Sprite;
	import flash.events.*;
	import flash.geom.Point;
	import flash.net.XMLSocket;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;
	
	public class GEControl extends Sprite
	{
		//public static var SERVRE_IP:String = "127.0.0.1";
		public static var SERVRE_IP:String = "192.168.1.18";
		public static var SERVRE_PORT:int = 5000;
		
		private var DEBUG:Boolean = true;
		private var DEBUG_TEXT:TextField;		
		
		private var socket:XMLSocket;			
		
		private var parentMap:Map;
		
		private var lat:Number = 23.69781;
		private var lng:Number = 120.960515;
		private var pitch:Number = 90;		
		private var yaw:Number = 0;
		private var roll:Number = 0;		
		
		public function GEControl(parentMap:Map,  $DEBUG:Boolean = true)
		{
			super();
			 
			this.parentMap = parentMap;
			DEBUG = $DEBUG;
			
			setupDraw();			
			setupSocket();
			this.addEventListener(MouseEvent.MOUSE_DOWN, pickUp);
			this.addEventListener(MouseEvent.MOUSE_MOVE, pickMove);
			this.addEventListener(MouseEvent.MOUSE_UP, dropIt);
			
			this.addEventListener(MouseEvent.MOUSE_WHEEL, onWheel);
			
			//this.addEventListener(KeyboardEvent.KEY_DOWN, onKeyUp);
			//stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyUp);
			
			if(DEBUG){
				var format:TextFormat = new TextFormat("Verdana", 10, 0xFFFFFF);
				DEBUG_TEXT = new TextField();
				DEBUG_TEXT.defaultTextFormat = format;
				DEBUG_TEXT.autoSize = TextFieldAutoSize.LEFT;
				DEBUG_TEXT.background = true;	
				DEBUG_TEXT.backgroundColor = 0x000000;	
				DEBUG_TEXT.border = true;	
				DEBUG_TEXT.borderColor = 0x333333;							
				
				DEBUG_TEXT.x = -25;
				DEBUG_TEXT.y = 30;
				
				DEBUG_TEXT.text = "-";
				addChild(DEBUG_TEXT);
			}
		}
		
		private function setupDraw():void{
			var w:Number = 50, h:Number = 50;
			
			this.graphics.beginFill(0x0000ff, 0.4);
			this.graphics.drawRect(-w/2, -h/2, w, h);
			this.graphics.endFill();
			
			// draw cross line
			this.graphics.beginFill(0x0000ff, 1);
			this.graphics.drawRect(0, -h/2, 1, h);
			this.graphics.drawRect(-w/2, 0, w, 1);			
			this.graphics.endFill();
			
			this.graphics.lineStyle(1, 0x0000ff);
			this.graphics.moveTo(-w/2, -h/2);
			this.graphics.lineTo(w/2, -h/2);
			this.graphics.lineTo(w/2, h/2);			
			this.graphics.lineTo(-w/2, h/2);
			this.graphics.lineTo(-w/2, -h/2);			
			
		}

		private function setupSocket():void{
											
			socket = new XMLSocket();
			socket.addEventListener(Event.CONNECT, function(event:Event):void{
				socket.send("11, flashGE"); 
			});
			
			socket.addEventListener(DataEvent.DATA, onData);
			socket.addEventListener(Event.CONNECT, onConnect);
			socket.addEventListener(Event.CLOSE, onDisconnect);
//			socket.addEventListener(ProgressEvent.SOCKET_DATA, onRecvOmViewerSocket);			
			socket.connect(SERVRE_IP, SERVRE_PORT);			
		}	

		private function onData(e:DataEvent):void{
			var msg:String = e.data;
//			status.text = message.text + "\n" + msg;			
		}
		
		private function onConnect(e:Event):void{
			if(DEBUG)
				DEBUG_TEXT.text = "+";
		}
		
		private function onDisconnect(e:Event):void{
			if(DEBUG)
				DEBUG_TEXT.text = "Disconnect";			
		}

		private function pickUp(event:MouseEvent):void {
		    event.target.startDrag(false);
		}
		private function pickMove(event:MouseEvent):void {
			//update();
		}
		private function dropIt(event:MouseEvent):void {
			event.target.stopDrag();			
			update();
		}
		private function onWheel(event:MouseEvent):void{
			trace(event.delta);
			
			if(event.localX < 0)
				pitch += event.delta;
			else
				yaw += event.delta;			
			update();
		}
		
		public function update():void{
//			updateMap();
			updateSend();
			if(DEBUG)
				updateDebug();
		}
		
		public function moveLeft(value:Number=1):void{
			this.x-=value;
			update();
		}
		public function moveRight(value:Number=1):void{
			this.x+=value;
			update();
		}
		public function moveUp(value:Number=1):void{
			this.y-=value;
			update();
		}
		public function moveDown(value:Number=1):void{
			this.y+=value;
			update();
		}
		
//		private function updateMap():void{
//			var toLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(this.x, this.y));
//			lat = toLatlng.lat();
//			lng = toLatlng.lng();
//		}
		
		private function updateSend():void{		
			if(socket.connected){
				
				// get target latlng
				var p1ToLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(0, 0));
				var p2ToLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(0, parentMap.height));
				var p3ToLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(parentMap.width, parentMap.height));
//				var p4ToLatlng:LatLng = parentMap.fromViewportToLatLng(new Point(0, parentMap.height));								
				
				var s:String = "ll," + p1ToLatlng.lat() + "," + p1ToLatlng.lng() + ","
									+ p2ToLatlng.lat() + "," + p2ToLatlng.lng() + ","
									+ p3ToLatlng.lat() + "," + p3ToLatlng.lng(); 
//									+ p4ToLatlng.lat() + "," + p4ToLatlng.lng();									
				socket.send("15,tabletGE_1,flashGE," + s);
			}
		}
		
		private function updateDebug():void{
			if(socket.connected)
				DEBUG_TEXT.text = "Connected";
			else 
				DEBUG_TEXT.text = "Dis-connected";
			//DEBUG_TEXT.appendText("\nLat: " + lat + "\nLng: " + lng + "\nPitch: " + pitch + "\nYaw: " + yaw);
		}		
	}
}