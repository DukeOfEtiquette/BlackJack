
class Card
{

public:
	enum Suit{
		Club = 0,
		Diamond = 1,
		Spade = 2,
		Heart = 3,
	};

	Card(int, Suit);

	int m_value;
	Suit suit;

	void PrintCard();
	int GetValue();


};
