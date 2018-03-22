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

class BST: public binTree
{
    public:
        BST() : binTree() {}    // constructor
        void insert( int );     // insert an item in the tree
        bool search( int );     // search an item in the tree
        bool remove( int );     // remove an item in the tree
                                // returns true when successful
        int sumLeftLeaves();    // return the sum of values
                                // of left leaves
    private:
        void insert( Node*&, int ); // private version of insert(int)
        bool search( Node*&, int ); // private version of search(int)
        bool remove( Node*&, int ); // private version of remote(int)
        int sumLeftLeaves( Node*& n );  // private version sumLeftLeaves

};

/***************************************************************
  
 Name: BST 

 Use: Constructor for BST class. 

 Parameters: None. 
 
 Returns: None. 

 ***************************************************************/
BST::BST()
{
}

/***************************************************************
  
 Name: insert

 Use: Calls private insert method and passes in a value. 

 Parameters: An integer. 
 
 Returns: None.   

 ***************************************************************/
void BST::insert( int val)
{
    insert(val);
}

/***************************************************************
  
 Name: search

 Use: Calls private search method. 

 Parameters: An integer called val. 
 
 Returns: A bool.  

 ***************************************************************/
bool BST::search( int val)
{
    search(val);
}

/***************************************************************
  
 Name: remove

 Use: Calls private remove method and passes a value into it. 

 Parameters: An integer called val. 
 
 Returns: A bool. 

 ***************************************************************/
bool BST::remove( int val)
{
    remove(val);
}

/***************************************************************
  
 Name: sumLeftLeaves 

 Use: Returns the sum of the left leaves values. 

 Parameters: None. 
 
 Returns: An integer value that is the sum of the left leaves... 

 ***************************************************************/
int BST::sumLeftLeaves()
{
    sumLeftLeaves();
}

/***************************************************************
  
 Name: insert 

 Use: Insert a value into the BST. 

 Parameters: A reference to a node pointer and an integer value. 
 
 Returns: No return. 

 ***************************************************************/
void BST::insert( Node*& n, int val )
{
    if ( n->data != NULL )
    {
        n->data = val;
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
    if ( n->data != NULL ) 
    {
        if ( n->data == val )
        {
            return true;
        }
        else if ( n->value > val )
        {
            search( n->left, val )
        }
        else
        {
            search( n->right, val)
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
    if( n->data == NULL )
    {
        exit();
    }
    if ( n->data > val )
    {
        remove(n->left, val);
    }

    if( n->left && n->right )
    {
        // Need to find precessor still just psuedocode
        pred = n->predecessor;
        n->data = pred;
    }
    // Need to find if n is a leaf still just psuedocode
    else if( n.isleaf() )
    {
        // Call destructor for node
        // Or delete can't remember which one
        // just needs to be deleted.
        delete n;
        n = NULL;
    }
    else
    {
        // n.child is psuedocode 
        Node temp = n;
        n = n->child();
        delete temp;
}

/***************************************************************
  
 Name: 

 Use: 

 Parameters: 
 
 Returns: 

 ***************************************************************/
int BST::sumLeftLeaves( Node*& n )
{
    if ( n->left != NULL )
    {
        sumLeftLeaves
    }
}
