/***********************************************************
 CSCI 340 - Assignment 6 - Spring 2018
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: 
 Date Due: March 22, 2018 
 Purpose: 
 ************************************************************/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node {
    // Give binTree access
    friend class binTree;
    friend class BST;

    public:
        Node(int& x, Node* l = 0, Node* r = 0)
        { data = x; left = l; right = r; }

    // Method prototypes
    public:
        // Constructor what upppp
        Node(); 
        // Variable to store node's data
        int data;
        // Variable to store node's left child
        Node* left;
        // Variable to store node's right child
        Node* right;
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
		void inorder( Node*, void(*)(int) );
		void preorder( Node*, void(*)(int) );
		void postorder( Node*, void(*)(int) );
};


#endif
