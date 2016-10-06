using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

ref class TcpServer
{
public:
    void ProcessThread(Object ^clientObj);
};

void TcpServer::ProcessThread(Object ^clientObj)
{
    TcpClient^ client = (TcpClient^)clientObj;

    IPEndPoint^ clientEP = (IPEndPoint^)client->Client->RemoteEndPoint;

    Console::WriteLine("Connected on IP: {0} Port: {1}", 
                        clientEP->Address, clientEP->Port);

    StreamWriter^ writer = gcnew StreamWriter(client->GetStream()); 
    StreamReader^ reader = gcnew StreamReader(client->GetStream()); 

    writer->WriteLine("Successfully connection to the server on port {0}", 
                      clientEP->Port);
    writer->Flush();

    String^ msg;
    while (true)
    {
        try
        {
            msg = reader->ReadLine();
            Console::WriteLine("Port[{0}] {1}", clientEP->Port, msg);

            writer->WriteLine(msg);
            writer->Flush();
        }
        catch (IOException^)
        {
            break;  // connection lost
        }
    }
    client->Close();

    Console::WriteLine("Connection to IP: {0} Port {1} closed.", 
        clientEP->Address, clientEP->Port);
}

void main()
{
    TcpServer^ server = gcnew TcpServer();

    TcpListener^ socket = gcnew TcpListener(IPAddress::Any, 12345);
    socket->Start();
    
    while(true) 
    {
        Console::WriteLine("Waiting for client connection.");
        TcpClient^ client = socket->AcceptTcpClient();

        Thread ^thr = gcnew Thread(
            gcnew ParameterizedThreadStart(server, &TcpServer::ProcessThread));
        thr->Start(client);
    }
}
