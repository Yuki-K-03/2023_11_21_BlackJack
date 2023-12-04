#include <iostream>
#include <ctime>
#include "Shoe.h"
using namespace std;


// �R���X�g���N�^
Shoe::Shoe() {
	_cardNum = CARD_NUM;

	for (int i = 0; i < _cardNum; i++) {
		_cardShoe[i] = i;
	}
}

Shoe::~Shoe() {

}

int Shoe::takeCard() {
	if (_cardNum <= 0) {
		return -1;
	}
 	_cardNum--;
	int card = _cardShoe[_cardNum];
	_cardShoe[_cardNum] = -1;

	return card;
}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	//srand((unsigned int)time(NULL));

	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}
