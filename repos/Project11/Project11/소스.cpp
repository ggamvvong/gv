#include <Windows.h>
#include <TCHAR.H>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM IParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)

{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"), _T("Window Title Name"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
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
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rect[4] = { {200,0,300,100},{100,100,200,200},{300,100,400,200},{200,200,300,300} };
	static char text[4][10] = { {"UP"},{"LEFT"},{"RIGHT"},{"DOWN"} };
	static int count, select = -1;
	HBRUSH hBrush, oldBrush;

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (count = 0; count < 4; count++)
		{
			Rectangle(hdc, rect[count].left, rect[count].top, rect[count].right, rect[count].bottom);
			DrawText(hdc, text[count], strlen(text[count]), &rect[count], DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, rect[count].left, rect[count].top, rect[count].right, rect[count].bottom);
		DrawText(hdc, text[count], strlen(text[count]), &rect[count], DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		SelectObject(hdc, oldBrush);
		DeleteObject(hBrush);
		EndPaint(hwnd, &ps);
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			select = 0;
			break;
		case VK_LEFT:
			select = 1;
			break;
		case VK_RIGHT:
			select = 2;
			break;
		case VK_DOWN:
			select = 3;
			break;
		default:
			select = -1;
			break;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

