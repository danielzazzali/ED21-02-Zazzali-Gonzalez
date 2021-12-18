#include "include/AVLNode.h"

AVLNode::AVLNode(int id) {

	this->id = id;
	this->frames = 0;
	this->height = 1;
	this->LLink = nullptr;
	this->RLink = nullptr;
}

void AVLNode::setIdentity(int id) {

	this->id = id;
}

//Aqui se añade el frame
void AVLNode::addFrame(int frame) {

	//Primero guardo el frame especifico de aparicion en el vector
	this->intervals.push_back(frame);

	//Luego sumo al contador de frames
	this->frames++;
}

void AVLNode::setHeight(int h) {

	this->height = h;
}

void AVLNode::setLLink(AVLNode* llink) {

	this->LLink = llink;

}

void AVLNode::setRLink(AVLNode* rlink) {

	this->RLink = rlink;

}

int AVLNode::getId()
{
	return id;
}

int AVLNode::getFrames() 
{

	return frames;
}

int AVLNode::getHeight()
{
	return height;
}

AVLNode* AVLNode::getLLink()
{
	return LLink;
}

AVLNode* AVLNode::getRLink()
{
	return RLink;
}

vector<int> AVLNode::getIntervals()
{
	return vector<int>();
}

bool AVLNode::operator<(AVLNode const& a)
{
	return a.frames < this->frames;
}
