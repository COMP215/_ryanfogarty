//
//  binarysearchtree.cpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include "binarysearchtree.h"
#include <string>
#include <iostream>
using namespace std;

Node::Node(string data) {
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
    WhereInTree = NULL;

}

bool BinarySearchTree::Insert(string data) {
    if (root_ == NULL) {
        // Empty tree, make a root
        root_ = new Node(data);
        return true;
    } else {
        // Non-empty tree, find correct position for data
        Node* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, fail to insert
                return false;
            } else if (data < curr->data_) {
                // Lexicographically lesser, find location to the left
                if (curr->left_ == NULL) {
                    curr->left_ = new Node(data);
                    cout << "inserting: " << data << endl;
                    return true;
                } else {
                    curr = curr->left_;
                }
            } else {
                // Lexicographically greater, find location to the right
                if (curr->right_ == NULL) {
                    curr->right_ = new Node(data);
                    cout << "inserting: " << data << endl;
                    return true;
                } else {
                    curr = curr->right_;
                }
            }
        }
    }
    return false;
}
bool BinarySearchTree::Search(string name)
{
    if(RecursiveSearch(this->root_,name) == true)
    {
        //cout << "found: " << name << endl;
        return true;
    }
    else{
        //cout << "could not find: " << name << endl;
        return false;
    }
}
bool BinarySearchTree::RecursiveSearch(Node* root_, const string name)
{
    if (root_ == NULL)
       return false;
   else
      {
         if (root_->data_ == name){
             this->WhereInTree = root_;
             return true;
         }
         else{
                if(name < root_->data_){
                    return RecursiveSearch(root_->left_, name);

                }
                else {
                    return RecursiveSearch(root_->right_, name);

                }


         }
      }
}
void BinarySearchTree::InOrder()
{
    InOrder(this->root_);
}
void BinarySearchTree::InOrder(Node* root_)
{
    if(root_->left_ != NULL){
        InOrder(root_->left_);
    }
    cout << root_->data_ << endl;
    if (root_->right_ != NULL){
        InOrder(root_->right_);
    }

}

bool BinarySearchTree::Delete(string name)
{
    string DELETE;
    DELETE = "";
    Search(name);
    cout << "deleting: " << name << endl;
    //WhereInTree->data_ = DELETE;
    delete WhereInTree;
}

