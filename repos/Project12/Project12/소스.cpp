#include <windows.h>
#include <TCHAR.H>
#include "resource.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgEx6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hInst;
BOOL first = TRUE;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND 	hwnd;
	MSG 	msg;
	WNDCLASS	WndClass;
	hInst = hInstance;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("Window Title Name"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_MENU:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgEx6_1Proc);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
void RollingBall(HWND hwnd)
{
	static POINT pt = { 20,20 }, oldpt = { 0,0 };
	static RECT rect;
	static int stepX = 10, stepY = 10;
	HDC hdc;
	GetClientRect(hwnd, &rect);
	hdc = GetDC(hwnd);
	SetROP2(hdc, R2_XORPEN);
	SelectObject(hdc, GetStockObject(WHITE_PEN));
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
	if (!first)
		Ellipse(hdc, oldpt.x - 20, oldpt.y - 20, oldpt.x + 20, oldpt.y + 20);
	else
		first = FALSE;
	pt.x = pt.x + stepX;
	if (pt.x + 20 > rect.right || pt.x - 20 < 0)
	{
		pt.x = pt.x - stepX;
		stepX = -1 * stepX;
	}
	pt.y = pt.y + stepY;
	if (pt.y + 20 > rect.bottom || pt.y - 20 < 0)
	{
		pt.y = pt.y - stepY;
		stepY = -1 * stepY;
	}
	Ellipse(hdc, pt.x - 20, pt.y - 20, pt.x + 20, pt.y + 20);
	oldpt = pt;
	ReleaseDC(hwnd, hdc);
}
BOOL CALLBACK DlgEx6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton;
	switch (iMsg)
	{
	case WM_INITDIALOG:
		hButton = GetDlgItem(hDlg, IDPAUSE);
		EnableWindow(hButton, FALSE);
		first = TRUE;
		return 1;
	case WM_TIMER:
		RollingBall(hDlg);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDSTART:
			hButton = GetDlgItem(hDlg, IDSTART);
			EnableWindow(hButton, FALSE);
			hButton = GetDlgItem(hDlg, IDPAUSE);
			EnableWindow(hButton, TRUE);
			SetTimer(hDlg, 1, 50, NULL);
			return 0;
		case IDPAUSE:
			hButton = GetDlgItem(hDlg, IDSTART);
			EnableWindow(hButton, TRUE);
			hButton = GetDlgItem(hDlg, IDPAUSE);
			EnableWindow(hButton, FALSE);
			KillTimer(hDlg, 1);
			return 0;
		case IDCLOSE:
			EndDialog(hDlg, 0);
			return 0;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return 0;
}