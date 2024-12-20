#include "Card.h"
std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",
"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// smkenney
Card::Card() //default constructor
{
	suitVal_ = 0;
	faceVal_ = 0;
}

Card::Card(int s, int f) //overloaded constructor
{
	suitVal_ = s;
	faceVal_ = f;
}

Card::~Card() //destructor
{
	//suitVal_ = NULL;
	//faceVal_ = NULL;
}

std::string Card::getSuit() //gets the suit of the card in string format
{
	return Card::SUIT[suitVal_];
}

std::string Card::getFace() //gets the face of the card in string format
{
	return Card::FACE[faceVal_];
}

std::string Card::print() //returns the suit and face of the card in string format
{
	return FACE[faceVal_] + " of " + SUIT[suitVal_];
}

int Card::getSuitVal() //gets the suit value of the card
{
	return suitVal_;
}

int Card::getFaceVal() //gets the face value of the card
{
	return faceVal_;
}

void Card::initialize(int s, int f) //initializes a card to specific suit and face value
{
	suitVal_ = s;
	faceVal_ = f;
}