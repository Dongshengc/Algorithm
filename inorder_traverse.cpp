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

void inorder_traverse(const TreeNode *root)
{
	if (root != nullptr)
	{
		inorder_traverse(root->left);
		cout << root->data << endl;
		inorder_traverse(root->right);
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

	inorder_traverse(root);


	return 0;
}