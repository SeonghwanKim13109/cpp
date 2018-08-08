#include <iostream>
#include <time.h>
#include "function.h"
using namespace std;

int main() {

	srand((unsigned int)time(0));
	_tagPlayer player = createCharacter();
	_tagMonster monsters[MAX_MONSTER_SORT] = {};
	for (int i = 0; i < MAX_MONSTER_SORT; i++) {
		monsters[i] = createMonster(i);
	}
	cout << monsters[0].strName << endl;
	cout << monsters[1].strName << endl;
	cout << monsters[2].strName << endl;
	
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
			iMenu = selectMap();
			_tagMonster monster = monsters[iMenu - 1];

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