#include <iostream>
#include <time.h>
#include "function.h"
using namespace std;

int failCheck() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return 1;
	}
	return 0;
}
_tagPlayer createCharacter() {
	_tagPlayer player = {};
	cout << "이름을 입력하세요" << endl;
	cin.getline(player.strName, NAME_LENGTH - 1);
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		cls;
		cout << "직업을 선택하세요" << endl;
		cout << "1 .Knight " << endl;
		cout << "2. Archer " << endl;
		cout << "3. Wizard" << endl;
		cin >> iJob;

		if (failCheck())
			continue;
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}
	player.iLevel = 1;
	player.iExp = 0;
	player.eJob = (JOB)iJob;

	switch (player.eJob) {
	case JOB_KNIGHT:
		strcpy_s(player.strJobName, "Knight");
		player.iAttackMin = 5;
		player.iAttackMax = 5;
		player.iArmorMax = 20;
		player.iArmorMin = 15;
		player.iHpMax = 50;
		player.iHp = 50;
		player.iMpMax = 20;
		player.iMp = 20;
		break;
	case JOB_ARCHER:
		strcpy_s(player.strJobName, "Archer");
		player.iAttackMin = 7;
		player.iAttackMax = 7;
		player.iArmorMax = 15;
		player.iArmorMin = 12;
		player.iHpMax = 45;
		player.iHp = 45;
		player.iMpMax = 25;
		player.iMp = 25;
		break;
	case JOB_WIZARD:
		strcpy_s(player.strJobName, "Wizard");
		player.iAttackMin = 10;
		player.iAttackMax = 10;
		player.iArmorMax = 20;
		player.iArmorMin = 15;
		player.iHpMax = 25;
		player.iHp = 25;
		player.iMpMax = 50;
		player.iMp = 50;
		break;
	}
	return player;
}
_tagMonster createMonster(int idx) {
	_tagMonster monster;
	switch (idx)
	{
	case 0 : 
		strcpy_s(monster.strName, "Goblin");
		monster.iAttackMin = 3;
		monster.iAttackMax = 7;
		monster.iArmorMin = 15;
		monster.iArmorMax = 18;
		monster.iHp = 25;
		monster.iHpMax = 25;
		monster.iMp = 0;
		monster.iMpMax = 0;
		monster.iLevel = 3;
		monster.iGetExp = 50;
		monster.iGoldMin = 30;
		monster.iGoldMax = 50;
		break;
	case 1 :
		strcpy_s(monster.strName, "Tau");
		monster.iAttackMin = 5;
		monster.iAttackMax = 9;
		monster.iArmorMin = 18;
		monster.iArmorMax = 20;
		monster.iHp = 35;
		monster.iHpMax = 35;
		monster.iMp = 10;
		monster.iMpMax = 10;
		monster.iLevel = 5;
		monster.iGetExp = 100;
		monster.iGoldMin = 50;
		monster.iGoldMax = 90;
		break;
	case 2 :
		strcpy_s(monster.strName, "Troll");
		monster.iAttackMin = 30;
		monster.iAttackMax = 50;
		monster.iArmorMin = 50;
		monster.iArmorMax = 70;
		monster.iHp = 200;
		monster.iHpMax = 200;
		monster.iMp = 30;
		monster.iMpMax = 30;
		monster.iLevel = 40;
		monster.iGetExp = 10000000;
		monster.iGoldMin = 1000000;
		monster.iGoldMax = 2000000;
	default:
		break;
	}
	return monster;
}
