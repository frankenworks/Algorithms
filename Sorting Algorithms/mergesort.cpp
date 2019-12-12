#include "sorting.h"

inline void mergecombine(int* arr, int size) {
	int j = 0;
	int k = size / 2;
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		if (j == (size / 2)) {
			temp[i] = arr[k++];
		}
		else if (k == size) {
			temp[i] = arr[j++];
		}
		else if (arr[j] > arr[k]) {
			temp[i] = arr[k++];
		}
		else {
			temp[i] = arr[j++];
		}
	}
	for (int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}
	delete[] temp;
	temp = nullptr;
}

void mergesort(int* arr, int size) {
	if (size == 1) {
		return;
	}
	else {
		if (size % 2 == 1) {
			mergesort(arr, size / 2);
			mergesort(arr + (size / 2), (size / 2) + 1);
			mergecombine(arr, size);
		}
		else if (size % 2 == 0) {
			mergesort(arr, size / 2);
			mergesort(arr + (size / 2), (size / 2));
			mergecombine(arr, size);
		}
	}
}
