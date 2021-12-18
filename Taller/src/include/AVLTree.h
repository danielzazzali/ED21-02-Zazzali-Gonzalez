#pragma once
#include "AVLNode.h"

class AVLTree {

private:

	AVLNode* root;

	void PrintTreeLevels(AVLNode* root);

	int Height(AVLNode* root);

	int Max(int a, int b);

	AVLNode* CreateNode(int id, int frame);

	AVLNode* RightRotation(AVLNode* root);

	AVLNode* LeftRotation(AVLNode* root);

	int GetBalance(AVLNode* node);

	AVLNode* InsertIntoAVL(AVLNode* root, int id, int frame);

	void Preorder(AVLNode* root);

	void Inorder(AVLNode* root);

	void Postorder(AVLNode* root);

	int Size(AVLNode* root);

	void Show(AVLNode* node, std::vector<AVLNode>& arreglo);

public:

	AVLTree();

	void insert(int id, int frame);

	int height();

	void printTreeLevels();

	void preorder();

	void inorder();

	void postorder();

	int size();

	void show(int type, std::vector<AVLNode>& arreglo);
};

