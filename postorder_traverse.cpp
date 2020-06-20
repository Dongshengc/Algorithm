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

void postorder_traverse(const TreeNode *root)
{
	if (root != nullptr)
	{
		postorder_traverse(root->left);
		postorder_traverse(root->right);
		cout << root->data << endl;
	}
}


int	main(int argc, char const *argv[])
{
	// formulate tree
	TreeNode *root = new TreeNode(18);
	root->left = new TreeNode(211);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(23);
	root->left->right = new	TreeNode(89);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(32);

	postorder_traverse(root);


	return 0;
}