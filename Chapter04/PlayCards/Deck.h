namespace Cards
{
    public ref class Deck
    {
        array<Card^>^  deck;
        int   curCard;

    public:
        Deck(void);

        Card ^Deal();
        void Shuffle();
    };
}
