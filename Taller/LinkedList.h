#ifndef LinkedList_HEADER
#define LinkedList_HEADER
#include <iostream>
#include "Node.h"

class LinkedList {

private:

	Node* first;
	int size;

public:

	LinkedList(Node* first);

	~LinkedList();

	Node* getFirst();

	int getSize();

	bool isEmpty();

	bool add(Node* node);

	bool remove(int position);

};

#endif