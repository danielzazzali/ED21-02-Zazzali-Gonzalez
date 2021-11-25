#ifndef LinkedList_HEADER
#define LinkedList_HEADER
#include <iostream>
#include "Nodo.h"

class LinkedList {
	
private:

	Nodo* first;
	int size;

public:

	LinkedList();

	~LinkedList();

	Nodo* getFirst();

	Identity* getX(int x);

	int getSize();

	bool isEmpty();

	bool add(Identity* identity);

	bool remove(int position);

	int search(Mat image);

};

#endif
