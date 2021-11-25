#ifndef NodeBinaryTree_HEADER
#define NodeBinaryTree_HEADER

#include "../include/Identity.h"

class NodeBinaryTree {

private:

	Identity* data;
	NodeBinaryTree* llink;
	NodeBinaryTree* rlink;

public:

	NodeBinaryTree();

	NodeBinaryTree(Identity* data);

	Identity* getData();

	NodeBinaryTree* getLLink();

	NodeBinaryTree* getRLink();

	void setData(Identity* data);

	void setLLink(NodeBinaryTree* llink);

	void setRLink(NodeBinaryTree* rlink);

};

#endif
