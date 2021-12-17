#include "AVLNode.h"

AVLNode::AVLNode() {

	this->id = nullptr;
	this->bfactor = 0;
	this->llink = nullptr;
	this->rlink = nullptr;
}

AVLNode::AVLNode(Identity* id) {

	this->id = id;
	this->bfactor = 0;
	this->llink = nullptr;
	this->rlink = nullptr;
}

void AVLNode::setIdentity(Identity* id) {

	this->id = id;

}

void AVLNode::setBFactor(int bf) {

	this->bfactor = bf;

}

void AVLNode::setLLink(AVLNode* llink) {

	this->llink = llink;

}

void AVLNode::setRLink(AVLNode* rlink) {

	this->rlink = rlink;

}

Identity* AVLNode::getId()
{
	return id;
}

int AVLNode::getBFactor()
{
	return bfactor;
}

AVLNode* AVLNode::getLLink()
{
	return llink;
}

AVLNode* AVLNode::getRLink()
{
	return rlink;
}
