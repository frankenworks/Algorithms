#pragma once

/*
All Sorting Algorithms take an int pointer and an int
The first parameter, the pointer, is the address of an int array
The second parameter, the int, is the size of the array
*/

// insertion sort
void insertsort(int*, int);

// selection sort
void selectsort(int*, int);

// bubble sort
void bubblesort(int*, int);

// merge sort
void mergesort(int*, int);

// quicksort
void quicksort(int*, int);
void quicksortL(int*, int);
void quicksortMoM(int*, int);

// heapsort
void heapsort(int*, int);