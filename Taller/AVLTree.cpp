#include "AVLTree.h"
#include <iostream>

using namespace std;

int AVLTree::Size(AVLNode* root)
{
	if (root == nullptr) { return 0; }

	return Size(root->getLLink()) + 1 + Size(root->getRLink());
}

int AVLTree::Height(AVLNode* root) {

	if (root == nullptr) { return 0; }

	return 1 + Max(Height(root->getLLink()), Height(root->getRLink()));
}

void AVLTree::Print(AVLNode* root) {

	if (root == nullptr) {

		return;
	}

	cout << "ID: " << root->getId()->getIdentifier() << " Frames: " << root->getId()->getFrames() << endl;
	Print(root->getLLink());
	Print(root->getRLink());
}

int AVLTree::Max(int a, int b) {

	if (b > a) { return b; }

	return a;
}

int AVLTree::Search(Mat face, AVLNode* root) {

	int id = -1;

	if (root == nullptr) {

		return id;
	}

	Mat original = root->getId()->getImage();

	double dist = norm(original, face, cv::NormTypes::NORM_L2);

	if (dist < 3100)
	{
		id = root->getId()->getIdentifier();
		return id;
	}

	if (id == -1) {

		id = Search(face, root->getLLink());
		id = Search(face, root->getRLink());
	}

	return id;
}

void AVLTree::Update(int id, AVLNode* root) {

	if (root == nullptr) {

		return;

	}

	if (root->getId()->getIdentifier() == id) {

		root->getId()->addFrame();

	}
	else {


		Update(id, root->getLLink());
		Update(id, root->getRLink());

	}
}

void AVLTree::rotateLeft(AVLNode* root) {

	AVLNode* p;

	if (root == nullptr) { return; }

	else if (root->getRLink() == nullptr) { return; }

	else {

		p = root->getRLink();

		root->setRLink(p->getLLink());

		p->setLLink(root);

		root = p;
	}
}

void AVLTree::rotateRight(AVLNode* root) {

	AVLNode* p;

	if (root == nullptr) { return; }

	else if (root->getLLink() == nullptr) { return; }

	else {

		p = root->getLLink();

		root->setLLink(p->getRLink());

		p->setRLink(root);

		root = p;
	}
}

void AVLTree::balanceLeft(AVLNode* root) {

	AVLNode* p;
	AVLNode* w;

	p = root->getLLink();

	switch (p->getBFactor()) {

	case -1:

		root->setBFactor(0);
		p->setBFactor(0);
		rotateRight(root);
		break;
	
	case 0:
		break;

	case 1:

		w = p->getRLink();

		switch (w->getBFactor()) {

		case -1:
			root->setBFactor(1);
			p->setBFactor(0);
			break;


		case 0:
			root->setBFactor(0);
			p->setBFactor(0);
			break;

		case 1:
			root->setBFactor(0);
			p->setBFactor(-1);

		}

		w->setBFactor(0);
		rotateLeft(p);
		root->setLLink(p);
		rotateRight(root);
	}
}

void AVLTree::balanceRight(AVLNode* root) {

	AVLNode* p;
	AVLNode* w;

	p = root->getRLink();

	switch (p->getBFactor()) {

	case -1:

		w = p->getLLink();

		switch (w->getBFactor()) {

		case -1:

			root->setBFactor(0);
			p->setBFactor(1);
			break;

		case 0:

			root->setBFactor(0);
			p->setBFactor(0);
			break;

		case 1:

			root->setBFactor(-1);
			p->setBFactor(0);
		}

		w->setBFactor(0);
		rotateRight(p);
		root->setRLink(p);
		rotateLeft(root);
		break;


	case 0:
		break;

	case 1:

		root->setBFactor(0);
		p->setBFactor(0);
		rotateLeft(root);
	}
}

void AVLTree::insertIntoAVL(AVLNode* root, AVLNode* newNode, bool& isTaller) {

	if (root == nullptr) {

		root = newNode;
		isTaller = true;
	}

	else if (root->getId()->getIdentifier() == root->getId()->getIdentifier()) {

		return;

	}

	else if (root->getId()->getIdentifier() > newNode->getId()->getIdentifier()) {

		insertIntoAVL(root->getLLink(), newNode, isTaller);

		if (isTaller) {

			switch (root->getBFactor()) {

			case -1:

				balanceLeft(root);
				isTaller = false;
				break;

			case 0:

				root->setBFactor(-1);
				isTaller = true;
				break;

			case 1:

				root->setBFactor(0);
				isTaller = false;
			}

		}

		else {

			insertIntoAVL(root->getRLink(), newNode, isTaller);

			if (isTaller) {

				switch (root->getBFactor()) {

				case -1:

					root->setBFactor(0);
					isTaller = false;
					break;

				case 0:

					root->setBFactor(1);
					isTaller = true;
					break;

				case 1:

					balanceRight(root);
					isTaller = false;
				}
			}

		}

	}

}

AVLTree::AVLTree() {

	root = nullptr;

}

AVLTree::AVLTree(AVLNode* root) {

	this->root = root;

}

int AVLTree::size() {

	return Size(root);
}

int AVLTree::height() {

    return Height(root);
}

void AVLTree::print() {

	Print(root);

	cout << endl;

}

void AVLTree::insert(Mat face) {

	bool isTaller = false;

	Identity* id = new Identity(face);

	id->setIdentifier(idCounter++);

	AVLNode* newNode = new AVLNode(id);
	
	newNode->setBFactor(0);

	if (root == nullptr) {

		root = newNode;
		return;
	}

	insertIntoAVL(root, newNode, isTaller);
}

int AVLTree::search(Mat face) {

	// Retorna el identifier que concuerda con la imagen para actualizar los frames en el arbol.

	int identifier = -1; // no existe = -1

	identifier = Search(face, root);

	return identifier;

}

void AVLTree::addFrame(int id) {

	Update(id, root);
}

bool AVLTree::isEmpty()
{
	return root == nullptr;
}
