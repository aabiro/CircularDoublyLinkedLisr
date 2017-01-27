#pragma once
#include <memory>
#include "Stack.h"
#include "Queue.h"
#include "UnoCard.h"
#include "Bag.h"
#include "UnoPlayer.h"
#define MAX_CARD_NUM 5		//the maximum denomination of cards
#define MAX_NUM_CARDS 40	//the number of cards in the bag


class UnoGame {
public:

	UnoGame(unsigned int _numPlayers = NUM_OF_PLAYERS);
	~UnoGame();
	UnoPlayer* player = new UnoPlayer[NUM_OF_PLAYERS];						// unoplayer pointer " players" makes players
	Stack<std::shared_ptr<Card>> faceUpPile;								// points to  dynamic array of unoplayers	
	Queue<std::shared_ptr<Card>> deck;
	void play();

	int _gameOver;	
};

UnoGame::UnoGame(unsigned int _numPlayers){
	_gameOver = 0;
	Bag<std::shared_ptr<Card>> bag(MAX_NUM_CARDS);						    //make bag object
	Suit s[] = { RED,BLUE,GREEN,YELLOW };

	int denomArr[MAX_NUM_CARDS];
																			//make denom array
	for (int j = 1; j <= MAX_CARD_NUM; j++) {
		denomArr[j] = j;
	}
	
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 4; i++) {										//fill - 2 of each card
			for (int j = 1; j <= MAX_CARD_NUM; j++) {
				bag.add(std::make_shared<Card>(s[i], denomArr[j]));		
			}			
		}
	}

	do {
	deck.enqueue(bag.getOne());										//pull cards from bag randomly and place in deck
	} while (bag.currentSize() != 0);
	
for (int i = 1; i <= NUM_OF_PLAYERS;i++) {
																	//puts the players names in the array
	player[i-1].setName(i);											//sets their names
	player[i-1].getAHand(deck);
	}

	faceUpPile.push(deck.peek());	
	std::cout << " "<< *faceUpPile.peek() << " was drawn from the deck." << "\n"; //faceupPile first card
	deck.dequeue();
}

UnoGame::~UnoGame()
{
	delete[] player;
}
	
void UnoGame::play(){												//procedural gameplay

	std::cout << "	         Start!\n" << std::endl;

	while (_gameOver != 1) {

		for (int i = 0; i < NUM_OF_PLAYERS; i++) {

			if (player[i].checkSuit(faceUpPile) == 1)
			{
				std::cout << player[i] << " found a match! They played " << *faceUpPile.peek() << "\n";
				player[i]._handSize--;
				if (player[i]._handSize == 0)
				{
					std::cout << "\n" << player[i] << " yells\: \"UNO! I beat you!\" " << std::endl;
					_gameOver = 1;
					break;
				}
			}
			else if (player[i].checkNumber(faceUpPile) == 1)
			{
				std::cout << player[i] << " found a match! They played " << *faceUpPile.peek() << "\n";
				player[i]._handSize--;
				if (player[i]._handSize == 0)
				{
					std::cout<< "\n" << player[i] << " yells\: \"UNO! I beat you!\" "<< "\n" << std::endl;
					_gameOver = 1;
					break;
				}
			}
			else {
				player[i].drawACard(deck, faceUpPile);
				player[i]._handSize++;
				std::cout << player[i] << " did not find a match. They drew a card. " << "\n";
			}
		}
	}

	std::cout << "\nGame over. Thanks for playing!" << "\n\n";
}



