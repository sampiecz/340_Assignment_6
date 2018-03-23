/***********************************************************
 CSCI 340 - Assignment 6 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: March 22, 2018 
 Purpose: 
 ************************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

/***************************************************************
  
 Name: Node 

 Use: Constructor for node class. 

 Parameters: None. 
 
 Returns: None. 

 ***************************************************************/
Node::Node()
{
}

/***************************************************************
  
 Name: binTree 

 Use: Constructor for binTree class. 

 Parameters: None. 
 
 Returns: None. 

 ***************************************************************/
binTree::binTree()
{
    root = nullptr;
}

/***************************************************************
  
 Name: insert 

 Use: Calls private method and passes in root and a value.

 Parameters: An integer value. 
 
 Returns: None. 

 ***************************************************************/
void binTree::insert(int val)
{
    insert(root, val);
}

/***************************************************************
  
 Name: height 

 Use: Returns the height. 

 Parameters: None. 
 
 Returns: An unsigned value that is the result of the private
 height method.

 ***************************************************************/
unsigned binTree::height() const
{
    return height(root);
}

/***************************************************************
  
 Name: size 

 Use: Returns the size of the binary tree.

 Parameters: None. 
 
 Returns: An unsigned value that is the result of the private
 size method.

 ***************************************************************/
unsigned binTree::size() const
{
    return size(root);
}

/***************************************************************
  
 Name: inorder 

 Use: Calls the private inorder method. 

 Parameters: val 
 
 Returns: None. 

 ***************************************************************/
void binTree::inorder( void(* val)(int) )
{
    inorder(root, val);
}

/***************************************************************
  
 Name: preorder 

 Use: Calls private preorder method. 

 Parameters: val 
 
 Returns: None. 

 ***************************************************************/
void binTree::preorder( void(* val)(int) )
{
    preorder(root, val);
}

/***************************************************************
  
 Name: postorder 

 Use: Calls private postorder method.

 Parameters: val 
 
 Returns: None. 

 ***************************************************************/
void binTree::postorder( void(* val)(int) )
{
    postorder(root, val);
}

/***************************************************************
  
 Name: insert

 Use: This function is used to insert a node with the data data 
 x in a binary (sub-)tree at root r, applying the following 
 technique: if the tree is empty, then the new node will be 
 the root of the tree with the data x; otherwise, x is inserted 
 in the left or->right sub-tree of r, depending on the sub-trees’
 sizes. If the size of the right sub-tree is less than the size 
 of the left sub-tree, x is inserted in the right sub-tree; 
 otherwise x is inserted in the left sub-tree. 
 
 Parameters: Reference to Node pointer r. Integer called val. 
 
 Returns: None. 

 ***************************************************************/
void binTree::insert( Node*& r, int val )
{
	if ( r == nullptr) 
	{
		// node will be root of tree with data x
        r = new Node;
        r->data = val;
        r->left = nullptr;
        r->right = nullptr;
	}
	else
	{
		// x is inserted in the left or->right sub-tree of r
		// depending on the sub tree's sizes.

		// if right sub tree less than size of left sub tree, x is inserted into the left subtree
		if ( size(r->right) < size(r->left) )
		{
			insert(r->right, val);
		}
		else
		{
			insert(r->left, val);
		}
	}
}


/***************************************************************
  
 Name: size

 Use: This function returns the number of nodes in the tree 
 rooted at r. If the tree is empty, the size is 0. 
 
 Parameters: Pointer to Node r. 
 
 Returns: Unsigned.  

 ***************************************************************/
unsigned binTree::size( Node* r ) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else
	{
        return 1 + size(r->left) + size(r->right);
	}
}


/***************************************************************
  
 Name: height

 Use: This function returns the height of the tree rooted at r. 
 If the tree is empty, the size is -1. 
 
 Parameters: Pointer to Node r. 
 
 Returns: None.

 ***************************************************************/
unsigned binTree::height( Node* r ) const
{
	if (r == nullptr)
	{
		return -1;
	}
	else
	{

        int leftDepth = height(r->left);
        int rightDepth = height(r->right);

        if (rightDepth < leftDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
	}
}


/***************************************************************
  
 Name: inorder

 Use: This function traverse the tree rooted at r. p is the 
 “visit” operation on each node. To visit r, simply invoke p(r->data). 

 Parameters: Pointer to Node r. Pointer to p. 
 
 Returns: None.

 ***************************************************************/
void binTree::inorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
		inorder(r->left, p);
        p(r->data);
		inorder(r->right, p);
	}
}


/***************************************************************
  
 Name: preorder

 Use: Recursively traverses tree in preorder. 

 Parameters: Pointer to Node r. Pointer to p. 
 
 Returns: None.

 ***************************************************************/
void binTree::preorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
        p(r->data);
		preorder(r->left, p);
		preorder(r->right, p);
	}
}


/***************************************************************
  
 Name: postorder

 Use: Recursively traverses binary tree. 

 Parameters: Pointer to Node r. Pointer to p. 
 
 Returns: None. 

 ***************************************************************/
void binTree::postorder( Node* r, void(* p)(int) )
{
	if (r != NULL)
	{
		postorder(r->left, p);
		postorder(r->right, p);
        p(r->data);
	}
}

// Start pre provided stuff
const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

// New main method in assignment6main.cc
// #define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
