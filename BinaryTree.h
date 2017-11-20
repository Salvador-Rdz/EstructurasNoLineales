#include "Leaf.h"

class BTree {
private:
	Leaf *root;
	int leaves;	
	Leaf *mostLeft(Leaf *root);
public:
	BTree();
	BTree(int d);
	~BTree();

	void insert(int d, Leaf *root);
	void showLeaf(Leaf *root);
	Leaf *fetch(int d, Leaf *root);
	Leaf *getFather(Leaf *leaf, Leaf *root); //nuevo
	bool deleteLeaf(int d, Leaf *root);
	bool isEmpty();
	Leaf *getRoot();
	int Height(Leaf *root);
	int getLeaves();
	void inOrder(Leaf *root);
	void preOrder(Leaf *root);
	void postOrder(Leaf *root);
};