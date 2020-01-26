// Carson Gedeus
// Spring 2017

// GenericBST: BST.java
// Basic binary search tree (BST) implementation that supports insert() and
// delete() operations.


import java.io.*;
import java.util.*;

class Node <AnyType>
{
	AnyType data;
	Node<AnyType> left, right;

	Node(AnyType data)
	{
		this.data = data;
	}
}

public class GenericBST <AnyType extends Comparable<AnyType>>
{
	private Node<AnyType> root;
	
	public void insert(AnyType data)
	{
		root = insert(root, data);
	}
	
	private Node<AnyType> insert(Node<AnyType> root, AnyType data)
	{
		if (root == null)
		{
			return new Node<AnyType>(data);
		}
		else if (root.data.compareTo(data) > 0)
		{
			root.left = insert(root.left, data);
		}
		else if (root.data.compareTo(data) < 0)
		{
			root.right = insert(root.right, data);
		}
		else
		{
			// Stylistically, I have this here to explicitly state that we are
			// disallowing insertion of duplicate values. This is unconventional
			// and a bit cheeky.
			;
		}

		return root;
	}

	public void delete(AnyType data)
	{
		root = delete(root, data);
	}

	private Node<AnyType> delete(Node<AnyType> root, AnyType data)
	{
		if (root == null)
		{
			return null;
		}
		else if (root.data.compareTo(data) > 0)
		{
			root.left = delete(root.left, data);
		}
		else if (root.data.compareTo(data) < 0)
		{
			root.right = delete(root.right, data);
		}
		else
		{
			if (root.left == null && root.right == null)
			{
				return null;
			}
			else if (root.right == null)
			{
				return root.left;
			}
			else if (root.left == null)
			{
				return root.right;
			}
			else
			{
				root.data = findMax(root.left);
				root.left = delete(root.left, root.data);
			}
		}

		return root;
	}

	// This method assumes root is non-null, since this is only called by
	// delete() on the left subtree, and only when that subtree is non-empty.
	private AnyType findMax(Node<AnyType> root)
	{
		while (root.right != null)
		{
			root = root.right;
		}

		return root.data;
	}

	// Returns true if the value is contained in the BST, false otherwise.
	public boolean contains(AnyType data)
	{
		return contains(root, data);
	}

	private boolean contains(Node<AnyType> root, AnyType data)
	{
		if (root == null)
		{
			return false;
		}
		else if (root.data.compareTo(data) > 0)
		{
			return contains(root.left, data);
		}
		else if (root.data.compareTo(data) < 0)
		{
			return contains(root.right, data);
		}
		else
		{
			return true;
		}
	}

	public void inorder()
	{
		System.out.print("In-order Traversal:");
		inorder(root);
		System.out.println();
	}

	private void inorder(Node<AnyType> root)
	{
		if (root == null)
			return;

		inorder(root.left);
		System.out.print(" " + root.data);
		inorder(root.right);
	}

	public void preorder()
	{
		System.out.print("Pre-order Traversal:");
		preorder(root);
		System.out.println();
	}

	private void preorder(Node<AnyType> root)
	{
		if (root == null)
			return;

		System.out.print(" " + root.data);
		preorder(root.left);
		preorder(root.right);
	}

	public void postorder()
	{
		System.out.print("Post-order Traversal:");
		postorder(root);
		System.out.println();
	}

	private void postorder(Node<AnyType> root)
	{
		if (root == null)
			return;

		postorder(root.left);
		postorder(root.right);
		System.out.print(" " + root.data);
	}

	public static void main(String [] args)
	{
		GenericBST<Integer> myTree = new GenericBST<Integer>();

		for (int i = 0; i < 5; i++)
		{
			int r = (int)(Math.random() * 100) + 1;
			System.out.println("Inserting " + r + "...");
			myTree.insert(new Integer(r));
		}
		
		myTree.inorder();
		myTree.preorder();
		myTree.postorder();
	}
	
	public static double difficultyRating()
	{	return 1.00;	}
	
	public static double hoursSpent()
	{	return 10.00;	}
}
