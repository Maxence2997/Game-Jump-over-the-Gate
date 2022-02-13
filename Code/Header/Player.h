#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

/*	@Author: Maxence2997
	@Version:1.0
	@Date: 2022/02/08		*/

class Player {

private:
	
	string name;
	int balance;
	int earnAmount;
	int payAmount;
	void calculate();

public:

	static int playerCount;
	Player(string s);
	string getName();
	void addEarning(int amounts);
	int getEarning();
	void addPaying(int amounts);
	int getPaying();
	int getBalance();
};
#endif
