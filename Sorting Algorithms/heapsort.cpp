#include "sorting.h"

inline void heapify(int* arr, int size, int pos) {
	int max = pos;
	int left = pos * 2 ;
	int right = pos * 2 + 1;

	if (left < size && arr[left] > arr[max]) {
		max = left;
	}
	if (right < size && arr[right] > arr[max]) {
		max = right;
	}
	if (max != pos) {
		int temp = arr[pos];
		arr[pos] = arr[max];
		arr[max] = temp;
		heapify(arr, size, max);
	}
}

void heapsort(int* arr, int size) {
	for (int i = size / 2; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		
		heapify(arr, i, 0);
	}
}