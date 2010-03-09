using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace SocketSystem
{
    public class CommuncationServer
    {

        private CSocketServer pSocketServer;

        public CommuncationServer(String strIP, short strPort)
        {
            try
            {
                short serverPort = strPort;

                // Instantiate a CSocketServer object
                pSocketServer = new CSocketServer();

                // Start listening for connections
                pSocketServer.Start(strIP, serverPort, 10, 10240, null,
                  new CSocketServer.MESSAGE_HANDLER(MessageHandlerServer),
                  new CSocketServer.ACCEPT_HANDLER(AcceptHandler),
                  new CSocketServer.CLOSE_HANDLER(CloseHandler),
                  new CSocketServer.ERROR_HANDLER(ErrorHandler));
                Console.WriteLine("Waiting for a client connection on Machine: {0} Port: {1}", System.Environment.MachineName, serverPort);
                // Stay here until you are ready to shutdown the server   
                Console.ReadLine();
                pSocketServer.Dispose();


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
        public void MessageHandlerServer(CSocketClient pSocket, Int32 iNumberOfBytes)
        {

            

            try
            {
                // Find a complete message
                String strMessage = System.Text.ASCIIEncoding.ASCII.GetString(pSocket.GetRawBuffer, 0, iNumberOfBytes);
                //Console.WriteLine("commServer: " + strMessage);

                String[] strMessages = strMessage.Split('\0');
                for (int i = 0; i < strMessages.Length; i++)
                {
                    //Console.WriteLine(msgs[i]);

                    if (strMessages[i].Length > 0)
                    {
                        String[] cmds = strMessages[i].Split(',');

                        CommandType cmdType = (CommandType)int.Parse(cmds[0]);

                        switch (cmdType)
                        {
                            case CommandType.ClientLogin:

                                pSocket.GetClientName = cmds[1];
                                Console.WriteLine("Client [" + pSocket.GetClientName + "] login.");
                                

                                ArrayList clients = pSocketServer.GetSockets();
                                Console.WriteLine("\n=== Client List ===");
                                foreach (CSocketClient client in clients)
                                {
                                    Console.WriteLine("Client: " + client.GetClientName);
                                }

                                break;

                            case CommandType.Message:

                                String target = cmds[1];
                                String from = cmds[2];

                                CSocketClient tSocket = pSocketServer.GetSocket(target);
                                if (tSocket != null)
                                {
                                    //tSocket.Send(msg);
                                    tSocket.Send(strMessages[i]);
                                    
                                    Console.WriteLine("From [" + pSocket.GetClientName + "], send msg[" + strMessages[i] + "] to [" + tSocket.GetClientName + "].");
                                }
                                else
                                    Console.WriteLine("[" + target + "] dose not exist");


                                break;

                            default:
                                break;
                        }
                    }

                }
            }
            catch (Exception pException)
            {
                Console.WriteLine(pException.Message);
            }
        }
        //********************************************
        /// <summary> Called when a socket connection is accepted </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        public void AcceptHandler(CSocketClient pSocket)
        {
            //Console.WriteLine("Accept Handler");
            //Console.WriteLine("IpAddress: " + pSocket.GetIpAddress);
        }

        //*********************************************
        /// <summary> Called when a socket connection is closed </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        public void CloseHandler(CSocketClient pSocket)
        {
//            Console.WriteLine("Close Handler");
//            Console.WriteLine("IpAddress: " + pSocket.GetIpAddress);
            
            String logoutClient = pSocket.GetClientName;
            pSocketServer.RemoveSocket(pSocket);
            Console.WriteLine("Client [" + logoutClient + "] logout.");
            
            ArrayList clients = pSocketServer.GetSockets();

            // list and boradcast to all live clients
            Console.WriteLine("\n=== Client List ===");
            foreach (CSocketClient client in clients)
            {
                client.Send("15," + client.GetClientName + ",Server,clientLogout," + logoutClient);
                Console.WriteLine("Client: " + client.GetClientName);
            }
        }
        //**************************************************
        /// <summary> Called when a socket error occurs </summary>
        /// <param name="pSocket"> The SocketClient object the message came from </param>
        /// <param name="pException"> The reason for the error </param>
        public void ErrorHandler(CSocketClient pSocket, Exception pException)
        {
            Console.WriteLine("Error Handler: " + pException.Message);
        }
    }
}
