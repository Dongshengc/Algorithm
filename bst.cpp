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

void inorder_traverse(TreeNode *_root)
{
	if (_root != nullptr)
	{
		 inorder_traverse(_root->left);
		 cout << _root->data << endl;	
		 inorder_traverse(_root->right);
	}
}


TreeNode* findMinNode(TreeNode *_root, TreeNode *&parent)
{
	if (_root->left != nullptr)
	{
		parent = _root;
		findMinNode(_root->left, parent);
	}
	else
	{
		return _root;
	}
}

void insert(TreeNode *&_node, const int &_data)
{
	if (_node == nullptr)
	{
		 _node = new TreeNode(_data);
	}
	else
	{
		if (_data >= _node->data)
		{
			 insert(_node->right, _data);
		}
		else
		{
			insert(_node->left, _data);
		}
	}
}

TreeNode* search(TreeNode *_root, TreeNode *&parent, const int &_data)
{
	if (_root->data == _data)
	{
		return _root;
	}
	else if (_root->data > _data)
	{
		parent = _root;
		search(_root->left, parent, _data);
	}
	else if (_root->data <= _data)
	{
		parent = _root;
		search(_root->right, parent, _data);
	}
}

void delete_node(TreeNode *_root, TreeNode *parent, const int &_data)
{
	TreeNode *target = search(_root, parent, _data);
	if (target->left == nullptr && target->right == nullptr)
	{
		if (parent->left == target)
		{
			parent->left = nullptr;
		}
		else
		{
			parent->right = nullptr;
		}
		delete target;
	}
	else if (target->left != nullptr && target->right == nullptr)
	{
		TreeNode *child = target->left;
		if (parent->left == target)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
		delete target;
	}
	else if (target->left == nullptr && target->right != nullptr)
	{
		TreeNode *child = target->right;
		if (parent->left == target)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
		delete target;
	}
	else
	{
		TreeNode *min_parent = target->right;
		TreeNode *repalce_node = findMinNode(target->right, min_parent);
		int val = repalce_node->data;
		delete_node(_root, _root, repalce_node->data);
		target->data = val;
	}
}


int	main(int argc, char const *argv[])
{
	// formulate tree
	TreeNode *root = new TreeNode(18);
	TreeNode *parent;

	int choice = 0;
	while (choice != 6)
	{
		parent = root;
		cout << "1. Insert element: " << endl;
		cout << "2. Delete element: " << endl;
		cout << "3. Find the minimum element: " << endl;
		cout << "4. Find specific element: " << endl;
		cout << "5. Inoder traverse: " << endl; 
		cout << "Enter the operation choice: " << ends;
		cin >> choice;

		int element;
		switch (choice)
		{
			case 1: 
				cout << "Enter the element to be inserted: " << ends;
				cin	>> element;
				insert(root, element);
				break;
			case 2:
				cout << "Enter the element to be deleted: " << ends;
				cin >> element;
				delete_node(root, parent, element);
				break;
			case 3:
				cout << "minimum element: " << findMinNode(root, parent)->data << endl;
				cout << "its parent is: " << parent->data << endl;
				break;
			case 4: 
				cout << "Enter the element to be searched: " << ends;
				cin >> element;
				cout << "the node is: " << search(root, parent, element)->data << endl;
				cout << "its parent is: " << parent->data << endl;
				break;
			case 5: 
				inorder_traverse(root);
				break;
			case 6:
				exit(0);
		}
	}

	return 0;
}