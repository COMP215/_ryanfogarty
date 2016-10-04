#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;


class Node{
public:
    Node();
    string Name;
    vector<Node> friends;
    void addConnection(Node* newConnection);
    bool areFriends(Node* node);
};
Node::Node()
{
    Name = "";
    friends = {};
}
void Node::addConnection(Node* newConnection)
{
    friends.push_back(*newConnection);
}
bool Node::areFriends(Node* node)
{
    for(int i=0; i<friends.size(); ++i){
        Node temp = friends[i];
        if (temp.Name == node->Name)
        {
            return true;
        }
    }
}


class Graph{
public:
    Graph();
    vector<Node> theGraph;
    void addToGraph(string nodeName, string newConnection);
    void printGraph();
    bool isBipartite();
    int numberOfVertices;
};

Graph::Graph()
{
    theGraph = {};
    numberOfVertices = 0;
}

void Graph::addToGraph(string nodeName, string newConnection)
{
    numberOfVertices++;
    if (theGraph.size() == 0)
    {
        Node* newNode = new Node;
        Node* connectionNode = new Node;
        newNode->Name = nodeName;
        connectionNode->Name = newConnection;
        newNode->friends.push_back(*connectionNode);
        theGraph.push_back(*newNode);
        cout << "initial push" << endl;
    }
    else{
        for (int i = 0; i<theGraph.size();i++)
        {
            Node* temp;
            temp = &theGraph[i];
            if (nodeName == temp->Name)
            {
                Node* newNode = new Node;
                newNode->Name = newConnection;
                temp->friends.push_back(*newNode);
                return;
            }
            else if (i==theGraph.size()-1){
                    Node* newNode = new Node;
                    Node* connectionNode = new Node;
                    newNode->Name = nodeName;
                    connectionNode->Name = newConnection;
                    newNode->friends.push_back(*connectionNode);
                    theGraph.push_back(*newNode);
                    return;
            }
            else{
                //nothing
            }
        }
    }

}
void Graph::printGraph()
{
    if (theGraph.size() == 0)
    {
        cout << "empty Graph" << endl;
    }
    for(int i=0; i<theGraph.size(); ++i){
        Node temp;
        temp = theGraph[i];
        for(int i=0; i<temp.friends.size();i++)
        {
            Node tempNode;
            tempNode = temp.friends[i];
            cout << temp.Name << " -> " << tempNode.Name << endl;

        }
    }
}
bool Graph::isBipartite()
{

    int x, y;
    x=0;

    for (int i = 0; i<theGraph.size();i++)
    {
        y=0;
        int checkCount = 0;
        while (checkCount != numberOfVertices )
        {
            if (theGraph[i].Name == theGraph[x].friends[y].Name)
            {
                cout << theGraph[i].Name << " and  " << theGraph[x].friends[y].Name << endl;
                return false;
            }

            else{

                //nada
            }
            if(y == theGraph[x].friends.size()-1)
            {
                x++;
                y = -1;
            }
            else{
                //nada
            }
            checkCount++;
            y++;

        }
        x = 0;
    }
    return true;
}


int main()
{

    Graph newGraph;
    newGraph.addToGraph("1","11");
    newGraph.addToGraph("1","10");
    newGraph.addToGraph("2","6");
    newGraph.addToGraph("2","8");
    newGraph.addToGraph("3","9");
    newGraph.addToGraph("1","8");
    cout << "graph size " << newGraph.theGraph.size() << endl;
    newGraph.printGraph();
    if (newGraph.isBipartite())
    {

        cout << "Its bipartite" << endl;
    }
    else{
        cout << "naa mang" << endl;
    }


}
