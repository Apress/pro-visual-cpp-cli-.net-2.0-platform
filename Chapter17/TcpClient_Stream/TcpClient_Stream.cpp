using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;

void main()
{
    TcpClient^ server;
    StreamWriter^ writer;
    StreamReader^ reader; 
    String^ msg;

    try
    {
        server = gcnew TcpClient("127.0.0.1", 12345);

        writer = gcnew StreamWriter(server->GetStream()); 
        reader = gcnew StreamReader(server->GetStream()); 
    }
    catch (SocketException^ se)
    {
        Console::WriteLine("Connection to server failed with error: {0}", 
                            se->Message);
        return;
    }

    msg = reader->ReadLine();

    Console::WriteLine(msg);

    while (true)
    {
        Console::Write("Message ('q' to quit): ");
        msg = Console::ReadLine();

        if (msg->ToLower()->Equals("q"))
            break;

        try
        {
            writer->WriteLine(msg);
            writer->Flush();

            msg = reader->ReadLine();
            Console::WriteLine(msg);
        }
        catch (IOException^)
        {
            break;  // connection lost
        }
    }
    Console::WriteLine("Ended connection with server.");
    server->Close();
}
