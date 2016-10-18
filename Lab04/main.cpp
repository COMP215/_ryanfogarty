//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//
#include <string>
#include <iostream>
#include <fstream>	// need for file streams
#include <cstdlib>
#include "binarysearchtree.h"
#include "linkedList.h"
//#include "linkedList.cpp"



int main(int argc, const char * argv[]) {

    BinarySearchTree* people_names = new BinarySearchTree();
    ifstream FIN, FOUT;

    string file_name, full_path, line;
    string one_line, file_contents;

    file_name = "foowords.txt";


    full_path = file_name;  //concat folder and filename
    FIN.open( full_path.c_str() ); //open requiresold-style C string
    FOUT.open (full_path.c_str());

    if (FIN.is_open() )
    {
        //cout << "It is open";


        while (std::getline(FIN, one_line))
        {
            people_names->Insert(one_line);
        }


        //FIN.close();
    }
    else{
        cout << "Not open   " << full_path << " not working";
    }




    people_names->InOrder();

    /*
    people_names->Insert("gousie");
    people_names->Insert("bloch");
    people_names->Insert("armstrong");
    people_names->Insert("decoste");
    people_names->Search("gousie");
    people_names->Search("decoste");
    people_names->Search("armstrong");
    people_names->Search("Not there");
    //people_names->Delete("bloch");
    people_names->Search("bloch");
    people_names->Search("armstrong");
    people_names->Search("decoste");
    people_names->InOrder();



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
    theList.searchNode("text1");
    theList.searchNode("text11");

    */
    std::cout << "Hello, World!\n";
    return 0;
}
