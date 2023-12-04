#pragma once
#include "Person.h"
#include "common.h"

class Shoe;

class Dealer : public Person {
public :
	Dealer();
	Dealer(const char* name);
	virtual ~Dealer();
public:
	void Play(Shoe& shoe);
};