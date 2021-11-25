#ifndef Node_HEADER
#define Node_HEADER
#include "Identity.h"

class Nodo {

private:

	Identity* data;
	Nodo* next;
	Nodo* previous;

public:

	Nodo();

	Nodo(Identity* data);

	~Nodo();

	Identity* getData();

	Nodo* getNext();

	Nodo* getPrevious();

	void setData(Identity* data);

	void setNext(Nodo* next);

	void setPrevious(Nodo* previous);

};

#endif
