#include <iostream>
#include <time.h>
#include <Windows.h>
#include "function.h"
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define BLACK 0
#define GRAY 8
#define RED 12
#define WHITE 15
#define ENTER 13
using namespace std;

void makeArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
}

void shuffle(int* arr, int size) {
	srand((unsigned int)time(0));
	int num = rand() % 200 + 100;
	for (int i = 0; i < num; i++) {
		int idx1 = rand() % size;
		int idx2 = rand() % size;
		swap(arr, idx1, idx2);
	}
}

void swap(int* arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

//https://blog.naver.com/sharonichoya/220874370397
//콘솔 글자 배경색 변경
static void setColor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void display(int* arr, int size, int currPosi,bool* selected) {
	for (int i = 0; i < size; i++) {
		if (i == currPosi)
			setColor(WHITE, BLACK);
		else
			setColor(BLACK, WHITE);

		if (selected[i])
			setColor(RED, GRAY);
		cout << arr[i];
		setColor(BLACK, WHITE);
		cout << "\t";
		if (i % 5 == 4)
			cout << endl;
	}
	
}

void command(char cmd, int* currPosi,bool* selected) {
	switch (cmd) {
	case LEFT :
		if((*currPosi)%5 != 0)
			*currPosi-=1;
		break;
	case RIGHT:
		if ((*currPosi + 1) % 5 != 0)
			*currPosi+=1; 
		break;
	case UP :
		if (*currPosi > 5)
			*currPosi -= 5;
		break;
	case DOWN :
		if (*currPosi < 20)
			*currPosi += 5;
		break;
	case ENTER :
		selected[*currPosi] = true;
		break;
	}
}

static int bingoHorizontal( bool* selected) {
	int result = 0;
	for (int i = 0; i < 5; i++) {			//행 번호
		int count = 0;
		for (int j = 0; j < 5; j++) {		//열 번호
			if (selected[i * 5 + j])
				count++;
		}
		if (count == 5)
			result++;
	}
	return result;
}

static int bingoVertical(bool* selected) {
	int result = 0;
	for (int i = 0; i < 5; i++) {			//열 번호
		int count = 0;
		for (int j = 0; j < 5; j++) {		//행 번호
			if (selected[i + 5*j])
				count++;
		}
		if (count == 5)
			result++;
	}
	return result;
}
static int bingoDiagonal(bool* selected) {
	int result = 0;
	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (selected[i * 5 + i])
			count++;
	}
	if (count == 5)
		result++;
	count = 0;
	for (int i = 0; i < 5; i++) {
		if (selected[i * 5 + 4 - i])
			count++;
	}
	if (count == 5)
		result++;
	return result;
}

int bingoCheck( bool* selected) {
	int result = 0;
	result += bingoHorizontal(selected);
	result += bingoVertical(selected);
	result += bingoDiagonal(selected);
	return result;
}