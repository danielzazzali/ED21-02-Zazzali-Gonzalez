#pragma once
#include "AVLNode.h"
class AVLTree {

private:

	AVLNode* root;

	int idCounter = 1;

	int Size(AVLNode* root);

	int Height(AVLNode* root);

	void Print(AVLNode* root);

	int Max(int a, int b);

	int Search(Mat face, AVLNode* root);

	void Update(int id, AVLNode* root);

	void rotateLeft(AVLNode* root);

	void rotateRight(AVLNode* root);

	void balanceLeft(AVLNode* root);

	void balanceRight(AVLNode* root);

	void insertIntoAVL(AVLNode* root, AVLNode* newNode, bool& isTaller);

public:

	AVLTree();

	AVLTree(AVLNode* root);

	int size();

	int height();

	void print();

	void insert(Mat face);

	int search(Mat face);

	void addFrame(int id);

	bool isEmpty();
};

