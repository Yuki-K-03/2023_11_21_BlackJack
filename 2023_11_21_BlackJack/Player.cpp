#include <iostream>
#include "Player.h"
#include "Shoe.h"
using namespace std;


Player::Player(const char* name) : Person(name) {

}

Player::~Player() {

}

//ゲーム実行
void Player::PlayBase(Shoe& shoe) {

	//入力
	char str[HAND_SIZE] = {" "}; //文字列型
	//バーストするまでループ処理
	do {
		cout << "hit or stand >> ";

		cin >> str; //文字列を入力
		//hitが入力された場合
		if (strcmp(str, "hit") == 0) {
			//カードの配布
			hit(shoe);

			//手札の表示
			cout << "====================" << endl;
			cout << "player" << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			break;
		}
	} while (calcScore());
}
