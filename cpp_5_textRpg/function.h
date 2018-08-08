#pragma once
#define NAME_LENGTH 32
#define STAGE_NUM 3
#define MAX_MONSTER_SORT  STAGE_NUM
#define cls system("cls")
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
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};
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
struct _tagMonster {
	char strName[NAME_LENGTH];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHp;
	int iHpMax;
	int iMp;
	int iMpMax;
	int iLevel;
	int iGetExp;
	int iGoldMin;
	int iGoldMax;

};

int failCheck();
_tagPlayer createCharacter();
_tagMonster createMonster(int idx);