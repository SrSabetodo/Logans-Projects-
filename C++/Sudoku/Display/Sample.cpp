#include <iostream>
#include <windows.h>
using namespace std;

/*
Handy colors for system function

0 = Black   8 = Gray
1 = Blue    9 = Light Blue
2 = Green   A = Light Green
3 = Aqua    B = Light Aqua
4 = Red     C = Light Red
5 = Purple  D = Light Purple
6 = Yellow  E = Light Yellow
7 = White   F = Bright White
*/

int main()
{
	char space=' ';
	
	system("Color 70");
	cout<<endl;
	cout<<"     " <<"  A | B | C || A | B | C || A | B | C "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  D | E | F || D | E | F || D | E | F "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  G | H | I || G | H | I || G | H | I "<<endl;
	cout<<"      "<<"====================================="<<endl;
	cout<<"     " <<"  J | K | L || J | K | L || J | K | L "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  M | N | O || M | N | O || M | N | O "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  P | Q | R || P | Q | R || P | Q | R "<<endl;
	cout<<"      "<<"====================================="<<endl;
	cout<<"     " <<"  S | T | U || S | T | U || S | T | U "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  V | W | X || V | W | X || V | W | X "<<endl;
	cout<<"      "<<"_____________________________________"<<endl;
	cout<<"     " <<"  Y | Z | Z || Y | Z | Z || Y | Z | Z "<<endl;
	
	cin>>space;
	
return 0;	
}