#pragma once
class BinaryNode {

private:

	//frames of the identity
	int frames;

	//identifier of the identity
	int identifier;

	BinaryNode* llink;
	BinaryNode* rlink;

public:

	BinaryNode();

	BinaryNode(int identifier);

	BinaryNode(int identifier, int frames);

	void setFrames(int fra);

	void addOneFrame();

	void setIdentifier(int id);

	void setLLink(BinaryNode* llink);

	void setRLink(BinaryNode* rlink);

	int getIdentifier();

	int getFrames();

	BinaryNode* getLLink();

	BinaryNode* getRLink();

};

