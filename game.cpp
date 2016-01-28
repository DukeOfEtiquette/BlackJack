#include <iostream>
#include <string>
#include "Board.h"

int main()
{
	int ch;
	//Clear terminal window
	for(int i = 0; i < 100; i++)
		std::cout << std::endl;

	int nPlayers, nDecks;
	std::string gameName;

	std::cout << "How many players will there be?: ";
	std::cin >> nPlayers;

	std::cout << "How many decks will you be playing with?: ";
	std::cin >> nDecks;

	//std::cout << "What do you want to name this game?: ";
	//std::getline(std::cin, gameName);
	//std::cin >> gameName;
	
	//std::cout << "gameName: " << gameName << std::endl;

	//while ((ch = std::cin.get()) != '\n' && ch != EOF);

	Board* gameBoard = new Board(nPlayers, nDecks, "Test Game");

	//Board* gameBoard = new Board(5, 12, "fun game");

	gameBoard->StartGame();

	return 0;
}
