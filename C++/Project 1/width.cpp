#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream myFile; // declare ifstream object
    myFile.open("Peik_Hall_University_of_Minnesota_5-tiny.ppm"); //open file
    string reader;

    string type;
    string height;
    string width;

    if (myFile.is_open()) // check to see if file is open
    {
        int counter = 1;
        while (counter < 4) // read from file into string, reader
        {
            myFile >> reader;
            
            if(counter == 1)
            {
                type = reader;
            }
            if(counter == 2)
            {
                width = reader;
            }
            if(counter == 3)
            {
                height = reader;
            }

            counter++;
        }

        cout<<"Type is: "<<type<<endl;
        cout<<"Height is: "<<height<<endl;
        cout<<"Width is: "<<width<<endl;
    }

    return 0;
}