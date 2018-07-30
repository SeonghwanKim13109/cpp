#include <iostream>
#include <time.h>
using namespace std;

int lotto();
bool lottoCheck(int[], int);
void printArr(int[], int);

int main() {
	const int MAX_NUM = 46;
	int arr[MAX_NUM] = { 0 };
	int NumberOfLotto = 7;
	for (int i = 0; i < NumberOfLotto; i++) {
		int lotto_num;
		do {
			lotto_num = lotto();
		} while (lottoCheck(arr,lotto_num));
		arr[lotto_num] = 1;
	}
	printArr(arr, MAX_NUM);
	return 0;
}

int lotto() {
	srand((unsigned)time(0));
	int lotto = rand() % 45 + 1;
	return lotto;
}

bool lottoCheck(int arr[], int lotto_num) {
	if (arr[lotto_num])
		return true;
	return false;
}

void printArr(int arr[], int length) {
	for (int i = 1; i < length; i++)
		if (arr[i])
			cout << i << "\t";
	cout << endl;
}