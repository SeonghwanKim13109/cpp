// cpp_3_lotto.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int lotto();
bool lottoCheck(int[],int,int);
void printArr(int[][7], int);

int main()
{

	int arr[7][7];
	int length = pow(sizeof(arr)/sizeof(int),0.5);
	srand((unsigned)time(0));
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < length; i++) {
			int lotto_num;
			do {
				lotto_num = lotto();
			} while (lottoCheck(arr[j], i, lotto_num));
			arr[j][i] = lotto_num;
		}
	}
	printArr(arr, length);
    return 0;
}

int lotto() {
	int lotto = rand() % 45 + 1;
	return lotto;
}

bool lottoCheck(int arr[], int current , int lotto) {
	for (int i = 0; i < current; i++) {
		if (arr[i] == lotto)
			return true;
	}
	return false;
}

void printArr(int arr[][7],int length) {
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < length; i++)
			cout << arr[j][i] << "\t";
		cout << endl;
	}
}