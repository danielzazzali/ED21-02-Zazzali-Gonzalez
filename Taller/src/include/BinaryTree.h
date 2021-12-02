#include "BinaryNode.h"
#include <iostream>
#include <vector>


class BinaryTree {

private:

	BinaryNode* root;

	int Size(BinaryNode* root);

	int Height(BinaryNode* root);

	int Max(int a, int b);

	void Add(BinaryNode* parent, BinaryNode* newNode);

	void Print(BinaryNode* root);

	int* FindMax(BinaryNode* node);

	void showIn(BinaryNode* node,std::vector<BinaryNode> & arreglo);


public:

	BinaryTree();

	BinaryTree(BinaryNode* root);

	void setRoot(BinaryNode* root);

	int size();

	int height();

	void add(int identifier);

	void print();

	int* findMax();

	void show(int type, std::vector<BinaryNode> & arreglo);


};

