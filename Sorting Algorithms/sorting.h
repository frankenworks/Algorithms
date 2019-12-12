#pragma once

/*
All Sorting Algorithms take an int pointer and an int
The first parameter, the pointer, is the address of an int array
The second parameter, the int, is the size of the array
*/

// merge sort
inline void mergecombine(int*, int);
void mergesort(int*, int);

// quicksort
void quicksort(int*, int);
void quicksortMoM(int*, int);