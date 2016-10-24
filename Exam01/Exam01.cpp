#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;



class Mushrooms{
public:
    Mushrooms();
    string common_name;
    string scientific_name;
    int quantity;
    int price;
    int price_per_ounce;
    void find_price_per_ounce();
    bool operator() (Mushrooms i,Mushrooms j) { return (i.price_per_ounce>j.price_per_ounce);}


}mush_rooms;
Mushrooms::Mushrooms()
{
    price = 0;
    quantity = 0;
}
void Mushrooms::find_price_per_ounce()
{
    price_per_ounce = price/quantity;
}

vector<Mushrooms> the_market;




int main()
{
    int basket_size = 30; //ounces basket will fit
    ifstream fin;
    string inFile;
    string line;
    fin.clear();
    inFile = "mushrooms_2.csv";
    fin.open( inFile.c_str() );
    if ( fin.fail() )				// but did the attempt to open fail?
	{
		cout << "ERROR: file did NOT open." << endl;

	} // if
	int line_count = 0;
	while (line_count < 4)
    {
        getline(fin,line,',');
        //cout << line << "NO" <<endl;
        line_count++;
    }
    line_count = 0;
    Mushrooms* new_mushroom = new Mushrooms;
    while(getline(fin,line,','))
    {

        if (line_count == 0)
        {
            new_mushroom->common_name = line;
            line_count++;

        }
        else if(line_count == 1)
        {
            new_mushroom->scientific_name = line;
            line_count++;

        }
        else if(line_count == 2)
        {
            int int_line = atoi( line.c_str() );
            new_mushroom->quantity = int_line;
            line_count++;
        }
        else{
            int int_line = atoi( line.c_str() );
            new_mushroom->price = int_line;
            new_mushroom->find_price_per_ounce();
            the_market.push_back(*new_mushroom);
            Mushrooms* new_mushroom = new Mushrooms;
            line_count = 0;

        }
    }

    for (int i=0; i<the_market.size();i++)
    {
        //cout << "in" << endl;
        //cout << the_market[i].common_name << endl;
    }

    sort(the_market.begin(),the_market.end(),mush_rooms);  //sort by price per ounce
        for (int i=0; i<the_market.size();i++)
    {
        //cout << "in" << endl;
        //cout << the_market[i].common_name << endl;
    }
    int current_basket_size = 0;
    int i = 0;    //to iterate through the_market vector (which is now sorted)
    bool keep_going = true;
    int total_value = 0;
    while (keep_going)
    {
        Mushrooms current_mushroom = the_market[i];
        if (current_mushroom.quantity < (basket_size-current_basket_size))
        {
            cout << current_mushroom.quantity << " ounces of " << current_mushroom.common_name << "(" <<
            current_mushroom.scientific_name << ") mushrooms" << endl;
            current_basket_size = current_basket_size + current_mushroom.quantity;
            total_value = total_value + current_mushroom.price;

        }
        else{
            int fill_remaining_space;
            fill_remaining_space = (basket_size - current_basket_size);
            current_basket_size = current_basket_size + fill_remaining_space;
            total_value = total_value + (current_mushroom.price_per_ounce* fill_remaining_space);
            cout << fill_remaining_space << " ounces of " << current_mushroom.common_name << "(" <<
            current_mushroom.scientific_name << ") mushrooms" << endl;
        }
        i++;
        if (i==the_market.size() || current_basket_size >= basket_size)
        {
            keep_going = false;
        }
    }
    cout << "-----------------------------------------" << endl;
    cout << "total price: " << total_value << ".00" << endl;


    return 0;
}
