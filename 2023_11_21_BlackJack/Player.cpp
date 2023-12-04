#include <iostream>
#include "Player.h"
#include "Shoe.h"
using namespace std;


Player::Player(const char* name) : Person(name) {

}

Player::~Player() {

}

//�Q�[�����s
bool Player::play(Shoe& shoe) {
	//�o�[�X�g����܂Ń��[�v����
	while (calcScore()) {
		cout << "hit or stand >> ";

		//����
		char str[HAND_SIZE]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << "player" << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�Ԃ�l��true�Ƃ��ďI��
			return true;
		}
	}
	//�o�[�X�g���Ă���̂�false��Ԃ��ďI��
	return false;
}
