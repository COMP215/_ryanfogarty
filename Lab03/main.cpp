#include "Tree.h"
#include <iostream>
using namespace std;

void printInorder(Node* node);

int main()
{
    Node* p;
    Tree T(15);



    double newNumber;
    cout << "enter a new number. " << endl;
    cin >> newNumber;
    do
    {

        p = T.GetRoot();
        Node* lessThan, *greaterThan;
        while(newNumber < p->GetNumber())
        {

            Node* left = p->LChild();
            if(left == 0)
            {
                cout << "left appended: " << newNumber;
                lessThan = new Node(newNumber);
                p->AppendLeft(lessThan);


            }
            else
            {
                //cout << "moving down left" << endl;
                p = p->LChild();
            }
        }
        while(newNumber > p->GetNumber())
        {
            Node* right = p->RChild();
            if(right == 0)
            {
                cout << "right appended : " << newNumber;
                greaterThan = new Node(newNumber);
                p->AppendRight(greaterThan);

            }
            else
            {
                p = p->RChild();
                //cout << "moving down right" << endl;
            }
        }

            cout << "enter a new number. (enter '000' to stop entering numbers) " << endl;
            cin >> newNumber;


    } while (newNumber != 000);
    cout << "numbers in order..." << endl;
    printInorder(T.GetRoot());

}

void printInorder(Node* node)
{

     if (node == NULL)
          return;


     printInorder(node->LChild());


     cout << node->GetNumber() << endl;

     printInorder(node->RChild());
}
