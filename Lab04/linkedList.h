#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;
class node
{
    public:
        string data;
        node* nextNode = 0;
};
class linkedList
{
    public:
        linkedList();
        node buffer;
        node* head;
        node* tail;
        void addlastnode(node*);
        void insertnode(node*, node*);
        bool searchNode(string data);
};

#endif // LINKEDLIST_H_INCLUDED
