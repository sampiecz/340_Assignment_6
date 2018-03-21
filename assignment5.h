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


#endif
