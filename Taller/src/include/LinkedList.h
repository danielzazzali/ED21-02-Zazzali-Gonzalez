#ifndef LinkedList_HEADER
#define LinkedList_HEADER
#include <iostream>
#include "Nodo.h"

class LinkedList {
	
private:

	Nodo* first;
	int size;
	int num[8];
	bool checkrep(int n, int num[]);

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
