#pragma once
#include "linked_list.h"

/*
Hash Table size defined in hash_functions.h
Hash Function Method chosen in definition of hash(size_t)
This implementation has many features missing such as storing values other than integers
I eventually plan to improve/fix this code once I have more free time to work on it
*/

// Hash Table with Linked Lists
class hash_table_linked_list {
private:
	linked_list* array;
	int length;
	inline size_t hash(size_t);
public:
	hash_table_linked_list();
	void insertEntry(size_t);
	void removeEntry(size_t);
	size_t getValue(size_t);
	~hash_table_linked_list();
};

// Perfect Hashing
// Coming Soon