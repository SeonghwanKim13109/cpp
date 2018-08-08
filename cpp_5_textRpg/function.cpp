#include <iostream>
#include <time.h>
#include "function.h"
using namespace std;

int failCheck() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return 1;
	}
	return 0;
}

