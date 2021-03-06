#include <iostream>
#include <string>
#include "Player.h"
#include <thread>
#include "gameSetting.h"
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
using namespace game;
using namespace std::this_thread;     // sleep_for, sleep_until
typedef struct _Card Card;

/*	@Author: Maxence2997
	@Version:1.0
	@Date: 2022/02/09	

	This programme is the final project of the C++ basic class in CSIE of NTU, 
	and it's a simple gambling game called <Jump over the Gate> which we always play in chinese lunar new year.
	Game rules =>  Ref.: https://shopee.tw/blog/poker-games/  */

int main() {

	//cout.width(50);
	//cout.fill('-');
	//cout << setiosflags(ios::left);
	//cout << setw(49) << "+" << "+" << endl;			//frame
	//cout.fill(' ');

	//cout << setw(49) << "| 歡迎來到射龍門遊戲!" << "|" << endl;

	//cout.fill('-');
	//cout << setw(49) << "+" << "+" << endl;			//frame
	//cout.fill(' ');
	//cout << endl;
	//cout << resetiosflags(ios::left);
	//cout << endl;

	frame(" 歡 迎 來 到 射 龍 門 遊 戲 !");

	setPlayers();
		
	for (int i = 0;; i++)
	{
		cout << endl;
		string s = "                   第 " + to_string(i + 1) + " 局";
		frame(s);
		//cout << "================  第 " << i + 1 << " 局  ================" << endl;

		//sleepAndDot(5);
		//cout << endl;
		cout << "請輸入指令:\ti: 開始遊戲!\tq: 離開並結算!\t按任意鍵查看目前的收支平衡";
		cout << endl;
		char command;
		cin >> command;

		if (tolower(command) == 'i')

			proceed();

		else if (tolower(command) == 'q')
		{
			showBalanceSheet();
			cout << "確定要離開遊戲?\t y: 離開遊戲\t按任意鍵繼續遊戲\t";
			char c;
			cin >> c;
			if (tolower(c) == 'y')
				exit(0);
			else
				i -= 1;
		}
		else 
		{
			showBalanceSheet();
			i -= 1;
		}
	}

	return 0;
}