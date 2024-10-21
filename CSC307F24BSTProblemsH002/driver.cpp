#include "BinarySearchTree.h"
using std::cin;

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

	while (true)
	{
		int value;
		cout << "Enter a value to lookup: ";
		cin >> value;

		
		if (my_bst.Search(value) == true)
			cout << "The value \"" << value << "\" is in the BST tree.";
		else
			cout << "The value \"" << value << "\" is NOT in the BST tree.";
		cout << "\n";
	}
}