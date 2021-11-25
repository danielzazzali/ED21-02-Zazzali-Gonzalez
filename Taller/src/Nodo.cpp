#include "include/Nodo.h"

Nodo::Nodo() {

	this->data = nullptr;
	this->next = nullptr;
	this->previous = nullptr;

}

Nodo::Nodo(Identity* identity) {

	this->data = identity;
	this->next = nullptr;
	this->previous = nullptr;

}

Nodo::~Nodo() {

}

Identity* Nodo::getData() {

	return this->data;

}

Nodo* Nodo::getNext() {

	return this->next;

}

Nodo* Nodo::getPrevious() {

	return this->previous;

}

void Nodo::setData(Identity* data) {

	this->data = data;

}

void Nodo::setNext(Nodo* next) {

	this->next = next;

}

void Nodo::setPrevious(Nodo* previous) {

	this->previous = previous;

}