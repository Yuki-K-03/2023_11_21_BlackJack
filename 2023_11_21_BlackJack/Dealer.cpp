#include <iostream>
#include "Dealer.h"
#include "Shoe.h"
using namespace std;

Dealer::Dealer() : Person("Dealer") {

}

Dealer::Dealer(const char* name) : Person("Dealer") {

}

Dealer::~Dealer() {

}


bool Dealer::play(Shoe& shoe) {
	//スコアが16以下の場合hitを続ける
	while (calcScore() < 17 && calcScore() > 0) {
		//ヒットする
		hit(shoe);
		cout << "hit" << endl;
		//手札の表示
		cout << "====================" << endl;
		cout << "dealer" << endl;
		showHand();
		cout << "====================" << endl;
	}
	if (calcScore() <= 0) return false;
	return true;
}