using System;
using System.Collections.Generic;
using System.Text;

namespace SocketSystem
{
    // �K�n:
    //     The type of commands that you can sent to the clients.(Note : These are just
    //     some comman types.You should do the desired actions when a command received
    //     to the client yourself.)
    public enum CommandType
    {

        //
        // �K�n:
        //     This command will sent to all clients when an specific client is had been
        //     logged in to the server.The metadata of this command is in this format :
        //     "RemoteClientIP:RemoteClientName"
        ClientLogin = 11,
        //
        // �K�n:
        //     This command will sent to all clients when an specific client is had been
        //     logged off from the server.
        ClientLogOff = 12,
        //
        // �K�n:
        //     This command will send to the new connected client with MetaData of 'True'
        //     or 'False' in replay to the same command that client did sent to the server
        //     as a question.
        ClientRename = 13,
        //
        // �K�n:
        //     This command will send to the new connected client with MetaData in "RemoteClientIP:RemoteClientName"
        //     format in replay to the same command that client did sent to the server as
        //     a request.
        Broadcast = 14,
        //SendClientList = 14,
        //
        // �K�n:
        //     Send a text message to the server.Pass the body of text message as command's
        //     Metadata.
        Message = 15,
        //
        // �K�n:
        //     This is a free command that you can sent to the clients.
        FreeCommand = 16,
    }
}
