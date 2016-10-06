using namespace System;

#include "card.h"
using namespace Cards;

Card::Card(int type, Suits suit)
{
    Type = type;
    Suit = suit;
}

int Card::Type::get()      
{ 
    return type; 
}

void Card::Type::set(int value)      
{ 
    type = value; 
}

Suits Card::Suit::get() 
{ 
    return suit; 
}

void Card::Suit::set(Suits value) 
{ 
    suit = value; 
}

String^ Card::ToString()
{
    String ^t;

    if (Type > 1 && Type < 11)
        t = Type.ToString();
    else if (Type == 1)
        t = "A";
    else if (Type == 11)
        t = "J";
    else if (Type == 12)
        t = "Q";
    else
        t = "K";

    switch (Suit)
    {
        case Suits::Heart:
            return String::Concat(t, "H");
        case Suits::Diamond:
            return String::Concat(t, "D");
        case Suits::Spade:
            return String::Concat(t, "S");
        default:
            return String::Concat(t, "C");
    }
}
