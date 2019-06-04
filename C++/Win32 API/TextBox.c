#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdSho)
{
	MessageBox(NULL, "Hello World!", "Handy Dandy Box", MB_OK);
	return 0;
}
/*
int main()
{
	printf("Hello World!");
	
	return 0;
}
*/