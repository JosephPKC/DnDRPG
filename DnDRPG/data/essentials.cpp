#include "essentials.h"

string toString(size_t i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

/* Does not srand */
int roll(int min, int max, int num) {
	int sum = 0;
	for (std::size_t i = 0; i < num; ++i) {
		sum += (rand() % (max - min + 1)) + min;
	}
	return sum;
}
