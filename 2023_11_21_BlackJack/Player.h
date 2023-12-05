#pragma once
#include "Person.h"
#include "common.h"

class Shoe;

class Player : public Person{
public :
	Player(const char* name);
	virtual ~Player();
	//using Person::Person;
private :
	void Play(Shoe& shoe);
};