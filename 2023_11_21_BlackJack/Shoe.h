#pragma once

#include "common.h"

class Shoe {
private :
	int _cardShoe[CARD_NUM];
	int _cardNum;

public :
	Shoe();
	virtual ~Shoe();	// �f�X�g���N�^�� virtual ������

public :
	int takeCard();		// �J�[�h���ꖇ�o��
	void _shuffle();
};