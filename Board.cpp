#include <iostream>
#include <exception>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"

/***********************************************************************************
 * Purpose: Constructor for Board
 * In: Takes a number of players, number of Decks, and a game name
 * Out: Assigns each variable passed to its member, creates a game deck, and creates
 *		the players in the game
 ***********************************************************************************/
Board::Board(int nPlayers, int nDecks, int initialPot)
{
    if(nPlayers < 2 || nDecks < 1)
    {
        throw "Invalid number of players or decks passed.\n";
    }
    
    //Sets member variables
    m_nPlayers = nPlayers;
    m_nDecks = nDecks;
	m_initialPot = initialPot;
    m_bPlay = true;
	m_bPush = false;
    m_gameDeck = MakeGameDeck();

    Player* player; //Used in the for loop just below to create all the players
    
    //Creates a new player with the number passed
    for(int i = 0; i <= m_nPlayers; i++)
    {
        player = new Player(i, m_initialPot);
        m_players.insert(std::pair<int, Player*>(i, player));
    }
}

/***********************************************************************************
 * Purpose: Destructor for Board
 * Out: Deletes the players and the games deck
 ***********************************************************************************/
Board::~Board()
{
    //Every player is deleted
    for(int i = 0; i < m_nPlayers; i++)
    {
        delete m_players[i];
    }
    //Deletes the gameDeck
    delete m_gameDeck;
}


/***********************************************************************************
 * Purpose: Deals the starting hands (used at the start of a round)
 * Out: All players, including dealer, have a starting hand
 ***********************************************************************************/
void Board::DealStartingHands()
{
    //Deals each player a starting hand
    for(int i = 0; i < m_players.size(); i++)
    {
        m_players[i]->AddHand(MakeStartingHand());
    }
}

/***********************************************************************************
 * Purpose: Creates a starting hand with two dealt cards from the deck, used in
 *      DealStartingHands()
 * Out: Will remove two cards off the deck and return a pointer to the hand
 ***********************************************************************************/
Hand* Board::MakeStartingHand()
{
    //Deals each player two cards
    Hand* h = new Hand(0);
    for(int i = 0; i < 2; i++)
    {
        h->m_hand.push_back(m_gameDeck->DealCard());
    }
    return h;
}

/***********************************************************************************
 * Purpose: Creates a deck based on the number of sets passed
 * Out: Creates a new deck with m_nDecks sets then shuffles and returns the deck
 ***********************************************************************************/
Deck* Board::MakeGameDeck()
{
    //Creates a deck and shuffles it
    Deck* d = new Deck(m_nDecks);
    d->Shuffle();
    return d;
}

/***********************************************************************************
 * Purpose: Deals a card to a player from the deck
 * In: The index of the player that is recieving the card and an index of the hand
 *		a card will be put in
 * Out: A player's hand will recieve a card from a deck of cards
 ***********************************************************************************/
void Board::DealCard(int player, int hand)
{
    //Deals a card to a player from the deck
    m_players[player]->m_handList[hand]->m_hand.push_back(m_gameDeck->DealCard());
}

/***********************************************************************************
 * Purpose: Will split a players hand
 * In: A pointer to a player player and the index of the handList
 * Out: A players hand at a particular index will be split into different hands in
 *		it's handList
 ***********************************************************************************/
void Board::SplitHand(Player* player, int index)
{
    player->Split(index);
    player->m_handList[index]->m_hand.push_back(m_gameDeck->DealCard());
    player->m_handList.back()->m_hand.push_back(m_gameDeck->DealCard());
}

/***********************************************************************************
 * Purpose: Print all players on the board
 * Out: Prints each players hand to stdout
 ***********************************************************************************/
void Board::PrintAllPlayers()
{
    for(int i = 1; i < m_players.size(); i++)
    {
        m_players[i]->PrintHands();
    }
    //Formatting
    std::cout << std::endl;
}

/***********************************************************************************
 * Purpose: Prints the dealers hand
 * In: A bool to determine if entire hand should be printed or just the first card
 * Out: The function will print out a dealers first card while it is called when hide
 *		is true. When hide is false, the dealers current hand will be printed
 ***********************************************************************************/
void Board::PrintDealer(bool hide)
{
    //Dealer will always be printed first so this is the header for the table
    std::cout << "\n### TABLE ###\n";
    
    //If hide then print first card and hide second, else print entire hand
    if(hide)
    {
        std::cout << "Dealer : ";
        m_players[0]->m_handList[0]->m_hand[0]->PrintCard();
        std::cout << " *\n";
    }else{
        
        std::cout << "Dealer : ";
        m_players[0]->m_handList[0]->PrintHand();
        m_players[0]->m_handList[0]->SumHand();
    }
}

/***********************************************************************************
 * Purpose: Dumps all players hands
 * Out: Sets all players hands to a size of 0
 ***********************************************************************************/
void Board::ClearBoard()
{
    //For all the players, dump their hands
    for(int i = 0; i < m_players.size(); i++)
    {
        m_players[i]->DumpHands();
    }
}

/**********************************************************************************
 * Purpose: Acts as the Game interface and will gather an option from the user
 * Out: Outputs the interface and will start, pause, or end a game based on user
 *		input
***********************************************************************************/
void Board::GameMenu()
{
        std::cout << "\n#### Game Menu ###\n";
        std::cout << "\nPlease select an option below...\n";
        std::cout << "1) Start A Round\n";
        std::cout << "2) Pause game\n";
        std::cout << "3) End Game\n";
        std::cout << ">";
}

/***********************************************************************************
 * Purpose: Creates a loop that	determines if a game is in play (boolean m_play)
 *			and takes appropriate action based on user input
 * Out: If true then main can delete the Board object, else it can hold onto it for
 *		later use
 ***********************************************************************************/
bool Board::StartGame()
{
    while(m_bPlay)//Use
    {
        CheckDeck();
		GameMenu();
        std::cin >> m_option; //Use
        
        //Clear stdin before starting loop again
		std::cin.clear();
        std::cin.ignore();
        
        //Validate user input
        if(!isnan(m_option))
        {
            switch(m_option)
            {
                case 1:
                    StartRound();
                    break;
                case 2://Return out of StartGame to main
                    return false;
                case 3:
                    return true;
                default:
                    std::cout << "That option is not valid, try again...\n\n";
                    break;
            }
        }
        
		//Clear stdin before starting loop again
        std::cin.clear();
        std::cin.ignore();
    }
    return false;
}

/***********************************************************************************
 * Purpose: This will determine if a player has a hand that can be split
 * In: A pointer to a player that needs to be checked for a split
 * Out: No change if not split can be made. No change if player chooses not to split.
 *		Two new hands each with a card from the original hand that was split if the
 *		player chooses.
 ***********************************************************************************/
void Board::CheckSplit(Player* player)
{
    bool split = true;//Controls while loop
    
    while(split)
    {
        for(int i = 0; i < player->m_handList.size(); i++)
        {
            if(player->CanSplit(i))
            {
                std::string option;//Used right below this to record input
                player->PrintHand(i);
                std::cout << "Would you like to split this hand (y/n): ";
                std::getline(std::cin, option);
                std::cout << std::endl;
                
                if(tolower(option[0]) == 'y')
                {
                    SplitHand(player, i);//Split hand and deal two cards
                    split = false;//We want to exit while loop and j for loop
                    i--;//Restart split check at current hand
                }else if(tolower(option[0]) == 'n'){
                    split = false;
                }else{
                    std::cout << "Not a valid option, try again.\n";
                    i--;
                }
            }

            split = false;
        }
    }
}

/***********************************************************************************
 * Purpose: This function controls the order of a round, including clearing the
 *			board, dealing hands, controling which players get to play and what
 *			order, and printing the table to the user
 * Out: All player's hands will have their ending state of cards
 ***********************************************************************************/
void Board::StartRound()
{
    ClearBoard();
    DealStartingHands();
    
    GetPlayerBets();

	m_bDealerBJ = DealerHasBJ();
    
    PrintDealer(true);
    PrintAllPlayers();

	if(m_players[0]->AcePos(0) == 0)
		OfferInsurance();
    
    for(int i = 1; i < m_players.size(); i++)
    {
        PlayHands(m_players[i]);
    }
    
    PlayDealer();
    PrintDealer(false);
    PrintAllPlayers();
    PrintWinners();

	RewardPlayers();
	m_roundWinners.clear();

	std::cout << "\nEnter to continue...";
}

/***********************************************************************************
 * Purpose: This function will set each players bet
 * Out: All player's m_curPot's will be set
 ***********************************************************************************/
void Board::GetPlayerBets()
{
	int bet = 0;
	bool bFail = false;

    for(int i = 1; i < m_players.size(); i++)
    {
        std::cout << "\nPlayer" << i << " ";
		m_players[i]->PrintPot();
		std::cout << std::endl;
        
        do {
            std::cout << "Player" << i << " please enter your bet> ";
            std::cin >> bet;
            bFail = std::cin.fail();
			if(bFail) 
				std::cout << "Not a valid option, try again.\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
        }while(bFail);

		if(!m_players[i]->PlaceBet(bet))
			i--;
    }
}

/***********************************************************************************
 * Purpose: Payouts from bets are added to players that have blackjack
 * Out: Each winner is paid out if there isn't a push
***********************************************************************************/
void Board::RewardPlayers()
{
	for(int i = 1; i < m_roundWinners.size(); i++)
	{
		if(m_bPush)
			m_roundWinners[i]->PushWinnings();
		else
			m_roundWinners[i]->AddWinnings(m_roundWinners[i]->HasBlackJack());
	}

	ResetPlayerBets();
	m_bPush = false; //Reset board push variable
}

/***********************************************************************************
 * Purpose: Resets all players bets
 * Out: If a player has run out we reset their current pot
***********************************************************************************/
void Board::ResetPlayerBets()
{
	for(int i = 1; i <= m_nPlayers; i++)
	{
		m_players[i]->ResetBets();
	}
}

/***********************************************************************************
 * Putpose: This is the "AI" for the dealer. The dealer only hits until it is over
 *			a hard 17 or has busted
 * Out: The dealer will have it's hand after completing it's turn
 ***********************************************************************************/
void Board::PlayDealer()
{
    
    bool dBust = false;//Used in the while loop and potentially the for loop
    int pSum = 0;//Used in for loop for storing players' hand sum
    int maxHand = 0;//Used in for loop to store highest players' hand
    
    //Cycle through all players' hands
    for(int i = 1; i < m_players.size(); i++)
    {
        //Cycle through all hands for each player
        for(int j = 0; j < m_players[i]->m_handList.size(); j++)
        {
            //Get the sum for a particular hand
            pSum = m_players[i]->m_handList[j]->SumHand();
            
            //Check if it is the highest checked so far and not a bust
            if(maxHand < pSum && pSum < 22)
            {
                //Record current hand as the highest and flag that the dealer
                //needs to hit until hard 17 or bust
                maxHand = pSum;
                dBust = true;
            }
        }
    }
    //While the dealer hasn't won or busted
    while(dBust)
    {
        //Get the dealers current sum
        int dSum = m_players[0]->m_handList[0]->SumHand();
        //If less than 17 deal card
        if(dSum < 17)
        {
            DealCard(0, 0);
        }else{
            dBust = false;//Otherwise exit because dealer won or busted
        }
    }
}

/***********************************************************************************
 * Purpose: This function will determine who won the round and print that they have
 *			won
 * Out: The round winners to stdout
 ***********************************************************************************/
void Board::PrintWinners()
{
    int playerSum = 0;//In each for loop
    bool bPush = false;//Used in first nested for loop when determining push/no push
    bool checkHands = true;//Used in while loop
    int dSum = m_players[0]->m_handList[0]->SumHand();
    
    int i = 1;//Used in while loop and skip dealer
    
    //Cycle through all players to determine if there is a push
    while(checkHands && i < m_players.size())
    {
        for(int j = 0; j < m_players[i]->m_handList.size(); j++)
        {
            //Get sum of current hand being evaluated
            playerSum = m_players[i]->m_handList[j]->SumHand();
            
            //If it is the same as the dealers hand then push
            //but if any hand is greater than the dealers make push false and stop
            //checking because a hand exists that is greated than the dealers but
            //has not busted
            if(dSum == playerSum)
                bPush = true;
            else if(playerSum > dSum && playerSum < 22)
            {
                bPush = false;
                checkHands = false;
            }
        }
        i++;//Check next player
    }
    
    //If no push, else push
    if(!bPush || dSum > 21)
    {
        //Display winners haeder
        std::cout << "Round Winner(s):";
        
        //Assume dealer has won
        bool dWin = true;//Used in if/else if statement below
        
        //If there is no push or the dealer has busted, cycle through all players'
        //hands
        for(int i = 1; i < m_players.size(); i++)
        {
            for(int j = 0; j < m_players[i]->m_handList.size(); j++)
            {
                playerSum = m_players[i]->m_handList[j]->SumHand();
                
                //If dealer has busted...
                if(dSum > 21)
                {
                    //And the current hand has not busted, then that player has won
                    //and flip bool for dWin to false since dealer lost
                    if(playerSum < 22)
                    {
                        std::cout << " Player " << m_players[i]->m_playerID;
                        std::cout << "(" << playerSum << ")";
                        dWin = false;//dWin used either here
                        break;//Break out of checking this player
                    }
                }else if(dSum < playerSum && playerSum < 22){
                    
                    std::cout << " Player " << m_players[i]->m_playerID;
                    std::cout << "(" << playerSum << ")";
                    dWin = false;//Or dWin used here for the first
                    break;//Break out of checking this player
                }
            }
        }
        
        //If no player has a larger hand than dealer and the dealer hasn't bust
        if(dWin && dSum < 22)//dWin also used here
            std::cout << " Dealer(" << dSum << ")";
    }else{
        
        //Print that the dealer has pushed
        std::cout << "Push(" << dSum << "): Dealer";
        
        //And cycle through all players' hands and print they have pushed as well
        for(int i = 1; i < m_players.size(); i++)
        {
            for(int j = 0; j < m_players[i]->m_handList.size(); j++)
            {
                playerSum = m_players[i]->m_handList[j]->SumHand();
                
                if(dSum == playerSum)
                    std::cout << " Player" << m_players[i]->m_playerID;
            }
        }
    }
    
}

/***********************************************************************************
 * Purpose: Ends a game
 * Out: Sets m_play to false, terminating the game loop
 ***********************************************************************************/
void Board::EndGame()
{
    std::cout << "Ending game......\n\n\n\n";
    m_bPlay = false;
}

/***********************************************************************************
 * Purpose: Checks for valid user input
 * Out: Will return true if the user has entered h,H,s,or S and false otherwise
 * In: A char to check against h, H, s, or S
 ***********************************************************************************/
bool isValid(char option)
{
    if(tolower(option) == 'h' || tolower(option) == 's')
        return true;
    else
        return false;
}

/***********************************************************************************
 * Purpose: This will allow a player to play out their hand until stay or bust
 * In: Player pointer to current player
 * Out: The player who completed their turn will have their hand(s) in the state
 *		they want to end the round with
 ***********************************************************************************/
void Board::PlayHands(Player* player)
{
    std::string option = "";
    bool stay = false;
    
	if(player->CanDoubleDown())
		player->DoubleDown();
        
	CheckSplit(player);

    for(int i = 0; i < player->m_handList.size(); i++)
    {
        std::cout << std::endl;
        stay = false;
        
        //While player hasn't picked stay or the player has not busted
        while(!stay)//validOption used for first time
        {
            //If the player has busted then exit while loop
            if(player->PrintHand(i))
                break;
			//Surrender check
            if(player->m_bSurrender == true)
				break;

            //Ask player if they want to hit or stay
            std::cout << "Player " << player->m_playerID << " would you like to (h)it, (s)tand for Hand " << i + 1 << "?>";
            std::getline(std::cin, option);//option used for first time
            
            //Verify option provided is valid
            if(!isValid(option[0]))
            {
                std::cout << "Invalid choice, please choose again.\n";
            }
            else{
                //If player wants to stay then exit while loop
                //Else deal them a card since only other option is to hit
                if(option[0] == 's' || option[0] == 'S')
                {
                    stay = true;
                }else{
                    DealCard(player->m_playerID, i);
                }
            }
        }
    }
}

/***********************************************************************************
 * Purpose: If the gameDeck gets below 50% of it's size then it will delete 
 *			and create a brand new gameDeck
 ***********************************************************************************/
void Board::CheckDeck()
{
    if(m_gameDeck->m_deck.size() < (m_nDecks/2)*52)
    {
        std::cout << "Reshuffling deck...\n";
        delete m_gameDeck;
        m_gameDeck = 0;
        m_gameDeck = MakeGameDeck();
    }
}

/***********************************************************************************
 * Purpose: Pays each player that bought insurance
 * Out:		Insurance is paid 2 to 1 back to a players pot
***********************************************************************************/
void Board::AwardInsurance()
{
	for(int i = 1; i < m_players.size(); i++) 
	{
		if(m_players[i]->m_pot->m_curInsurance != 0)
		{
			//award players their insurance
			m_players[i]->m_pot->m_curInsurance *= 2;
			m_players[i]->m_pot->m_curPot += m_players[i]->m_pot->m_curInsurance;
			m_players[i]->m_pot->m_curInsurance = 0; //reset a players insurance
		}
	}	
}

/***********************************************************************************
 * Purpose: Offer insurance to each player if the dealer has an Ace as its face up card
 * Out:     Insurance is offered if it is declined a player is then offered surrender
***********************************************************************************/
void Board::OfferInsurance()
{
	for(int i = 1; i < m_players.size(); i++)
	{
		if(m_players[i]->CanBuyInsur())
			m_players[i]->BuyInsurance();
	}
	if(m_bDealerBJ)
	{
		//Players win insurance
		AwardInsurance();
	}else{
		OfferSurrender();
	}
}

/***********************************************************************************
 * Purpose: If a player declines insurance they are offered surrender
 * Out: If a player accepts surrender, their get 50% of their current bet back
***********************************************************************************/
void Board::OfferSurrender()
{
	for(int i = 1; i < m_players.size(); i++)
	{
		std::string option;//Used right below this to record input
		std::cout << "Would you like to surrender (y/n): ";
		std::getline(std::cin, option);
				
		if(tolower(option[0]) == 'y')
		{
			m_players[i]->m_pot->m_curBet *= 0.5; 
			m_players[i]->m_pot->m_curPot += m_players[i]->m_pot->m_curBet;
			m_players[i]->m_bSurrender = true;
		}else if(tolower(option[0]) == 'n'){
			//continue as normal
		}else{ 
			std::cout << "Not a valid option, try again.\n";
			i--;
		}
		if(m_players[i]->m_pot->m_curInsurance != 0)
		{
			m_players[i]->m_pot->m_curInsurance = 0;
		}
	}
}

/***********************************************************************************
 * Purpose: Determine if the dealer has blackjack
 * Out: If the dealer has blackjack return true otherwise false
***********************************************************************************/
bool Board::DealerHasBJ()
{
	if(m_players[0]->BlackjackPos() > -1)
		return true;
	else
		return false;
}
