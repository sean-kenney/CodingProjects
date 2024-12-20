#ifndef DECK_H
#define DECK_H
#include "Card.h"
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// smkenney
class Deck
{
	public:
		Deck();
		~Deck();
		bool isEmpty();
		int getNumCards();
		void displayCard(int i);
		void printDeck();
		void shuffle();
		void clearDeck();
		Card getCard(int i);
		Card getTop();
		Card * getDeck();
	protected:
		Card * deck_; // Pointer to record the location of the array of Cards in memory.
		int numCards_;
};
#endif