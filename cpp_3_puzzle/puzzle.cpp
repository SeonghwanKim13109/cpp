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
		//enter�� �Է����� �ʴ��� ���ڸ� ������ ����
		// �� ���ڸ� ��ȯ�ϰ� ����
		char cinput = _getch();
		if (cinput == 'q' || cinput == 'Q')
			break;
		move_console(arr,SIZE,&starIndex,cinput);
		if (puzzleCheck(arr, SIZE)) {
			cout << "���ڸ� ��� ������ϴ�" << endl;
			break;
		}

	}
	cout << "������ �����մϴ�" << endl;
	return 0;
}