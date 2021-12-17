#include "include/BinaryTree.h"
#include <iostream>
#include <vector>

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
	}

	else if (newNode->getIdentifier() < parent->getIdentifier()) {

		if (parent->getLLink() == nullptr) {

			parent->setLLink(newNode);

		} else {

			Add(parent->getLLink(), newNode);

		}

	} else if (newNode->getIdentifier() > parent->getIdentifier()) {

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

int* BinaryTree::FindMax(BinaryNode* node) {

	if (node == nullptr) {

		return 0;
	}

	int* max = new int[2];

	max[0] = node->getFrames();
	max[1] = node->getIdentifier();

	int* maxL = FindMax(node->getLLink());
	int* maxR = FindMax(node->getRLink());

	if (maxL != nullptr && maxL[0] > max[0]) {

		max = maxL;

	}

	if (maxR != nullptr && maxR[0] > max[0]) {

		max = maxR;

	}

	return max;
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

int* BinaryTree::findMax()
{
	return FindMax(root);
}


void BinaryTree::showIn(BinaryNode* node,vector<BinaryNode> & arreglo) {
	if (node != NULL) {
		showIn(node->getLLink(), arreglo);
		arreglo.push_back(*node);
		showIn(node->getRLink(), arreglo);
	}
}


void BinaryTree::show(int type, vector<BinaryNode> & arreglo) {
	switch (type) {
		case 1: showIn(root,arreglo); break;
		default: throw std::invalid_argument("0, 1 or 2");
	}
}





