#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int i;
	cout<<"Hello";
	cin>>i;
if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
{
   cout<<"Hello World!";
}

return 0;
}