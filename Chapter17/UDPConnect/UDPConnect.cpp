using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

void main()
{
    Socket^ socket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);

    EndPoint^ Remote = gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), 54321);
    socket->Connect(Remote);

    while (true)
    {
        Console::Write("Message ('q' to quit): ");
        String^ input = Console::ReadLine();

        if (input->ToLower()->Equals("q"))
            break;

        array<unsigned char>^ message = Encoding::ASCII->GetBytes(input);
        socket->Send(message);

        message = gcnew array<unsigned char>(1024);
        int recv = socket->Receive(message);

        Console::WriteLine("[{0}] {1}", 
            Remote->ToString(), Encoding::ASCII->GetString(message, 0, recv));
    }
}
