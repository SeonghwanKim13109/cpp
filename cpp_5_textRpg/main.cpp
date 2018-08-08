#include <iostream>
#include <time.h>
#include "function.h"
#define cls system("cls")
using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};
enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMARL,
	MT_HARD,
	MT_BACK
};
enum JOB {
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD
};
#define NAME_LENGTH 32

struct _tagPlayer {
	char strName[NAME_LENGTH];
	char strJobName[NAME_LENGTH];
	JOB	 eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHp;
	int iHpMax;
	int iMp;
	int iMpMax;
	int iExp;
	int iLevel;
};
int main() {
	while (true) {
		cls;
		cout << "1 . Map " << endl;
		cout << "2. Store " << endl;
		cout << "3. Inventory" << endl;
		cout << "4. EXIT" << endl;

		int iMenu;
		cin >> iMenu;

		if (failCheck())
			continue;

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP :
			while (true) {
				cls;
				cout << "choose the map" << endl;
				cout << "1. Easy  \t";
				cout << "2. Normal\t";
				cout << "3. Hard  \t";
				cout << "4. Back" << endl;
				cin >> iMenu;

				if (failCheck())
					continue;

				if (iMenu == MT_BACK)
					break;
				switch (iMenu) {
				case MT_EASY :
					break;
				case MT_NORMARL:
					break;
				case MT_HARD:
					break;
				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			break;
		}
	}
	return 0;
}