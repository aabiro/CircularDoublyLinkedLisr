#pragma once
#include <iostream>

enum Suit { RED = 1, BLUE = 2, GREEN = 3, YELLOW = 4 };		// User defined Suit

class Card
{
public:
	Card();
	Card(Suit suit = GREEN, int denomination = 1);			// constructor with some default values
	~Card();												// destructor
	Suit getSuit(void) const { return m_suit; }
	int getDenomination(void) const { return m_denomination; }
	char toCharSuit(void) const;							// returns a char that "describes" card's suit
	

private:
	Suit m_suit; 
	int m_denomination; 
	friend std::ostream& operator<< (std::ostream& os, const Card& a);
};

Card::Card(): m_suit(GREEN), m_denomination(1){}

Card::Card(Suit suit, int denomination): m_suit(suit), m_denomination(denomination){}  

Card::~Card(){}

char Card::toCharSuit() const
{
	if		(m_suit == RED)     return 'R';
	else if (m_suit == BLUE)    return 'B';
	else if (m_suit == GREEN)   return 'G';
	else                        return 'Y';
}

std::ostream& operator<<(std::ostream& os, const Card& a) {		//Card output
	auto suit = a.toCharSuit();
	auto demo = a.getDenomination();
	switch (suit) {
	case 'R':
		os << " Red - ";
		break;
	case 'B':
		os << " Blue - ";
		break;
	case 'G':
		os << " Green - ";
		break;
	default:
		os << " Yellow - ";
	}
		os << demo;
	return os;
}

