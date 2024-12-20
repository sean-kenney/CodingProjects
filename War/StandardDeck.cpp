#include "StandardDeck.h"
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// smkenney
StandardDeck::StandardDeck() //default constructor
{
}


bool StandardDeck::addCard(Card c) //returns if a card can be added to the deck without going over 52 cards, if a card can be added it is added
{
	if(numCards_ == 52)
	{
		return false;
	}
	else
	{
		deck_[numCards_] = c;
		numCards_ ++;
		return true;
	}
}

void StandardDeck::initializeDeck() //creates a standard full deck of cards
{
	delete [] deck_;
	numCards_ = 0;
	deck_ = new Card[52];
	for(int s = 1; s < 5; s++)
	{
		for(int f = 1; f < 14; f++)
		{
			deck_[numCards_] = (Card(s,f));
			numCards_++;
		}
	}
}
Card StandardDeck::dealCard() // returns the top card from the deck and decreases the number of cards in deck
{
	numCards_--;
	return deck_[numCards_];
}

void StandardDeck::clearDeck() //sets the number of cards to zero
{
	numCards_ = 0;
}
