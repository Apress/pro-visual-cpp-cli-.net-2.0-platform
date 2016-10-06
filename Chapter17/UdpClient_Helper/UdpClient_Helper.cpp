using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

void main()
{
    UdpClient^ client = gcnew UdpClient();

    IPEndPoint^ Remote = 
        gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), 54321);

    while (true)
    {
        Console::Write("Message ('q' to quit): ");
        String^ input = Console::ReadLine();

        if (input->ToLower()->Equals("q"))
            break;

        array<unsigned char>^ message = Encoding::ASCII->GetBytes(input);
        client->Send(message, message->Length, Remote);

        message = client->Receive(Remote);
        Console::WriteLine("[{0}] {1}", 
            Remote->ToString(), 
            Encoding::ASCII->GetString(message, 0, message->Length));
    }
}
