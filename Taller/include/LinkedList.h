#ifndef LinkedList_HEADER
#define LinkedList_HEADER
#include <iostream>
#include "Node.h"

class LinkedList {

private:

	Node* first;
	int size;

public:

	LinkedList();

	~LinkedList();

	Node* getFirst();

	Identity* getX(int x);

	int getSize();

	bool isEmpty();

	bool add(Identity* identity);

	bool remove(int position);

};

#endif