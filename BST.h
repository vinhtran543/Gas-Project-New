/**
Gaseek
*Dat Pham

* CIS 22C

* BST.h

*/
#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
//#include <minmax.h>


using namespace std;

template <class bstdata>
class BST
{
private:
	struct Node
	{
		bstdata data;
		Node* left;
		Node* right;

		Node() : left(NULL), right(NULL){}
		Node(bstdata newdata) : left(NULL), right(NULL), data(newdata){}
	};

	typedef struct Node* Nodeptr;

	Nodeptr root;


	/**Private helper functions*/

	void insert_value(Nodeptr root, bstdata value);

	//private helper function for insert

	//recursively inserts a value into the BST

	void inOrderPrint(Nodeptr root);

	//private helper function for inOrderPrint

	//recursively prints tree values in order from smallest to largest

	void SaveinOrderPrint(Nodeptr root, ofstream &fout);

	void preOrderPrint(Nodeptr root, ofstream &fout);

	//private helper function for preOrderPrint

	//recursively prints tree values in preorder

	void postOrderPrint(Nodeptr root, ofstream &fout);

	//private helper function for postOrderPrint

	//recursively prints tree values according in postorder

	bool containsValue(Nodeptr root, bstdata value);   //helper function for the search()

	bstdata findMin(Nodeptr root);   //helper function for minimum()

	bstdata findMax(Nodeptr root);   //helper function for maximum()

	Nodeptr remove(Nodeptr root, bstdata value);  //helper function for remove(bstdata value)

	void BSTdestructhelper(Nodeptr root);  //helper funtion for destructor

	void BSTcopyhelper(const Nodeptr temp);  //helper function for copy constructor

	int getSizehelper(Nodeptr root);    //helper function for getSize()



public:
	BST();
	//Instantiates a new BST

	//post: a new BST object

	~BST();   //destructor

	BST(const BST &bst);

	bool is_empty();

	//determines whether the BST is empty

	void insert(bstdata value);

	//inserts a new value into the BST

	//post: a new value inserted into the BST

	bstdata getRoot();

	//returns the value stored at the root of the BST

	//pre: the BST is not empty

	void inOrderPrint();

	//calls the inOrderPrint function to print out the values

	//stored in the BST

	void SaveinOrderPrint(ofstream &fout);    //saves BST in order to ouput file


	void preOrderPrint(ofstream &fout);

	//calls the reOrderPrint function to print out the values

	//stored in the BST


	void postOrderPrint(ofstream &fout);

	//calls the postOrderPrint function to print out the values

	//stored in the BST

	bool search(bstdata value);  //searches for a value in the BST

	bstdata minimum(); //finds the minimum value in the BST

	bstdata maximum(); //finds the maximum value in the BST

	void remove(bstdata value);  //removes the value in the BST

	int getSize();   //get size of BST (number of NODES)
};



template <class bstdata>
BST<bstdata>::BST() : root(NULL) {};    //default constructor


template <class bstdata>
void BST<bstdata>::BSTdestructhelper(Nodeptr root)   //destructor helper
{
	if (root != NULL)
	{
		BSTdestructhelper(root->left);
		BSTdestructhelper(root->right);
		delete root;
	}
}

template <class bstdata>
BST<bstdata>::~BST()
{
	BSTdestructhelper(root);

}


template <class bstdata>
void BST<bstdata>::BSTcopyhelper(const Nodeptr root)  //copy constructor helper
{
	if(root != NULL)
	{
		insert(root->data);
		BSTcopyhelper(root->left);
		BSTcopyhelper(root->right);
	}
}

template <class bstdata>
BST<bstdata>::BST(const BST &bst)
{
	root = NULL;
	BSTcopyhelper(bst.root);
}

template <class bstdata>
bstdata BST<bstdata>::getRoot()
{
	if (root == NULL)
	{
		cout << "getRoot(): BST is empty\n";
		//exit(-1);
	}
	else
		return root->data;
}

template <class bstdata>
bool BST<bstdata>::is_empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

template <class bstdata>
void BST<bstdata>::insert(bstdata value)
{
	if (root == NULL)
	{
		root = new Node(value);
	}
	else
		insert_value(root, value);
}

template <class bstdata>
void BST<bstdata>::insert_value(Nodeptr root, bstdata value)   //helper function
{
	if (value == root->data)
	{
		return;
	}
	else if (value < root->data)
	{
		if (root->left == NULL)
		{
			root->left = new Node(value);
		}
		else
			insert_value(root->left, value);

	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new Node(value);
		}
		else
			insert_value(root->right, value);

	}
}

template <class bstdata>
void BST<bstdata>::inOrderPrint()
{
	inOrderPrint(root);
	cout << endl;
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(Nodeptr root)   //helper function
{
	if (root != NULL)
	{
		inOrderPrint(root->left);
		cout << root->data << ", ";
		inOrderPrint(root->right);
	}
}

template <class bstdata>
void BST<bstdata>::SaveinOrderPrint(ofstream &fout)
{
	SaveinOrderPrint(root, fout);
	fout << endl;
}

template <class bstdata>
void BST<bstdata>::SaveinOrderPrint(Nodeptr root, ofstream &fout)
{
    if (root != NULL)
	{
		SaveinOrderPrint(root->left, fout);
		fout << root->data << ",";
		SaveinOrderPrint(root->right, fout);
	}

}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ofstream &fout)
{
	preOrderPrint(root, fout);
}

template <class bstdata>                         //helper function
void BST<bstdata>::preOrderPrint(Nodeptr root, ofstream &fout)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		fout << root->data << " ";
		preOrderPrint(root->left, fout);
		preOrderPrint(root->right, fout);
	}
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ofstream &fout)
{
	postOrderPrint(root, fout);
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(Nodeptr root, ofstream &fout)   //helper function
{
	if (root != NULL)
	{
		postOrderPrint(root->left, fout);
		postOrderPrint(root->right, fout);
		cout << root->data << " ";
		fout << root->data << " ";
	}
}

template <class bstdata>
bool BST<bstdata>::containsValue(Nodeptr root, bstdata value)
{
	if (value == root->data)
    {
        cout << "\nFOUND: ";
        cout << root->data;
        return true;
    }
	else if (value < root->data)
	{
		if (root->left == NULL)
			return false;

		if (root->left != NULL)
			containsValue(root->left, value);
	}
	else if (root->right == NULL)
		return false;
	else if (root->right != NULL)
		containsValue(root->right, value);
	else
		return false;
}

template <class bstdata>
bool BST<bstdata>::search(bstdata value)
{

	//check for any preconditions

	if (value == root->data)
    {
        cout << "\nFOUND: ";
        cout << root->data << endl;
        return true;
    }
	else
		return containsValue(root, value);
}

template <class bstdata>
bstdata BST<bstdata>::findMin(Nodeptr root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}


template <class bstdata>
bstdata BST<bstdata>::minimum()
{

	if (root == NULL)
	{
		cout << "Minimum: Tree is empty" << endl;
		//will need to include cstdlib for exit below
		exit(-1);
	}
	else
	{
		return findMin(root);
	}
}

template <class bstdata>
bstdata BST<bstdata>::findMax(Nodeptr root)
{
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

template <class bstdata>
bstdata BST<bstdata>::maximum()
{

	if (root == NULL)
	{
		cout << "Maximum: Tree is empty" << endl;
		//will need to include cstdlib for exit below
		exit(-1);
	}
	else
	{
		return findMax(root);
	}
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::remove(Nodeptr root, bstdata value)
{
	if (root == NULL)
		return root;
	else if (value < root->data)
		root->left = remove(root->left, value);
	else if (value > root->data)
		root->right = remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			//return NULL;
		}

		else if (root->left != NULL && root->right == NULL)
		{
			Nodeptr temp;
			temp = root;
			root = root->left;
			delete temp;
		}
		else if (root->right != NULL && root->left == NULL)
		{
			Nodeptr temp;
			temp = root;
			root = root->right;
			delete temp;
		}
		else
		{
			bstdata rightMinimum = findMin(root->right);
			root->data = rightMinimum;
			root->right = remove(root->right, rightMinimum);
			//delete rightMinimum;
		}
	}
	return root;

}

template <class bstdata>
void BST<bstdata>::remove(bstdata value)
{
	//add test(s) for pre-condition(s)
	if (root == NULL)
	{
		cout << "remove(): BST is empty, no root node\n";
		//exit(-1);
	}
	root = remove(root, value);
}



template <class bstdata>
int BST<bstdata>::getSizehelper(Nodeptr root)
{
	int size = 0;

	if (root)
	{
		size++;
		size += getSizehelper(root->left);
		size += getSizehelper(root->right);
	}
	return size;
}

template <class bstdata>
int BST<bstdata>::getSize()
{
	return getSizehelper(root);
}


#endif /* BST_H */
