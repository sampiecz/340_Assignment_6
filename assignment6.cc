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
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

/***************************************************************
  
 Name: insert

 Use: Calls private insert method and passes in a value. 

 Parameters: An integer. 
 
 Returns: None.   

 ***************************************************************/
void BST::insert( int val)
{
    insert(root, val);
}

/***************************************************************
  
 Name: search

 Use: Calls private search method. 

 Parameters: An integer called val. 
 
 Returns: A bool.  

 ***************************************************************/
bool BST::search( int val)
{
    return search(root, val);
}

/***************************************************************
  
 Name: remove

 Use: Calls private remove method and passes a value into it. 

 Parameters: An integer called val. 
 
 Returns: A bool. 

 ***************************************************************/
bool BST::remove( int val)
{
    return remove(root, val);
}

/***************************************************************
  
 Name: sumLeftLeaves 

 Use: Returns the sum of the left leaves values. 

 Parameters: None. 
 
 Returns: An integer value that is the sum of the left leaves... 

 ***************************************************************/
int BST::sumLeftLeaves()
{
    return sumLeftLeaves(root);
}

/***************************************************************
  
 Name: insert 

 Use: Insert a value into the BST. 

 Parameters: A reference to a node pointer and an integer value. 
 
 Returns: No return. 

 ***************************************************************/
void BST::insert( Node*& n, int val )
{
    if ( n == NULL )
    {
        n = new Node(val);
    }
    else if ( n->data > val )
    {
        insert( n->left, val);
    }
    else
    {
        insert( n->right, val);
    }
}

/***************************************************************
  
 Name: search 

 Use: Searches the binary tree for the value specified.  

 Parameters: A reference to a node pointer and an integer value. 
 
 Returns: A bool. 

 ***************************************************************/
bool BST::search( Node*& n, int val )
{
    if ( n != NULL ) 
    {
        if ( n->data == val )
        {
            return true;
        }
        else if ( n->data > val )
        {
            return search( n->left, val );
        }
        else
        {
            return search( n->right, val);
        }
    }
    else
    {
        return false;
    }
}

/***************************************************************
  
 Name: remove 

 Use: Removes a node from the binary search tree. 

 Parameters: A reference to a node point and an integer. 
 
 Returns: A bool. 

 ***************************************************************/
bool BST::remove( Node*& n, int val )
{
    Node* predecessor = n;

    if( n->data == NULL )
    {
        return false; 
    }
    if ( n->data > val )
    {
        return remove(n->left, val);
    }
    if ( n->data < val )
    {
        return remove(n->right, val);
    }

    if( n->left != NULL && n->right != NULL )
    {
        predecessor = n->left;   

        while( predecessor->right != NULL)
        {
            predecessor = predecessor->right;
        }

        n->data = predecessor->data;

        return remove( n->left, predecessor->data );
    }

    if( n->right == NULL )
    {
        n = n->left;
    }
    else if( n->left == NULL )
    {
        n = n->right;
    }
    else
    {
        predecessor = n->left;

        while( predecessor->right != NULL )
        {
            predecessor = predecessor->right;
        }

        predecessor->right = n->right;
        predecessor = n;
        n = n->left;
        delete predecessor;

    }

    return true;
}

/***************************************************************
  
 Name: isLeaf 

 Use: Say if the node is a leaf or not. 

 Parameters: A node.
 
 Returns: A bool. 
 
 ***************************************************************/
bool isLeaf( Node *n )
{
    if ( n == NULL )
    {
        return false;
    }
    else if( n->left == NULL && n->right == NULL )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
  
 Name: sumLeftLeaves

 Use: Return the sum of the left leaves based on the passed in
 node object.

 Parameters: A reference to a pointer to a node.
 
 Returns: An integer that is the sum of the leaves leaves in 
 the binary search tree.

 ***************************************************************/
int BST::sumLeftLeaves( Node*& n )
{
    int sum = 0;

    if ( n != NULL )
    {

        if (isLeaf(n->left))
        {
            sum += n->left->data;
        }
        else
        {
            sum += sumLeftLeaves(n->left);
        }

        sum += sumLeftLeaves(n->right);
    }

    return sum;
}
