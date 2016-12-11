#include <iostream>
#include <vector>
using namespace std;
void printPrimes(int n);
int main()
{
    printPrimes(100);

}

void printPrimes(int n)
{
    vector <int> primes;
    int x = 2;
    for(int i=0;i<n-1;i++)
    {
        primes.push_back(x);
        x++;
    }
    bool primeList = false;
    int multipleTracker = 0;
    bool atLeastOnce;
    int multiple;
    while(primeList == false)
    {
        atLeastOnce = false;
        multiple = primes[multipleTracker];
        for(int i=0;i<primes.size();i++)
        {
            cout << primes[i] << endl;
            if((primes[i]% multiple) == 0)
            {
                atLeastOnce = true;
                if(primes[i]!=multiple){
                    primes.erase(primes.begin()+i);
                    i--;
                }

            }
        }
        if(atLeastOnce == false)
        {
            primeList = true;
        }
        multipleTracker++;

    }
    for(int i=0;i<primes.size();i++)
    {
        cout << primes[i] << endl;
    }

}
