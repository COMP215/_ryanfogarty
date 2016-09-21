
#include <iostream>
#include <stdlib.h>

#include "Tree.h"

// ======================================================================
Tree::Tree()								//CTOR
//..........................................
//POST: new tree is created with a root
{
	this->root = new Node();

	root->AppendLeft( 0 );
	root->AppendRight( 0 );
}//CTOR


// ======================================================================
Tree::Tree(double number)
//..........................................
//POST: new tree is created with a root with known question and left/right objects
{
	this->root = new Node(number);


	//root->AppendLeft( new Node(leftObject) );
	//root->AppendRight( new Node(rightObject) );
}//CTOR


// ======================================================================



// ======================================================================
bool Tree::IsEmpty(void) const
//..........................................
//POST: RETURN == whether or not the root node has children
{
	return (root->RChild() == 0  &&  root->LChild() == 0 );
}// IsEmpty


// ======================================================================
Node* Tree::GetRoot(void) const
//..........................................
//POST: RETURN == address of root node
{
	return root;
}// GetRoot
// =======================================================================


