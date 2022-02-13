#include <string>
#include "Cards.h"
#include <iostream>
#include "Lib.h"
#include <random>
#include "CustomLinkedList.h"
#define KindOfSuit 4
#define AmountOfEachSuit 13
#define NumOfCards 52

//comparasion rules
#define TheBiggest 1

using namespace std;

Cards::Cards() {

	pack = new CustomLinkedList<Card>();
	
	for (string s : suits)
	{
		for (int i = 0; i < AmountOfEachSuit; i++)
		{
			Card c(s, i + 1);
			pack->add(c);
		}
	}
}

void Cards::showCards() {

	for (int i = 0; i < NumOfCards; i++)
	{
		pack->printList();
	}
}

Card& Cards::draw() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 51);

	Card& card = pack->get(dist(gen));

	return card;
}


/*================= struct _Card =================*/

Card::_Card(string s, int n) : suit(s), num(n) {}

Card::_Card() {}

ostream& operator<<(ostream& out, const Card& obj) {

	out << obj.suit << " / " << obj.num;
	return out;
}

bool Card::operator==(const _Card& obj) {

	bool flag = false;

	if ((this->num == obj.num) && (this->suit == obj.suit))
		flag = true;

	return flag;
}

_Card& Card::operator=(const _Card& obj) {

	this->num = obj.num;
	this->suit = obj.suit;

	return *this;
}

bool Card::operator>(const _Card& obj) {

	bool flag = false;

	if (this->num != obj.num)
	{
		if ((this->num == TheBiggest) && (obj.num != TheBiggest))

			flag = true;

		else if ((this->num != TheBiggest) && (obj.num == TheBiggest))

			flag = false;

		else

			flag = (this->num > obj.num) ? true : false;

	}
	else  //nums are equal
	
		flag = (getArrayIndex(suits,this->suit) > getArrayIndex(suits, obj.suit)) ? true : false;
			
	return flag;
}