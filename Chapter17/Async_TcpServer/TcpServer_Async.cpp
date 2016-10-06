using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::Text;

ref class StateObject
{
public:
    property int bufSize;
    property Socket ^workSocket;
    property array<unsigned char>^ message;

    StateObject(Socket^ sock, int bufsize)
    {
        workSocket = sock;
        bufSize = bufsize;
        message = gcnew array<unsigned char>(bufsize);
    }
};

ref class TcpServer
{
public:
    static void AcceptCB(IAsyncResult^ iar);
    static void SendCB(IAsyncResult^ iar);
    static void ReceiveCB(IAsyncResult^ iar);
};

void TcpServer::AcceptCB(IAsyncResult^ iar)
{
    TcpListener^ tcpListener = (TcpListener^)iar->AsyncState;
    Socket^ client = tcpListener->EndAcceptSocket(iar);

    IPEndPoint^ clientEP = (IPEndPoint^)client->RemoteEndPoint;

    Console::WriteLine("Connected on IP: {0} Port: {1}", 
                        clientEP->Address, clientEP->Port);

    // Send socket successful connection message
    array<unsigned char>^ msg = Encoding::ASCII->GetBytes(
        String::Format("Successfully connection to the server on port {0}", 
                        clientEP->Port));
    client->BeginSend(msg, 0, msg->Length, SocketFlags::None, 
        gcnew AsyncCallback(&TcpServer::SendCB), client);

    // Get message from client
    StateObject^ so = gcnew StateObject(client, 1024);
    client->BeginReceive(so->message, 0, so->bufSize, 
        SocketFlags::None, gcnew AsyncCallback(&TcpServer::ReceiveCB), so); 

    // Get the next socket connection
    Console::WriteLine("Waiting for client connections. [Return to Exit]");
    tcpListener->BeginAcceptSocket(gcnew AsyncCallback(&TcpServer::AcceptCB), 
        tcpListener);
}

void TcpServer::SendCB(IAsyncResult^ iar)
{
    Socket^ client = (Socket^)iar->AsyncState;
    client->EndSend(iar);
}

void TcpServer::ReceiveCB(IAsyncResult^ iar)
{
    StateObject^ so = (StateObject^)iar->AsyncState;
    Socket^ client = so->workSocket;
    IPEndPoint^ clientEP = (IPEndPoint^)client->RemoteEndPoint;

    int rcv;
    if ((rcv = client->EndReceive(iar)) > 0) // get message
    {
        Console::WriteLine("Port[{0}] {1}", 
            clientEP->Port, Encoding::ASCII->GetString(so->message, 0, rcv));

        // echo message
        client->BeginSend(so->message, 0, rcv, SocketFlags::None, 
            gcnew AsyncCallback(&TcpServer::SendCB), client);

        // set up for next receive
        so = gcnew StateObject(client, 1024);
        client->BeginReceive(so->message, 0, so->bufSize, 
            SocketFlags::None, gcnew AsyncCallback(&TcpServer::ReceiveCB), so); 
    }
    else // connection closed
    {
         client->Close();
         Console::WriteLine("Connection to IP: {0} Port {1} closed.", 
            clientEP->Address, clientEP->Port);
    }
}

void main()
{
    TcpListener^ socket = gcnew TcpListener(IPAddress::Any, 12345);
    socket->Start();

    Console::WriteLine("Waiting for client connections. [Return to Exit]");
    socket->BeginAcceptSocket(gcnew AsyncCallback(&TcpServer::AcceptCB), 
        socket);

    // Exit on return key
    Console::ReadLine();
}
