#include "Card.h"
#include "Deck.h"
#include "StandardDeck.h"
#include "NonStandardDeck.h"

// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment->
//
// smkenney

int main()
{
	srand (time(NULL));
	StandardDeck * deck = new StandardDeck();
	NonStandardDeck * p1 = new NonStandardDeck();
	NonStandardDeck * p2 = new NonStandardDeck();
	//deck = new StandardDeck(); //the starting deck, also serves as the 'battleground'
	//p1 = new NonStandardDeck(); //player 1's hand
	//p2 = new NonStandardDeck; //player 2's hand
	int playing = 0; 
	bool battling;
	int p1Score = 0; 
	int p2Score = 0;
	int p1NumWins = 0;
	int p2NumWins = 0;
	while(playing < 50) //loops through 50 times
	{
		p1->clearDeck(); //clears player 1's deck to play again
		p2->clearDeck(); //clears player 2's deck to play again 
		deck->clearDeck(); //clears the starting deck
		deck->initializeDeck(); //recreates a deck
		deck->shuffle(); //shuffles the deck
		battling = true; //starts the loop for the new round
		while(deck->getNumCards() >2) //deals cards until the deck is empty
		{
			p1->addCard(deck->dealCard());
			p2->addCard(deck->dealCard());
		}
		p1->shuffle(); //shuffles player 1's cards
		p2->shuffle(); //shuffles player 2's cards
		while(battling) //loops through until someone wins the round
		{
			p1->shuffle(); //shuffles players 1's hand so that a random card is selected
			deck->addCard(p1->dealCard()); //plays a card from player 1's hand
			if((deck->getNumCards() >= 2) && (deck->getCard(deck->getNumCards() - 2).getFaceVal() == deck->getTop().getFaceVal()))
			{ //if the two card on the top of the deck are the same face value player 1 gets all cards in the deck
				p1->mergeDecks(deck,true);
				deck->clearDeck();
				deck->addCard(p1->dealCard());
			}
			p2->shuffle(); //shuffles players 2's hand so that a random card is selected
			deck->addCard(p2->dealCard()); //plays a card from player 1's hand
			if((deck->getNumCards() >= 2) && (deck->getCard(deck->getNumCards() - 2).getFaceVal() == deck->getTop().getFaceVal()))
			{ //if the two card on the top of the deck are the same face value player 2 gets all cards in the deck
				p2->mergeDecks(deck,true);
				deck->clearDeck();
				deck->addCard(p2->dealCard());
			}
			if(p1->isEmpty()) //if player 1 runs out of cards first player 2's number of wins gets updated and the round ends
			{
				battling = false;
				p2Score += p2->getNumCards();
				p2NumWins++;
			}
			else if(p2->isEmpty()) //if player 2 runs out of cards first player 1's number of wins gets updated and the round ends
			{
				battling = false;
				p1Score += p1->getNumCards();
				p1NumWins++;
			}
		}
		playing++;
		
	}
	if(p1NumWins > p2NumWins) //if player 1 has more wins they are declared the winnner
	{
		std::cout << "Player 1 is the champion with " << p1NumWins << " wins over Player 2." << std::endl;
	}
	else if((p2NumWins > p1NumWins)) //if player 2 has more wins they are declared the winnner
	{
		std::cout << "Player 2 is the champion with " << p2NumWins << " wins over Player 1." << std::endl;
	}
	else //if they tie it's declared a draw
	{
		std::cout << "Player 1 and Player 2 tied and both players had " << p1NumWins << "." << std::endl;
	}
	std::cout << "Player 1 Average Score: " << (p1Score/p1NumWins) << " points" << std::endl; //prints player 1's average score
	std::cout << "Player 2 Average Score: " << (p2Score/p2NumWins) << " points" << std::endl; //prints player 2's average score
	
	delete deck;
	delete p1;
	delete p2;
	return 0;
	
};