#include <iostream>
#include <time.h>
#include "functions.h"
using namespace std;

void makeArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

void shuffle(int arr[], int size) {
	srand((unsigned)time(0));
	int num = rand() % 200 + 100;
	for (int i = 0; i < num; i++) {
		int idx1 = rand() % size;
		int idx2 = rand() % size;
		swap(arr, idx1, idx2);
	}
}

static void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int findStrike(int arr[],int base[] ,int length ) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] == base[i])
			count++;
	}
	return count;
}

int findBall(int arr[], int base[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (i == j)
				continue;
			else if (arr[i] == base[j])
				count++;
		}
	}
	return count;
}

void showLife(int life) {
	cout << "(";
	for (int i = 0; i < life; i++)
		cout << "*";
	cout << ")" << endl;
}