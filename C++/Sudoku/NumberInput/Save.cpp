#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myFile; 
    
    myFile.open("test.txt");
    
    char **num = new char*[9];
	for(int i=0;i<9;i++){
		num[i] = new char[9];
	}

    for(int z=0;z<9;z++)
    {
        for(int x=0;x<9;x++)
        {
            num[z][x] = '1';
        }
    }

    if(myFile.is_open())
    {
     for(int i=0;i<9;i++)
        {
            for(int n=0;n<9;n++)
            {
                myFile << num[i][n];
            }
        }
    }
    myFile.close();

    return 0;
}