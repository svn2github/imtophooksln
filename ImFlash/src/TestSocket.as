package
{
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.XMLSocket;
	import flash.text.TextField;
	
	public class TestSocket extends Sprite
	{
		public static var SERVRE_IP:String = "127.0.0.1";
		public static var SERVRE_PORT:int = 5000;
				
		private var socket:XMLSocket;			
		
		private var text1:TextField;
		private var message:TextField; 
		
		public function TestSocket()
		{
			super();		
			setupSocket();
			
			text1 = new TextField();
			text1.text = "connect to " + SERVRE_IP + ":" + SERVRE_PORT;
			addChild(text1);
			
			message = new TextField();
			message.y = text1.y + 20;
			message.text = "received:";			
			addChild(message);
		}
		
		private function setupSocket():void{
								
			// Setup OmMenum Socket			
			socket = new XMLSocket();
			socket.addEventListener(Event.CONNECT, function(event:Event):void{
				socket.send("hello socket"); 
			});
			
			socket.addEventListener(DataEvent.DATA, onRecvOmViewerSocket);
//			socket.addEventListener(ProgressEvent.SOCKET_DATA, onRecvOmViewerSocket);			
			socket.connect(SERVRE_IP, SERVRE_PORT);			
		}
		
		private function onRecvOmViewerSocket(event:DataEvent):void{
			var msg:String = event.data;
			message.text = message.text + "\n" + msg;			
		}
	}
}