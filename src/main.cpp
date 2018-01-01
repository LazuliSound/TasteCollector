/*
 * main.cpp
 *
 *  Created on: 1 Jan 2018
 *      Author: user
 */
#include <iostream>
#include <windows.h>
using namespace std;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSW wc = {0};

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursorA(NULL,IDC_ARROW);
	wc.hInstance = hInstance;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if(!RegisterClassW(&wc)){
		cout << "Error:Window Class Registration Failed";
		return -1;
	}

	CreateWindowW(L"MyWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0,0,500,500,NULL,NULL,NULL,NULL);


	MSG msg = {0};
	while(GetMessage(&msg,NULL,NULL,NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProcW(hWnd,msg,wp,lp));
	}
	return 0;
}
