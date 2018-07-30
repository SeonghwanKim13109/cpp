#include <iostream>
#include <time.h>
#include <conio.h>
#include "function.h"
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

using namespace std;

void makeArr(int arr[], int size) {
	for (int i = 0; i < size-1; i++) {
		arr[i] = i + 1;
	}
}

void shuffle(int arr[], int size) {
	srand((unsigned int)time(0));
	int num = rand() % (size * 100) + 100;
	for (int i = 0; i < num; i++) {
		int idx1 = rand() % (size - 1);
		int idx2 = rand() % (size - 1);
		swap(arr, idx1, idx2);
	}
}

void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void display(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == INT_MAX)
			cout << "*\t";
		else
			cout << arr[i] << "\t";
		if (i && i % 5 == 4)
			cout << endl;
		
	}
	cout << "w : 위 s: 아래 a : 왼쪽 d : 오른쪽 q : 종료";
}

void move_console(int arr[], int SIZE, int *starIndex,char cinput) {
	
	switch (cinput) {
	case UP :
	case 'w':
	case 'W':
		if (*starIndex > 4) {
			swap(arr, *starIndex, *starIndex - 5);
			*starIndex -= 5;
		}
		break;
	case LEFT :
	case 'a':
	case 'A':
		if (*starIndex % 5) {
			swap(arr, *starIndex, *starIndex - 1);
			*starIndex -= 1;
		}
		break;
	case DOWN :
	case 's':
	case 'S':
		if (*starIndex < 20) {
			swap(arr, *starIndex, *starIndex + 5);
			*starIndex += 5;
		}
		break;
	case RIGHT :
	case 'd':
	case 'D':
		if ((*starIndex + 1) % 5) {
			swap(arr, *starIndex, *starIndex + 1);
			*starIndex += 1;
		}
		break;
	}
}

bool puzzleCheck(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] != i + 1)
			return false;
	}
	return true;
}