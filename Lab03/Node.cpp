
#include<iostream>
#include<stdlib.h>
#include <cassert>
#include "Node.h"

// ======================================================================
Node::Node()					// Default CTOR
{
	this->Qthing = 0;

	this->left  = 0;			//make left and right point to NULL
	this->right = 0;

}// CTOR

// ======================================================================
Node::Node(const double number)	// CTOR when text is known
{
	this->Qthing = number;
	this->left  = 0;			// make left and right point to NULL
	this->right = 0;

}// CTOR

// ======================================================================
Node::Node(const Node& old)		// COPY CTOR
{
	this->Qthing = old.Qthing;

	this->left  = old.left;
	this->right = old.right;

}// COPY CTOR

// ======================================================================
Node::~Node()	// DTOR
{
	// Tree DTOR does the work ...

}


// ======================================================================
// ---------- SETTERS ------------------------

void Node::StoreNumber(const double  newNumber)
{
	this->Qthing = newNumber;

}// StoreText

// ======================================================================
void Node::AppendRight(Node*  newNode)
{

    this->right = newNode;

}// AppendRight


// ======================================================================
void Node::AppendLeft(Node*  newNode)
{

    this->left = newNode;

}// AppendLeft


// ======================================================================
// ---------- GETTERS ------------------------

double Node::GetNumber() const
{
	return this->Qthing;		// return the text of current node
}// GetText


// ======================================================================
Node* Node::LChild() const
{
    //assert(this->left != 0);
    return this->left;

}// LChild


// ======================================================================
Node* Node::RChild() const
{
    //assert(this->right != 0);
    return this->right;


}// RChild


// ======================================================================
bool Node::IsLeaf() const
{

    return(this->left == 0 && this->right == 0);

}// IsLeaf

