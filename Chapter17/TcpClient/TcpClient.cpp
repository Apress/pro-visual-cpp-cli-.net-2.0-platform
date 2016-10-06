using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::Text;

void main()
{
    Socket^ server = gcnew Socket(AddressFamily::InterNetwork, 
                                  SocketType::Stream, ProtocolType::Tcp);
    try
    {
        IPEndPoint^ iped = 
            gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), 12345);
        server->Connect(iped);
    }
    catch (SocketException^ se)
    {
        Console::WriteLine("Connection to server failed with error: {0}", 
                            se->Message);
        return;
    }

    array<unsigned char>^ msg = gcnew array<unsigned char>(1024);
    int rcv = server->Receive(msg);

    Console::WriteLine(Encoding::ASCII->GetString(msg, 0, rcv));

    while (true)
    {
        Console::Write("Message ('q' to quit): ");
        String^ input = Console::ReadLine();

        if (input->ToLower()->Equals("q"))
            break;

        msg = Encoding::ASCII->GetBytes(input);
        server->Send(msg, msg->Length, SocketFlags::None);

        msg = gcnew array<unsigned char>(1024);
        rcv = server->Receive(msg);
        Console::WriteLine(Encoding::ASCII->GetString(msg, 0, rcv));
    }
    Console::WriteLine("Ended connection with server.");
    server->Shutdown(SocketShutdown::Both);
    server->Close();
}
