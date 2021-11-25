#pragma once
#include "BinaryNode.h"

class BinaryTree {

private:

	BinaryNode* root;

	int Size(BinaryNode* root);

	int Height(BinaryNode* root);

	int Max(int a, int b);

	void Add(BinaryNode* parent, BinaryNode* newNode);

	void Print(BinaryNode* root);

	int* FindMax(BinaryNode* node);

public:

	BinaryTree();

	BinaryTree(BinaryNode* root);

	void setRoot(BinaryNode* root);

	int size();

	int height();

	void add(int identifier);

	void print();

	int* findMax();
};

