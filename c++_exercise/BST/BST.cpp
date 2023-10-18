/*
 * Carson Gedeus, Binary Search Tree Example
 */

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* left = NULL;
	Node* right = NULL;

	Node(int data)
	{
		this->data = data;
	}
};

class BinSearchTree
{
public:
	Node* root;

	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			root = new Node(data);
			return root;
		}

		if (root->data > data)
		{
			if (root->left == NULL)
			{
				root->left = new Node(data);
			}
			insert(root->left, data);
			return root;
		}
		else if (root->data < data)
		{
			if (root->right == NULL)
			{
				root->right = new Node(data);
			}
			insert(root->right, data);
			return root;
		}
		else
		{
			// Nothing
		}
	}

	void printBST(Node* tree)
	{
		if (tree == NULL)
			return;

		cout << tree->data << " ";

		printBST(tree->left);
		printBST(tree->right);
	}
};

int main(void)
{
	BinSearchTree bST{};

	bST.root = bST.insert(bST.root, 50);
	bST.root = bST.insert(bST.root, 25);
	bST.root = bST.insert(bST.root, 75);
	bST.root = bST.insert(bST.root, 10);
	bST.root = bST.insert(bST.root, 4);
	bST.root = bST.insert(bST.root, 11);
	bST.root = bST.insert(bST.root, 33);
	bST.root = bST.insert(bST.root, 30);
	bST.root = bST.insert(bST.root, 40);
	bST.root = bST.insert(bST.root, 56);
	bST.root = bST.insert(bST.root, 52);
	bST.root = bST.insert(bST.root, 61);
	bST.root = bST.insert(bST.root, 87);
	bST.root = bST.insert(bST.root, 82);
	bST.root = bST.insert(bST.root, 95);

	cout << "Pre-order Traversal: ";
	bST.printBST(bST.root);
	cout << endl;

	return 0;
}