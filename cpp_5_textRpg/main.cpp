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

int main() {
	while (true) {
		cls;
		cout << "1 . Map " << endl;
		cout << "2. Store " << endl;
		cout << "3. Inventory" << endl;
		cout << "4. EXIT" << endl;

		int iMenu;
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;
	}
	return 0;
}