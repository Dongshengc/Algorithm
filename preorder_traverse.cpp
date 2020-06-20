#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(const int &_data): data(_data){}
};

void preorder_traverse(const TreeNode *root)
{
	if (root != nullptr)
	{
		cout << root->data << endl;
		preorder_traverse(root->left);
		preorder_traverse(root->right);
	}
}


int	main(int argc, char const *argv[])
{
	// formulate tree
	TreeNode *root = new TreeNode(18);
	root->left = new TreeNode(211);
	root->right = new TreeNode(20);
	root->left->right = new	TreeNode(12);
	root->right->right = new TreeNode(190);

	preorder_traverse(root);


	return 0;
}