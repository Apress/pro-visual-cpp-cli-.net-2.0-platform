using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::Text;

ref class TcpServer
{
public:
    void ProcessThread(Object ^clientObj);
};

void TcpServer::ProcessThread(Object ^clientObj)
{
    Socket^ client = (Socket^)clientObj;
    IPEndPoint^ clientEP = (IPEndPoint^)client->RemoteEndPoint;

    Console::WriteLine("Connected on IP: {0} Port: {1}", 
                        clientEP->Address, clientEP->Port);

    array<unsigned char>^ msg = Encoding::ASCII->GetBytes(
        String::Format("Successfully connection to the server on port {0}", 
                        clientEP->Port));
    client->Send(msg);

    int rcv;
    while (true)
    {
        msg = gcnew array<unsigned char>(1024);

        if ((rcv = client->Receive(msg)) == 0)
            break;

        Console::WriteLine("Port[{0}] {1}", 
            clientEP->Port, Encoding::ASCII->GetString(msg, 0, rcv));

        client->Send(msg, rcv, SocketFlags::None);
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
        Socket^ client = socket->AcceptSocket();

        Thread ^thr = gcnew Thread(
            gcnew ParameterizedThreadStart(server, &TcpServer::ProcessThread));
        thr->Start(client);
    }
}
