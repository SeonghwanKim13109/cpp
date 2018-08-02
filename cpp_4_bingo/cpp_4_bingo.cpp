#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "function.h"
#define clear system("cls")
using namespace std;

int main() {
	const int SIZE = 25;
	int currPosi = 24;
	int arr[SIZE] = { 0 };
	bool selected[SIZE] = { false };
	makeArr(arr, SIZE);
	shuffle(arr, SIZE);
	while (true) {
		int check = bingoCheck(selected);
		display(arr, SIZE,currPosi,selected);
		cout << "Bingo :  " << check << endl;
		if (check == 5)
			break;
		char cmd = _getch();
		//cout << (int)cmd << endl;
		command(cmd,&currPosi,selected);

		
		clear;
	}
	return 0;
}