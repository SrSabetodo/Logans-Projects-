#include <iostream>
#include <fstream>
using namespace std;

void readNumbers(char** num);


int main()
{
    char **num = new char*[9];
	for(int i=0;i<9;i++){num[i] = new char[9];} //dynamically allocate an array

    readNumbers(num);




    return 0;
}

void readNumbers(char** num) //read numbers from a user inputted text file
{
    	// this function reads 81 numbers off of a text file, and intreprets the 0s into blank spaces 
	// and adds them into the array
	
	ifstream myFile; //ifstream object
	
	
	char TempStorage[81]; //temporary storage for reading numbers off of text file
	char maybe; //no clue what this one does
	
	int i=0; //used for temp storage input
	int x=0; //used to copy values to multidimensional array
	
	myFile.open("numbers.txt"); //open docurument
	
	if(myFile.is_open()) //check if document is open
	{
		while(myFile >> maybe) //while numbers are still on document
		{
			TempStorage[i] = maybe; //input numbers into temporary array
			i++; //index by one
		}
		myFile.close(); //close document
	
		for(int n=0;n<9;n++) //first loop to control first index n
		{
			for(int q=0;q<9;q++) //second loop to control second index q		
			{
				num[n][q] = TempStorage[x]; //read numbers from temporary storage 
				if(TempStorage[x]=='0'){num[n][q]=' ';} //if number read is a zero, it will be translated into a empty space
				x++; //increment x
			}
		}
	}
	else{cout<<"Error opening file"<<endl;} //in case file doesn't open
}