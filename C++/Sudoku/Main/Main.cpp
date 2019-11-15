#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <vector>
using namespace std;

/*=====prototypes=====*/
void gatherNumbers(char **num); //inputs numbers into a dynamic array 
void display(char **num); //displays the actual puzzle
void displaySelection(char **num, int &xCoord, int &yCoord, vector<int> &prevX, vector<int> &prevY, int &counter, vector<int> &backX, vector<int> &backY); //gets keyboard input and moves selection around
void enterSelection(char** num, int counter, vector<int> &prevX, vector<int> &prevY, int val, int &xCoord, int &yCoord); //function to input user values
bool isValid (char** num, int &xCoord, int &yCoord, char val); //evaluates numbers inputted
void backspacePressed(char** num, vector<int> &backX, vector<int> &backY, int &counter); //used to cycle through avaliable spaces once board fills up

void sleep_seconds (const unsigned int sleepMSs) {Sleep(sleepMSs); } //makes everything look better


bool escapePressed = false; //I know this is sloppy, but it works so great....

int main()
{
	/*======== Declarations ========*/
	char **num = new char*[9];
	for(int i=0;i<9;i++){num[i] = new char[9];} //create the dynamic 2D array
	
	int xCoord = 0; //x coordinate for selection
	int yCoord = 1; //y coordinate for selection
	
	vector<int> prevY;
	vector<int> prevX;

	vector<int> backY;
	vector<int> backX;
	
	int counter = 0; //using this to single out when program is running on its first time
	
	/*====== end declarations ======*/
	
	gatherNumbers(num); //get this started first and out of the way 
	
	

	do
	{
		system("cls");
		display(num);
		displaySelection(num, xCoord, yCoord, prevY, prevX, counter, backX, backY);
		
	
		//do more stuff
		
		
		
		sleep_seconds(450);
	}while(escapePressed != true);
	
	
/*======deallocating dynamic array======*/
for(int i = 0; i < 9; ++i){delete [] num[i];}
delete [] num;	
	
return 0;
}



void displaySelection(char **num, int &xCoord, int &yCoord, vector<int> &prevX, vector<int> &prevY, int &counter, vector<int> &backX, vector<int> &backY)
{
	// this function is huge and could probably be broken up more, but alas, I'm too lazy
	
	// displaySelection is tasked with accepting the num array, x and y coordinates, vectors and counter
	// the function determines the key pressed based on its value returned from the getch() function 
	// it then determines if the selection can be moved to the desired location, and if it cannot,
	// a series of loops determine the closest valid location that an X can be put 
	// next, the function adds previous x and y coordinates to their respective vectors, and 
	// uses the vector along with the counter to determine what the previous x and y coordinates were, 
	// and replaces them with a blank space again
	
	
	int val; //value to store key 
	
	val = getch(); //get value for key pressed 
	if(val==27){escapePressed = true;} //can you really not tell what this does?
	
	/*====== Keeping things inside the bounds ======*/
	if((yCoord > 8) && (val==115)){yCoord=0;} //for S key
	if((yCoord <= 0) && (val==119)){yCoord=10;} //for W key
	/*==============================================*/		
	if((xCoord >= 8) && (val==100)){xCoord=-1;} // for D key
	if((xCoord <=0) && (val==97)){xCoord=9;} // for A key
	
	/*Keys controlling the movement of current selection*/
	
	/*====== W key ======*/
	if((val==119) || (val==87)) //yCoord
	{
		yCoord--;
		
		if(num[yCoord-1][xCoord]!=' ') //if index value isn't a space, keep moving
		{
			do
			{
				yCoord--; 
				if(yCoord < 1){yCoord = 9;} // move yCoord over to the other side if it runs out of room here
			}
			while(num[yCoord-1][xCoord]!=' ');
		}
	}	
	/*====== A Key ======*/
	if((val==97) || (val==65))//xCoord
	{
		xCoord--;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				xCoord--;
				if(xCoord < 0){xCoord = 9;}
				
			}
			while(num[yCoord-1][xCoord]!=' ');
		}
	}
	/*====== S Key ======*/
	if((val==115) || (val==83))//yCoord
	{
		
		yCoord++;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				yCoord++;
				if(yCoord > 9){yCoord = 1;}
			}	
			while(num[abs(yCoord-1)][xCoord]!=' ');
		}
	}
	/*====== D Key ======*/
	if((val==100) || (val==68))//xCoord
	{
		
		xCoord++;
		
		if(num[yCoord-1][xCoord]!=' ')
		{
			do
			{
				xCoord++;
				if(xCoord > 9){xCoord = 0;}
			}
			while(num[yCoord-1][xCoord]!= ' ');
		}
	}
	
	/*===== BackSpace =====*/
	if(val == 8)
	{
		backspacePressed(num, backX, backY, counter);
	}

	cout<<"X Value: "<<xCoord<<endl; //keep these here for now cause they're pretty
	cout<<"Y Value: "<<yCoord<<endl;
	
	num[yCoord-1][xCoord] = 'X'; //set these coordinates to an X 
	
	prevX.push_back(xCoord); //add current Xcoord to end of vector
	prevY.push_back(yCoord); //add current Ycoord to end of vector
	
	if(counter!=0){prevX.erase(prevX.begin());prevY.erase(prevY.begin());}

	if(counter!=0) //only run this after the first run as it will break otherwise
	{
		if(num[(prevY[counter-1])-1][prevX[counter-1]] == 'X') //if previous number is an X 
		{
			num[(prevY[counter-1])-1][prevX[counter-1]] = ' '; //'Make That Space Blank Again!' 
		}
		
	}
	
	if( (val!=119) && (val!=97) && (val!=115) && (val!=100) && (val!=27) && (val!=87) && (val!=65) && (val!=83) && (val!=68) ) //if any key other than WASD is pressed 
	{
		enterSelection(num, counter, prevX, prevY, val, xCoord, yCoord); //input that key into the array 
	}
	
	
	if( (val!=119) && (val!=97) && (val!=115) && (val!=100) && (val!=27) && (val!=49) && (val!=50) && (val!=51) && (val!=52) && (val!=53) && (val!=54) && (val!=55) && (val!=56) && (val!=57) && (val!=27) && (val!=8) && (val!=87) && (val!=65) && (val!=83) && (val!=68) )
	{
		cout<<"Please enter a valid key"<<endl;
	}

	counter++; //increment the counter so it will only equal 0 once
}

void enterSelection(char** num, int counter, vector<int> &prevX, vector<int> &prevY, int val, int &yCoord, int &xCoord)
{
	// this function is called when a number key is pressed, and takes that key 
	// and inputs that key pressed into the 2D array
	
	char retVal; 
	bool canThisWork;
	
	if     (val == 49){num[(prevY[counter-1])-1][prevX[counter-1]] = '1'; retVal = '1';}
	else if(val == 50){num[(prevY[counter-1])-1][prevX[counter-1]] = '2'; retVal = '2';}
	else if(val == 51){num[(prevY[counter-1])-1][prevX[counter-1]] = '3'; retVal = '3';}
	else if(val == 52){num[(prevY[counter-1])-1][prevX[counter-1]] = '4'; retVal = '4';}
	else if(val == 53){num[(prevY[counter-1])-1][prevX[counter-1]] = '5'; retVal = '5';}
	else if(val == 54){num[(prevY[counter-1])-1][prevX[counter-1]] = '6'; retVal = '6';}
	else if(val == 55){num[(prevY[counter-1])-1][prevX[counter-1]] = '7'; retVal = '7';}
	else if(val == 56){num[(prevY[counter-1])-1][prevX[counter-1]] = '8'; retVal = '8';}
	else if(val == 57){num[(prevY[counter-1])-1][prevX[counter-1]] = '9'; retVal = '9';}
	else{cout<<"Please enter a valid key"<<endl; val = getch();}
	
	canThisWork = isValid(num, xCoord, yCoord, retVal); //call this bool function and assign the value to the variable
	
	if(canThisWork == false){ num[(prevY[counter-1])-1][prevX[counter-1]] = 'X'; system("cls");}
}

bool isValid (char** num, int &xCoord, int &yCoord, char val)
{
	//function to determine if the inputted number is valid 
	// will use nested for loops to check if there are any other numbers 
	// will check all values of yCoord and xCoord to determine if there is exactly one of these numbers
	
	//val is the char that is returned when a key is pressed 

	bool first = false; //sum of numbers that match val 
	bool second = false; //sum of numbers that match val
	
	int actualY = xCoord;
	int actualX = yCoord;
	
	int firstTrues = 0;
	int secondTrues = 0;
	
		for(int s=0;s<9;s++)
		{
			if(num[s][actualX] == val)
			{
				firstTrues++;
			}
		}
		
	if(firstTrues > 1){first=true;}
		
		for(int y=1;y<10;y++)
		{
			if(num[actualY-1][y] == val)
			{
				secondTrues++;
			}
		}
		
	if(secondTrues > 1){second = true;}
	
	if((first == false) && (second == false)) {return true;}
	
	else {return false;}
}

void backspacePressed(char** num, vector<int> &backX, vector<int> &backY, int &counter)
{
	int x = 0;
	int y = 1;
	
	bool canThisWork = false;
	
	do
	{
		if(num[y-1][x] == ' '){canThisWork = true; }
		
		else {x++;}
		
		if(x > 9){y++; x = 0;}
		
	}while(canThisWork == false);

	num[y-1][x] = 'X';
	
	backX.push_back(x);
	backY.push_back(y);

	if(num[(backY[counter-1])-1][backX[counter-1]] == 'X') //if previous number is an X 
		{
			num[(backY[counter-1])-1][backX[counter-1]] = ' '; //'Make That Space Blank Again!' 
		}
}

void clearExtras(char** num, int xCoord, int yCoord)
{

}

void display(char** num)
{
	// this function displays the body of the sudoku, along with the values stored inside the multidimensional array,
	// and arranges them into a proper looking sudoku
	
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
} //end of main


//do more stuff... hopefully..?