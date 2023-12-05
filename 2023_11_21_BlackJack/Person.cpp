#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include "Person.h"
#include "Shoe.h"
using namespace std;


Person::Person(const char* pName) {
	fill_n(_hand, HAND_SIZE, -1);
	_cardNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

Person::~Person() {
	if (_pName != nullptr) {
		delete[] _pName;
		_pName = nullptr;
	}
}

const char* Person::getName() const {
	return _pName;
}

//�X�R�A�̌v�Z
int Person::calcScore() const {
	if (_cardNum <= 0) {
		return 0;
	}
	int* data = NULL; //�X�R�A�v�Z�p�z��p�|�C���^

	data = new(nothrow) int[_cardNum]; //��D�����m��
	if (data == NULL)
	{
		// �������s���͍���̓o�[�X�g�Ƃ��ďI������B
		cout << "�������̊m�ۂɎ��s���܂����B�ċN�����Ă��������B" << endl;
		return 0;
	}

	//��D�z�񂩂�f�[�^���擾,1-10�̒l�Ƃ��Ċi�[
	for (int i = 0; i < _cardNum; i++) {
		if (_hand[i] % 13 < 10) {
			//�z��̒l��10�ȉ�(0-9)�ł����1�������Ċi�[
			*(data + i) = _hand[i] % 13 + 1;
		}
		else {
			//������10���i�[���Ă���̂�,11-13�̃J�[�h�̂���
			*(data + i) = 10;
		}
	}

	//�\�[�g�iA�����Ԃ肾�����߁j
	sort(data, data + _cardNum);

	//�Ԃ�l�p�ϐ�(�v�Z����)
	int score = 0;
	//2�Ԗڂ��珇�ɃX�R�A�𑫂��Ă���
	//1�Ԗڂ�0�̏ꍇ(�܂�A�ł���B2�������\���͂��邪2���ڂ�A�͕K��1�Ƃ��ăJ�E���g����
	//�̂Ő擪�������ׂ�΂悢
	for (int i = 1; i < _cardNum; i++) {
		//�X�R�A�Ƀf�[�^��������
		score = score + (*(data + i));
	}

	//�擪��1(A)�ł��邩���肵�󋵂ɂ����1 or 11�Ƃ��Čv�Z
	if (*data == 1) {
		if (score + 11 < 22) { //11�Ƃ��Ĉ����Ă��o�[�X�g���Ȃ��ꍇ
			//11��������
			score += 11;
		}
		else {
			//11�Ƃ��Ĉ����ƃo�[�X�g����ꍇ
			//�X�R�A��1��������
			score += 1;
		}
	}
	else {
		//�擪��1�łȂ��Ȃ�,�X�R�A�Ƀf�[�^�����̂܂܉�����
		score += data[0];
	}

	//�o�[�X�g�ł���ꍇ��0��Ԃ�
	if (score > 21) {
		score = 0;
	}

	// ���
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
	}

	return score;
}

void Person::hit(Shoe& shoe) {
	int card = shoe.takeCard();
	if (card >= 0 && _cardNum <= 15) {
		_hand[_cardNum] = card;
		_cardNum++;
	}
	else
	{
		cout << "�J�[�h�������܂���ł����B" << endl;
	}
}

void Person::showHand() const {
	//�W���o��
	cout << "hand: ";
	//�z��̍ŏ�����Ō�܂ł����ɕ\��
	for (int i = 0; i < _cardNum; i++) {
		//�J�[�h�̎��(�X�y�[�h,�n�[�g,�_�C��,�N���u)��T��
		int type = (_hand[i] % CARD_NUM) / 13; //�f�b�L���Ƃɕ�������,13�Ŋ�������(0-3)��4��ނ𕪊�

		//�W���o��
		const char* strType[] = { "s", "h", "d", "c" };
		cout << strType[type];
		cout << _hand[i] % 13 + 1 << ' ';
	}
	//���s
	cout << endl;
	cout << "score: " << calcScore() << endl; //�X�R�A�̕\��
}

bool Person::play(Shoe &shoe) {
	Play(shoe);
	if (calcScore() <= 0) return false;
	return true;
}