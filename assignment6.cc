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
  
 Name: 

 Use: 

 Parameters: 
 
 Returns: 

 ***************************************************************/
void BST::insert( Node*&, int )
{
}

/***************************************************************
  
 Name: 

 Use: 

 Parameters: 
 
 Returns: 

 ***************************************************************/
bool BST::search( Node*&, int )
{
}

/***************************************************************
  
 Name: 

 Use: 

 Parameters: 
 
 Returns: 

 ***************************************************************/
bool BST::remove( Node*&, int )
{
}

/***************************************************************
  
 Name: 

 Use: 

 Parameters: 
 
 Returns: 

 ***************************************************************/
int BST::sumLeftLeaves( Node*& n )
{
}
