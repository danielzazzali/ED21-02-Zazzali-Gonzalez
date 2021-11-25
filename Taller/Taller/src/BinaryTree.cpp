#include "include/BinaryTree.h"
#include <iostream>

using namespace std;

int BinaryTree::Size(BinaryNode* root) {

	if (root == nullptr) { return 0; }

	return Size(root->getLLink()) + 1 + Size(root->getRLink());
}

int BinaryTree::Height(BinaryNode* root) {
	
	if (root == nullptr) { return 0; }

	return 1 + Max(Height(root->getLLink()), Height(root->getRLink()));

}

int BinaryTree::Max(int a, int b) {

	if (a > b) { return a; }

	if (b > a) { return b; }

	return a;
}

void BinaryTree::Add(BinaryNode* parent, BinaryNode* newNode) {

	if (parent->getIdentifier() == newNode->getIdentifier()) {

		parent->addOneFrame();

		delete newNode;

	} else if (newNode->getFrames() < parent->getFrames()) {

		if (parent->getLLink() == nullptr) {

			parent->setLLink(newNode);

		} else {

			Add(parent->getLLink(), newNode);

		}

	} else if (newNode->getFrames() > parent->getFrames()) {

		if (parent->getRLink() == nullptr) {

			parent->setRLink(newNode);

		} else {

			Add(parent->getRLink(), newNode);

		}

	}

}

void BinaryTree::Print(BinaryNode* root) {

	if (root == nullptr) {

		return;
	}

	cout << "ID: " << root->getIdentifier() << " Frames: " << root->getFrames() << endl;

	Print(root->getLLink());

	Print(root->getRLink());
}

BinaryTree::BinaryTree() {

	this->root = nullptr;

}

BinaryTree::BinaryTree(BinaryNode* root) {

	this->root = root;

}

void BinaryTree::setRoot(BinaryNode* root) {

	this->root = root;

}

int BinaryTree::size() {

	return Size(root);

}

int BinaryTree::height() {

	return Height(root);
}


void BinaryTree::add(int identifier) {

	BinaryNode* node = new BinaryNode(identifier, 1);

	if (root == nullptr) {
		
		root = node;
	
	} else {
		
		Add(root, node);
	}
}

void BinaryTree::print(){

	Print(root);
	cout << endl;

}

