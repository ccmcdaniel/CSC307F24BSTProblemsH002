#pragma once
#include "TreeNode.h"

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


private: 
	//Recursive Definitions

	bool Insert(int data, TreeNode* node)
	{

	}

};