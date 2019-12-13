#include <iostream>
#include "sorting.h"

int main() {
	int temp[7] = { 3,2,4,1,7,5,6 };
	heapsort(temp, 7);
	for (int i = 0; i < 7; i++) {
		std::cout << temp[i] << std::endl;
	}
	std::cin.get();
	return 0;
}