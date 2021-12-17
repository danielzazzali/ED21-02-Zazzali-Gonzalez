#pragma once
#include "src/include/Identity.h"
class AVLNode {

private:

	Identity* id;
	int bfactor; //Factor de balance
	AVLNode* llink;
	AVLNode* rlink;

public:

	AVLNode();

	AVLNode(Identity* id);

	void setIdentity(Identity* id);

	void setBFactor(int bf);

	void setLLink(AVLNode* llink);

	void setRLink(AVLNode* rlink);

	Identity* getId();

	int getBFactor();

	AVLNode* getLLink();

	AVLNode* getRLink();

};

