#include <iostream>
#include "../include/LinkedList.h"
#include "../include/Node.h"

LinkedList::LinkedList() {

	this->first = nullptr;
	this->size = 0;

}

LinkedList::~LinkedList() {

}

Node* LinkedList::getFirst() {

	return first;

}

Identity* LinkedList::getX(int x) {

	if (x < 0 || x > size) {

		return nullptr;

	}

	Node* p = first;

	for (int i = 0; i < x; i++) {

		p = p->getNext();

	}

	return p->getData();

}

int LinkedList::getSize() {

	return size;

}

bool LinkedList::isEmpty() {

	return size == 0;

}

bool LinkedList::add(Identity* identity) {

	Node* node = new Node(identity);

	if (size == 0) {

		first = node;
		first->setPrevious(nullptr);
		first->setNext(nullptr);
		size++;

		return true;
	}
	else {

		Node* p = first;

		while (p->getNext() != nullptr) {

			p = p->getNext();

		}

		node->setPrevious(p);
		p->setNext(node);
		node->setNext(nullptr);
		size++;

		return true;

	}

	return false;

}


bool LinkedList::remove(int x) {

	if (x < 0 || x >= size || size == 0) {

		return false;

	}

	if (x == 0) {

		if (size == 1) {

			first = nullptr;
			size--;
			return true;

		}

		first = first->getNext();
		first->setPrevious(nullptr);
		size--;

		return true;
	}

	Node* p = first;
	
	if (x > 0 && x < size - 1) {

		for (int i = 0; i < x; i++) {

			p = p->getNext();

		}

		p->getNext()->setPrevious(p->getPrevious());
		p->getPrevious()->setNext(p->getNext());
		size--;

		return true;

	}

	while (p->getNext() != nullptr) {

		p = p->getNext();

	}

	p->getPrevious()->setNext(nullptr);
	delete p;
	size--;

	return true;
	
}
