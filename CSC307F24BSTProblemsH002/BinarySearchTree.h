#pragma once
#include "TreeNode.h"
#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

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

	bool Delete(int data)
	{
		if (root == nullptr)
			return false;
		else
			return DeleteSearch(data, root);
	}

	void PrintTreePre()
	{
		if (root == nullptr)
			return;
		else
			PrintTreePre(root);
	}

	void SaveToFile(string filepath)
	{
		ofstream file;
		file.open(filepath);
		SaveToFile(file, root);
		file.close();
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

	bool DeleteSearch(int data, TreeNode* node)
	{
		if (node == nullptr)
			return false;

		else
		{
			if (node->data == data)
			{
				//delete node
				DeleteNode(node);
				count--;
				return true;
			}
			if (node->data > data)
			{
				//look at left side.
				return DeleteSearch(data, node->leftChild);
			}
			else
			{
				//look at right side.
				return DeleteSearch(data, node->rightChild);
			}
		}
	}

	void DeleteNode(TreeNode* node)
	{
		//Type 1 Deletion, node has NO children
		if (node->leftChild == nullptr && node->rightChild == nullptr)
		{
			//is this the root?
			if (node == root)
			{
				//perform a root deletion;
				root = nullptr;
				delete node;
				return;
			}
			else
			{
				//node has parent
				//is this node on the left side of its parent?
				if (node->parent->leftChild == node)
				{
					node->parent->leftChild = nullptr;
				}
				else
					node->parent->rightChild = nullptr;

				delete node;
				return;
			}
		}
		//Determine if its a type-2 deletion, left child ONLY
		else if (node->leftChild != nullptr && node->rightChild == nullptr)
		{
			if (node == root)
			{
				root = node->leftChild;
				root->parent = nullptr;
			}
			else if (node->parent->leftChild == node)

			{
				node->parent->leftChild = node->leftChild;
				//update the parent of the nodes left child to retain the connection to the tree.
				node->leftChild->parent = node->parent;
			}
			else //otherwise, its connected to its parents right.
			{
				node->parent->rightChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}

			delete node;
			return;
		}

		//Determine if its a type-2 deletion, right child ONLY
		else if (node->leftChild == nullptr && node->rightChild != nullptr)
		{

			if (node == root)
			{
				root = node->rightChild;
				root->parent = nullptr;
			}
			else if (node->parent->leftChild == node)
			{
				node->parent->leftChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}
			else //otherwise, its connected to its parents right.
			{
				node->parent->rightChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}

			delete node;
			return;
		}
		else //type 3 deletion, where node has two children.
		{
			TreeNode* temp = node->rightChild;

			//Traverse to the left-most child in the
			//right subtree, where temp is the left most child.
			while (temp->leftChild != nullptr)
				temp = temp->leftChild;

			//overwrite the target nodes data with
			//temps data.
			node->data = temp->data;

			//Perform a deletion on temp.
			DeleteNode(temp);

			return;

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

	void SaveToFile(ofstream& file, TreeNode* node)
	{
		if (node == nullptr)
			return;

		else
		{
			file << node->data << "\n";
			SaveToFile(file, node->leftChild);
			SaveToFile(file, node->rightChild);
		}
	}
};