#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char key;
	int val;
	
	cout<<"Press Key: ";
	
	while(1)
	{
		key=getch();
		val=key;
		
		cout<<"Key entered is: "<<key<<endl;
		cout<<"Value = "<<val<<endl;
		cout<<endl;
		
		if(val==27){break;}
		
	}
	
	return 0;
}