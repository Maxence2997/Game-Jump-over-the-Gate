#ifndef CARDS_H
#define CARDS_H
#include <string>
#include "CustomLinkedList.h"
#include <vector>
using namespace std;
typedef struct _Card Card;

/*	@Author: Maxence2997
	@Version:1.0
	@Date: 2022/02/04		*/

static const vector<string> suits = { "Club", "Diamond", "Heart", "Spade" };

class Cards {

private:
	CustomLinkedList<Card>* pack;
	
public:

	Cards();
	Card& draw();
	void showCards();
};

struct _Card {

	int num;
	string suit;
	struct _Card(string s, int n);
	struct _Card();
	bool operator>(const _Card& obj);
	bool operator==(const _Card& obj);
	_Card& operator=(const _Card& obj);
	friend ostream& operator<<(ostream&, const _Card&);
};
#endif // !CARDS_H

