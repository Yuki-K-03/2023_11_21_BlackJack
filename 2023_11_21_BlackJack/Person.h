#pragma once
#include "common.h"

class Shoe;

class Person {
private:
	int _hand[HAND_SIZE];
	int _cardNum;
	char* _pName;
	virtual void Play(Shoe& shoe) = 0;

public:
	Person(const char *pName);
	virtual ~Person();

	void hit(Shoe& shoe);
	void showHand() const;
	int calcScore() const;
	bool play(Shoe& shoe);

	const char* getName() const;
};