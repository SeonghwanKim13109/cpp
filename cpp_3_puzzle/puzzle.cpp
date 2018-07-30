#include <iostream>
#include <time.h>
#include <conio.h>
#include "function.h"

using namespace std;
#define clear system("cls")

int main() {
	
	const int SIZE = 25;
	int arr[SIZE];
	int starIndex = SIZE-1;
	arr[SIZE - 1] = INT_MAX;

	makeArr(arr, SIZE);
	shuffle(arr, SIZE);

	while (1) {
		
		clear;
		display(arr, SIZE);
		//enter를 입력하지 않더라도 문자를 누르는 순간
		// 그 문자를 반환하고 종료
		char cinput = _getch();
		if (cinput == 'q' || cinput == 'Q')
			break;
		move_console(arr,SIZE,&starIndex,cinput);
		if (puzzleCheck(arr, SIZE)) {
			cout << "숫자를 모두 맞췄습니다" << endl;
			break;
		}

	}
	cout << "게임을 종료합니다" << endl;
	return 0;
}