#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	ifstream myFile; //ifstream object
	
	/*====== for some reason this somehow works=====*/
	char **num = new char*[9];
	for(int i=0;i<9;i++){
		num[i] = new char[9];
	}
	
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
	
	for(int i = 0; i < 9; ++i) {
    delete [] num[i];
	}
	delete [] num;
	
	return 0;
}	