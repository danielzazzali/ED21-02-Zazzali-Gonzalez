#include <iostream>
#include "include/LinkedList.h"
#include "include/Nodo.h"


LinkedList::LinkedList() {

	this->first = nullptr;
	this->size = 0;

}

LinkedList::~LinkedList() {

}

Nodo* LinkedList::getFirst() {

	return first;

}

Identity* LinkedList::getX(int x) {

	if (x < 0 || x > size) {

		return nullptr;

	}

	Nodo* p = first;

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

	Nodo* node = new Nodo(identity);

	if (size == 0) {

		first = node;
		first->setPrevious(nullptr);
		first->setNext(nullptr);
		size++;

		node->getData()->setidentifier(size);
		return true;
	}
	else {

		Nodo* p = first;

		while (p->getNext() != nullptr) {

			p = p->getNext();

		}

		node->setPrevious(p);
		p->setNext(node);
		node->setNext(nullptr);
		size++;

		node->getData()->setidentifier(size);
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

	Nodo* p = first;

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

int LinkedList::search(Mat image) {

	// Retorna el identifier que concuerda con la imagen para actualizar los frames en el arbol.

	Nodo* p = first;
	int exist = -1;
	while (p != nullptr)
	{
		Mat original = p->getData()->getImage();
		double dist = norm(original, image, cv::NormTypes::NORM_L2);
		if (dist < 3100)
		{
			exist = p->getData()->getidentifier();
			break;
		}
		p = p->getNext();
	}
	return exist;
}