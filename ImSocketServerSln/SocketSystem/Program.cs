using System;
using System.Collections.Generic;
using System.Text;

namespace SocketSystem
{
    class Program
    {
        //**********************************************
        /// <summary> Called when a message is extracted from the socket </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        /// <param name="iNumberOfBytes"> The number of bytes in the RawBuffer inside the SocketClient </param>
        static public void MessageHandlerClient(CSocketClient pSocket, Int32 iNumberOfBytes)
        {
            try
            {
                // Convert the message from a byte array to a string
                String strMessage = System.Text.ASCIIEncoding.ASCII.GetString(pSocket.GetRawBuffer, 0, iNumberOfBytes);

                // Display the string to the console window
                Console.WriteLine(strMessage);
            }
            catch (Exception pException)
            {
                Console.WriteLine(pException.Message);
            }
        }
        //*********************************************
        /// <summary> Called when a socket connection is closed </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        static public void CloseHandler(CSocketClient pSocket)
        {
            Console.WriteLine("Close Handler");
            Console.WriteLine("IpAddress: " + pSocket.GetIpAddress);
        }
        //**************************************************
        /// <summary> Called when a socket error occurs </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        /// <param name="pException"> The reason for the error </param>
        static public void ErrorHandler(CSocketClient pSocket, Exception pException)
        {
            Console.WriteLine("Error Handler: " + pException.Message);
        }

        //*********************************************
        /// <summary> Function to test the CSocketClient class </summary>
        static void TestClient()
        {
            try
            {
                // Instantiate a CSocketClient object
                CSocketClient pSocketClient = new CSocketClient(10240, null,
                  new CSocketClient.MESSAGE_HANDLER(MessageHandlerClient),
                  new CSocketClient.CLOSE_HANDLER(CloseHandler),
                  new CSocketClient.ERROR_HANDLER(ErrorHandler));

                

                // Establish a connection to the server hosting www.continuumtechnologycenter.com
                //pSocketClient.Connect("www.continuumtechnologycenter.com", 80);
                pSocketClient.Connect("127.0.0.1", 5000);
                // Send the HTTP Get command
                pSocketClient.Send("11,csGE");
//                Console.ReadLine();
//                pSocketClient.Disconnect();
//                Console.ReadLine();
//                pSocketClient.Dispose();
            }
            catch (Exception pException)
            {
                Console.WriteLine(pException.Message);
            }
        }



        //********************************************
        /// <summary> Called when a message is extracted from the socket </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        /// <param name="iNumberOfBytes"> The number of bytes in the RawBuffer inside the SocketClient </param>
        static public void MessageHandlerServer(CSocketClient pSocket, Int32 iNumberOfBytes)
        {
            try
            {
                // Find a complete message
                String strMessage = System.Text.ASCIIEncoding.ASCII.GetString(pSocket.GetRawBuffer, 0, iNumberOfBytes);
                Console.WriteLine(strMessage);
                pSocket.Send(strMessage);

                /*
                String[] cmds = strMessage.Split(',');

                if (cmds.Length == 0)
                    return;

                CommandType cmdType = (CommandType)int.Parse(cmds[0]);

                switch (cmdType)
                {
                    case CommandType.ClientLogin:
                        pSocket.GetClientName = cmds[1];
                        Console.WriteLine("set name: " + pSocket.GetClientName);
                        break;
                    
                    case CommandType.Message:

                        String target = cmds[1]; ;
                        String msg = cmds[2];

                        

                        Console.WriteLine("set name: " + pSocket.GetClientName);
                        break;

                    default:
                        break;
                }
                */
            }
            catch (Exception pException)
            {
                Console.WriteLine(pException.Message);
            }
        }
        //********************************************
        /// <summary> Called when a socket connection is accepted </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        static public void AcceptHandler(CSocketClient pSocket)
        {
            Console.WriteLine("Accept Handler");
            Console.WriteLine("IpAddress: " + pSocket.GetIpAddress);

        }
        //*********************************************
        /// <summary> Function to test the CSocketServer class </summary>
        static void TestServer()
        {
            try
            {
                // Instantiate a CSocketServer object
                CSocketServer pSocketServer = new CSocketServer();
                // Start listening for connections
                pSocketServer.Start("localhost", 5000, 1024, 10240, null,
                  new CSocketServer.MESSAGE_HANDLER(MessageHandlerServer),
                  new CSocketServer.ACCEPT_HANDLER(AcceptHandler),
                  new CSocketServer.CLOSE_HANDLER(CloseHandler),
                  new CSocketServer.ERROR_HANDLER(ErrorHandler));
                Console.WriteLine("Waiting for a client connection on Machine: {0} Port: {1}", System.Environment.MachineName, 5000);
                // Stay here until you are ready to shutdown the server   
                Console.ReadLine();
                pSocketServer.Dispose();

            }
            catch (Exception pException)
            {
                Console.WriteLine(pException.Message);
            }
        }


        //**********************************************
        /// <summary> Function to test the CSocketClient class </summary>
        static void Main(string[] args)
        {
            // Test the CSocketClient class
             TestClient();

            // Test the CSocketClient class
            //TestServer();

            // For Macball Application
            //CommuncationServer commServer = new CommuncationServer(5000);

             Console.ReadLine();
        }
    }
}
