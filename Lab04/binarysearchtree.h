#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED


#include <stdio.h>
#include <string>

class Node {
public:
    std::string data_;
    Node* left_;
    Node* right_;

public:
    Node(std::string);
};


class BinarySearchTree {


public:
    BinarySearchTree();
    bool Insert(std::string);
    bool Search(std::string);
    bool Delete(std::string);

private:
    Node* root_;
    Node* WhereInTree;
    bool RecursiveSearch(Node* root_, std::string name );
};



#endif // BINARYSEARCHTREE_H_INCLUDED
