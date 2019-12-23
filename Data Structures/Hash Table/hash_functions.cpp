// #include <random>
#include "hash_functions.h"

// Division Method
size_t division_hash(size_t N) {
	return N % TABLE_SIZE;
}

// Multiplication Method
size_t multiply_hash(size_t) {
	// Coming Soon
	return 0;
}

// Universal Hash Function by Carter and Wegman
size_t universal_hash(size_t) {
	// Coming Soon
	return 0;
}