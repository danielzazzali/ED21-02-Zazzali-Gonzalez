#include "include/BinaryNode.h"
#include <iostream>

BinaryNode::BinaryNode() {

	this->frames = 0;
	this->identifier = -1;
	this->llink = nullptr;
	this->rlink = nullptr;

}

BinaryNode::BinaryNode(int identifier) {

	this->frames = 0;
	this->identifier = identifier;
	this->llink = nullptr;
	this->rlink = nullptr;

}

BinaryNode::BinaryNode(int identifier, int frames) {

	this->frames = frames;
	this->identifier = identifier;
	this->llink = nullptr;
	this->rlink = nullptr;

}

void BinaryNode::setFrames(int frames) {

	this->frames = frames;

}

void BinaryNode::addOneFrame() {

	this->frames += 1;

}

void BinaryNode::setIdentifier(int id) {

	this->identifier = id;
	
}

void BinaryNode::setLLink(BinaryNode* llink) {

	this->llink = llink;

}

void BinaryNode::setRLink(BinaryNode* rlink) {

	this->rlink = rlink;

}

int BinaryNode::getIdentifier()
{
	return identifier;
}

int BinaryNode::getFrames()
{
	return frames;
}

BinaryNode* BinaryNode::getLLink()
{
	return llink;
}

BinaryNode* BinaryNode::getRLink()
{
	return rlink;
}

bool BinaryNode::operator<(BinaryNode const& a) {

	return a.frames < this->frames;
}