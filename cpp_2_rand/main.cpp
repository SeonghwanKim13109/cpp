#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand((unsigned int)time(0));
	int iUpgrade = 0;
	/*
	cout << rand()%20 << endl;
	cout << rand()%20 << endl;
	cout << rand()%20/20.f << endl;
	*/
	while (iUpgrade<15) {
		float fPercent = rand() % 10000 / 100.f;
		bool cont = true;
		int fail = 0;
		// 0~3 : 100 4~6 : 40 7~9 : 10
		//10~13 : 1 14~15 : 0.01
		cout << "Upgrad : " << iUpgrade << endl;
		cout << "Percent : " << fPercent << endl;

		while (cont) {
			if (iUpgrade <= 3) {
				cout << "강화 성공" << endl;
				iUpgrade++;
				cont = false;
			}
			else if (4 <= iUpgrade && iUpgrade <= 6) {
				if (fPercent <= 40.f) {
					cout << "강화 성공" << endl;
					iUpgrade++;
					cont = false;
				}
				else
					fail++;

			}
			else if (7 <= iUpgrade && iUpgrade <= 9) {
				if (fPercent <= 10.f) {
					cout << "강화 성공" << endl;
					iUpgrade++;
					cont = false;
				}
				else fail++;
			}
			else if (10 <= iUpgrade && iUpgrade <= 13) {
				if (fPercent <= 1.f) {
					cout << "강화 성공" << endl;
					iUpgrade++;
					cont = false;
				}
				else fail++;

			}
			else if (14 <= iUpgrade && iUpgrade <= 15) {
				if (fPercent <= 0.01f) {
					cout << "강화 성공" << endl;
					iUpgrade++;
					cont = false;
				}
				else
					fail++;
			}
			fPercent = rand() % 10000 / 100.f;
		}
		cout << fail << endl << endl;
	}
	return 0;
}