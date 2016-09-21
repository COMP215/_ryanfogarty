#include "linkedList.h"
linkedList::linkedList()
{
    head = &buffer;
    tail = &buffer;
}
void linkedList::addlastnode(node* new_node)
{
    tail->nextNode = new_node;
    tail = new_node;
}
void linkedList::insertnode(node* first_node, node* new_node)
// inserts new_node between first_node and First_node's nextNode
{
    node* temp = first_node->nextNode;
    first_node->nextNode = new_node;
    new_node->nextNode = temp;
}
bool linkedList::searchNode(string data)
{
    node* p;
    p = this->head;
    while (p != this->tail)
    {
        if (p->data == data)
        {
            cout << "found: " << data << endl;
            return true;
        }
        else{
            p = p->nextNode;
        }
    }
    cout << data << " not found" << endl;
}
/*
int main()
{
    // testing addition to the end with two nodes
    // we're pretending we can't access the nodes directly, so we cycle through with position
    node node1, node2;
    node1.data = "text1";
    node2.data = "text2";
    linkedList theList;
    theList.addlastnode(&node1);
    theList.addlastnode(&node2);
    node* position = theList.head;
    position = position->nextNode;
    cout << position->data << endl;
    position = position->nextNode;
    cout << position->data << endl << endl;
    // testing node insertion between node1 and node2
    // still pretending
    node node3;
    node3.data = "text3";
    position = theList.head;
    position = position->nextNode;
    theList.insertnode(position, &node3);
    position = theList.head;
    position = position->nextNode;
    cout << position->data << endl;
    position = position->nextNode;
    cout << position->data << endl;
    position = position->nextNode;
    cout << position->data << endl;
    return 0;
}
*/
