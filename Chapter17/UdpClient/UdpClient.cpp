using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

void main()
{
    Socket^ socket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);

    //IPEndPoint^ ipep = gcnew IPEndPoint(IPAddress::Any, 54322);
    //socket->Bind(ipep);

    EndPoint^ Remote = gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), 54321);

    while (true)
    {
        Console::Write("Message ('q' to quit): ");
        String^ input = Console::ReadLine();

        if (input->ToLower()->Equals("q"))
            break;

        array<unsigned char>^ message = Encoding::ASCII->GetBytes(input);
        socket->SendTo(message, Remote);

        message = gcnew array<unsigned char>(1024);
        int recv = socket->ReceiveFrom(message, Remote);
        Console::WriteLine("[{0}] {1}", 
        Remote->ToString(), Encoding::ASCII->GetString(message, 0, recv));
    }
}
