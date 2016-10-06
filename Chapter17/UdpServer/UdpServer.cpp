using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

void main()
{
    Socket^ socket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
    IPEndPoint^ ipep = gcnew IPEndPoint(IPAddress::Any, 54321);

    socket->Bind(ipep);

    Console::WriteLine("Waiting for client connection.");

    while(true) 
    {
        array<unsigned char>^ message = gcnew array<unsigned char>(1024);
        EndPoint^ Remote = (EndPoint^) gcnew IPEndPoint(IPAddress::Any, 0);

        int recv = socket->ReceiveFrom(message, Remote);

        Console::WriteLine("[{0}] {1}", 
            Remote->ToString(), Encoding::ASCII->GetString(message, 0, recv));

        socket->SendTo(message, recv, SocketFlags::None, Remote);
    }
}
