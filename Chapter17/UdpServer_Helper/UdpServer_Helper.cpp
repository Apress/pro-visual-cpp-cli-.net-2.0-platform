using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

void main()
{
    IPEndPoint^ ipep = gcnew IPEndPoint(IPAddress::Any, 54321);
    UdpClient^ server = gcnew UdpClient(ipep);

    Console::WriteLine("Waiting for client connection.");

    array<unsigned char>^ message;

    while(true) 
    {
        IPEndPoint^ Remote = gcnew IPEndPoint(IPAddress::Any, 0);

        message = server->Receive(Remote);

        Console::WriteLine("[{0}] [{1}]", 
            Remote->ToString(), Encoding::ASCII->GetString(message, 0, 
            message->Length));

        server->Send(message, message->Length, Remote);
    }
}
