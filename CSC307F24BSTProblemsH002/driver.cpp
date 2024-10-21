#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree my_bst;

	my_bst.Insert(48);
	my_bst.Insert(12);
	my_bst.Insert(96);
	my_bst.Insert(77);
	my_bst.Insert(34);
	my_bst.Insert(64);

	my_bst.PrintTreePre();
	cout << "\n";
}