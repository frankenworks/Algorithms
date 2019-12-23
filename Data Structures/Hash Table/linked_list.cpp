#include "linked_list.h"

linked_list::linked_list(): length(0) {
	head = new entry;
	head->next = nullptr;
}

void linked_list::insert_entry(entry* newEntry) {
	if (!head->next) {
		head->next = newEntry;
	}
	else {
		entry* temp = head;
		entry* tempNext = head;
		while (tempNext) {
			temp = tempNext;
			tempNext = temp->next;
		}
		temp->next = newEntry;
		newEntry->next = nullptr;
	}
	length++;
}

void linked_list::remove_entry(size_t key) {
	if (!head->next) {
		return;
	}
	else {
		entry* temp = head;
		entry* tempNext = head;
		while (tempNext) {
			if (tempNext->key == key) {
				temp->next = tempNext->next;
				delete tempNext;
				length--;
				return;
			}
			temp = tempNext;
			tempNext = temp->next;
		}
	}
}

entry* linked_list::get_entry(size_t key) {
	entry* temp = head;
	entry* tempNext = head;
	while (tempNext) {
		temp = tempNext;
		if ((temp != head) && (temp->key == key)) {
			return temp;
		}
		tempNext = temp->next;
	}
	return nullptr;
}

int linked_list::getLength() {
	return length;
}

linked_list::~linked_list() {
	entry* temp = head;
	entry* tempNext = head;
	while (tempNext) {
		temp = tempNext;
		tempNext = temp->next;
		if (tempNext) {
			delete temp;
		}
	}
}