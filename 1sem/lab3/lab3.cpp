﻿// lab3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab3.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB3));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

void Claus(HDC hdc, int x, int y) {
    
    

    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);

}
void centr(HDC hdc){
    Claus(hdc, 0, 0);
    Claus(hdc, 1380, 0);
    Claus(hdc, 0, 620);
    Claus(hdc, 1380, 620);
    Claus(hdc, 700, 310);
}
void line(HDC hdc) {
    {
        int x = 0;
            while (x < 1100){
                Claus(hdc, x, 0);
                x = x + 50;
            }
    }
}
void linever(HDC hdc) {
    {
        int y = 0;
        while (y < 1100) {
            Claus(hdc, 0, y);
            y = y + 80;
        }
    }
}

void diag(HDC hdc) {
    {
        int y = 0;
        int x = 0;
        while (y < 1100) {
            Claus(hdc, x, y);
            x = x + 50;
            y = y + 80;
        }
    }
}

void riad(HDC hdc) {
    {
        int y = 0;
        int x = 0;
        while (y < 1100) {
            
            
            while (x < 1000) {
                    Claus(hdc, x, y);
                    x = x + 50;
            }
            x = 0;
            y = y + 80;
        }
    }
}

void Sneg(HDC hdc, int x, int y) {

    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 20 + x, 20 + y, NULL);

    LineTo(hdc, 0 + x, 30 + y);

    MoveToEx(hdc, 38 + x, 20 + y, NULL);

    LineTo(hdc, 58 + x, 30 + y);


    MoveToEx(hdc, 35 + x, 120 + y, NULL);
    LineTo(hdc, 60 + x, 10 + y);


    LineTo(hdc, 58 + x, 0 + y);
    MoveToEx(hdc, 60 + x, 10 + y, NULL);


    LineTo(hdc, 64 + x, 0 + y);
    MoveToEx(hdc, 60 + x, 10 + y, NULL);


    LineTo(hdc, 70 + x, 0 + y);
    MoveToEx(hdc, 60 + x, 10 + y, NULL);
}
void Logo(HDC hdc, int x, int y) {
            
            MoveToEx(hdc, 25 + x, 0 + y, NULL);
            LineTo(hdc, 0 + x, 50 + y);
            LineTo(hdc, 25 + x, 100 + y);
            LineTo(hdc, 50 + x, 50 + y);
            LineTo(hdc, 25 + x , 0 + y);

}
void centr_logo(HDC hdc) {
    Logo(hdc, 0, 0);
    Logo(hdc, 1380, 0);
    Logo(hdc, 0, 620);
    Logo(hdc, 1380, 620);
    Logo(hdc, 700, 310);

}

void line_logo(HDC hdc) {
    {
        int x = 0;
        while (x < 1100) {
            Logo(hdc, x, 0);
            x = x + 70;
        }
    }
}
void linever_Logo(HDC hdc) {
    {
        int y = 0;
        while (y < 1100) {
            Logo(hdc, 0, y);
            y = y + 120;
        }
    }
}

void diag_Logo(HDC hdc) {
    {
        int y = 0;
        int x = 0;
        while (y < 1100) {
            Logo(hdc, x, y);
            x = x + 50;
            y = y + 80;
        }
    }
}
void riad_Logo(HDC hdc) {
    {
        int y = 0;
        int x = 0;
        while (y < 1100) {


            while (x < 1000) {
                Logo(hdc, x, y);
                x = x + 70;
            }
            x = 0;
            y = y + 120;
        }
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN hPen;

            HBRUSH hBrush;
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
            SelectObject(hdc, hPen);

            
            //centr(hdc);
            //line(hdc);
            //linever(hdc);
            //diag(hdc);
            //riad(hdc);    


            hPen = CreatePen(PS_SOLID, 2, RGB(128, 166, 255));
            SelectObject(hdc, hPen);
            //Sneg(hdc, 0, 0);


            DeleteObject(hPen);
            


            hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 255));
            SelectObject(hdc, hBrush);
            hPen = CreatePen(PS_SOLID, 20, RGB(192, 192, 192));
            SelectObject(hdc, hPen);


            //Logo(hdc, 0, 0);
            //centr_logo(hdc);
            //line_logo(hdc);
            //linever_Logo(hdc);
            //diag_Logo(hdc);
            //riad_Logo(hdc);


            DeleteObject(hPen);
            DeleteObject(hBrush);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
