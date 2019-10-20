
// WinMain의 SAL 사용 관련 경고제거
#pragma warning(disable : 28251)

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

namespace myStd{
	using std::string;
	using std::wstring;
	using std::vector;
}

LRESULT
CALLBACK
WinProc(HWND hWnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam)		
{
	switch(msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		MessageBoxW(NULL, L"quit", L"quiting", MB_OK);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int
CALLBACK
WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int iCmdLine)
{
	myStd::vector<int> vec;
	//HINSTANCE hInstance = GetModuleHandle(NULL);
	myStd::wstring className(L"FIRST CLASS");

	WNDCLASSEXW wndClass      = {0};
	wndClass.lpfnWndProc     = WinProc;
	wndClass.lpszClassName   = className.c_str();
	wndClass.cbSize          = sizeof(wndClass);
	wndClass.style           = CS_OWNDC;
	wndClass.cbWndExtra      = 0;
	wndClass.hInstance       = GetModuleHandle(NULL);
	wndClass.hIcon           = nullptr;
	wndClass.hbrBackground   = nullptr;
	wndClass.hCursor         = nullptr;
	wndClass.lpszMenuName    = nullptr;
	wndClass.hIconSm         = nullptr;

	RegisterClassExW(&wndClass);
	HWND hWnd = CreateWindowExW(0,
							   className.c_str(),
							   L"Happy Window",
							   WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
							   200, 200, 640, 480,
							   nullptr, nullptr, hInstance, nullptr);

	MSG msg;
	BOOL bRes;

	ShowWindow(hWnd, SW_SHOW);

	do{
		
		bRes = GetMessage(&msg, nullptr, NULL, NULL);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		
		
	}while(bRes > 0);
	
	return msg.wParam;
}

