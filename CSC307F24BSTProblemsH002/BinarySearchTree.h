#pragma once
#include "TreeNode.h"
#include <iostream>

using std::cout;

class BinarySearchTree
{
private:
	TreeNode* root = nullptr;
	int count = 0;

public:
	//Wrapper Definition
	bool Insert(int data)
	{
		if (root == nullptr)
		{
			//Make a new node at the root
			root = new TreeNode;
			root->data = data;
			count++;
			return true;
		}
		else
		{
			return Insert(data, root);
		}
	}

	bool Search(int data)
	{
		if (root == nullptr)
			return false;
		else
		{
			return Search(data, root);
		}
	}

	void PrintTreePre()
	{
		if (root == nullptr)
			return;
		else
			PrintTreePre(root);
	}


private: 
	//Recursive Definitions

	bool Insert(int data, TreeNode* node)
	{
		if (node->data == data)
			return false;
		else
		{
			if (node->data > data)
			{
				//look at left child 
				if (node->leftChild == nullptr)
				{
					//insert as the left child
					TreeNode* new_node = new TreeNode;
					
					new_node->data = data;
					new_node->parent = node;
					new_node->parent->leftChild = new_node;
					count++;
					return true;
				}
				else
				{
					//continue looking 
					return Insert(data, node->leftChild);
				}
			}
			else
			{
				//Look at right child
				//look at left child 
				if (node->rightChild == nullptr)
				{
					//insert as the left child
					TreeNode* new_node = new TreeNode;

					new_node->data = data;
					new_node->parent = node;
					new_node->parent->rightChild = new_node;
					count++;
					return true;
				}
				else
				{
					//continue looking 
					return Insert(data, node->rightChild);
				}
			}

		}
	}

	bool Search(int data, TreeNode* node)
	{
		if (node == nullptr)
			return false;

		else
		{
			if (node->data == data)
				return true;
			if (node->data > data)
			{
				//look at left side.
				return Search(data, node->leftChild);
			}
			else
			{
				//look at right side.
				return Search(data, node->rightChild);
			}
		}
	}

	void PrintTreePre(TreeNode* node)
	{
		if (node == nullptr)
			return;

		cout << node->data << ", ";
		PrintTreePre(node->leftChild);
		//cout << node->data << ", "; //in order location
		PrintTreePre(node->rightChild);
		//cout << node->data << ", "; //post order location
	}

};