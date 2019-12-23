#include "hash_functions.h"
#include "hash_tables.h"

hash_table_linked_list::hash_table_linked_list() {
	array = new linked_list[TABLE_SIZE];
	length = TABLE_SIZE;
}

inline size_t hash_table_linked_list::hash(size_t a) {
	// change to hash function of choice
	return division_hash(a);
}

void hash_table_linked_list::insertEntry(size_t key) {
	// for now, let key == value
	entry* temp = new entry { key, key, nullptr };
	size_t index = hash(key);
	array[index].insert_entry(temp);
}

void hash_table_linked_list::removeEntry(size_t key) {
	size_t index = hash(key);
	array[index].remove_entry(key);
}

size_t hash_table_linked_list::getValue(size_t key) {
	size_t index = hash(key);
	if (array[index].get_entry(key) == nullptr) {
		return 0;
	}
	else {
		return array[index].get_entry(key)->value;
	}
}

hash_table_linked_list::~hash_table_linked_list() {
	delete[] array;
	array = nullptr;
}