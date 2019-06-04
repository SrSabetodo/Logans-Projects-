#include <windows.h>
#include "WindowsBaseClass.h"
	
	//step 2: creating the window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"This is a new window",
		WS_OVERLAPPEDWINDOW,
		500, 250, 600, 600,
		NULL, NULL, hInstance, NULL);
		
		if(hwnd == NULL)
		{
			MessageBox(NULL, "Window creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
			return 0;
		}
		
		ShowWindow(hwnd, nCmdShow);
		UpdateWindow(hwnd);
		
		//step 3: The message loop
		while(GetMessage(&Msg, NULL, 0,0) > 0)
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		return Msg.wParam;
}