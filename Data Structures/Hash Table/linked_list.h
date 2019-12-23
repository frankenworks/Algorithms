#pragma once

struct entry {
	size_t key;
	size_t value;
	entry* next;
};

class linked_list {
private:
	entry* head;
	int length;
public:
	linked_list();
	void insert_entry(entry*);
	void remove_entry(size_t);
	entry* get_entry(size_t);
	int getLength();
	~linked_list();
};