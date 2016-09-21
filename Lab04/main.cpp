//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//
#include <string>
#include <iostream>
#include "binarysearchtree.h"



int main(int argc, const char * argv[]) {

    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("bloch");
    people_names->Insert("armstrong");
    people_names->Insert("decoste");
    people_names->Search("gousie");
    people_names->Search("decoste");
    people_names->Search("armstrong");
    people_names->Search("Not there");
    people_names->Delete("bloch");
    people_names->Search("bloch");
    people_names->Search("armstrong");
    people_names->Search("decoste");


    std::cout << "Hello, World!\n";
    return 0;
}
