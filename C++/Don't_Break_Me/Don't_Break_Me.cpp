#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <cmath>
using namespace std;

/*=====prototypes=====*/
void gatherNumbers(char **num); //inputs numbers into a dynamic array 
void display(char **num); //displays the actual puzzle
void displaySelection(char **num, int &xCoord, int &yCoord); //gets keyboard input and moves selection around
void sleep_seconds (const unsigned int sleepMSs) {Sleep(sleepMSs); } //makes everything look better

bool escapePressed = false; //I know this is sloppy, but it works so great....

int main()
{
	/*======== Declarations ========*/
	char **num = new char*[9];
	for(int i=0;i<9;i++){num[i] = new char[9];} //create the dynamic 2D array
	int xCoord = 0; //x coordinate for selection
	int yCoord = 0; //y coordinate for selection
	
	/*====== end declarations ======*/
	
	gatherNumbers(num); //get this started first and out of the way 
	
	

	do
	{
		system("cls");
		display(num);
		displaySelection(num, xCoord, yCoord);
		
	
		//do more stuff
		
		
		
		sleep_seconds(125);
	}while(escapePressed!=true);
	
	
	
	
	
	
	
	
	
	
	
/*======deallocating dynamic array======*/
for(int i = 0; i < 9; ++i){delete [] num[i];}
delete [] num;	
	
return 0;
}



void displaySelection(char **num, int &xCoord, int &yCoord)
{
	
	int val; //value to store key 
	
	val = getch(); //get value for key pressed 
	if(val==27){escapePressed = true;} //can you really not tell what this does?
	
	/*====== Keeping things inside the bounds ======*/
	if((yCoord > 8) && (val==115)){yCoord=0;} //for S key
	if((yCoord <= 1) && (val==119)){yCoord=10;} //for W key
	/*==============================================*/		
	if((xCoord >= 8) && (val==100)){xCoord=-1;} // for D key
	if((xCoord <=1) && (val==97)){xCoord=9;} // for A key
	
	/*====== W key ======*/
	if(val==119) //yCoord
	{
		yCoord--;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				yCoord--;
				if(yCoord < 1){yCoord = 9;}
			}
			while(num[yCoord-1][xCoord]!=' ');
		}
	}	
	/*====== A Key ======*/
	if(val==97)//xCoord
	{
		xCoord--;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				xCoord--;
				
			}
			while(num[yCoord-1][xCoord]!=' ');
		}
	}
	/*====== S Key ======*/
	if(val==115)//yCoord
	{
		
		yCoord++;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				yCoord++;
				if(yCoord > 9){cout<<yCoord;yCoord = 0;}
			}
			while(num[abs(yCoord-1)][xCoord]!=' ');
		}
	}
	/*====== D Key ======*/
	if(val==100)//xCoord
	{
		
		xCoord++;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				xCoord++;
			}
			while(num[yCoord-1][xCoord]!= ' ');
		}
	}
	
	cout<<"X Value: "<<xCoord<<endl;
	cout<<"Y Value: "<<yCoord<<endl;
	num[yCoord-1][xCoord] = 'X';
	
	}


void display(char** num)
{
	//system("cls"); //clear screen first 
	system("Color 70"); //set background to white and text to black
	
	/*=====I'm not going to bother explaining how this bit works=====*/
	cout<<endl;
	cout<<"     " <<"  "<<num[0][0]<<" | "<<num[0][1]<<" | "<<num[0][2]<<" || "<<num[0][3]<<" | "<<num[0][4]<<" | "<<num[0][5]<<" || "<<num[0][6]<<" | "<<num[0][7]<<" | "<<num[0][8]<<" "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  "<<num[1][0]<<" | "<<num[1][1]<<" | "<<num[1][2]<<" || "<<num[1][3]<<" | "<<num[1][4]<<" | "<<num[1][5]<<" || "<<num[1][6]<<" | "<<num[1][7]<<" | "<<num[1][8]<<" "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  "<<num[2][0]<<" | "<<num[2][1]<<" | "<<num[2][2]<<" || "<<num[2][3]<<" | "<<num[2][4]<<" | "<<num[2][5]<<" || "<<num[2][6]<<" | "<<num[2][7]<<" | "<<num[2][8]<<" "<<endl;
	cout<<"      "<<"====================================="<<endl;
	cout<<"     " <<"  "<<num[3][0]<<" | "<<num[3][1]<<" | "<<num[3][2]<<" || "<<num[3][3]<<" | "<<num[3][4]<<" | "<<num[3][5]<<" || "<<num[3][6]<<" | "<<num[3][7]<<" | "<<num[3][8]<<" "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  "<<num[4][0]<<" | "<<num[4][1]<<" | "<<num[4][2]<<" || "<<num[4][3]<<" | "<<num[4][4]<<" | "<<num[4][5]<<" || "<<num[4][6]<<" | "<<num[4][7]<<" | "<<num[4][8]<<" "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  "<<num[5][0]<<" | "<<num[5][1]<<" | "<<num[5][2]<<" || "<<num[5][3]<<" | "<<num[5][4]<<" | "<<num[5][5]<<" || "<<num[5][6]<<" | "<<num[5][7]<<" | "<<num[5][8]<<" "<<endl;
	cout<<"      "<<"====================================="<<endl;
	cout<<"     " <<"  "<<num[6][0]<<" | "<<num[6][1]<<" | "<<num[6][2]<<" || "<<num[6][3]<<" | "<<num[6][4]<<" | "<<num[6][5]<<" || "<<num[6][6]<<" | "<<num[6][7]<<" | "<<num[6][8]<<" "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  "<<num[7][0]<<" | "<<num[7][1]<<" | "<<num[7][2]<<" || "<<num[7][3]<<" | "<<num[7][4]<<" | "<<num[7][5]<<" || "<<num[7][6]<<" | "<<num[7][7]<<" | "<<num[7][8]<<" "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  "<<num[8][0]<<" | "<<num[8][1]<<" | "<<num[8][2]<<" || "<<num[8][3]<<" | "<<num[8][4]<<" | "<<num[8][5]<<" || "<<num[8][6]<<" | "<<num[8][7]<<" | "<<num[8][8]<<" "<<endl;
}

void gatherNumbers(char **num) //reads numbers from a text file and adds them to the array 
{
	//I don't care if this code is slightly broken.. it works..
	
	ifstream myFile; //ifstream object
	
	
	char TempStorage[81]; //temporary storage for reading numbers off of text file
	char maybe; //no clue what this one does
	
	int i=0; //used for temp storage input
	int x=0; //used to copy values to multidimensional array
	
	myFile.open("xs.txt"); //open docurument
	
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
} //end of main


//do more stuff