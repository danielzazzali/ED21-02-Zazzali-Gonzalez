#pragma once
#include <vector>

using namespace std;

class AVLNode {

private:

	int id;
	int frames;
	vector<int> intervals;

	AVLNode* LLink;
	AVLNode* RLink;
	int height;

public:

	AVLNode(int id);

	void setIdentity(int id);

	void addFrame(int frame);

	void setHeight(int height);

	void setLLink(AVLNode* llink);

	void setRLink(AVLNode* rlink);

	int getId();

	int getFrames();

	int getHeight();

	AVLNode* getLLink();

	AVLNode* getRLink();

	vector<int> getIntervals();

	bool operator<(AVLNode const& a);
};

