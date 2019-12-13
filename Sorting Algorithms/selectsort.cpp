#include "sorting.h"

void selectsort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int min_pos = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_pos]) {
				min_pos = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_pos];
		arr[min_pos] = temp;
	}
}