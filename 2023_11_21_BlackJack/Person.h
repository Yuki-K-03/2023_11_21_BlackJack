#pragma once
#include "common.h"

class Shoe;

class Person {
private:
	int _hand[HAND_SIZE];
	int _cardNum;

	char* _pName;

public:
	Person(const char *pName);
	virtual ~Person();

	void hit(Shoe& shoe);
	void showHand();
	int calcScore();

	const char* getName() const;
};