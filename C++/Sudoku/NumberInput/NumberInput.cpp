#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	ifstream myFile; //ifstream object
	
	int num[9][9];
	int TempStorage[81]; //temporary storage for reading numbers off of text file
	int maybe; //no clue what this one does
	
	int i=0; //used for temp storage input
	int x=0; //used to copy values to multidimensional array
	
	char doCopy;
	
	
	myFile.open("numbers.txt"); //open docurument
	
	if(myFile.is_open()) //check if document is open
	{
		while(myFile >> maybe) //while numbers are still on document
		{
			TempStorage[i] = maybe; //input numbers into temporary array
			i++; //index 
		}
		myFile.close(); //close document
	
		for(int n=0;n<9;n++) //first loop to control first index n
		{
			for(int q=0;q<9;q++) //second loop to control second index q		
			{
				num[n][q] = TempStorage[x]; //read numbers from temporary storage 
				x++; //increment x
			}
		}
	}
	
	else{cout<<"Error opening file"<<endl;} //in case file doesn't open
	
	for(int a=0;a<9;a++)
	{
		for(int s=0;s<9;s++)
		{
			doCopy = num[a][s];
			cout<<doCopy<<" ";
			//if(copy=='0'){array[a][s]='x';}
			//else{array[a][s] = copy;}
		}
	}
	
	/*cout<<array[0][0]<<" "<<array[0][1]<<" "<<array[0][2]<<" "<<array[0][3]<<" "<<array[0][4]<<" "<<array[0][5]<<" "<<array[0][6]<<" "<<array[0][7]<<" "<<array[0][8]<<endl;
	*/
	return 0;
}	