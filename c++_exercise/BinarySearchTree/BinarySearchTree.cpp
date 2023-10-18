/*
* Carson gedeus, Binary Search Tree example, 10/17/2023
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

class BST
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

		void printBinSearchTree(Node* node)
		{
			// base-case
			if (node == nullptr)
				return;

			cout << node->data << " ";

			printBinSearchTree(node->left);
			printBinSearchTree(node->right);
		}
};

int main(void)
{
	BST binSearchTree{};

	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 50);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 25);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 10);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 4);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 11);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 33);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 30);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 40);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 75);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 56);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 89);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 52);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 61);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 82);
	binSearchTree.root = binSearchTree.insert(binSearchTree.root, 95);

	cout << "Pre-order traversal: ";
	binSearchTree.printBinSearchTree(binSearchTree.root);
	cout << endl;

	return 0;
}