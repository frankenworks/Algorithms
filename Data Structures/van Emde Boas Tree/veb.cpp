#include <cmath>
#include "VEB.h"

//largest 2-tetration smaller than root u
int getClusterSize(int x) {
	int a = (int)sqrt(x);
	int b = 2;
	for (int i = 2; i <= a; i = i * i) {
		b = i;
	}
	return b;
}

VEB::VEB(int x)
	:u(x), max(nullptr), min(nullptr),
	summary(nullptr), cluster(nullptr) {
	if (u > 2) {
		//subu = number of clusters
		int subu = u / (getClusterSize(u));
		summary = new VEB(subu);
		cluster = new VEB*[subu];
		for (int i = 0; i < subu; i++) {
			cluster[i] = nullptr;
		}
	}
}

int VEB::getMin() {
	return (*min);
}

int VEB::getMax() {
	return (*max);
}

int* VEB::getMinPtr() {
	return min;
}

void VEB::insert(int x) {
	//smallest cluster case
	if (u == 2) {
		if (x == 0) {
			if (min == nullptr) {
				min = new int;
				max = new int;
				(*min) = x;
				(*max) = x;
			}
			else {
				(*min) = x;
			}
		}
		else if (x == 1) {
			if (max == nullptr) {
				min = new int;
				max = new int;
				(*min) = x;
				(*max) = x;
			}
			else {
				(*max) = x;
			}
		}
	}
	//else not smallest cluster case
	else {
		//first check if min is empty
		if (min == nullptr) {
			min = new int;
			max = new int;
			(*min) = x;
			(*max) = x;
		}
		//else insert recursively in smaller clusters
		else {
			if (x < (*min)) {
				//swap x and min
				int tempMin = (*min);
				(*min) = x;
				this->insert(tempMin);
			}
			//insert to smaller clusters recursively
			else {
				int subu = getClusterSize(u);
				int high = x / subu;
				int low = x % subu;
				//update summary if cluster was empty
				if (cluster[high] == nullptr) {
					cluster[high] = new VEB(subu);
					cluster[high]->insert(low);
					summary->insert(high);
				}
				else {
					cluster[high]->insert(low);
				}
				//update max if necessary
				if (x > (*max)) {
					(*max) = x;
				}
			}
		}
	}
}

void VEB::remove(int x) {
	//smallest cluster case
	if (u == 2) {
		//delete min/set to 1
		if (x == 0) {
			//if only one element
			if ((*max) == 0) {
				delete min;
				min = nullptr;
				delete max;
				max = nullptr;
			}
			else {
				(*min) = 1;
			}
		}
		//delete max/set to 0
		else if (x == 1) {
			if ((*min) == 1) {
				delete min;
				min = nullptr;
				delete max;
				max = nullptr;
			}
			else {
				(*max) = 0;
			}
		}
	}
	//else not smallest case
	else {
		int subu = getClusterSize(u);
		int high = x / subu;
		int low = x % subu;
		//deleting the min
		if (x == (*min)) {
			//if only one element
			if (x == (*max)) {
				delete min;
				min = nullptr;
				delete max;
				max = nullptr;
			}
			else {
				//delete next min recursively
				int temp = subu * (summary->getMin());
				int nextMin = temp + ((cluster[summary->getMin()])->getMin());
				this->remove(nextMin);
				//make next min the new min
				if ((*max) == (*min)) {
					(*max) = nextMin;
				}
				(*min) = nextMin;
			}
		}
		//deleting non-min element
		else {
			cluster[high]->remove(low);
			// if cluster becomes empty
			if (cluster[high]->getMinPtr() == nullptr) {
				summary->remove(high);
				delete cluster[high];
				cluster[high] = nullptr;
			}
			//if max was deleted
			if (x == (*max)) {
				//if one element remains
				if (summary->getMinPtr() == nullptr) {
					(*max) = (*min);
				}
				//else get new max
				else {
					int temp = subu * (summary->getMax());
					int nextMax = temp + (cluster[summary->getMax()]->getMax());
					(*max) = nextMax;
				}
			}
		}
	}
}

bool VEB::check(int x) {
	//smallest cluster case
	if (u == 2) {
		if (min == nullptr)
			return false;
		if (x == 0)
			return ((*min) == 0);
		else if (x == 1)
			return ((*max) == 1);
		return false;
	}
	//else not smallest cluster case
	else {
		//first compare with min/max
		if (min == nullptr)
			return false;
		if ((x < (*min)) || (x > (*max))) {
			return false;
		}
		else if ((x == (*min)) || (x == (*max))) {
			return true;
		}
		//else call smaller cases recursively
		else {
			int subu = getClusterSize(u);
			int high = x / subu;
			int low = x % subu;
			if (cluster[high] == nullptr) {
				return false;
			}
			else {
				return cluster[high]->check(low);
			}
		}
	}
}

int VEB::findNext(int x) {
	//smallest cluster case
		//this must be done because 
		//u=2 cases do not have a summary/cluster
	if (u == 2) {
		//should return *max
		if (x == 1) {
			return 2;
		}
		else if (x == 0) {
			if (max == nullptr) {
				return 2;
			}
			else if ((*max) == 0) {
				return 2;
			}
			return (*max);
		}
		else {
			return 2;
		}
	}
	else {
		//if no elements
		if (min == nullptr) {
			return u;
		}
		//if min is Next
		else if (x < (*min)) {
			return (*min);
		}
		//if no next element
		else if (x >= (*max)) {
			return u;
		}
		int subu = getClusterSize(u);
		int high = x / subu;
		int low = x % subu;
		//check if current cluster is empty
		if (cluster[high] == nullptr) {
			int temp = subu * (summary->findNext(high));
			return temp + cluster[summary->findNext(high)]->getMin();
		}
		//check if Next is in the same cluster
		if (low < (cluster[high]->getMax())) {
			int temp = x - low;
			return temp + (cluster[high]->findNext(low));
		}
		//else return min of next cluster
		else {
			int temp = subu * (summary->findNext(high));
			return temp + cluster[summary->findNext(high)]->getMin();
		}
	}
}

int VEB::findPrev(int x) {
	//smallest cluster case
		//this must be done because 
		//u==2 cases do not have a summary/cluster
	if (u == 2) {
		//should return *min
		if (x == 0) {
			return -1;
		}
		else if (x == 1) {
			if (min == nullptr) {
				return -1;
			}
			else if ((*min) == 1) {
				return -1;
			}
			else {
				return (*min);
			}
		}
		else {
			return -1;
		}
	}
	else {
		//if no elements
		if (min == nullptr) {
			return -1;
		}
		//if max is Prev
		if (x > (*max)) {
			return (*max);
		}
		//if no previous element
		else if (x <= (*min)) {
			return -1;
		}
		int subu = getClusterSize(u);
		int high = x / subu;
		int low = x % subu;
		//check if current cluster is empty
		if (cluster[high] != nullptr) {
			//check if Prev is in the same cluster
			if (low > (cluster[high]->getMin())) {
				int temp = x - low;
				return temp + (cluster[high]->findPrev(low));
			}
		}
		//check if previous cluster is empty
		int checkk = summary->findPrev(high);
		if (checkk == -1) {
			return (*min);
		}
		//else return max of previous cluster
		else {
			int temp = subu * (summary->findPrev(high));
			return temp + cluster[summary->findPrev(high)]->getMax();
		}
	}
}

VEB::~VEB() {
	if (min != nullptr) {
		delete min;
		min = nullptr;
	}
	if (max != nullptr) {
		delete max;
		max = nullptr;
	}
	if (summary != nullptr) {
		delete summary;
		summary = nullptr;
	}
	if (cluster != nullptr) {
		delete[] cluster;
		cluster = nullptr;
	}
}
