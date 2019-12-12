#include "sorting.h"

// quicksort with Hoare partition scheme
void quicksort(int* arr, int size){
	int left = 0;
	int right = size - 1;
	int pivot = size / 2;
	while (left < right) {
		while (arr[left] < arr[pivot]) {
			left++;
		}
		while (arr[right] > arr[pivot]) {
			right--;
		}
		if (left < right) {
			if (arr[left] == arr[right]) {
				left++;
				right++;
				break;
			}
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			if (left == pivot || right == pivot) {
				left = 0;
				right = size - 1;
			}
		}
	}
	if (pivot > 0) {
		quicksort(arr, pivot);
		quicksort(arr + pivot + 1, size - pivot - 1);
	}
}

// quicksort with Median of Medians
void quicksortMoM(int* arr, int size) {
	// Coming Soon
	return;
}