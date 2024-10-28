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
	my_bst.Insert(30);
	my_bst.Insert(99);
	my_bst.Insert(98);
	my_bst.Insert(97);

	my_bst.PrintTreePre();
	cout << "\n";

	//while (true)
	//{
	//	int value;
	//	//cout << "Enter a value to lookup: ";
		//cin >> value;

		
		//if (my_bst.Search(value) == true)
		//	cout << "The value \"" << value << "\" is in the BST tree.";
		//else
		//	cout << "The value \"" << value << "\" is NOT in the BST tree.";
		//cout << "\n";
	//}

	//Type 1 Deletion (leaf node)
	my_bst.Delete(30);
	my_bst.PrintTreePre();
	cout << "\n";

	//Type 2 Deletion (Right Child Only)
	my_bst.Delete(12);
	my_bst.PrintTreePre();
	cout << "\n";

	//Type 2 Deletion (Left Child Only)
	my_bst.Delete(77);
	my_bst.PrintTreePre();
	cout << "\n";

	//Type 3 Deletion (not root)
	my_bst.Delete(96);
	my_bst.PrintTreePre();
	cout << "\n";

	//Type 3 Deletion (root)
	my_bst.Delete(48);
	my_bst.PrintTreePre();
	cout << "\n";
}