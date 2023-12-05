#include <iostream>
#include "Card.h"

void Card::operator=(const Card other) {
	_cardNum = other._cardNum;
	_cardSuit = other._cardSuit;
}

bool Card::operator==(const Card other) {
	if (_cardNum == other._cardNum) {
		return true;
	}
	else {
		return false;
	}
}

const int Card::GetNum() const {
	return _cardNum;
}

const int Card::GetSuit() const {
	return _cardSuit;
}

void Card::SetCard(int num, int suit) {
	_cardNum = num;
	_cardSuit = suit;
}

const char* Card::ShowNum() const{
	return CARD_NUMBER[_cardNum];
}

const char* Card::ShowSuit()  const{
	return CARD_SUIT[_cardSuit];
}