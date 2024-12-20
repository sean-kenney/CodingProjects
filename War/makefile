# I pledge that I have neither given nor
# received any help on this assignment.
#
# smkenney
Play.exe: driver.o Card.o StandardDeck.o Deck.o NonStandardDeck.o
	g++ driver.o Card.o StandardDeck.o Deck.o NonStandardDeck.o -o Play.exe
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
Card.o: Card.cpp
	g++ -c Card.cpp -o Card.o
	
StandardDeck.o: StandardDeck.cpp
	g++ -c StandardDeck.cpp -o StandardDeck.o

Deck.o: Deck.cpp
	g++ -c Deck.cpp -o Deck.o

NonStandardDeck.o: NonStandardDeck.cpp
	g++ -c NonStandardDeck.cpp -o NonStandardDeck.o
	
clean:
	rm *.o Play.exe
	
run:
	Play.exe