#include "../include/Identity.h"
#include "../include/NodeBinaryTree.h"


NodeBinaryTree::NodeBinaryTree() {

	data = new Identity();
	llink = nullptr;
	rlink = nullptr;

}

NodeBinaryTree::NodeBinaryTree(Identity* data) {

	this->data = data;
	llink = nullptr;
	rlink = nullptr;

}

Identity* NodeBinaryTree::getData() {

	return data;

}

NodeBinaryTree* NodeBinaryTree::getLLink() {

	return llink;
}

NodeBinaryTree* NodeBinaryTree::getRLink() {

	return rlink;
}

void NodeBinaryTree::setData(Identity* data) {

	this->data = data;

}

void NodeBinaryTree::setLLink(NodeBinaryTree* llink) {

	this->llink = llink;

}

void NodeBinaryTree::setRLink(NodeBinaryTree* rlink) {

	this->rlink = rlink;

}

