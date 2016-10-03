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
                cout << "nodeName == temp->name" << endl;
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
    bool doneChecking = false;
    int checkCount = 0;
    int x = 0;
    for (int i = 0; i<theGraph.size();i++)
    {
        while (x<theGraph[i].friends.size() && doneChecking == false)
        {
            checkCount++;
            if (theGraph[i].Name == theGraph[i].friends[x].Name)
            {
                return false;
                cout << "yeep" << endl;
            }
            else{
                cout << theGraph[i].Name << " , " << theGraph[i].friends[x].Name << endl;
                cout << "naap" << endl;
            }
            if (checkCount == numberOfVertices)
            {
                doneChecking == true;
            }
            else if(checkCount == theGraph[i].friends.size())
            {
                i++;
            }
        }
    }
    return true;
}


int main()
{
    /*
    Node firstNode;
    Node secondNode, thirdNode;
    firstNode.Name = "Steve";
    secondNode.Name = "Ryan";
    thirdNode.Name = "jim";
    //Graph myConnections;

    firstNode.addConnection(&secondNode);
    firstNode.addConnection(&thirdNode);
    secondNode.addConnection(&thirdNode);
    thirdNode.addConnection(&firstNode);
    thirdNode.addConnection(&secondNode);
    if (firstNode.areFriends(&secondNode))
    {
        //cout << "connected" << endl;
    };
    if (secondNode.areFriends(&thirdNode))
    {
        //cout << "another one" << endl;
    }
    Graph newGraph;
    newGraph.addToGraph(&firstNode);
    newGraph.addToGraph(&secondNode);
    newGraph.addToGraph(&thirdNode);
    newGraph.printGraph();
    */
    Graph newGraph;
    newGraph.addToGraph("1","2");
    newGraph.addToGraph("1","3");
    newGraph.addToGraph("2","6");
    newGraph.addToGraph("2","8");
    newGraph.addToGraph("3","9");
    newGraph.addToGraph("1","8");
    cout << "graph size " << newGraph.theGraph.size() << endl;
    newGraph.printGraph();
    newGraph.isBipartite();
    //cout << newGraph.theGraph.size();

}
