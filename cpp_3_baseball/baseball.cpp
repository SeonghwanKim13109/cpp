#include <iostream>
#include <time.h>
#include "functions.h"
using namespace std;



int main() {
	const int LENGTH = 3;
	const int SIZE = 10;
	int arr[SIZE] = { 0 };
	int strike = 0;
	int ball = 0;
	int first, second, third;
	int life = 3;
	int score = 0;
	int out = 0;

	while (life > 0) {
		makeArr(arr, SIZE);
		shuffle(arr, SIZE);

		while (strike != 3) {
			cout << "0~9까지의 숫자를 입력해주세요\t" << "score :"  <<score << endl;
			cin >> first >> second >> third;
			int base[LENGTH] = { first,second,third };
			strike = findStrike(arr, base, LENGTH);
			ball = findBall(arr, base, LENGTH);
			if (!strike && !ball) {
				cout << "OUT !! ";
				out++;
				if (out == 3) {
					life--;
					out = 0;
				}
				showLife(life);
			}
			else {
				cout << "Strike : " << strike << " Ball :" << ball << " ";
				showLife(life);
			}
		}

		cout << endl;
		system("cls");
		strike = 0;
		ball = 0;
		score += 500;
	}
}