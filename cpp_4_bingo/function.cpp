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
int aiMode() {
	cout << "AI 난이도를 선택해 주십시오" << endl;
	int hard;
	while (true) {
		cout << "1 : Easy Mode , 2 : Hard Mode" << endl;
		cin >> hard;
		if (hard == 1 || hard == 2)
			return hard;
	}
}
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

		if (selected[i]) {
			if (i == currPosi)
				setColor(RED, BLACK);
			else
				setColor(RED, GRAY);
		}
		
		cout << arr[i];
		setColor(BLACK, WHITE);
		cout << "\t";
		if (i % 5 == 4)
			cout << endl;
	}
	
}

static int findNum(int* arr, int num, int size) {
	for (int i = 0; i < size; i++)
		if (arr[i] == num)
			return i;
	return -1;
}

void command(char cmd,int* userArr,int* aiArr, int* currPosi,bool* userSelected,bool* aiSelected,bool* already) {
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
		if (*currPosi > 4)
			*currPosi -= 5;
		break;
	case DOWN :
		if (*currPosi < 20)
			*currPosi += 5;
		break;
	case ENTER :
		if (userSelected[*currPosi]) {
			*already = true;
			break;
		}
		else
			userSelected[*currPosi] = true;
		int num = userArr[*currPosi];
		int position = findNum(aiArr, num,25);
		aiSelected[position] = true;
		break;
	}
}

void aiCommand(int* userArr, int * aiArr, bool * userSelected, bool * aiSelected, int size) {
	int num; 
	int currPosi;  
	do {
		num = rand() % size;;
		currPosi =findNum(aiArr, num,size);
	} while (aiSelected[currPosi]);
	//while문을 빠져나오면 선택되지 않았던 숫자가 선택된것
	aiSelected[currPosi] = true;
	currPosi = findNum(userArr, num,size);
	userSelected[currPosi] = true;
}

static int findMaxRow(int * arr,bool * selected ,int * row ,int size) {
	int number = (int)pow(size, 0.5);
	int max_count = 0;
	for (int i = 0; i < number; i++) { // 행 마다 확인
		int count = 0;
		for (int j = 0; j < number; j++)
			if (selected[5 * i + j])
				count++;
		if(count != 5)
			max_count = max_count > count ? max_count : count;
		if (max_count == count)
			*row = i;
	}
	return max_count;
}

static int findMaxCol(int * arr, bool* selected, int* col, int size) {
	int number = pow(size, 0.5);
	int max_count = 0;
	for (int i = 0; i < number; i++) { // 열 마다 확인
		int count = 0;
		for (int j = 0; j < number; j++)
			if (selected[i + j * 5])
				count++;
		if (count != 5)
			max_count = max_count > count ? max_count : count;
		if (max_count == count)
			*col = i;
	}
	return max_count;
}
void aiHardCommand(int* userArr, int * aiArr, bool * userSelected, bool * aiSelected, int size) {
	int number = pow(size, 0.5);
	int row;
	int row_count = findMaxRow(aiArr,aiSelected,&row,size);
	int col;
	int col_count = findMaxCol(aiArr,aiSelected,&col,size);
	int currPosi = 0;

	if (row_count > col_count ) {
		for (int i = 0; i < number; i++) {	//열
			if (!aiSelected[5 * row + i]) {
				currPosi = 5 * row + i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < number; i++) {	//행
			if (!aiSelected[5 * i + col]) {
				currPosi = 5 * i + col;
				break;
			}
		}
	}


	int num = aiArr[currPosi];
	aiSelected[currPosi] = true;
	currPosi = findNum(userArr, num, 25);
	userSelected[currPosi] = true;
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
void clearArr(bool* selected, int size) {
	for (int i = 0; i < size; i++) {
		selected[i] = false;
	}
}