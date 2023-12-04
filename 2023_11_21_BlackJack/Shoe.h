#pragma once

#include "common.h"

class Shoe {
private :
	int _cardShoe[CARD_NUM];
	int _cardNum;

public :
	Shoe();
	virtual ~Shoe();	// デストラクタは virtual をつける

public :
	int takeCard();		// カードを一枚出す
	void _shuffle();
};