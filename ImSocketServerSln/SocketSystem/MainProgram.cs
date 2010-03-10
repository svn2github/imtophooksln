using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace SocketSystem
{
    class MainProgram
    {

        //private String COMMUNICATION_SERVER_IP = "127.0.0.1";
        private String PARAMETERS_FROM_FILE = ".\\setting.txt";
        private String COMMUNICATION_SERVER_IP;// = "192.168.1.18";
        private short COMMUNICATION_SERVER_PORT;// = 5000;
        private CommuncationServer commServer;
        private CSocketClient lightClient;
        //private LightComPort lightComPort;

        public MainProgram()
        {

            loadParamsFromFile();

            setupCommunicationServer();
            
            Console.ReadLine();
        }

        private void loadParamsFromFile()
        {
            String line;
            // Read the file and display it line by line.            
            System.IO.StreamReader file = new System.IO.StreamReader(PARAMETERS_FROM_FILE);

            line = file.ReadLine();
            COMMUNICATION_SERVER_IP = line.Split(new Char[] { ' ' })[1];
            line = file.ReadLine();
            COMMUNICATION_SERVER_PORT = short.Parse(line.Split(new Char[] { ' ' })[1]);
            line = file.ReadLine();

            Console.WriteLine("COMMUNICATION_SERVER_IP \t" + COMMUNICATION_SERVER_IP);
            Console.WriteLine("COMMUNICATION_SERVER_PORT \t" + COMMUNICATION_SERVER_PORT);
            file.Close();
            Console.WriteLine("------");
        }


        private void setupCommunicationServer()
        {
            Thread commServerThread = new Thread(new ThreadStart(commServerFunc));
            commServerThread.Start();
        }

        private void commServerFunc()
        {
            commServer = new CommuncationServer(COMMUNICATION_SERVER_IP, COMMUNICATION_SERVER_PORT);
        }

        /*
        private void setupLightClient()
        {
            lightComPort = new LightComPort();
            Console.WriteLine("Open light comport successful");

            // Instantiate a CSocketClient object
            lightClient = new CSocketClient(10240, null,
              new CSocketClient.MESSAGE_HANDLER(MessageHandlerClient),
              new CSocketClient.CLOSE_HANDLER(CloseHandler),
              new CSocketClient.ERROR_HANDLER(ErrorHandler));

            lightClient.Connect(COMMUNICATION_SERVER_IP, COMMUNICATION_SERVER_PORT);
            lightClient.Send("11,light");
        }
        */
        
    }
}
