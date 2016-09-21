#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include<algorithm>
#include <string>

using namespace std;
string CreateString(int max_size_of_string, int& size_of_array);
void StringSorter(string& name_of_file, int number_of_strings);
int main()
{


    int size_of_array = 0;
    int number_of_strings = 150000;

    srand ( time(NULL) );
    ofstream string_store_1, string_store_2, string_store_3;
    string_store_1.open ("stringstore1.txt");
    string_store_2.open("stringstore2.txt");
    string_store_3.open("stringstore3.txt");
    for (int i=0;i<number_of_strings;i++){
        string new_string = CreateString(10,size_of_array);
        for (int i=0; i<size_of_array; i++)
        {
            string_store_1 << new_string[i];
        }
        string_store_1 << "\n";
    }

    string_store_1.close();
    string name_of_file = "stringstore1.txt";
    StringSorter(name_of_file,number_of_strings);

    for (int i=0;i<number_of_strings;i++){
        string new_string = CreateString(10,size_of_array);
        for (int i=0; i<size_of_array; i++)
        {
            string_store_2 << new_string[i];
        }
        string_store_2 << "\n";
    }
    string_store_2.close();
    name_of_file = "stringstore2.txt";
    StringSorter(name_of_file ,number_of_strings);

    for (int i=0;i<number_of_strings;i++){
        string new_string = CreateString(10,size_of_array);
        for (int i=0; i<size_of_array; i++)
        {
            string_store_3 << new_string[i];
        }
        string_store_3 << "\n";
    }
    string_store_3.close();
    name_of_file = "stringstore3.txt";
    StringSorter(name_of_file,number_of_strings);



    return 0;


}

string CreateString(int max_size_of_string, int& size_of_array)
{

   char the_letters[26] =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   int size_of_string = rand() % max_size_of_string + 1;
   //cout << sizeOfString << "is the Size of the string" << endl;
   char *p;
   char random_string[size_of_string];
   p = random_string;
   size_of_array = size_of_string;
   int i = 0;
   while (i < size_of_string)
   {
    int rand_num = rand() % 26;
    //cout << randNumb << "is rand number" << endl;
    //cout << theLetters[randNumb] << endl;
    p[i] = the_letters[rand_num];
    i++;
   }
   for (i = 0; i<size_of_string; i++)
   {
       cout << p[i];
   }
   cout << endl;
   return p;



}

void StringSorter(string& name_of_file, int number_of_strings)
{
    cout << "now sorting..." << endl;
    ifstream FIN, FOUT;

    string file_name, full_path;

    file_name = name_of_file;

    string sort_array[number_of_strings]; //array used to store strings read in

    full_path = file_name;  //concat folder and filename
    FIN.open( full_path.c_str() ); //open requiresold-style C string
    FOUT.open (full_path.c_str());

    if (FIN.is_open() )
    {
        //cout << "It is open";

        string one_line;
        for (int i=0; i<number_of_strings;i++){
            getline(FIN, one_line);  //read one line from FIN stream
            //cout << oneLine << endl;
            sort_array[i] = one_line;

        }
        //FIN.close();
    }
    else{
        cout << "Not open   " << full_path << " not working";
    }

    sort(sort_array,sort_array + number_of_strings);
    ofstream string_store_1;
    string_store_1.open(name_of_file.c_str());
    for (int i=0; i<number_of_strings;i++){
        cout << sort_array[i] << endl;
        string_store_1 << sort_array[i] << "\n";

    }


}





