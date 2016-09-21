

#ifndef NODE
#define NODE

//#include "constants.h"

class Node
{
  public:
	Node();				// default CTOR
	Node(double);		// CTOR when string is known

	Node(const Node&);  // COPY CTOR

	~Node();			// DTOR

    // ---------- SETTERS ------------------------
	void StoreNumber(const double /*in*/ newNumber);
	//..........................................
	// PRE:   newText is a valid string
	// POST:  node contains the string in it

	void AppendRight(Node* /*in*/ newNode);
	//..........................................
	// PRE: Assigned(newNode)
	// POST: this-> node has a new right child


	void AppendLeft(Node* /*in*/ newNode);
	//..........................................
	// PRE: Assigned(newNode)
	// POST: this-> node has a new left child



	// ---------- GETTERS ------------------------
	double GetNumber() const;
	//..........................................
	// POST: RETURN == string in current node

	Node* LChild() const;
	//..........................................
	// PRE: this != NULL
	// POST: RETURN == pointer to left node

	Node* RChild() const;
	//..........................................
	// PRE: this != NULL
	// POST: RETURN == pointer to right node


	// ---------- QUERIES ------------------------
	bool IsLeaf() const;
	//..........................................
	// PRE: this != NULL
	// POST: RETURN T/F whether or not this-> is a leaf node


  private:
	 Node* left;	// pointer to a left  child node
	 Node* right;	// pointer to a right child node

	 double Qthing;	// question at a node OR if a leaf node the name of an object

}; // class Node


#endif






