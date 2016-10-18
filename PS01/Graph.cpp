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
    int weight;
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
    void addToGraph(string nodeName, string newConnection, int weight);
    void printGraph();
    bool isBipartite();
    void createGraphDot();
    void minimumSpanningTree();
    int numberOfVertices;
    void KruskalMST();
    vector<Node> minimumTree;
private:
    struct makeGraph
    {
        string vertex;
        vector <string> edges;
        vector <int> weight;
    };
    struct graphSort
    {
        string vertex;
        string edge;
        int weight;

        bool operator() (graphSort i,graphSort j) { return (i.weight<j.weight);}
    }sortPlease;
    vector <makeGraph> to_be_sorted;
    vector <graphSort> sortThis;

};

Graph::Graph()
{
    theGraph = {};
    numberOfVertices = 0;
}

void Graph::addToGraph(string nodeName, string newConnection, int weight)
{
    numberOfVertices++;
    if (theGraph.size() == 0)
    {
        Node* newNode = new Node;
        Node* connectionNode = new Node;
        newNode->Name = nodeName;
        connectionNode->Name = newConnection;
        connectionNode->weight = weight;
        connectionNode->parentNode = newNode;
        newNode->friends.push_back(*connectionNode);
        theGraph.push_back(*newNode);
        connectionNode->friends.push_back(*newNode);
        //cout << connectionNode->friends.size() << " " << endl;
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
                newNode->weight = weight;
                newNode->parentNode = temp;
                temp->friends.push_back(*newNode);
                newNode->friends.push_back(*temp);
                //cout << " " << newNode->friends.size() << endl;
                return;
            }
            else if (i==theGraph.size()-1){
                    Node* newNode = new Node;
                    Node* connectionNode = new Node;
                    newNode->Name = nodeName;
                    connectionNode->Name = newConnection;
                    connectionNode->weight = weight;
                    connectionNode->parentNode = newNode;
                    newNode->friends.push_back(*connectionNode);
                    connectionNode->friends.push_back(*newNode);
                    //cout << "  " << connectionNode->friends.size() << endl;
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

            myfile << "\"" << temp.Name << "\"" <<  " -- " << "\"" << tempNode.Name << "\"" << " [label=" << tempNode.weight << "]" << endl;
            //myfile.close();
            //cout << temp.Name << " -> " << tempNode.Name << endl;

        }
    }
    myfile << "}";
}

void Graph::minimumSpanningTree()
{
    /*This is Kruskals algorithm*/

    for(int i=0; i<theGraph.size(); ++i){
        makeGraph graph;
        Node temp;
        temp = theGraph[i];
        Node lowestWeight = temp.friends[0];
        graph.vertex = temp.Name;
        for(int i=0; i<temp.friends.size();i++)
        {
            Node currentVertice;
            currentVertice = temp.friends[i];
            graph.edges.push_back(currentVertice.Name);
            graph.weight.push_back(currentVertice.weight);
        }
        to_be_sorted.push_back(graph);
    }
    for (int i=0; i<to_be_sorted.size();i++)
    {
        makeGraph currentVertex = to_be_sorted[i];
        for (int i=0;i<currentVertex.edges.size();i++)
        {
            graphSort aConnectionStruct;
            //cout << "edge: " << currentVertex.edges[i] << " weight: " << currentVertex.weight[i] << endl;
            aConnectionStruct.vertex = currentVertex.vertex;
            aConnectionStruct.edge = currentVertex.edges[i];
            aConnectionStruct.weight = currentVertex.weight[i];
            sortThis.push_back(aConnectionStruct);
        }

    }
    sort(sortThis.begin(),sortThis.end(),sortPlease);
    for (int i =0;i<to_be_sorted.size(); i++)
    {
        makeGraph currentVertex = to_be_sorted[i];
        for(int i=0;i<currentVertex.edges.size();i++)
        {
            string edge = currentVertex.edges[i];
            for (int i=0; i<to_be_sorted.size();i++)
            {
                if (to_be_sorted[i].vertex == edge)
                {
                    makeGraph currentVertex2 = to_be_sorted[i];
                    for (int i = 0; i<currentVertex.edges.size();i++)
                    {
                        string currentEdge = currentVertex.edges[i];
                        for(int i = 0; i<currentVertex2.edges.size();i++)
                        {
                            if (currentVertex2.edges[i] == currentEdge)
                            {
                                for(int i = 0; i<sortThis.size();i++)
                                {
                                    if (sortThis[i].vertex == currentVertex.vertex && sortThis[i].edge == currentVertex2.vertex)
                                    {
                                        sortThis.erase(sortThis.begin()+i);
                                    }
                                }
                            }

                        }
                    }


                }
            }
        }
    }



}


void Graph::KruskalMST()
{
    minimumSpanningTree();
    ofstream myfile ( "minimumSpanningTree.txt");
    myfile << "Graph G{" << endl;
    for(int i=0;i<sortThis.size();i++)
    {
        myfile << "\"" << sortThis[i].vertex << "\"" <<  " -- " << "\"" << sortThis[i].edge << "\""   << endl;
    }
    myfile << "}";
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
    newGraph.addToGraph("1","2",18);
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

