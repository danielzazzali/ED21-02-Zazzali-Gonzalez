#ifndef Node_HEADER
#define Node_HEADER
#include "Identity.h"

class Node {

private:

	Identity* data;
	Node* next;
	Node* previous;

public:
	
	Node();

	Node(Identity* data);

	~Node();

	Identity* getData();

	Node* getNext();

	Node* getPrevious();

	void setData(Identity* data);

	void setNext(Node* next);

	void setPrevious(Node* previous);

};

#endif
