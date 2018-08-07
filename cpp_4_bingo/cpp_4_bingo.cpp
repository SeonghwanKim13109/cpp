#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "function.h"
#define ENTER 13
#define clear system("cls")
using namespace std;

int main() {
	const int SIZE = 25;
	int currPosi = 24;
	int userArr[SIZE] = { 0 };
	int aiArr[SIZE] = { 0 };
	bool userturn = false;
	bool userSelected[SIZE] = { false };
	bool aiSelected[SIZE] = { false };
	int userBingo;
	int aiBingo;
	bool already = false;

	
	while (true) {
		int aimode = aiMode();
		makeArr(userArr, SIZE);
		shuffle(userArr, SIZE);

		makeArr(aiArr, SIZE);
		shuffle(aiArr, SIZE);
		shuffle(aiArr, SIZE);

		int turnselect = rand() % 1000;
		if (turnselect % 2)
			userturn = true;
		userBingo = bingoCheck(userSelected);
		aiBingo = bingoCheck(aiSelected);

		while (true) {
			if (userturn) {
				char cmd;
				do {
					display(userArr, SIZE, currPosi, userSelected);

					cout << "MyBingo :  " << userBingo << endl;
					cout << "ComputerBingo : " << aiBingo << endl;
					cmd = _getch();
					//cout << (int)cmd << endl;
					command(cmd, userArr, aiArr, &currPosi, userSelected, aiSelected, &already);
					clear;
				} while (cmd != ENTER || already);
				already = false;
			}
			else {
				if (aimode == 1)
					aiCommand(userArr, aiArr, userSelected, aiSelected, SIZE);
				else
					aiHardCommand(userArr, aiArr, userSelected, aiSelected, SIZE);
			}
			userBingo = bingoCheck(userSelected);
			aiBingo = bingoCheck(aiSelected);

			if (userBingo == 5 || aiBingo == 5)
				break;
			userturn = userturn ^ 1;
			clear;
		}
		if (userBingo == 5 && userturn)
			cout << "You win" << endl;
		else
			cout << "You lose" << endl;

		cout << "계속하시겠습니까 ? " << endl;
		cout << "1. continue\t 2.exit" << endl;
		int continued;
		cin >> continued;
		if (continued == 2)
			break;
		clearArr(userSelected,SIZE);
		clearArr(aiSelected,SIZE);
	}
	return 0;
}