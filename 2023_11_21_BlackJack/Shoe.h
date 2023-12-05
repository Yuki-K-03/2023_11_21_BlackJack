#pragma once

#include "common.h"
#include "Card.h"

class Shoe{
private :
public :
	//int _cardShoe[CARD_MAX];
	int _cardNum;
	Card _cardShoe[CARD_MAX];

public :
	Shoe();
	virtual ~Shoe();	// デストラクタは virtual をつける

public :
	bool takeCard(Card &card);		// カードを一枚出す
	void _shuffle();
};