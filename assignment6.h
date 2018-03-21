/***********************************************************
 CSCI 340 - Assignment 6 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: March 22, 2018 
 Purpose: 
 ************************************************************/
#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"

class BST : public binTree {
    public:
        BST() : binTree() {}
        void insert( int );
        bool search( int );
        bool remove( int );
        int sumLeftLeaves();
    private:
        void insert( Node*&, int );
        bool search( Node*&, int );
        bool remove( Node*&, int );
        int sumLeftLeaves(Node*&);
};

#endif
