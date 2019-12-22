#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
using namespace std;

void sleep_seconds (const unsigned int sleepMSs) {Sleep(sleepMSs); }

int main()
{
    srand (time(NULL));

   while(true)
   {
    int p;
    p = rand() % 173 + 1;
   
    int z; 
    z = rand() % 173 + 1;

    do
    {
        if(z<p)
        {
        z = rand() % 173 + 1;
        }
    }
    while(p>z);


    while(p<z)
    {
        for(int i = 0;i<p;i++)
        {
            cout<<"_";
         }
        if(p!=172){cout<<endl;}
        p++;
    }
/*=============================================*/
   int x; //same as p
    x = rand() % 173 + 1;
   int c; //same as z
    c = rand() % 173 + 1;

    do
    {
        if(c>x)
        {
            c = rand() % 173 + 1;
        }
    }
    while(c>x);

    while(x>c)
    {

        for(int i = 0; i<x; i++)
        {     
            cout<<"_";
        }
         cout<<endl;
         x--;
    }
   
   }

}