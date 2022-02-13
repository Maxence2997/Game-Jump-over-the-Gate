#ifndef GAMESETTING_H
#define GAMESETTING_H
#include "Player.h"
#include <vector>
#include "Cards.h"
using namespace std;

/*	@Author: Maxence2997
	@Version:1.0
	@Date: 2022/02/09		*/

namespace game {
		
	void proceed();
	void showBalanceSheet();
	void setPlayers();
	void win(Player& p, int bet);
	void lose(Player& p, int bet, int weight);
	void sleepAndDot(int times);
	void dots(int times);

}	
#endif
