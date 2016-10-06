#using <cards.dll>

using namespace System;
using namespace Cards;

void main()
{
    Deck deck;

    deck.Shuffle();

    Card ^card;
    int cnt = 0;
    while ((card = deck.Deal()) != nullptr)
    {
        Console::Write(card->ToString());
        Console::Write("\t");
        cnt++;

        if (cnt > 4)
        {
            Console::WriteLine("");
            cnt = 0;
        }
    }
    Console::WriteLine("");
}