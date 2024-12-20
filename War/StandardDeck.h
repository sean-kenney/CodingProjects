#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H
#include "Card.h"
#include "Deck.h"
#define DECK_SIZE 52
/**
* @class StandardDeck
*
* The StandardDeck class represents a standard deck of 52 cards.
*
*/
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// smkenney
class StandardDeck : public Deck
{
public:
/// Default constructor.
StandardDeck();
/// Default destructor.
//~StandardDeck();
/**
* Returns True/False (1/0) whether or not the Deck is empty.
*
* @return Boolean
*/
//bool isEmpty();
/**
* Returns the number of cards remaining in the deck.
*
* @return Integer value
*/
//int getNumCards();
/**
* Displays the i'th card in the Deck.
*
* @param[in] Index
*/
//void displayCard(int i);
/**
* Prints the contents of the Deck. This method should call the
* print() method on each Card.
*/
bool addCard(Card c);
bool mergeDecks(StandardDeck & deck2, bool shuf);
void initializeDeck();
Card dealCard();
void clearDeck();
};
#endif
