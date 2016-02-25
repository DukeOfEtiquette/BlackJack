#include <iostream>
#include <string>
#include "Board.h"

int main()
{
	//Clear terminal window
	for(int i = 0; i < 100; i++)
		std::cout << std::endl;

	int nPlayers, nDecks, potSize;
	char gameName[80];
	Board* gameBoard;

	std::cout << "How many players will there be?: ";
	std::cin >> nPlayers;

	std::cout << "How many decks will you be playing with?: ";
	std::cin >> nDecks;

	std::cout << "What would you like all players initial pot size ot be?: ";
	std::cin >> potSize;

	std::cin.ignore();
	std::cin.clear();

//	std::cout << "Enter a name for your game: ";
//	std::cin.getline(gameName, 80);
	//fgets(gameName, 80, stdin);

	try{
		gameBoard = new Board(nPlayers, nDecks, potSize);
		gameBoard->StartGame();

		delete gameBoard;
	}catch(const char* msg){
		std::cerr << msg << std::endl;
	}

	return 0;
}
