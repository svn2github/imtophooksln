using System;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Collections;

namespace SocketSystem
{
    //=============================================
    /// <summary> This class abstracts a socket </summary>
    public class CSocketClient
    {
        // Delegate Method Types
        /// <summary> DelType: Called when a message is received </summary>
        public delegate void MESSAGE_HANDLER(CSocketClient pSocket, Int32 iNumberOfBytes);

        /// <summary> DelType: Called when a connection is closed </summary>
        public delegate void CLOSE_HANDLER(CSocketClient pSocket);

        /// <summary> DelType: Called when a socket error occurs </summary>
        public delegate void ERROR_HANDLER(CSocketClient pSocket, Exception pException);

        // Private Properties
        private NetworkStream m_pNetworkStream;
        private TcpClient m_pTcpClient;
        private AsyncCallback m_pCallbackReadMethod;
        private AsyncCallback m_pCallbackWriteMethod;
        private MESSAGE_HANDLER m_pfnMessageHandler;
        private CLOSE_HANDLER m_pfnCloseHandler;
        private ERROR_HANDLER m_pfnErrorHandler;
        private Boolean m_bDisposeFlag;

        private String m_strName;
        private String m_strIpAddress;
        private Int16 m_iPort;
        private Object m_pUserArg;
        private Byte[] m_bytRawBuffer;
        private Int32 m_iSizeOfRawBuffer;

        private CSocketServer m_pSocketServer;
        private Int32 m_iSocketListIndex;
        private Socket m_pClientSocket;

        // Public Properties
        
        // Constructor, Finalize, Dispose
        //*************************************************
        /// <summary> Constructor for client support </summary>
        /// <param name="iSizeOfRawBuffer"> SimType: The size of the raw buffer </param>
        /// <param name="pUserArg"> RefType: A Reference to the Users arguments </param>
        /// <param name="pfnMessageHandler"> DelType: Reference to the user defined message handler method </param>
        /// <param name="pfnCloseHandler"> DelType: Reference to the user defined close handler method </param>
        /// <param name="pfnErrorHandler"> DelType: Reference to the user defined error handler method </param>
        public CSocketClient(Int32 iSizeOfRawBuffer, Object pUserArg,
          MESSAGE_HANDLER pfnMessageHandler, CLOSE_HANDLER pfnCloseHandler, ERROR_HANDLER pfnErrorHandler)
        {
            // Create the raw buffer
            GetSizeOfRawBuffer = iSizeOfRawBuffer;
            GetRawBuffer = new Byte[GetSizeOfRawBuffer];
            // Save the user argument
            GetUserArg = pUserArg;
            // Set the handler methods
            GetMessageHandler = pfnMessageHandler;
            GetCloseHandler = pfnCloseHandler;
            GetErrorHandler = pfnErrorHandler;
            // Set the async socket method handlers
            GetCallbackReadMethod = new AsyncCallback(ReceiveComplete);
            GetCallbackWriteMethod = new AsyncCallback(SendComplete);

            // Init the dispose flag
            IsDisposed = false;
        }

        //**********************************************
        /// <summary> Constructor for SocketServer Suppport </summary>
        /// <param name="pSocketServer"> RefType: A Reference to the parent SocketServer </param>
        /// <param name="pClientSocket"> RetType: The Socket object we are encapsulating </param>
        /// <param name="iSocketListArray"> SimType: The index of the SocketServer Socket List Array </param>
        /// <param name="strIpAddress"> RetType: The IpAddress of the remote server </param>
        /// <param name="iPort"> SimType: The Port of the remote server </param>
        /// <param name="pfnMessageHandler"> DelType: Reference to the user defined message handler function </param>
        /// <param name="pfnCloseHandler"> DelType: Reference to the user defined close handler function </param>
        /// <param name="pfnErrorHandler"> DelType: Reference to the user defined error handler function </param>
        /// <param name="iSizeOfRawBuffer"> SimType: The size of the raw buffer </param>
        /// <param name="pUserArg"> RefType: A Reference to the Users arguments </param>
        public CSocketClient (CSocketServer pSocketServer, Socket pClientSocket, Int32 iSocketListArray, String strIpAddress, Int16 iPort,
                             Int32 iSizeOfRawBuffer, Object pUserArg, MESSAGE_HANDLER pfnMessageHandler, CLOSE_HANDLER pfnCloseHandler,
                             ERROR_HANDLER pfnErrorHandler)
        {
            // Create the raw buffer
            GetSizeOfRawBuffer = iSizeOfRawBuffer;
            GetRawBuffer = new Byte[GetSizeOfRawBuffer];
            // Save the user argument
            GetUserArg = pUserArg;
            // Set the handler functions
            GetMessageHandler = pfnMessageHandler;
            GetCloseHandler = pfnCloseHandler;
            GetErrorHandler = pfnErrorHandler;
            // Set the async socket function handlers
            GetCallbackReadMethod = new AsyncCallback(ReceiveComplete);
            GetCallbackWriteMethod = new AsyncCallback(SendComplete);
            // Init the dispose flag
            IsDisposed = false;
            // Set reference to SocketServer
            GetSocketServer = pSocketServer;
            // Init the socket references
            GetClientSocket = pClientSocket;
            GetSocketListIndex = iSocketListArray;
            // Set the Ipaddress and Port
            GetIpAddress = strIpAddress;
            GetPort = iPort;
            // Init the NetworkStream reference
            GetNetworkStream = new NetworkStream(GetClientSocket);
            // Set these socket options
            GetClientSocket.SetSocketOption(System.Net.Sockets.SocketOptionLevel.Socket, System.Net.Sockets.SocketOptionName.ReceiveBuffer, 1048576);
            GetClientSocket.SetSocketOption(System.Net.Sockets.SocketOptionLevel.Socket, System.Net.Sockets.SocketOptionName.SendBuffer, 1048576);
            GetClientSocket.SetSocketOption(System.Net.Sockets.SocketOptionLevel.Socket, System.Net.Sockets.SocketOptionName.DontLinger, 1);
            GetClientSocket.SetSocketOption(System.Net.Sockets.SocketOptionLevel.Tcp, System.Net.Sockets.SocketOptionName.NoDelay, 1);
            // Wait for a message
            Receive();
        }

        //**************************************************
        /// <summary> Finialize </summary>
        ~CSocketClient()
        {
            if (!IsDisposed)
                Dispose();
        }

        //********************************************
        /// <summary> Dispose </summary>
        public void Dispose()
        {
            try
            {
                // Flag that dispose has been called
                IsDisposed = true;
                // Disconnect the client from the server
                Disconnect();
            }
            catch
            {
            }
            // Remove the socket from the list
            if (GetSocketServer != null)
                GetSocketServer.RemoveSocket(this);
        }

        public String GetClientName { get { return m_strName; } set { m_strName = value; } }

        // Private Methods
        /// <summary> RefType: A network stream object </summary>
        public NetworkStream GetNetworkStream { get { return m_pNetworkStream; } set { m_pNetworkStream = value; } }
        /// <summary> RefType: A TcpClient object for socket connection </summary>
        private TcpClient GetTcpClient { get { return m_pTcpClient; } set { m_pTcpClient = value; } }
        /// <summary> RetType: A callback object for processing recieved socket data </summary>
        private AsyncCallback GetCallbackReadMethod { get { return m_pCallbackReadMethod; } set { m_pCallbackReadMethod = value; } }
        /// <summary> RetType: A callback object for processing send socket data </summary>
        private AsyncCallback GetCallbackWriteMethod { get { return m_pCallbackWriteMethod; } set { m_pCallbackWriteMethod = value; } }
        /// <summary> DelType: A reference to a user supplied function to be called when a socket message arrives </summary>
        private MESSAGE_HANDLER GetMessageHandler { get { return m_pfnMessageHandler; } set { m_pfnMessageHandler = value; } }
        /// <summary> DelType: A reference to a user supplied function to be called when a socket connection is closed </summary>
        private CLOSE_HANDLER GetCloseHandler { get { return m_pfnCloseHandler; } set { m_pfnCloseHandler = value; } }
        /// <summary> DelType: A reference to a user supplied function to be called when a socket error occurs </summary>
        private ERROR_HANDLER GetErrorHandler { get { return m_pfnErrorHandler; } set { m_pfnErrorHandler = value; } }
        /// <summary> SimType: Flag to indicate if the class has been disposed </summary>
        private Boolean IsDisposed { get { return m_bDisposeFlag; } set { m_bDisposeFlag = value; } }
        //*********************************************
        /// <summary> Called when a message arrives </summary>
        /// <param name="ar"> RefType: An async result interface </param>
        private void ReceiveComplete(IAsyncResult ar)
        {

            try
            {
                // Is the Network Stream object valid
                if (GetNetworkStream.CanRead)
                {
                    // Read the current bytes from the stream buffer
                    Int32 iBytesRecieved = GetNetworkStream.EndRead(ar);
                    // If there are bytes to process else the connection is lost
                    if (iBytesRecieved > 0)
                    {
                        try
                        {
                            // A message came in send it to the MessageHandler
                            GetMessageHandler(this, iBytesRecieved);
                        }
                        catch
                        {
                        }
                        // Wait for a new message
                        Receive();
                    }
                    else
                        throw new Exception("Shut Down");
                }
            }
            catch (Exception)
            {
                try
                {
                    // The connection must have dropped call the CloseHandler
                    GetCloseHandler(this);
                }
                catch
                {
                }
                // Dispose of the class
                Dispose();
            }
        }
        //*********************************************
        /// <summary> Called when a message is sent </summary>
        /// <param name="ar"> RefType: An async result interface </param>
        private void SendComplete(IAsyncResult ar)
        {
            try
            {
                // Is the Network Stream object valid
                if (GetNetworkStream.CanWrite)
                    GetNetworkStream.EndWrite(ar);
            }
            catch (Exception)
            {
            }
        }
        
        /// <summary> RefType: The SocketServer for this socket object </summary>
        private CSocketServer GetSocketServer { get { return m_pSocketServer; } set { m_pSocketServer = value; } }

        // Public Methods
        /// <summary> RefType: The IpAddress the client is connect to </summary>
        public String GetIpAddress { get { return m_strIpAddress; } set { m_strIpAddress = value; } }
        /// <summary> SimType: The Port to either connect to or listen on </summary>
        public Int16 GetPort { get { return m_iPort; } set { m_iPort = value; } }
        /// <summary> RefType: A reference to a user defined object </summary>
        public Object GetUserArg { get { return m_pUserArg; } set { m_pUserArg = value; } }
        /// <summary> SimType: A raw buffer to capture data comming off the socket </summary>
        public Byte[] GetRawBuffer { get { return m_bytRawBuffer; } set { m_bytRawBuffer = value; } }
        /// <summary> SimType: Size of the raw buffer for received socket data </summary>
        public Int32 GetSizeOfRawBuffer { get { return m_iSizeOfRawBuffer; } set { m_iSizeOfRawBuffer = value; } }
        //********************************************
        /// <summary> Function used to connect to a server </summary>
        /// <param name="strIpAddress"> RefType: The address to connect to </param>
        /// <param name="iPort"> SimType: The Port to connect to </param>
        public void Connect(String strIpAddress, Int16 iPort)
        {
            try
            {
                if (GetNetworkStream == null)
                {
                    // Set the Ipaddress and Port
                    GetIpAddress = strIpAddress;
                    GetPort = iPort;
                    // Attempt to establish a connection
                    GetTcpClient = new TcpClient(GetIpAddress, GetPort);
                    GetNetworkStream = GetTcpClient.GetStream();
                    // Set these socket options
                    GetTcpClient.ReceiveBufferSize = 1048576;
                    GetTcpClient.SendBufferSize = 1048576;
                    GetTcpClient.NoDelay = true;
                    GetTcpClient.LingerState = new System.Net.Sockets.LingerOption(false, 0);
                    // Start to receive messages
                    Receive();

           
                }
            }
            catch (System.Net.Sockets.SocketException e)
            {
                throw new Exception(e.Message, e.InnerException);
            }
        }
        //********************************************
        /// <summary> Function used to disconnect from the server </summary>
        public void Disconnect()
        {
            // Close down the connection
            if (GetNetworkStream != null)
                GetNetworkStream.Close();
            if (GetTcpClient != null)
                GetTcpClient.Close();
            if (GetClientSocket != null)
                GetClientSocket.Close();
            // Clean up the connection state
            GetClientSocket = null;
            GetNetworkStream = null;
            GetTcpClient = null;
        }
        //***************************************************
        /// <summary> Function to send a string to the server </summary>
        /// <param name="strMessage"> RefType: A string to send </param>
        public void Send(String strMessage)
        {
            if ((GetNetworkStream != null) && (GetNetworkStream.CanWrite))
            {
                
                strMessage += "\0"; // for flash

                // Convert the string into a Raw Buffer
                Byte[] pRawBuffer = System.Text.Encoding.ASCII.GetBytes(strMessage);
                // Issue an asynchronus write
                GetNetworkStream.BeginWrite(pRawBuffer, 0, pRawBuffer.GetLength(0), GetCallbackWriteMethod, null);
                GetNetworkStream.Flush();
            }
            else
                throw new Exception("Socket Closed");
        }
        //************************************************
        /// <summary> Function to send a raw buffer to the server </summary>
        /// <param name="pRawBuffer"> RefType: A Raw buffer of bytes to send </param>
        public void Send(Byte[] pRawBuffer)
        {
            if ((GetNetworkStream != null) && (GetNetworkStream.CanWrite))
            {
                // Issue an asynchronus write
                GetNetworkStream.BeginWrite(pRawBuffer, 0, pRawBuffer.GetLength(0), GetCallbackWriteMethod, null);
            }
            else
                throw new Exception("Socket Closed");
        }
        //**********************************************
        /// <summary> Wait for a message to arrive </summary>
        public void Receive()
        {
            if ((GetNetworkStream != null) && (GetNetworkStream.CanRead))
            {
                // Issue an asynchronous read
                GetNetworkStream.BeginRead(GetRawBuffer, 0, GetSizeOfRawBuffer, GetCallbackReadMethod, null);
            }
            else
                throw new Exception("Socket Closed");
        }
        /// <summary> SimType: Index into the Socket List Array </summary>
        public Int32 GetSocketListIndex { get { return m_iSocketListIndex; } set { m_iSocketListIndex = value; } }
        /// <summary> RefType: The socket for the client connection </summary>
        public Socket GetClientSocket { get { return m_pClientSocket; } set { m_pClientSocket = value; } }
    }


    //=============================================
    /// <summary> This class abstracts a socket server </summary>
    public class CSocketServer
    {
        // Delegate Method Types
        /// <summary> DelType: Called when a message is extracted from the socket </summary>
        public delegate void MESSAGE_HANDLER(CSocketClient pSocket, Int32 iNumberOfBytes);

        /// <summary> DelType: Called when a socket connection is closed </summary>
        public delegate void CLOSE_HANDLER(CSocketClient pSocket);

        /// <summary> DelType: Called when a socket error occurs </summary>
        public delegate void ERROR_HANDLER(CSocketClient pSocket, Exception pException);

        /// <summary> DelType: Called when a socket connection is accepted </summary>
        public delegate void ACCEPT_HANDLER(CSocketClient pSocket);

        // Private Properties
        private TcpListener m_pTcpListener;
        private Thread m_pAcceptThread;
        private ArrayList m_pSocketClientList;
        //private CSocketClient[] m_pSocketClientList;
        private Int32 m_iMaxClientConnections;
        private Int32 m_iSizeOfRawBuffer;
        private Object m_pSocketListCS;
        private Boolean m_bDisposeFlag;

        private String m_strIpAddress;
        private Int16 m_iPort;
        private Object m_pUserArg;

        // Public Properties

        //*********************************************
        /// <summary> Constructor </summary>
        public CSocketServer()
        {
            // Create the critical section object
            GetSocketListCS = new Object();
            // Init the dispose flag
            IsDisposed = false;
        }

        //*********************************************
        /// <summary> Finalize </summary>
        ~CSocketServer()
        {
            // If this object has not been disposed yet
            if (!IsDisposed)
                Stop();
        }

        //***********************************************
        /// <summary> Dispose function to shutdown the SocketManager </summary>
        public void Dispose()
        {
            try
            {
                // Mark the object as disposed
                IsDisposed = true;
                // Stop the server if the thread is running
                if (GetAcceptThread != null)
                    Stop();
            }
            catch
            {
            }
        }

        // Private Methods
        /// <summary> RefType: A TcpListener object to accept socket connections </summary>
        private TcpListener GetTcpListener { get { return m_pTcpListener; } set { m_pTcpListener = value; } }
        /// <summary> RetType: A thread to process accepting socket connections </summary>
        private Thread GetAcceptThread { get { return m_pAcceptThread; } set { m_pAcceptThread = value; } }
        /// <summary> RefTypeArray: An Array of SocketClient objects </summary>
        private ArrayList GetSocketClientList { get { return m_pSocketClientList; } set { m_pSocketClientList = value; } }
        /// <summary> SimType: Maximum number of client connections </summary>
        public Int32 GetMaxClientConnections { get { return m_iMaxClientConnections; } set { m_iMaxClientConnections = value; } }
        /// <summary> SimType: Size of the raw buffer for received socket data </summary>
        private Int32 GetSizeOfRawBuffer { get { return m_iSizeOfRawBuffer; } set { m_iSizeOfRawBuffer = value; } }

        private MESSAGE_HANDLER m_pfnMessageHandler;
        /// <summary> DelType: A reference to a user supplied function to be called when a socket message arrives </summary>
        private MESSAGE_HANDLER GetMessageHandler { get { return m_pfnMessageHandler; } set { m_pfnMessageHandler = value; } }

        private CLOSE_HANDLER m_pfnCloseHandler;
        /// <summary> DelType: A reference to a user supplied function to be called when a socket connection is closed </summary>
        private CLOSE_HANDLER GetCloseHandler { get { return m_pfnCloseHandler; } set { m_pfnCloseHandler = value; } }

        private ERROR_HANDLER m_pfnErrorHandler;
        /// <summary> DelType: A reference to a user supplied function to be called when a socket error occurs </summary>
        private ERROR_HANDLER GetErrorHandler { get { return m_pfnErrorHandler; } set { m_pfnErrorHandler = value; } }

        private ACCEPT_HANDLER m_pfnAcceptHandler;
        /// <summary> DelType: A reference to a user supplied function to be called when a socket connection is accepted </summary>
        private ACCEPT_HANDLER GetAcceptHandler { get { return m_pfnAcceptHandler; } set { m_pfnAcceptHandler = value; } }

        /// <summary> RefType: A synchronization object to protect the class state </summary>
        private Object GetSocketListCS { get { return m_pSocketListCS; } set { m_pSocketListCS = value; } }
        /// <summary> SimType: Flag to indicate if the class is disposing </summary>
        private Boolean IsDisposed { get { return m_bDisposeFlag; } set { m_bDisposeFlag = value; } }

        //*************************************************
        /// <summary> Function to locate an empty slot in the client socket list array </summary>
        /// <returns> Will return the index slot or user defined MaxClientConnections if none found </returns>
        private Int32 LocateSocketIndex()
        {
            Int32 iSocket = GetMaxClientConnections;
            Monitor.Enter(GetSocketListCS);
            try
            {
                // Find an empty slot in the list
                for (iSocket = 0; iSocket < GetMaxClientConnections; ++iSocket)
                    if (GetSocketClientList[iSocket] == null)
                        break;
            }
            catch
            {
            }
            Monitor.Exit(GetSocketListCS);
            return iSocket;
        }
        //************************************************
        /// <summary> Function to process and accept socket connection requests </summary>
        private void AcceptThread()
        {
            Socket pClientSocket = null;
            try
            {
                // Create a new TCPListner and start it up
                GetTcpListener = new TcpListener(Dns.Resolve(GetIpAddress).AddressList[0], GetPort);
                GetTcpListener.Start();
                for (; ; )
                {
                    // If a client connects, accept the connection
                    pClientSocket = GetTcpListener.AcceptSocket();
                    if (pClientSocket.Connected)
                    {
                        // Locate a socket index
                        Int32 iSocketIndex = LocateSocketIndex();
                        // If we got a valid index
                        if (iSocketIndex != GetMaxClientConnections)
                        {
                            // Create a SocketClient object
                            /*
                            GetSocketClientList[iSocketIndex] = new CSocketClient(this,
                              pClientSocket,                                           // The socket object for the connection
                              iSocketIndex,                                            // The index into the SocketClientList
                              //pClientSocket.RemoteEndPoint.ToString().Substring(0, 15), // The IpAddress of the client
                              pClientSocket.RemoteEndPoint.ToString().Trim(),
                              GetPort,                                                 // The port the client connected to
                              GetSizeOfRawBuffer,                                      // The size of the byte array for storing messages
                              GetUserArg,                                              // Application developer state
                              new CSocketClient.MESSAGE_HANDLER(GetMessageHandler),    // Application developer Message Handler
                              new CSocketClient.CLOSE_HANDLER(GetCloseHandler),        // Application developer Close Handler
                              new CSocketClient.ERROR_HANDLER(GetErrorHandler));       // Application developer Error Handler
                             */

                            CSocketClient socket = new CSocketClient(this,
                              pClientSocket,                                           // The socket object for the connection
                              iSocketIndex,                                            // The index into the SocketClientList
                                //pClientSocket.RemoteEndPoint.ToString().Substring(0, 15), // The IpAddress of the client
                              pClientSocket.RemoteEndPoint.ToString().Trim(),
                              GetPort,                                                 // The port the client connected to
                              GetSizeOfRawBuffer,                                      // The size of the byte array for storing messages
                              GetUserArg,                                              // Application developer state
                              new CSocketClient.MESSAGE_HANDLER(GetMessageHandler),    // Application developer Message Handler
                              new CSocketClient.CLOSE_HANDLER(GetCloseHandler),        // Application developer Close Handler
                              new CSocketClient.ERROR_HANDLER(GetErrorHandler));

                            GetSocketClientList.Add(socket);       // Application developer Error Handler

                            // Call the Accept Handler
                            GetAcceptHandler(socket);
                        }
                        else
                        {
                            // Call the Error Handler
                            GetErrorHandler(null, new Exception("Unable To Accept Socket Connection"));
                            // Close the socket connection
                            pClientSocket.Close();
                        }
                    }
                }
            }
            catch (System.Net.Sockets.SocketException e)
            {
                // Did we stop the TCPListener
                if (e.ErrorCode != 10004)
                {
                    // Call the error handler
                    GetErrorHandler(null, e);
                    // Close the socket down if it exists
                    if (pClientSocket != null)
                        if (pClientSocket.Connected)
                            pClientSocket.Close();
                }
            }
            catch (Exception e)
            {
                // Call the error handler
                GetErrorHandler(null, e);
                // Close the socket down if it exists
                if (pClientSocket != null)
                    if (pClientSocket.Connected)
                        pClientSocket.Close();
            }
        }

        // Public Methods
        /// <summary> RefType: The IpAddress to either connect to or listen on </summary>
        public String GetIpAddress { get { return m_strIpAddress; } set { m_strIpAddress = value; } }
        /// <summary> SimType: The Port to either connect to or listen on </summary>
        public Int16 GetPort { get { return m_iPort; } set { m_iPort = value; } }
        /// <summary> RefType: A reference to a user defined object to be passed through the handler functions </summary>
        public Object GetUserArg { get { return m_pUserArg; } set { m_pUserArg = value; } }

        public ArrayList GetSockets()
        {
            return m_pSocketClientList;
        }

        //public void SendMe
        public CSocketClient GetSocket(String pClientName)
        {
            CSocketClient target = null;
            
            foreach (CSocketClient client in m_pSocketClientList)
            {
                if (client !=null && client.GetClientName == pClientName)
                    target = client;
            }

            return target;
        }

        //*********************************************
        /// <summary> Funciton to remove a socket from the list of sockets </summary>
        /// <param name="iSocketListIndex"> SimType: The index of the socket to remove </param>
        public void RemoveSocket(CSocketClient pSocketClient)
        {
            Monitor.Enter(GetSocketListCS);
            try
            {
                /*
                // Is the supplied CSocketClient object valid
                if (pSocketClient == GetSocketClientList[pSocketClient.GetSocketListIndex])
                {
                    // Set the slot to null
                    GetSocketClientList[pSocketClient.GetSocketListIndex] = null;
                }
                 */
                GetSocketClientList.Remove(pSocketClient); 
            }
            catch
            {
            }
            Monitor.Exit(GetSocketListCS);
        }

        //***********************************************
        /// <summary> Function to start the SocketServer </summary>
        /// <param name="strIpAddress"> RefType: The IpAddress to listening on </param>
        /// <param name="iPort"> SimType: The Port to listen on </param>
        /// <param name="iMaxClientConnections"> SimType: Max number of client connections accepted </param>
        /// <param name="iSizeOfRawBuffer"> SimType: Size of the Raw Buffer </param>
        /// <param name="pUserArg"> RefType: User supplied arguments </param>
        /// <param name="pfnMessageHandler"> DelType: Function pointer to the user MessageHandler function </param>
        /// <param name="pfnAcceptHandler"> DelType: Function pointer to the user AcceptHandler function </param>
        /// <param name="pfnCloseHandler"> DelType: Function pointer to the user CloseHandler function </param>
        /// <param name="pfnErrorHandler"> DelType: Function pointer to the user ErrorHandler function </param>
        public void Start(String strIpAddress, Int16 iPort, Int32 iMaxClientConnections, Int32 iSizeOfRawBuffer, Object pUserArg,
                          MESSAGE_HANDLER pfnMessageHandler, ACCEPT_HANDLER pfnAcceptHandler, CLOSE_HANDLER pfnCloseHandler,
                          ERROR_HANDLER pfnErrorHandler)
        {
            // Is an AcceptThread currently running
            if (GetAcceptThread == null)
            {
                // Set connection values
                GetIpAddress = strIpAddress;
                Console.WriteLine("GetIpAddress: " + GetIpAddress);
                GetPort = iPort;
                GetMaxClientConnections = iMaxClientConnections;

                // Init the array of CSocketClient references
                //GetSocketClientList = new CSocketClient[iMaxClientConnections];
                GetSocketClientList = new ArrayList();


                // Save the Handler Functions
                GetMessageHandler = pfnMessageHandler;
                GetAcceptHandler = pfnAcceptHandler;
                GetCloseHandler = pfnCloseHandler;
                GetErrorHandler = pfnErrorHandler;

                // Save the buffer size and user arguments
                GetSizeOfRawBuffer = iSizeOfRawBuffer;
                GetUserArg = pUserArg;

                // Start the listening thread if one is currently not running
                ThreadStart tsThread = new ThreadStart(AcceptThread);
                GetAcceptThread = new Thread(tsThread);
                GetAcceptThread.Name = "Accept";
                GetAcceptThread.Start();
            }
        }

        //*********************************************
        /// <summary> Function to stop the SocketServer.  It can be restarted with Start </summary>
        public void Stop()
        {
            // Abort the accept thread
            if (GetAcceptThread != null)
            {
                GetTcpListener.Stop();
                GetAcceptThread.Join();
                GetAcceptThread = null;
            }

            // Dispose of all of the socket connections
            /*
            for (int iSocket = 0; iSocket < GetMaxClientConnections; ++iSocket)
            {
                if (GetSocketClientList[iSocket] != null)
                {
                    GetSocketClientList[iSocket].Dispose();
                    GetSocketClientList[iSocket] = null;
                }
            }
             */
            foreach (CSocketClient pSocketClient in GetSocketClientList)
            {
                pSocketClient.Dispose();
                GetSocketClientList.Remove(pSocketClient);
            }

            // Wait for all of the socket client objects to be destroyed
            GC.Collect();
            GC.WaitForPendingFinalizers();

            // Clear the Handler Functions
            GetMessageHandler = null;
            GetAcceptHandler = null;
            GetCloseHandler = null;
            GetErrorHandler = null;

            // Clear the buffer size and user arguments
            GetSizeOfRawBuffer = 0;
            GetUserArg = null;
        }
    }
}