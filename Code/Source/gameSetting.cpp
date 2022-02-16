#include "Player.h"
#include <vector>
#include "Cards.h"
#include "gameSetting.h"
#include <iostream>
#include <thread>
#include <iomanip>
//#include "Lib.h"
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std;

namespace game {

	int numOfPpl = 0;
	int baseBet = 0;
	int stakesPool = 0;
	vector<Player> ppl = {};
	Cards card;

	void proceed()
	{
		/* @Author: Maxence2997
		   @Version:1.0
		   @Date: 2022/02/11 
		   The process in the game*/

		cout << endl;
		cout << "�п�J�o�@�������`���B :\t";
		cin >> baseBet;

		while ((baseBet <= 0) || cin.fail())
		{
			/*input check. Ref.: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/*/

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��J���~�A�Э��s�п�J�o�@�������`���B :\t";
			cin >> baseBet;
		}

		//cout << endl;
		sleep_for(1s);
		cout << endl;

		for (Player p : ppl)
			p.addPaying(baseBet);

		stakesPool = numOfPpl * baseBet;
		showBalanceSheet();
		cout << "�Y�N�}�l�C��!";
		dots(5);
		cout << endl;
		

		while(stakesPool>0) 
		{
			for (Player& p : ppl)
			{
				int weight = 0;
				Card card1 = card.draw();
				Card card2 = card.draw();
				cout << endl;
				cout << p.getName() << " :\t" << card1 << "\t" << card2 << endl;
				cout << endl;

				/*cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
				cout << "�аݭn�ɵPor���o�@��?\tp: �ɵP�ø�`\tl: ���o�@��    ";
				char comm;
				cin >> comm;

				int count1 = 0;
				while ((tolower(comm) != 'p') && (tolower(comm) != 'l') && (count1 < 1))
				{
					cout << "��J���~�A�A�����~�N�������P���o�@��" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�аݭn�ɵPor���o�@��?\tp: �ɵP�ø�`\tl: ���o�@��    ";
					cin >> comm;
					count1++;
				}

				cout << endl;

				if (tolower(comm) == 'p')
				{
					cout << "�аݳo�@���n��`�h�ֿ� ?\t";
					int bet;
					cin >> bet;

					while (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "��J���~�A�Э��s�п�J��`���B :\t";
						cin >> bet;
					}

					while (bet > stakesPool)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "��`���i�j��������B�A�Э��s��J !\t";
						cin >> bet;
					}

					cout << endl;

					if (card1.num == card2.num)
					{
						cout << "�аݭn���" << card1.num << "�j�٬O��" << card1.num << "�p?\tb: �j  s: �p\t";
						char BorS;
						cin >> BorS;

						int count2 = 0;
						while ((tolower(BorS) != 'b') && (tolower(BorS) != 's') && count2 < 1) {

							cout << "��J���~�A�A�����~�N�������P���o�@��" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "�аݭn���" << card1.num << "�j�٬O��" << card1.num << "�p?\tb: �j  s: �p\t";
							count2++;
						}

						cout << endl;

						Card card3 = card.draw();
						cout << card3 << endl;
						cout << endl;

						bool winCase1 = (tolower(BorS) == 'b') && (card3.num > card1.num);
						bool winCase2 = (tolower(BorS) == 's') && (card3.num < card1.num);
						bool loseCase1 = (card3.num == card1.num);

						if (winCase1 || winCase2)

							win(p, bet);

						else if (loseCase1)
						{
							weight = -3;
							lose(p, bet, weight);
						}
						else				//loseCases that guessed BIGGER but got SMALLER card in realty or 
						{					//guessed SMALLER but got BIGGER card in realty
							weight = -1;
							lose(p, bet, weight);
						}
					}
					else									// (card1.num != card2.num)
					{
						Card card3 = card.draw();
						cout << card3 << endl;
						cout << endl;
						bool loseCase = ((card3.num == card1.num) || (card3.num == card2.num));
						bool winCase1 = ((card3.num < card1.num) && (card3.num > card2.num));	//(card1.num > card2.num)
						bool winCase2 = ((card3.num > card1.num) && (card3.num < card2.num));	//(card1.num < card2.num)

						if (loseCase)
						{
							weight = -2;
							lose(p, bet, weight);
						}
						else if (winCase1 || winCase2)

							win(p, bet);

						else						//loseCases that Card3.num not between Card1.num and Card2.num
						{
							weight = -1;
							lose(p, bet, weight);
						}
					}

				}
				else		//quit from this round
				{
					weight = -1;
					lose(p, baseBet, weight);
					if (tolower(comm) == 'l')

						cout << "�еy��U�@���o�P !" << endl;

					else
						cout << "��J���~�A�еy��U�@���o�P !" << endl;
				}

				if (stakesPool == 0)
				{
					cout << "�����w�k�s�A�����i�J�U�@��" << endl;
					baseBet = 0;
					break;
				}
				cout << "============================================" << endl;
			}
		}

	}

	void showBalanceSheet() {

		/* @Author: Maxence2997
		   @Version:1.0
		   @Date: 2022/02/11	*/

		cout.width(50);
		cout.fill('-');
		cout << setiosflags(ios::left);
		cout << setw(49) << "+" << "+" << endl;			//frame
		cout.fill(' ');


		cout << setw(49) << "|�ثe���䥭�Ū��p" << "|" << endl;

		for (Player& p : ppl)
		{
			string s1 = "| " + p.getName() + " : " + to_string(p.getBalance());
			cout << setw(49) << s1 << "|" << endl;
		}

		string s2 = "| �o���H" + to_string(baseBet) + "�������`�A�ثe�����`�@��" +
			to_string(stakesPool) + "��";
		cout << setw(49) << s2 << "|" << endl;


		cout.fill('-');
		cout << setw(49) << "+" << "+" << endl;			//frame
		cout.fill(' ');
		cout << endl;
		cout << resetiosflags(ios::left);
	}

	void setPlayers() {

		/* @Author: Maxence2997
		   @Version:1.0
		   @Date: 2022/02/11	*/

		

		cout << "�п�J�ѻP�H��(2~10�H) : ";
		cin >> numOfPpl;
		cout << endl;
		sleep_for(1s);


		int count1 = 0;
		while ((numOfPpl > 10) || (numOfPpl < 2) || (cin.fail()))
		{
			/*input check. Ref.: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/*/

			count1++;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��J���~" << count1 << "���A�Э��s��J\t";
			cin >> numOfPpl;
			cout << endl;
		}

		for (int i = 0; i < numOfPpl; i++)
		{
			cout << "�п�J���a" << i + 1 << "�W�� :\t";
			string name;
			cin >> name;
			cout << endl;

			ppl.push_back(Player(name));
			cout << endl;
			//sleep_for(1s);
		}

		cout << "HI! ";
		for (Player p : ppl)

			cout << p.getName() << " ";

		cout << endl;
		//sleep_for(1s);
	}

	void win(Player& p, int bet) {

		/* @Author: Maxence2997
		   @Version:1.0
		   @Date: 2022/02/09	*/

		stakesPool -= bet;
		p.addEarning(bet);
		cout << p.getName() << "  �zĹ�F " << bet << "���A�ثe���䥭�Ŭ� :" << p.getBalance() << "��\t" << "�������� " << stakesPool << "��" << endl;
		cout << endl;
	}

	void lose(Player& p, int bet, int weight) {

		/* @Author: Maxence2997
		   @Version:1.0
		   @Date: 2022/02/09	*/

		int amount = -(bet * weight);  // (bet * weight) will be a negative number
		stakesPool += amount;
		p.addPaying(amount);
		cout << p.getName() << "  �z�l���F " << amount << "���A�ثe���䥭�Ŭ� :" << p.getBalance() << "��\t" << "�������� " << stakesPool << "��" << endl;
		cout << endl;
	}

	void frame(string s) {
		
		cout.width(50);
		cout.fill('-');
		cout << setiosflags(ios::left);
		cout << setw(49) << "+" << "+" << endl;			//frame
		cout.fill(' ');
				
		cout << setw(49) << "|" + s << "|" << endl;

		cout.fill('-');
		cout << setw(49) << "+" << "+" << endl;			//frame
		cout.fill(' ');
		cout << endl;
		cout << resetiosflags(ios::left);

	
	}

	void sleepAndDot(int times) {

		for (int i = 0; i < times; i++)
		{
			sleep_for(1s);
			cout << "    ." << endl;
		}
	}

	void dots(int times) {

		for (int i = 0; i < times; i++)
		{
			cout << "�C";
			sleep_for(1s);
		}
	}

}