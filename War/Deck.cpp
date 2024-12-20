#include "Deck.h"
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// smkenney
Deck::Deck()
{
	numCards_ = 52;
	deck_ = new Card[numCards_];
}
Deck::~Deck()
{
	numCards_ = 0;
	delete [] deck_;
}
bool Deck::isEmpty()
{
	return numCards_ == 0;
} 
int Deck::getNumCards()
{
	return numCards_;
}
void Deck::displayCard(int i)
{
	std::cout << deck_[i].print() <<std::endl;
}
void Deck::printDeck()
{
	for(int i = 0; i < numCards_; i++)
	{
		std::cout << deck_[i].print() <<std::endl;
	}
}
void Deck::shuffle()
{
	Card temp;
	Card temp2;
	int x,y;
	for (int i = 0; i < (numCards_ * 3); i++) //loops through 2 times
	{
		x = rand() % (numCards_ ); //picks random index for the first card
		y = rand() % (numCards_ ); //picks a random index for the second card
        temp.initialize(deck_[y].getSuitVal(),deck_[y].getFaceVal()); //creates a temporary card for the first card
		temp2.initialize(deck_[x].getSuitVal(),deck_[x].getFaceVal()); //creates a temporary card for the second card
		deck_[y].initialize(temp2.getSuitVal(),temp2.getFaceVal()); //adds the second card in the first cards spot
		deck_[x].initialize(temp.getSuitVal(),temp.getFaceVal()); //adds the first card in the second cards spot
	}
}

void Deck::clearDeck()
{
	numCards_ = 0;
}

Card Deck::getCard(int i)
{
	return deck_[i];
}

Card Deck::getTop()
{
	return deck_[numCards_-1];
}

Card * Deck::getDeck()
{
	return deck_;
}