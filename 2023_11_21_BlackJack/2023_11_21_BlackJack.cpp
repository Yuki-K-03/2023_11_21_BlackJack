#include <iostream>
#include <ctime>
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;


void ShowHand(Person& person) {
	printf("%s\n", person.getName());
	person.showHand();
	cout << "============================" << endl;
}

static void showResult(Player& player, Dealer& dealer)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	ShowHand(dealer);
	ShowHand(player);

	if (player.calcScore() > dealer.calcScore()) {
		cout << "Player Win!" << endl;
	}
	else if (player.calcScore() < dealer.calcScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	Player p("Herooo");
	Dealer d;
	Shoe shoe;
	shoe._shuffle();

	printf("====================\n");
	printf("%s\n", p.getName());
	for (int i = 0; i < 2; i++) {
		p.hit(shoe);
	}
	ShowHand(p);

	printf("====================\n");

	printf("====================\n");
	printf("%s\n", d.getName());
	d.hit(shoe);
	ShowHand(d);
	d.hit(shoe);
	printf("====================\n");



	if (p.play(shoe)) {
		d.play(shoe);

		showResult(p, d);
	}
	else {
		printf("バーストしたので負けです。");
	}
}