#pragma once

/*
Class VEB maps a bit vector using van Emde Boas structure
In this particular implementation if the size of the bit vector is not a tetration of 2
The size of the subclusters will be a tetration of 2
You can edit the code using subu = u/subu
to instead have the number of subclusters into a tetration of 2
limitations: assumption of bit vector size == 2^m, int m > 0
because data type int is used, u<2^31
*/

class VEB {
private:
	int u; //size of tree
	int* min;
	int* max;
	VEB* summary;
	VEB** cluster;
public:
	VEB(int);
	int getMin();
	int getMax();
	int* getMinPtr();
	void insert(int); //O(log log u)
	void remove(int); //O(log log u)
	bool check(int); //O(log log u)
	int findNext(int); //returns u if no next element
	int findPrev(int); //returns -1 if no previous element
	~VEB();
};
