#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H
#include "Card.h"
#include "Deck.h"
#include <fstream>
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// smkenney
class NonStandardDeck : public Deck
{
	public:
		NonStandardDeck();
		bool addCard(Card c);
		bool mergeDecks(Deck * deck2, bool shuf);
		void initializeDeck();
		Card dealCard();
		void clearDeck();
};
#endif