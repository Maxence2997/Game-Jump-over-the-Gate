#include <iostream>
#include <string>
#include "Player.h"
#include <thread>
#include "gameSetting.h"
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

	cout << "�w��Ө�g�s���C��!" << endl;
	cout << endl;

	setPlayers();
		
	for (int i = 0;; i++)
	{
		cout << "================  �� " << i + 1 << " ��  ================" << endl;
		sleepAndDot(5);
		cout << endl;
		cout << "�п�J���O:\ti: �}�l�C��!\tq: ���}�õ���!\t�����N��d�ݥثe�����䥭��";
		cout << endl;
		char command;
		cin >> command;

		if (tolower(command) == 'i')

			proceed();

		else if (tolower(command) == 'q')
		{
			showBalanceSheet();
			cout << "�T�w�n���}�C��?\t y: ���}�C��\t�����N���~��C��\t";
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