/*
 * TODO: Make into a proper singleton
 * FIXME: Initilization Bug
 * TODO: Implement SWIPES and other events see: TouchEvent
*/
package flash.events {		
	import flash.display.DisplayObject;
	import flash.display.DisplayObjectContainer;
	import flash.display.Sprite;
	import flash.display.Stage;
	import flash.geom.Point;
	import flash.net.NetConnection;
	import flash.net.Responder;
	import flash.net.URLLoader;
	import flash.net.URLRequest;
	import flash.net.XMLSocket;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;
	import flash.utils.getTimer;
	
	import impro.multiview.IMView;

	public class TUIO
	{	
		//private static var INSTANCE:TUIO;			
		private static var STAGE:Stage;
		private static var IMSTAGE:IMView;		
		private static var SOCKET:XMLSocket;	
		private static var SOCKET_STATUS:Boolean;	
		private static var HOST:String;			
		private static var PORT:Number;				
		private static var FRAME_RATE:Number;			
		private static var FRAME_COUNT:Number;
		//-------------------------------------- DEBUG VARS			
		internal static var DEBUG:Boolean;				
		private static var INITIALIZED:Boolean;		
		private static var PLAYBACK:Boolean;			
		private static var RECORDING:Boolean;			
		private static var DEBUG_TEXT:TextField;	
		private static var DEBUG_BUTTON:Sprite;			
		private static var RECORD_BUTTON:Sprite;							
		private static var PLAYBACK_BUTTON:Sprite;		
		private static var PLAYBACK_URL:String; 
		private static var PLAYBACK_LOADER:URLLoader;
		private static var PLAYBACK_XML:XML;
		private static var RECORDED_XML:XML;		
		private static var SERVICE:NetConnection;
    	private static var RESPONDER:Responder;
		//--------------------------------------		
		private static var ID_ARRAY:Array; 		
		private static var EVENT_ARRAY:Array;		
		private static var OBJECT_ARRAY:Array;		
		//--------------------------------------		
		private static var IMID_ARRAY:Array; 		
		private static var IMEVENT_ARRAY:Array;		
		private static var IMOBJECT_ARRAY:Array;		
		//--------------------------------------
		private static var SWIPE_THRESHOLD:Number = 1000;
		private static var HOLD_THRESHOLD:Number = 4000;

		// calculate everything here			
		private static var dirty:Number;
		private static var frameIndex:Number = 0;;
		private static var preCenter:Point = new Point();
		private static var preAveLength:Number
		private static var translation:Point = new Point();;
		private static var scale:Number = 1;
		
		
//---------------------------------------------------------------------------------------------------------------------------------------------	
// CONSTRUCTOR - SINGLETON
//---------------------------------------------------------------------------------------------------------------------------------------------		
//		public static function init ($STAGE:DisplayObjectContainer, $HOST:String, $PORT:Number, $PLAYBACK_URL:String, $DEBUG:Boolean = true):void
		public static function init ($IMSTAGE:IMView, $STAGE:DisplayObjectContainer, $HOST:String, $PORT:Number, $PLAYBACK_URL:String, $DEBUG:Boolean = true):void
		{
			if (INITIALIZED) { trace("TUIO Already Initialized!"); return; }	
			
			
			// FIXME: VERIFY STAGE IS AVAILABLE			
			STAGE = $STAGE.stage;
			STAGE.align = "TL";
			STAGE.scaleMode = "noScale";				

			// 刻意用 IMSTAGE 冒充一個  Stage 物件		
			IMSTAGE = $IMSTAGE;
			
			HOST=$HOST;			
			PORT=$PORT;					       
			
			SERVICE = new NetConnection();
			SERVICE.connect("http://touchlib.com/amfphp/gateway.php");
			
			PLAYBACK_URL = $PLAYBACK_URL;
			DEBUG = $DEBUG;				
			INITIALIZED = true;
			RECORDING = false;		
			PLAYBACK = false;									
			OBJECT_ARRAY = new Array();
			ID_ARRAY = new Array();
			EVENT_ARRAY = new Array();
			
			//
			IMOBJECT_ARRAY = new Array();
			IMID_ARRAY = new Array();
			IMEVENT_ARRAY = new Array();
			
			
			if(DEBUG)
			{
				activateDebugMode();						
			}  
			else 
			{		
				RECORDED_XML = new XML();	
				RECORDED_XML = <OSCPackets></OSCPackets>;
				RECORDING = false;
			}				
			
			SOCKET = new XMLSocket();	
			SOCKET.addEventListener(Event.CLOSE, closeHandler);
			SOCKET.addEventListener(Event.CONNECT, connectHandler);
			SOCKET.addEventListener(DataEvent.DATA, dataHandler);
			SOCKET.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
			//SOCKET.addEventListener(ProgressEvent.PROGRESS, progressHandler);
			SOCKET.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);	
			startSocket(null);				
			//socketStatus(null);			http://nuigroup.com/forums/viewthread/3516/			
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
// PUBLIC METHODS
//---------------------------------------------------------------------------------------------------------------------------------------------
/*
	public static function addEventListener(e:EventDispatcher):void
		{
			EVENT_ARRAY.push(e);
		}
*/
		public static function returnBlobs():Array{
			return OBJECT_ARRAY;
		}

//---------------------------------------------------------------------------------------------------------------------------------------------
		public static function addObjectListener(id:Number, reciever:Object):void
		{
			var tmpObj:TUIOObject = getObjectById(id);			
			if(tmpObj)
			{
				tmpObj.addListener(reciever);				
			}
		}
		
		public static function addIMObjectListener(reciever:Object):void
		{
//			var tmpObj:IMObject = getIMObjectById(id);			
//			if(tmpObj)
//			{
//				tmpObj.addListener(reciever);				
//			}
//			tmpObj.addListener(reciever);
			IMObject.addListener(reciever);			
		}		
//---------------------------------------------------------------------------------------------------------------------------------------------
		public static function removeObjectListener(id:Number, reciever:Object):void
		{
			var tmpObj:TUIOObject = getObjectById(id);			
			if(tmpObj)
			{
				tmpObj.removeListener(reciever);				
			}
		}
		
		public static function removeIMObjectListener(reciever:Object):void
		{
//			var tmpObj:IMObject = getIMObjectById(id);			
//			if(tmpObj)
//			{
//				tmpObj.removeListener(reciever);				
//			}
			IMObject.removeListener(reciever);
		}		
//---------------------------------------------------------------------------------------------------------------------------------------------
		
		public static function getObjects():Array{
			return OBJECT_ARRAY;
		}

		public static function getObjectById(id:Number):TUIOObject
		{
			if(id == 0)
			{
				return new TUIOObject("mouse", 0, STAGE.mouseX, STAGE.mouseY, 0, 0, 0, 0, 10, 10, null);
			}
			for(var i:int=0; i<OBJECT_ARRAY.length; i++)
			{
				// modified by me
				if(OBJECT_ARRAY[i].TUIO_TYPE == "2Dcur" && OBJECT_ARRAY[i].ID == id) 
					return OBJECT_ARRAY[i];
				
//				if(OBJECT_ARRAY[i].TUIO_TYPE == "2Dobj")
//					trace(OBJECT_ARRAY[i].sID + "(" + OBJECT_ARRAY[i].ID + ") == " + id);
			
				if(OBJECT_ARRAY[i].TUIO_TYPE == "2Dobj" && OBJECT_ARRAY[i].sID == id)
//				if(OBJECT_ARRAY[i].TUIO_TYPE == "2Dobj" && OBJECT_ARRAY[i].ID == id)
					return OBJECT_ARRAY[i];
				


//				if(OBJECT_ARRAY[i].ID == id)
//				{
//					return OBJECT_ARRAY[i];
//				}
			}
			return null;
		}
		

		public static function getIMObjectById(id:Number):IMObject
		{
			for(var i:int=0; i<IMOBJECT_ARRAY.length; i++)
			{
				if(IMOBJECT_ARRAY[i].ID == id)
				{
					return IMOBJECT_ARRAY[i];
				}
			}
			return null;
		}				
//---------------------------------------------------------------------------------------------------------------------------------------------
		public static function startSocket(e:Event):void
		{ 
			try
			{			
				SOCKET.connect(HOST, PORT);
			} 
			catch (e:Error) { }		
		}
		public static function stopSocket(e:Event):void
		{ 	
				try
			{			
				SOCKET.close();
			} 
			catch (e:Error) { }	
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
// PRIVATE METHODS
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function processMessage(msg:XML):void
		{
			// SPEEDTEST: For speed testing the function
			if (DEBUG)
			var time:Number = getTimer();
			
			var fseq:String;
			var node:XML;
			
			for each(node in msg.MESSAGE)
			{
				if(node.ARGUMENT[0] && node.ARGUMENT[0].@VALUE == "fseq")
					fseq = node.ARGUMENT[1].@VALUE;					
			}
			
			trace(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
			for each(node in msg.MESSAGE)
			{
				if(node.ARGUMENT[0] && node.ARGUMENT[0].@VALUE == "alive")
				{
					
					for each (var obj1:TUIOObject in OBJECT_ARRAY)
					{
						obj1.TUIO_ALIVE = false;
					}
					
					var newIdArray:Array = new Array();					
					for each(var aliveItem:XML in node.ARGUMENT.(@VALUE != "alive"))
					{
//						trace("alive: " + aliveItem.@VALUE);
						if(getObjectById(aliveItem.@VALUE)){
							getObjectById(aliveItem.@VALUE).TUIO_ALIVE = true;
//							trace("alive: " + aliveItem.@VALUE + " true" );
						}
//						else
// 							trace("alive: " + aliveItem.@VALUE + " false" );

					}   
					ID_ARRAY = newIdArray;
				}
			}				
													
			for each(node in msg.MESSAGE)
			{
				if(node.ARGUMENT[0])
				{
					var type:String;	
					if(node.@NAME == "/tuio/2Dobj")
					{
						
						// fixme: ensure everything is working properly here.
												
						type = node.ARGUMENT[0].@VALUE;				
						if(type == "set")
						{
							var sID = node.ARGUMENT[1].@VALUE;
							var id = node.ARGUMENT[2].@VALUE;
							var x = Number(node.ARGUMENT[3].@VALUE) * IMSTAGE.stageWidth;
							var y = Number(node.ARGUMENT[4].@VALUE) * IMSTAGE.stageHeight;
//							var x = Number(node.ARGUMENT[3].@VALUE) * STAGE.stageWidth;
//							var y = Number(node.ARGUMENT[4].@VALUE) * STAGE.stageHeight;
							var a = Number(node.ARGUMENT[5].@VALUE);
							var X = Number(node.ARGUMENT[6].@VALUE);
							var Y = Number(node.ARGUMENT[7].@VALUE);
							var A = Number(node.ARGUMENT[8].@VALUE);
							var m = node.ARGUMENT[9].@VALUE;
							var r = node.ARGUMENT[10].@VALUE;

							
//							// send object update event..							
							var objArray:Array = STAGE.getObjectsUnderPoint(new Point(x, y));
							var stagePoint:Point = new Point(x,y);					
							var displayObjArray:Array = STAGE.getObjectsUnderPoint(stagePoint);							
							var dobj = null;
//							
//							trace("displayObjArray.length: " + displayObjArray.length);
							if(displayObjArray.length > 0){								
								dobj = displayObjArray[displayObjArray.length-1];
//								trace("dobj: " + dobj);
							}										
						
//							var tuioobj:TUIOObject = getObjectById(id);
							var tuioobj:TUIOObject = getObjectById(sID);
							
							if(tuioobj == null)
							{
								tuioobj = new TUIOObject("2Dobj", id, x, y, X, Y, sID, a, 0, 0, dobj);
								STAGE.addChild(tuioobj.TUIO_CURSOR);
								
								OBJECT_ARRAY.push(tuioobj);
								tuioobj.notifyCreated();
								
								trace(id + "(" + sID + ") >> 2Dobj Created, sID: " + sID +"");
																
							} else {
								tuioobj.TUIO_CURSOR.x = x;
								tuioobj.TUIO_CURSOR.y = y;
								tuioobj.x = x;
								tuioobj.y = y;
								tuioobj.oldX = tuioobj.x;
								tuioobj.oldY = tuioobj.y;
								tuioobj.dX = X;
								tuioobj.dY = Y;
								
								tuioobj.setObjOver(dobj);
								tuioobj.notifyMoved();
								
								trace(id + "(" + sID + ") >> 2Dobj NotifyMoved!");								
							}
							
							try
							{
								if(tuioobj.TUIO_OBJECT && tuioobj.TUIO_OBJECT.parent)
								{							
									
//									var localPoint:Point = tuioobj.TUIO_OBJECT.parent.globalToLocal(stagePoint);							
//									tuioobj.TUIO_OBJECT.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_MOVE, true, false, x, y, localPoint.x, localPoint.y, tuioobj.oldX, tuioobj.oldY, tuioobj.TUIO_OBJECT, false,false,false, true, m, "2Dobj", id, sID, a));

									var localPoint:Point = tuioobj.TUIO_OBJECT.parent.globalToLocal(stagePoint);							
//									tuioobj.TUIO_OBJECT.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_MOVE, true, false, x, y, localPoint.x, localPoint.y, tuioobj.dX, tuioobj.dY, tuioobj.oldX, tuioobj.oldY, tuioobj.TUIO_OBJECT, false,false,false, true, m, "2Dobj", id, sID, a));
									
									tuioobj.TUIO_OBJECT.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_MOVE, true, false, x, y, localPoint.x, localPoint.y, tuioobj.dX, tuioobj.dY, tuioobj.oldX+100, tuioobj.oldY, tuioobj.TUIO_OBJECT, false,false,false, true, m, "2Dobj", id, sID, a));
								}
							} catch (e)
							{
							}
						}
						
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
//								x = Number(node.ARGUMENT[2].@VALUE);
//								y = Number(node.ARGUMENT[3].@VALUE);
								X = Number(node.ARGUMENT[4].@VALUE);
								Y = Number(node.ARGUMENT[5].@VALUE);
								m = Number(node.ARGUMENT[6].@VALUE);
								
								if(node.ARGUMENT[7])
									wd = Number(node.ARGUMENT[7].@VALUE) * IMSTAGE.stageWidth;						
//									wd = Number(node.ARGUMENT[7].@VALUE);
								
								if(node.ARGUMENT[8])
									ht = Number(node.ARGUMENT[8].@VALUE) * IMSTAGE.stageHeight;
							} catch (e:Error)
							{
								trace("Error Parsing TUIO XML");
							}
							
//							trace("set 2Dcur : ("+id + ")" + x + " " + y + " " + wd + " " + ht);
							

							var stagePoint:Point = new Point(x,y);					
							var displayObjArray:Array = STAGE.getObjectsUnderPoint(stagePoint);
							var dobj:DisplayObject = null;
							
//							trace("displayObjArray.length: " + displayObjArray.length);
							if(displayObjArray.length > 0){								
								dobj = displayObjArray[displayObjArray.length-1];
//								trace("dobj: " + dobj);
							}	
																				
							var tuioobj:TUIOObject = getObjectById(id);
							if(tuioobj == null)
							{
								tuioobj = new TUIOObject("2Dcur", id, x, y, X, Y, -1, 0, wd, ht, dobj);
								STAGE.addChild(tuioobj.TUIO_CURSOR);								
								OBJECT_ARRAY.push(tuioobj);
								tuioobj.notifyCreated();
								
								trace(id + " >> 2Dcur Created!");
								trace("OBJECT_ARRAY.length: " + OBJECT_ARRAY.length);
								dirty = 3; // need to clean dirty twice
								trace("dirty = true;");
								
							} else {
								tuioobj.TUIO_CURSOR.x = x;
								tuioobj.TUIO_CURSOR.y = y;
								tuioobj.oldX = tuioobj.x;
								tuioobj.oldY = tuioobj.y;
								tuioobj.x = x;
								tuioobj.y = y;

								tuioobj.width = wd;
								tuioobj.height = ht;
								tuioobj.area = wd * ht;								
								tuioobj.dX = X * IMSTAGE.stageWidth;
								tuioobj.dY = Y * IMSTAGE.stageHeight;
								tuioobj.setObjOver(dobj);
								
								var d:Date = new Date();																
								if(!( int(Y*1000) == 0 && int(Y*1000) == 0) )
								{
									tuioobj.notifyMoved();
									trace(id + " >> 2Dcur Moved");
								}
								
								
								if( int(Y*250) == 0 && int(Y*250) == 0) {
									if(Math.abs(d.time - tuioobj.lastModifiedTime) > HOLD_THRESHOLD)
									{
										for(var ndx:int=0; ndx<EVENT_ARRAY.length; ndx++)
										{
											EVENT_ARRAY[ndx].dispatchEvent(tuioobj.getTouchEvent(TouchEvent.LONG_PRESS));
										}
										tuioobj.lastModifiedTime = d.time;																		
									}
								}								
								
								/*
								 * // SWIP RIGHT OR LEFT (with thresholds)
								if(blobs.length == 1)
								{										
								if((blobs[0].history.length) >= 10 && (blobs[0].history.length) <= 50 ){	
								if((my-blobs[0].history[0].y) <= 25 && (my-blobs[0].history[0].y) >= -25){
								if((mx-blobs[0].history[0].x) >= 75 || (mx-blobs[0].history[0].x) <= -75){
								if(mx > blobs[0].history[0].x){
							 	 EVENT_ARRAY[ndx].dispatchEvent(tuioobj.getTouchEvent(TouchEvent.SWIPE_RIGHT));
								}
							    else{
								   EVENT_ARRAY[ndx].dispatchEvent(tuioobj.getTouchEvent(TouchEvent.SWIPE_LEFT));
								}
								}
								}//else()		
								}
								} 								 
								 */
							}

							try
							{
								if(tuioobj.TUIO_OBJECT && tuioobj.TUIO_OBJECT.parent)
								{							
									var localPoint:Point = tuioobj.TUIO_OBJECT.parent.globalToLocal(stagePoint);							
									tuioobj.TUIO_OBJECT.dispatchEvent(new TouchEvent(TouchEvent.MOUSE_MOVE, true, false, x, y, localPoint.x, localPoint.y, tuioobj.dX, tuioobj.dY, tuioobj.oldX, tuioobj.oldY, tuioobj.TUIO_OBJECT, false,false,false, true, m, "2Dcur", id, 0, 0));
								}
							} catch (e:Error)
							{
								trace("(" + e + ") Dispatch event failed " + tuioobj.ID);
							}
						}
					}
				}
			}
			
			
			for each(node in msg.MESSAGE)
			{
				{
					if(node.@NAME == "/tuio/BoundingBox")
					{
						type = node.ARGUMENT[0].@VALUE;				
						if(type == "set"){
							
							var rx1:Number, 
								ry1:Number,
								rx2:Number,
								ry2:Number;
							
							try 
							{
								id = node.ARGUMENT[1].@VALUE;
								rx1 = Number(node.ARGUMENT[2].@VALUE) * IMSTAGE.stageWidth;
								ry1 = Number(node.ARGUMENT[3].@VALUE) * IMSTAGE.stageHeight;
								rx2 = Number(node.ARGUMENT[4].@VALUE) * IMSTAGE.stageWidth;
								ry2 = Number(node.ARGUMENT[5].@VALUE) * IMSTAGE.stageHeight;								
							} catch (e:Error)
							{
								trace("imPro: Error Parsing TUIO XML");
							}
							
							var imObj:IMObject = getIMObjectById(id);
							if(imObj == null)
							{
								imObj = new IMObject("BoundingBox", id, rx1, ry1, rx2, ry2, -1);
	//							STAGE.addChild(tuioobj.TUIO_CURSOR);								
								IMOBJECT_ARRAY.push(imObj);
								imObj.notifyCreated();
							} else {
								imObj.rx1 = rx1;
								imObj.ry1 = ry1;
								imObj.rx2 = rx2;
								imObj.ry2 = ry2;							
							}
							
							imObj.notifyMoved();
							//imObj.TUIO_OBJECT.dispatchEvent(new HResEvent(HResEvent.POSE_CHANGE, true, false, rx, ry, rw, rh, id, 0));						
						}				
					}
					else if(node.@NAME == "/tuio/originalPts"){
						type = node.ARGUMENT[0].@VALUE;				
						if(type == "set"){
							
							var px1:Number,	py1:Number,
								px2:Number,	py2:Number,
								px3:Number,	py3:Number,
								px4:Number,	py4:Number;
							
							try 
							{
								id = node.ARGUMENT[1].@VALUE;
								px1 = Number(node.ARGUMENT[2].@VALUE) * IMSTAGE.stageWidth;
								py1 = Number(node.ARGUMENT[3].@VALUE) * IMSTAGE.stageHeight;
								px2 = Number(node.ARGUMENT[4].@VALUE) * IMSTAGE.stageWidth;
								py2 = Number(node.ARGUMENT[5].@VALUE) * IMSTAGE.stageHeight;
								px3 = Number(node.ARGUMENT[6].@VALUE) * IMSTAGE.stageWidth;
								py3 = Number(node.ARGUMENT[7].@VALUE) * IMSTAGE.stageHeight;
								px4 = Number(node.ARGUMENT[8].@VALUE) * IMSTAGE.stageWidth;
								py4 = Number(node.ARGUMENT[9].@VALUE) * IMSTAGE.stageHeight;
								
							} catch (e:Error)
							{
								trace("imPro: Error Parsing TUIO XML");
							}
							
							var imObj:IMObject = getIMObjectById(id);
							if(imObj != null){
								imObj.setOrignialPts(px1, py1, px2, py2, px3, py3, px4, py4);
							}
						}
					}
				}
			}
						
			frameIndex++;				
							
			var numFinger:Number = 0;
			for each(var tuioobj:TUIOObject in OBJECT_ARRAY)
				if(tuioobj.TUIO_TYPE == "2Dcur" && !tuioobj.NEW2)
					numFinger++;			
			
			trace("Number of Fingers not New: " + numFinger + " (" + OBJECT_ARRAY.length + ")");
			
			
			if(numFinger > 0){
				// calculate translation			
				var curCenter:Point = new Point();							
				for each(var tuioobj:TUIOObject in OBJECT_ARRAY){
					if(tuioobj.TUIO_TYPE == "2Dcur"){
						curCenter.x += tuioobj.x;
						curCenter.y += tuioobj.y;
					} 									
				}
				curCenter.x /= numFinger;
				curCenter.y /= numFinger;
				translation.x = curCenter.x - preCenter.x;
				translation.y = curCenter.y - preCenter.y;
				
				// ignore the frame if too small translation
	//			if( Math.sqrt(translate.x*translate.x+translate.y*translate.y) < 2)
	//				return;
									
				preCenter.x = curCenter.x;
				preCenter.y = curCenter.y;
						
				// calculate scale
				if(numFinger > 1){
					var curAveLength:Number = 0;
					var dx:Number, dy:Number;
					for each(var tuioobj:TUIOObject in OBJECT_ARRAY){
						if(tuioobj.TUIO_TYPE == "2Dcur" && !tuioobj.NEW2){
							dx = (tuioobj.x - curCenter.x);
							dy = (tuioobj.y - curCenter.y);
							curAveLength += Math.sqrt(dx * dx + dy * dy);
						} 	
					}

					
					curAveLength /= numFinger;

					trace("cur: " + curAveLength + " , pre: " + preAveLength);
					
					if(preAveLength != 0)
						scale = curAveLength / preAveLength;
					preAveLength = curAveLength;
					trace("acur: " + curAveLength + " , apre: " + preAveLength);
					

				}else
					scale = 1;
				
				if(dirty > 0){
					translation.x = 0;
					translation.y = 0;
					scale = 1;
					
					dirty--;
					trace("dirty = false (" + dirty + ")");
				}
				
//				trace("translation: " + translation.x + ", " + translation.y);
//				trace("scale: " + scale);
				

			}
			
			
			if(DEBUG)
			{
				DEBUG_TEXT.text = "";
				DEBUG_TEXT.visible = false;
			}	

//			trace("OBJECT_ARRAY.length: " + OBJECT_ARRAY.length);
			for (var i:int=0; i<OBJECT_ARRAY.length; i++ )
			{	
//				trace("OBJECT_ARRAY[i]: " + OBJECT_ARRAY[i]);
				
				if(OBJECT_ARRAY[i].TUIO_ALIVE == false)
				{
					trace("STAGE.removeChild: " + OBJECT_ARRAY[i].ID);
					
					dirty = 3;
					
					OBJECT_ARRAY[i].notifyRemoved();
					STAGE.removeChild(OBJECT_ARRAY[i].TUIO_CURSOR);
					OBJECT_ARRAY.splice(i, 1);
					
					trace("OBJECT_ARRAY.length: " + OBJECT_ARRAY.length);
					i--;

				} else {
					if(DEBUG)
					{	
						var tmp:int = (int(OBJECT_ARRAY[i].area)/-100000);
						DEBUG_TEXT.appendText("  " + (i + 1) +" - " +OBJECT_ARRAY[i].ID + "  X:" + int(OBJECT_ARRAY[i].x) + "  Y:" + int(OBJECT_ARRAY[i].y) +
						"  A:" + int(tmp) + "  \n");	
						DEBUG_TEXT.visible = true;
					}
					}
			}
		// SPEEDTEST END
		//trace("SPEEDTEST: " +  time + " - "  + getTimer() + " = " + (getTimer() - time));
		if(DEBUG)
		DEBUG_TEXT.appendText("  T - " + (getTimer() - time)+"  \n");	
		}
		
		public static function Scale():Number{
			return scale;
		}
		public static function Translation():Point{
			return translation;
		}
		public static function FrameIndex():Number{
			return frameIndex;
		}
		public static function Center():Point{
			return preCenter;	
		}
		
//---------------------------------------------------------------------------------------------------------------------------------------------
        private static function activateDebugMode():void 
        {
  				var format:TextFormat = new TextFormat("Verdana", 10, 0xFFFFFF);
				DEBUG_TEXT = new TextField();       
				DEBUG_TEXT.defaultTextFormat = format;
				DEBUG_TEXT.autoSize = TextFieldAutoSize.LEFT;
				DEBUG_TEXT.background = true;	
				DEBUG_TEXT.backgroundColor = 0x000000;	
				DEBUG_TEXT.border = true;	
				DEBUG_TEXT.borderColor = 0x333333;							
				DEBUG_TEXT.x = IMSTAGE.stageWidth-200;
				DEBUG_TEXT.y = 25;
				STAGE.addChild( DEBUG_TEXT );						
				STAGE.setChildIndex(DEBUG_TEXT, STAGE.numChildren-1);	
		
				RECORDED_XML = <OSCPackets></OSCPackets>;	
				//
				DEBUG_BUTTON = new Sprite();			
				DEBUG_BUTTON.graphics.beginFill(0xFFFFFF);
				DEBUG_BUTTON.graphics.drawRect(10, 25, 50, 50);			
				DEBUG_BUTTON.addEventListener(MouseEvent.CLICK, toggleDebug);		
				DEBUG_BUTTON.addEventListener(TouchEvent.CLICK, toggleDebug);	
				DEBUG_BUTTON.alpha = 0.85;		 
				STAGE.addChildAt(DEBUG_BUTTON, STAGE.numChildren-1);								
					
				RECORD_BUTTON = new Sprite();	
				RECORD_BUTTON.graphics.beginFill(0xFF0000);
				RECORD_BUTTON.graphics.drawRect(10, 75, 50, 50);	
				RECORD_BUTTON.addEventListener(MouseEvent.CLICK, toggleRecord);		
				RECORD_BUTTON.addEventListener(TouchEvent.CLICK, toggleRecord);	
				RECORD_BUTTON.alpha = 0.25; 	
				STAGE.addChildAt(RECORD_BUTTON, STAGE.numChildren-1);	
						
				PLAYBACK_BUTTON = new Sprite();	
				PLAYBACK_BUTTON.graphics.beginFill(0x00FF00);
				PLAYBACK_BUTTON.graphics.drawRect(10, 125, 50, 50);	
				PLAYBACK_BUTTON.addEventListener(MouseEvent.CLICK, togglePlayback);		
				PLAYBACK_BUTTON.addEventListener(TouchEvent.CLICK, togglePlayback);	
				PLAYBACK_BUTTON.alpha = 0.25;			
				STAGE.addChildAt(PLAYBACK_BUTTON, STAGE.numChildren - 1); 
				
				//STAGE.addEventListener(MouseEvent.MOUSE_MOVE, socketStatus);		
				//STAGE.addEventListener(TouchEvent.MOUSE_MOVE, socketStatus);					
        }
		
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function socketStatus(e:Event):void
		{ 		
				SOCKET_STATUS = SOCKET.connected;
				
				if (!SOCKET_STATUS) 
				{	
					DEBUG_TEXT.text = " TUIO Socket Not Found... \n Host - "+HOST+"\n Port - "+PORT+" ";
					STAGE.addEventListener(Event.ENTER_FRAME, startSocket);
					//STAGE.removeEventListener(MouseEvent.MOUSE_MOVE, socketStatus);		
					//STAGE.removeEventListener(TouchEvent.MOUSE_MOVE, socketStatus);
					DEBUG_BUTTON.graphics.clear();
					DEBUG_BUTTON.graphics.beginFill(0xFF0000,0.5);
					DEBUG_BUTTON.graphics.drawRect(10, 25, 50, 50);	
					DEBUG_TEXT.x = 65;
				} else 
				{
					DEBUG_TEXT.x = IMSTAGE.stageWidth-200;

					DEBUG_TEXT.text = "";
					STAGE.removeEventListener(Event.ENTER_FRAME, startSocket);
					DEBUG_BUTTON.graphics.clear();
					DEBUG_BUTTON.graphics.beginFill(0xFFFFFF,1);
					DEBUG_BUTTON.graphics.drawRect(10, 25, 50, 50);	
				}
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function togglePlayback(e:Event):void
		{ 	
			if (PLAYBACK) return;
			PLAYBACK_URL = "http://touchlib.com/amfphp/services/test.xml";		
			if(PLAYBACK_URL != "")
				 {	
					PLAYBACK_BUTTON.alpha = 0.9;
					PLAYBACK_LOADER = new URLLoader();
					PLAYBACK_LOADER.addEventListener("complete", xmlPlaybackLoaded);	
					PLAYBACK_LOADER.addEventListener( ProgressEvent.PROGRESS, onProgressHandler);		
					PLAYBACK_LOADER.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);	
					PLAYBACK_LOADER.load(new URLRequest(PLAYBACK_URL));					
				}
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function xmlPlaybackLoaded(e:Event):void 
        {
			trace("Playing from XML file...");
			PLAYBACK_XML = new XML(PLAYBACK_LOADER.data);						
			PLAYBACK_LOADER.close();	
			FRAME_COUNT = PLAYBACK_XML.OSCPACKET.length();
			STAGE.addEventListener(Event.ENTER_FRAME, frameUpdate);
			FRAME_RATE = STAGE.frameRate;
			STAGE.frameRate = 30;				
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function frameUpdate(e:Event):void
		{
			if(PLAYBACK_XML && PLAYBACK_XML.OSCPACKET && PLAYBACK_XML.OSCPACKET[0])
			{	
				RECORD_BUTTON.removeEventListener(MouseEvent.CLICK, toggleRecord);		
				RECORD_BUTTON.removeEventListener(TouchEvent.CLICK, toggleRecord);	
				//
				PLAYBACK = true;
				processMessage(PLAYBACK_XML.OSCPACKET[0]);
				delete PLAYBACK_XML.OSCPACKET[0];		
				DEBUG_TEXT.visible = true;
				DEBUG_TEXT.appendText ("  " + "F - " + PLAYBACK_XML.OSCPACKET.length() + " / " + FRAME_COUNT + "  ");
				if (PLAYBACK_XML.OSCPACKET.length() < 1) 
				{ 					
					RECORD_BUTTON.addEventListener(MouseEvent.CLICK, toggleRecord);		
					RECORD_BUTTON.addEventListener(TouchEvent.CLICK, toggleRecord);	
					//
					PLAYBACK = false;	
					DEBUG_TEXT.text = '';
					PLAYBACK_BUTTON.alpha = 0.25;		
					STAGE.removeEventListener(Event.ENTER_FRAME, frameUpdate);		
					trace('START FPS - ' + FRAME_RATE);
					trace('PLAYBACK FPS - ' + STAGE.frameRate);	
					STAGE.frameRate = FRAME_RATE;
					trace('END FPS - '+STAGE.frameRate);
				}				
			}
		}		
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function toggleDebug(e:Event):void
		{ 	
			stopSocket(null);
			startSocket(null);		
			
			if(!DEBUG){
			DEBUG=true;	
			e.target.alpha = 0.85;		
			//e.target.scaleX = e.target.scaleY = 1.0;		
			RECORD_BUTTON.visible = true;
			PLAYBACK_BUTTON.visible = true;	
			DEBUG_TEXT.visible = true;		
			//DEBUG_TEXT.text = '';
			}
			else{
			DEBUG=false;
			e.target.alpha = 0.25;		
			//e.target.scaleX = e.target.scaleY = 0.5;		
			RECORD_BUTTON.visible = false;
			PLAYBACK_BUTTON.visible = false;
			DEBUG_TEXT.visible = false;
			//DEBUG_TEXT.text = '';
			}	
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function toggleRecord(e:Event):void
		{ 	
			//
			var RESPONDER:Responder = new Responder(saveSessionResult, onFault);
			if(!RECORDING){
			PLAYBACK_BUTTON.removeEventListener(MouseEvent.CLICK, togglePlayback);		
			PLAYBACK_BUTTON.removeEventListener(TouchEvent.CLICK, togglePlayback);	
			//
			RECORDING = true;
			e.target.alpha = 0.9;		
			trace('-----------------------------------------------------------------------------------------------------');		
			trace('-------------------------------------- Record ON ----------------------------------------------------');
			trace('-----------------------------------------------------------------------------------------------------');	
			SERVICE.call("touchlib.clearSession", RESPONDER);			
			RECORDED_XML = <OSCPackets></OSCPackets>;			
			//
			}
			else {
			PLAYBACK_BUTTON.addEventListener(MouseEvent.CLICK, togglePlayback);		
			PLAYBACK_BUTTON.addEventListener(TouchEvent.CLICK, togglePlayback);	
			//
			RECORDING = false;
			e.target.alpha = 0.25;			
			trace('-----------------------------------------------------------------------------------------------------');		
			trace('-------------------------------------- Record OFF ---------------------------------------------------');
			trace('-----------------------------------------------------------------------------------------------------');	
			SERVICE.call("touchlib.saveSession", RESPONDER, RECORDED_XML.toXMLString());
			//trace(RECORDED_XML.toString());					
			RECORDED_XML = <OSCPackets></OSCPackets>;
			trace('-------------------------------------- Recording END ------------------------------------------------');			
			}
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
		private static function saveSessionResult(result:String):void
		{	
		DEBUG_TEXT.text = result;
		trace(result);			
		}
//---------------------------------------------------------------------------------------------------------------------------------------------
        private static function dataHandler(e:DataEvent):void 
        {           			
			if(RECORDING)
				RECORDED_XML.appendChild( XML(e.data) );
			
			try{
				processMessage(XML(e.data));
			}catch(e:Error){
			}
			
        } 
//---------------------------------------------------------------------------------------------------------------------------------------------   			
		private static function closeHandler(event:Event):void 
        {
            //trace("closeHandler: " + event);				
			//socketStatus(null);		
        }
     	private static function connectHandler(event:Event):void 
     	{	
			//trace("connectHandler: " + event);				
			//socketStatus(null);			
        }               
		private static function onFault(e:Event ):void
		{
			//trace("There was a problem: " + e.description);
		}	
        private static function ioErrorHandler(event:IOErrorEvent):void 
        {
            //trace("ioErrorHandler: " + event);
        }
		private static function onProgressHandler(e:ProgressEvent):void
		{	
		var percent:Number = 100*(e.target.bytesLoaded/e.target.bytesTotal);			
		DEBUG_TEXT.visible = true;
		DEBUG_TEXT.text = "  Loading... "+int(percent)+"% ";
		}
        private static function securityErrorHandler(event:SecurityErrorEvent):void 
        {
            //trace("securityErrorHandler: " + event);
        }
//---------------------------------------------------------------------------------------------------------------------------------------------
    }
}