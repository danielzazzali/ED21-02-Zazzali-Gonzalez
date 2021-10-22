#include "Node.h"

Node::Node() {

	this->data = nullptr;

}

Node::Node(Identity* identity) {

	this->data = identity;

}

Node::~Node() {

}

Identity* Node::getData() {

	return this->data;

}

Node* Node::getNext() {

	return this->next;

}

Node* Node::getPrevious() {

	return this->previous;

}

void Node::setData(Identity* data) {

	this->data = data;

}

void Node::setNext(Node* next) {

	this->next = next;

}

void Node::setPrevious(Node* previous) {

	this->previous = previous;

}


