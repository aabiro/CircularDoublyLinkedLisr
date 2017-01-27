#pragma once
#include <memory>
#include "UnoCard.h"
#include "Queue.h"
#include <iostream>
#include "OrderedList.h"
#define HAND_SIZE 7
#define NUM_OF_PLAYERS 3


class UnoPlayer
{
public:
	UnoPlayer();
	~UnoPlayer();
	
	OrderedList<std::shared_ptr<Card>> hand;

	void setName(int nm) { _name = nm; }

	void getAHand(Queue<std::shared_ptr<Card>> &deck);
	void drawACard(Queue<std::shared_ptr<Card>> &deck, Stack<std::shared_ptr<Card>> &pile);
	bool checkNumber(Stack<std::shared_ptr<Card>> &pile);
	bool checkSuit(Stack<std::shared_ptr<Card>> &pile);
	void repopulateDeck(Queue<std::shared_ptr<Card>> &deck, Stack<std::shared_ptr<Card>> &pile);

	int _handSize;
	
private:
	int _name;

	friend std::ostream& operator<< (std::ostream& os, const UnoPlayer& a);
	friend bool operator==(Card& a, Card& b);

};

UnoPlayer::UnoPlayer() : _handSize(HAND_SIZE) {
	//std::cout << "player created" << std::endl;
}

UnoPlayer::~UnoPlayer() {}

std::ostream& operator<<(std::ostream& os, const UnoPlayer& a) {	
	os << "Player " << a._name << " ";
	return os;
}

bool operator==(Card& a, Card& b) { 
	return (a.getDenomination() == b.getDenomination() && a.getSuit() == b.getSuit());
}

void UnoPlayer::getAHand(Queue<std::shared_ptr<Card>> &deck) {
	//put some cards in hand from the deck
	for (int i = 1; i <= HAND_SIZE; i++) {
		hand.insert(deck.peek());
		//std::cout << *deck.peek()<< std::endl;
		deck.dequeue();
	}
}

bool UnoPlayer::checkSuit(Stack<std::shared_ptr<Card>> &pile) {
	 for (int i = 1; i <= _handSize; i++) {
		if (hand.retrieve(i)->getSuit() == pile.peek()->getSuit()) {
			pile.push(hand.retrieve(i));
			hand.remove(i);
			return true;
		}
	}
	return false;
}
bool UnoPlayer::checkNumber(Stack<std::shared_ptr<Card>> &pile) {
	for (int i = 1; i <= _handSize; i++) {
		if (hand.retrieve(i)->getDenomination() == pile.peek()->getDenomination()) {
			pile.push(hand.retrieve(i));
			hand.remove(i);
			return true;
		}
	}
	return false;
}


void UnoPlayer::repopulateDeck(Queue<std::shared_ptr<Card>> &deck, Stack<std::shared_ptr<Card>> &pile) {
do {

	deck.enqueue(pile.pop());

	} while (pile.isEmpty() != 1);

	pile.push(deck.peek());
	deck.dequeue();

}

void UnoPlayer::drawACard(Queue<std::shared_ptr<Card>> &deck, Stack<std::shared_ptr<Card>> &pile){
	if (deck.isEmpty() == 1) {
		repopulateDeck(deck, pile);}
	
	hand.insert(deck.peek());
	deck.dequeue();
}

