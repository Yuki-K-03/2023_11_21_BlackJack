#pragma once
//
//const int NUMBER_MAX = 13;
//const char* CARD_NUMBER[] = { "Joker", " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };
//const char* CARD_SUIT[] = { "  heart", "diamond", "  spade", "   club" };

extern const int NUMBER_MAX;
extern const char* CARD_NUMBER[];
extern const char* CARD_SUIT[];


struct CardKinds{
	int CardNum;
	int CardSuit;
};

class Card
{
protected :
	public :
	int _cardNum;
	int _cardSuit;

public :
	void operator=(const Card other);
	bool operator==(const Card other);
	void SetCard(int num, int suit);
	const int GetNum()  const;
	const int GetSuit()  const;
	const char* ShowNum() const;
	const char* ShowSuit() const;
};