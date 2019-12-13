#include "sorting.h"

void bubblesort(int* arr, int size) {
	bool swapped = true;
	int pass = 0;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < size - pass - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}
		pass++;
	}
}