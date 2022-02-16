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
		cout << "請輸入這一局的底注金額 :\t";
		cin >> baseBet;

		while ((baseBet <= 0) || cin.fail())
		{
			/*input check. Ref.: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/*/

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "輸入錯誤，請重新請輸入這一局的底注金額 :\t";
			cin >> baseBet;
		}

		//cout << endl;
		sleep_for(1s);
		cout << endl;

		for (Player p : ppl)
			p.addPaying(baseBet);

		stakesPool = numOfPpl * baseBet;
		showBalanceSheet();
		cout << "即將開始遊戲!";
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
				cout << "請問要補牌or放棄這一輪?\tp: 補牌並跟注\tl: 放棄這一輪    ";
				char comm;
				cin >> comm;

				int count1 = 0;
				while ((tolower(comm) != 'p') && (tolower(comm) != 'l') && (count1 < 1))
				{
					cout << "輸入錯誤，再次錯誤將直接視同放棄這一輪" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "請問要補牌or放棄這一輪?\tp: 補牌並跟注\tl: 放棄這一輪    ";
					cin >> comm;
					count1++;
				}

				cout << endl;

				if (tolower(comm) == 'p')
				{
					cout << "請問這一輪要跟注多少錢 ?\t";
					int bet;
					cin >> bet;

					while (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "輸入錯誤，請重新請輸入跟注金額 :\t";
						cin >> bet;
					}

					while (bet > stakesPool)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "跟注不可大於獎池金額，請重新輸入 !\t";
						cin >> bet;
					}

					cout << endl;

					if (card1.num == card2.num)
					{
						cout << "請問要賭比" << card1.num << "大還是比" << card1.num << "小?\tb: 大  s: 小\t";
						char BorS;
						cin >> BorS;

						int count2 = 0;
						while ((tolower(BorS) != 'b') && (tolower(BorS) != 's') && count2 < 1) {

							cout << "輸入錯誤，再次錯誤將直接視同放棄這一輪" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "請問要賭比" << card1.num << "大還是比" << card1.num << "小?\tb: 大  s: 小\t";
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

						cout << "請稍後下一次發牌 !" << endl;

					else
						cout << "輸入錯誤，請稍後下一次發牌 !" << endl;
				}

				if (stakesPool == 0)
				{
					cout << "獎池已歸零，直接進入下一局" << endl;
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


		cout << setw(49) << "|目前收支平衡狀況" << "|" << endl;

		for (Player& p : ppl)
		{
			string s1 = "| " + p.getName() + " : " + to_string(p.getBalance());
			cout << setw(49) << s1 << "|" << endl;
		}

		string s2 = "| 這局以" + to_string(baseBet) + "元為底注，目前獎池總共有" +
			to_string(stakesPool) + "元";
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

		

		cout << "請輸入參與人數(2~10人) : ";
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
			cout << "輸入錯誤" << count1 << "次，請重新輸入\t";
			cin >> numOfPpl;
			cout << endl;
		}

		for (int i = 0; i < numOfPpl; i++)
		{
			cout << "請輸入玩家" << i + 1 << "名稱 :\t";
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
		cout << p.getName() << "  您贏了 " << bet << "元，目前收支平衡為 :" << p.getBalance() << "元\t" << "獎池仍有 " << stakesPool << "元" << endl;
		cout << endl;
	}

	void lose(Player& p, int bet, int weight) {

		/* @Author: Maxence2997
		   @Version:1.0
		   @Date: 2022/02/09	*/

		int amount = -(bet * weight);  // (bet * weight) will be a negative number
		stakesPool += amount;
		p.addPaying(amount);
		cout << p.getName() << "  您損失了 " << amount << "元，目前收支平衡為 :" << p.getBalance() << "元\t" << "獎池仍有 " << stakesPool << "元" << endl;
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
			cout << "。";
			sleep_for(1s);
		}
	}

}