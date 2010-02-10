package de.johannesluderschmidt.tuio 
{		
	
	//import app.core.element.FocusButton;import flash.display.DisplayObject;	
	import flash.display.DisplayObjectContainer;
	import flash.display.Stage;
	import flash.events.DataEvent;
	import flash.events.Event;
	import flash.events.EventDispatcher;
	import flash.events.IOErrorEvent;
	import flash.events.ProgressEvent;
	import flash.events.SecurityErrorEvent;
	import flash.geom.Point;
	import flash.net.LocalConnection;
	import flash.net.NetConnection;
	import flash.net.Responder;
	import flash.net.URLLoader;
	import flash.net.URLRequest;
	import flash.net.XMLSocket;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;	

	//import app.core.element.Wrapper;

	public class TUIO
	{		
		private static var FLOSCSocket:XMLSocket;		
		private static var FLOSCSocketHost:String;			
		private static var FLOSCSocketPort:Number;	
				
		public static var STAGE:Stage;
		private static var IMSTAGE:IMStage;	
		public static var objectArray:Array;
		public static var bDebug:Boolean;
		
		private static var idArray:Array; 				
		private static var debugText:TextField;		
		private static var xmlPlaybackURL:String; 
		private static var xmlPlaybackLoader:URLLoader;
		private static var playbackXML:XML;
		private static var recordedXML:XML;		
		private static var bInitialized:Boolean;
		private static var bRecording:Boolean;		
		private static var bPlayback:Boolean;	
		private static var myService:NetConnection;
    	private static var responder:Responder;
		private static var eventListeners:Array;
		
		private static var LONG_PRESS_TIME:Number = 4000;
		private static var HSIgnore : HotSpotIgnore;
		
		import impro.IMStage;
		
		//---------------------------------------------------------------------------------------------------------------------------------------------
        // Handle simulation event.
        //---------------------------------------------------------------------------------------------------------------------------------------------
//		public static var localConnection:LocalConnection; 
    	
	public static function init ($IMSTAGE:IMStage, $STAGE:DisplayObjectContainer, host:String, port:Number, debugXMLFile:String, dbug:Boolean = true):void
	{
			if(bInitialized){return;}	
			
			HSIgnore = new HotSpotIgnore();
			STAGE = $STAGE.stage;
			STAGE.align = "TL";
			STAGE.scaleMode = "noScale";
			// 刻意用 IMSTAGE 冒充一個  Stage 物件		
			IMSTAGE = $IMSTAGE;
							
			FLOSCSocketHost=host;			
			FLOSCSocketPort=port;					       
			myService = new NetConnection();	
			
			xmlPlaybackURL = debugXMLFile;
			bDebug = dbug;				
			bInitialized = true;
			bRecording = false;		
			bPlayback = false;									
			objectArray = new Array();
			idArray = new Array();
			
			
			eventListeners = new Array();
			
			try
			{
				FLOSCSocket = new XMLSocket();	
				FLOSCSocket.addEventListener(Event.CLOSE, closeHandler);
				FLOSCSocket.addEventListener(Event.CONNECT, connectHandler);
				FLOSCSocket.addEventListener(DataEvent.DATA, dataHandler);
				FLOSCSocket.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
				FLOSCSocket.addEventListener(ProgressEvent.PROGRESS, progressHandler);
				FLOSCSocket.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);	
				FLOSCSocket.connect(host, port);				
			} 
			catch(e:Error){}			
			if(bDebug)
			{
				activateDebugMode();				
			}  
			else 
			{		
				recordedXML = new XML();	
				recordedXML = <OSCPackets></OSCPackets>;
				bRecording = false;			
			}
			
			//---------------------------------------------------------------------------------------------------------------------------------------------
            // Add Local Connection to the TUIO init method. 

            //---------------------------------------------------------------------------------------------------------------------------------------------
//            localConnection = new LocalConnection();
//            localConnection.client = TUIO;
//            localConnection.allowDomain('*');
//            localConnection.connect("_simulatedTouch");			
		}
		
		/**
         * Handles the local connection event to the multi-touch applicaiton. 
         * Used in the SimTouch simulator.  
         * Calls the processMessage 
         * 
         * @param               xml             XML
         */ 
        public static function simulatedTouchEventHandler(xml:XML):void
        {
                processMessage(xml)
        }
        
		public static function addEventListener(e:EventDispatcher) : void
		{
			eventListeners.push(e);
		}
		
		public static function processMessage(msg:XML) : void
		{
			var fseq:String;
			var node:XML;
			for each(node in msg.MESSAGE)
			{
				if(node.ARGUMENT[0] && node.ARGUMENT[0].@VALUE == "fseq")
					fseq = node.ARGUMENT[1].@VALUE;					
			}
			
			for each(node in msg.MESSAGE)
			{
				if(node.ARGUMENT[0] && node.ARGUMENT[0].@VALUE == "alive")
				{
					for each (var obj1:TUIOObject in objectArray)
					{
						obj1.isAlive = false;
					}
								
					for each(var aliveItem:XML in node.ARGUMENT.(@VALUE != "alive"))
					{
						if(getObjectById(aliveItem.@VALUE))
							getObjectById(aliveItem.@VALUE).isAlive = true;

					}   
				}
			}				
			for each(node in msg.MESSAGE)
			{
				if(node.ARGUMENT[0])
				{
					var type:String;
										
					if(node.@NAME == "/tuio/2Dobj")
					{
						
						
					} 
					else if(node.@NAME == "/tuio/2Dcur")
					{
						
						type = node.ARGUMENT[0].@VALUE;				
						if(type == "set")
						{
							
							var id:int;
							
							var x:Number,
								y:Number,
								X:Number,
								Y:Number,
								m:Number,
								wd:Number = 0, 
								ht:Number = 0;
							try 
							{
								id = node.ARGUMENT[1].@VALUE;
								x = Number(node.ARGUMENT[2].@VALUE) * IMSTAGE.stageWidth;
								y = Number(node.ARGUMENT[3].@VALUE) *  IMSTAGE.stageHeight;
								X = Number(node.ARGUMENT[4].@VALUE);
								Y = Number(node.ARGUMENT[5].@VALUE);
								m = Number(node.ARGUMENT[6].@VALUE);
								
								if(node.ARGUMENT[7])
									wd = Number(node.ARGUMENT[7].@VALUE) * IMSTAGE.stageWidth;							
								
								if(node.ARGUMENT[8])
									ht = Number(node.ARGUMENT[8].@VALUE) * IMSTAGE.stageHeight;
							} catch (e:Error)
							{
								trace("Error parsing");
							}
							
							//trace("Blob : ("+id + ")" + x + " " + y + " " + wd + " " + ht);
							
							var stagePoint:Point = new Point(x,y);					
							var displayObjArray:Array = STAGE.getObjectsUnderPoint(stagePoint);
							var dobj:Object = null;
							
							if(displayObjArray.length > 0)								
							dobj = displayObjArray[displayObjArray.length-1];	
																				
							var tuioobj : Object = getObjectById(id);
						//TODO: add hotspot ignore
							if (!HSIgnore.checkHotSpot(stagePoint))
							{
								if(tuioobj == null)
								{
									
									
										tuioobj = new TUIOObject("2Dcur", id, x, y, X, Y, -1, 0, wd, ht, dobj);
										STAGE.addChild(tuioobj.spr);								
										objectArray.push(tuioobj);
										tuioobj.notifyCreated();
									
									
								} else {
									tuioobj.spr.x = x;
									tuioobj.spr.y = y;
									tuioobj.oldX = tuioobj.x;
									tuioobj.oldY = tuioobj.y;
									tuioobj.x = x;
									tuioobj.y = y;
	
									tuioobj.width = wd;
									tuioobj.height = ht;
									tuioobj.area = wd * ht;								
									tuioobj.dX = X;
									tuioobj.dY = Y;
									tuioobj.setObjOver(dobj);
									
									var d:Date = new Date();																
									if(!( int(Y*1000) == 0 && int(Y*1000) == 0) )
									{
										tuioobj.notifyMoved();
									}
									
									if( int(Y*250) == 0 && int(Y*250) == 0) {
		
										if(Math.abs(d.time - tuioobj.lastModifiedTime) > LONG_PRESS_TIME)
										{
											for(var ndx:int=0; ndx<eventListeners.length; ndx++)
											{
												eventListeners[ndx].dispatchEvent(tuioobj.getTouchEvent(TouchEvent.LONG_PRESS));
											}
	
											tuioobj.lastModifiedTime = d.time;																		
										}
									}
									
								}
	
								try
								{
									if(tuioobj.obj && tuioobj.obj.parent)
									{							
										var localPoint:Point = tuioobj.obj.parent.globalToLocal(stagePoint);							
										tuioobj.obj.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_MOVE, true, false, ((int)(x)), ((int)(y)), ((int)(localPoint.x)), ((int)(localPoint.y)), tuioobj.oldX, tuioobj.oldY, tuioobj.obj, false,false,false, true, m, "2Dcur", id, 0, 0));
									}
								} catch (e:Error)
								{
									trace("(" + e + ") Dispatch event failed " + tuioobj.ID);
								}
							}
							
						}
					}
					
						
				}
			}
			if(bDebug)
			{
				debugText.text = "";
				debugText.y = -2000;
				debugText.x = -2000;		
			}	
			for (var i:Number=0; i<objectArray.length; i++ )
			{	
				if(objectArray[i].isAlive == false)
				{
					
					objectArray[i].kill();
					STAGE.removeChild(objectArray[i].spr);
					objectArray.splice(i, 1);
					i--;

				} else {
					if(bDebug)
					{	var tmp:Number = (int(objectArray[i].area)/-100000);
						//trace('area: '+tmp);
						debugText.appendText("  " + (i + 1) +" - " +objectArray[i].ID + "  X:" + int(objectArray[i].x) + "  Y:" + int(objectArray[i].y) +
						"  A:" + int(tmp) + "  \n");						
						debugText.x = IMSTAGE.stageWidth-200;
						debugText.y = 25;	
					}
					}
			}
		}
		
		
		public static function listenForObject(id:Number, reciever:Object):void
		{
			var tmpObj:TUIOObject = getObjectById(id);			
			if(tmpObj)
			{
				tmpObj.addListener(reciever);				
			}
		}
		
		public static function getObjectById(id:Number): TUIOObject
		{
			if(id == 0)
			{
				return new TUIOObject("mouse", 0, STAGE.mouseX, STAGE.mouseY, 0, 0, 0, 0, 10, 10, null);
			}
			for(var i:Number=0; i<objectArray.length; i++)
			{
				if(objectArray[i].ID == id)
				{
					return objectArray[i];
				}
			}
			return null;
		}
		
		
        private static function activateDebugMode():void 
        {
			
  				var format:TextFormat = new TextFormat("Verdana", 10, 0xFFFFFF);
				debugText = new TextField();       
				debugText.defaultTextFormat = format;
				debugText.autoSize = TextFieldAutoSize.LEFT;
				debugText.background = true;	
				debugText.backgroundColor = 0x000000;	
				debugText.border = true;	
				debugText.borderColor = 0x333333;	
				STAGE.addChild( debugText );						
				STAGE.setChildIndex(debugText, STAGE.numChildren-1);	
		
				recordedXML = <OSCPackets></OSCPackets>;	
			
        }	
        
        private static function xmlPlaybackLoaded(evt:Event) : void
        {
			trace("Playing from XML file...");
			playbackXML = new XML(xmlPlaybackLoader.data);			
		}
		
		private static function frameUpdate(evt:Event) : void
		{
			if(playbackXML && playbackXML.OSCPACKET && playbackXML.OSCPACKET[0])
			{
				processMessage(playbackXML.OSCPACKET[0]);
				delete playbackXML.OSCPACKET[0];
			}
		}		
		
		private static function toggleDebug(e:Event) : void
		{ 
			if(!bDebug){
			bDebug=true;		
			FLOSCSocket.connect(FLOSCSocketHost, FLOSCSocketPort);
			e.target.parent.alpha=0.85;
			}
			else{
			bDebug=false;
			FLOSCSocket.connect(FLOSCSocketHost, FLOSCSocketPort);
			e.target.parent.alpha=0.5;	
			}
		}
		
		public static function startSocket() : void
		{ 	
			FLOSCSocket.connect(FLOSCSocketHost, FLOSCSocketPort);
		}
		public static function stopSocket() : void
		{ 	
			FLOSCSocket.close();
		}
		private static function toggleRecord(e:Event) : void
		{ 	
			var responder : Responder = new Responder(saveSession_Result, onFault);
			
			if(!bRecording){
			bRecording = true;
			e.target.parent.alpha=1.0;			
			trace(e.target.parent);
			trace('-----------------------------------------------------------------------------------------------------');		
			trace('-------------------------------------- Record ON ----------------------------------------------------');
			trace('-----------------------------------------------------------------------------------------------------');	
			myService.call("touchlib.clearSession", responder);
			}
			else{
			bRecording = false;
			e.target.parent.alpha=0.25;
			trace('-----------------------------------------------------------------------------------------------------');		
			trace('-------------------------------------- Record OFF ---------------------------------------------------');
			trace('-----------------------------------------------------------------------------------------------------');	
			myService.call("touchlib.saveSession", responder, recordedXML.toXMLString());
			trace('-------------------------------------- Recording END ------------------------------------------------');
			}
		}
			
		private static function saveSession_Result(result:String) : void
		{	
			debugText.x = debugText.y = 5;
			debugText.text = result;
		}
			
		private static function togglePlayback(e:Event) : void
		{ 	
			if(xmlPlaybackURL != "")
				 {	
				 	xmlPlaybackLoader = new URLLoader();
					xmlPlaybackLoader.addEventListener("complete", xmlPlaybackLoaded);
					xmlPlaybackLoader.load(new URLRequest(xmlPlaybackURL));			
					STAGE.addEventListener(Event.ENTER_FRAME, frameUpdate);
				 }
		}
		
        private static function dataHandler(event:DataEvent):void 
        {           			
			if(bRecording)
			recordedXML.appendChild( XML(event.data) );			
			processMessage(XML(event.data));
        }     			
        private static function onFault(e:Event ) : void
		{
			trace("There was a problem: " + e.type);
		}
     	private static function connectHandler(event:Event):void 
     	{
            trace("connectHandler: " + event);
        }       
        private static function ioErrorHandler(event:IOErrorEvent):void 
        {
            //trace("ioErrorHandler: " + event);
        }
        private static function progressHandler(event:ProgressEvent):void 
        {
            //trace("Debug XML Loading..." + event.bytesLoaded + " out of: " + event.bytesTotal);
        }
        private static function closeHandler(event:Event):void 
        {
            //trace("closeHandler: " + event);
        }
        private static function securityErrorHandler(event:SecurityErrorEvent):void 
        {
            //trace("securityErrorHandler: " + event);
        }  
    }
}