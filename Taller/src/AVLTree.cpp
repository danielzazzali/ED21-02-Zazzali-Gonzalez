#include "include/AVLTree.h"
#include <queue>
#include <iostream>

using namespace std;

AVLTree::AVLTree() {

	this->root = nullptr;
}

void AVLTree::insert(int id, int frame) {

    root = InsertIntoAVL(root, id, frame);
}

int AVLTree::height()
{
    return root->getHeight();
}

void AVLTree::printTreeLevels()
{
    PrintTreeLevels(root);
}

void AVLTree::preorder()
{
    Preorder(root);
}

void AVLTree::inorder()
{
    Inorder(root);
}

void AVLTree::postorder()
{
    Postorder(root);
}

int AVLTree::size()
{
    return Size(root);
}

void AVLTree::show(int type, std::vector<AVLNode>& arreglo) {

    switch (type) {
    case 1: Show(root, arreglo); break;
    default: throw std::invalid_argument("0, 1 or 2");
    }

}

void AVLTree::PrintTreeLevels(AVLNode* root) {

    if (root == NULL) return;

    queue<AVLNode*> q;

    q.push(root);

    while (q.empty() == false)
    {

        int nodeCount = q.size();

        while (nodeCount > 0)
        {
            AVLNode* node = q.front();
            cout << node->getId() << " ";
            q.pop();
            if (node->getLLink() != nullptr)
                q.push(node->getLLink());
            if (node->getRLink() != nullptr)
                q.push(node->getRLink());
            nodeCount--;
        }
        cout << endl;
    }

}

int AVLTree::Height(AVLNode* root)
{
    if (root == nullptr) {

        return 0;
    }

    return root->getHeight();
}

int AVLTree::Max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode* AVLTree::CreateNode(int id, int frame)
{
    AVLNode* newNode = new AVLNode(id);

    newNode->addFrame(frame);

    return newNode;
}

AVLNode* AVLTree::RightRotation(AVLNode* root)
{
    AVLNode* aux1 = root->getLLink();

    AVLNode* aux2 = aux1->getRLink();

    aux1->setRLink(root);

    root->setLLink(aux2);

    root->setHeight(Max(Height(root->getLLink()), Height(root->getRLink())) + 1);

    aux1->setHeight(Max(Height(root->getLLink()), Height(root->getRLink())) + 1);

    return aux1;
}

AVLNode* AVLTree::LeftRotation(AVLNode* root)
{
    AVLNode* aux1 = root->getRLink();

    AVLNode* aux2 = aux1->getLLink();

    aux1->setLLink(root);

    root->setRLink(aux2);

    root->setHeight(Max(Height(root->getLLink()), Height(root->getRLink())) + 1);

    aux1->setHeight(Max(Height(root->getLLink()), Height(root->getRLink())) + 1);

    return aux1;
}

int AVLTree::GetBalance(AVLNode* node)
{
    if (node == nullptr) {

        return 0;
    }

    return Height(node->getLLink()) - Height(node->getRLink());
}

AVLNode* AVLTree::InsertIntoAVL(AVLNode* root, int id, int frame) {

    if (root == nullptr) {
        //Si no existe el id se crea un nodo nuevo
        return(CreateNode(id, frame));
    }

    if (id < root->getId())
        root->setLLink(InsertIntoAVL(root->getLLink(), id, frame));
    else if (id > root->getId())
        root->setRLink(InsertIntoAVL(root->getRLink(), id, frame));

    //Si el id ya existe se añade el frame
    if (id == root->getId())
        root->addFrame(frame);

    root->setHeight(1 + Max(Height(root->getLLink()), Height(root->getRLink())));

    int bfactor = GetBalance(root);

    if (bfactor > 1 && id < root->getLLink()->getId()) {

        return RightRotation(root);
    }

    if (bfactor < -1 && id > root->getRLink()->getId()) {

        return LeftRotation(root);
    }

    if (bfactor > 1 && id > root->getLLink()->getId())
    {   
        root->setLLink(LeftRotation(root->getLLink()));

        return RightRotation(root);
    }

    if (bfactor < -1 && id < root->getRLink()->getId())
    {
        root->setRLink(RightRotation(root->getRLink()));

        return LeftRotation(root);
    }

    return root;
}

void AVLTree::Preorder(AVLNode* root) {

    if (root != nullptr)
    {
        cout << " ID: " << root->getId() << " frames: " << root->getFrames() << endl;
        Preorder(root->getLLink());
        Preorder(root->getRLink());
    }
}

void AVLTree::Inorder(AVLNode* root) {

    if (root != nullptr)
    {
        Inorder(root->getLLink());
        cout << " ID: " << root->getId() << " frames: " << root->getFrames() << endl;
        Inorder(root->getRLink());
    }
}

void AVLTree::Postorder(AVLNode* root) {

    if (root != nullptr)
    {
        Postorder(root->getLLink());
        Postorder(root->getRLink());
        cout << " ID: " << root->getId() << " frames: " << root->getFrames() << endl;
    }
}

int AVLTree::Size(AVLNode* root) {

    if (root == nullptr) { return 0; }

    return Size(root->getLLink()) + 1 + Size(root->getRLink());
}

void AVLTree::Show(AVLNode* node, std::vector<AVLNode>& arreglo) {

    if (node != nullptr) {
        Show(node->getLLink(), arreglo);
        arreglo.push_back(*node);
        Show(node->getRLink(), arreglo);
    }
}











