#include "Player.h"
#include "Deck.h"

public:
	Deck* m_gameDeck;
	Deck* m_discard;
	std::string m_gameName;
	int m_nPlayers;
	int m_nDecks;
	std::map<int, Players*> m_players;
	int m_curPlayer;
	int m_curHand;
	char m_option;

	Board(int, int, std::string);

	void DealStartingHands();
	void DealCard(int, int);
	void SplitHand();
	void PrintAllPlayers();
	void PrintCurPlayer(int);
	void StartGame();
	void PauseGame();
	void EndGame();
