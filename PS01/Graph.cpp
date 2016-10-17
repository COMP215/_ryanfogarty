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
    int connectionStrength;
    Node* parentNode;
    bool checked;
    string MSTname;
};
Node::Node()
{
    Name = "";
    friends = {};
    parentNode = NULL;
    checked = false;
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
    void addToGraph(string nodeName, string newConnection, int connectionStrength);
    void printGraph();
    bool isBipartite();
    void createGraphDot();
    void minimumSpanningTree();
    int numberOfVertices;
    void KruskalMST();
    vector<Node> minimumTree;

};

Graph::Graph()
{
    theGraph = {};
    numberOfVertices = 0;
}

void Graph::addToGraph(string nodeName, string newConnection, int connectionStrength)
{
    numberOfVertices++;
    if (theGraph.size() == 0)
    {
        Node* newNode = new Node;
        Node* connectionNode = new Node;
        newNode->Name = nodeName;
        connectionNode->Name = newConnection;
        connectionNode->connectionStrength = connectionStrength;
        connectionNode->parentNode = newNode;
        newNode->friends.push_back(*connectionNode);
        theGraph.push_back(*newNode);
        connectionNode->friends.push_back(*newNode);
        cout << connectionNode->friends.size() << " " << endl;
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
                newNode->connectionStrength = connectionStrength;
                newNode->parentNode = temp;
                temp->friends.push_back(*newNode);
                newNode->friends.push_back(*temp);
                cout << " " << newNode->friends.size() << endl;
                return;
            }
            else if (i==theGraph.size()-1){
                    Node* newNode = new Node;
                    Node* connectionNode = new Node;
                    newNode->Name = nodeName;
                    connectionNode->Name = newConnection;
                    connectionNode->connectionStrength = connectionStrength;
                    connectionNode->parentNode = newNode;
                    newNode->friends.push_back(*connectionNode);
                    connectionNode->friends.push_back(*newNode);
                    cout << "  " << connectionNode->friends.size() << endl;
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
                //cout << theGraph[i].Name << " and  " << theGraph[x].friends[y].Name << endl;
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
void Graph::createGraphDot()
{
    ofstream myfile ( "dotGraph.txt");
    //myfile.open ("dotGraph.txt");
    if (theGraph.size() == 0)
    {
        cout << "empty Graph" << endl;
    }
    myfile << "Graph G{" << endl;
    for(int i=0; i<theGraph.size(); ++i){
        Node temp;
        temp = theGraph[i];
        for(int i=0; i<temp.friends.size();i++)
        {
            Node tempNode;
            tempNode = temp.friends[i];

            myfile << "\"" << temp.Name << "\"" <<  " -- " << "\"" << tempNode.Name << "\"" << " [label=" << tempNode.connectionStrength << "]" << endl;
            //myfile.close();
            //cout << temp.Name << " -> " << tempNode.Name << endl;

        }
    }
    myfile << "}";
}

void Graph::minimumSpanningTree()
{
    for(int i=0; i<theGraph.size(); ++i){
        Node temp;
        temp = theGraph[i];
        Node lowestWeight = temp.friends[0];
        //cout << " " << temp.Name << endl;
        for(int i=0; i<temp.friends.size();i++)
        {
            Node currentVertice;
            currentVertice = temp.friends[i];
            //cout << currentVertice.friends.size() << "Fish" << endl;
            for(int i = 0; i<currentVertice.friends.size(); i++)
            {
                cout << currentVertice.connectionStrength << " < " << lowestWeight.connectionStrength << endl;

                if (currentVertice.connectionStrength < lowestWeight.connectionStrength  )
                {
                    lowestWeight = temp.friends[i];
                    //temp.friends[i].checked = true;

                    //cout << lowestWeight.connectionStrength << endl;
                }
                else
                {
                    //nada
                }

                //cout << " " << currentVertice.friends[i].connectionStrength << endl;
            }
            Node* addToMST = new Node;
            addToMST->Name = temp.Name;
            addToMST->MSTname = lowestWeight.Name;
            minimumTree.push_back(*addToMST);

        }



    }


}


void Graph::KruskalMST()
{
    minimumSpanningTree();
    ofstream myfile ( "minimumSpanningTree.txt");
    myfile << "Graph G{" << endl;
    for(int i=0;i<minimumTree.size();i++)
    {
        myfile << "\"" << minimumTree[i].Name << "\"" <<  " -- " << "\"" << minimumTree[i].MSTname << "\""   << endl;
    }
}
int main()
{

    Graph newGraph;
    newGraph.addToGraph("1","11",14);
    newGraph.addToGraph("1","10",9);
    newGraph.addToGraph("2","6",4);
    newGraph.addToGraph("2","8",3);
    newGraph.addToGraph("3","9",1);
    newGraph.addToGraph("1","8",0);
    newGraph.addToGraph("10","8",8);
    cout << "graph size " << newGraph.theGraph.size() << endl;
    newGraph.printGraph();
    if (newGraph.isBipartite())
    {

        cout << "Its bipartite" << endl;
    }
    else{
        cout << "naa mang" << endl;
    }
    newGraph.createGraphDot();
    newGraph.KruskalMST();

    return 0;
}

