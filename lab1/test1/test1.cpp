// test1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "test1.h"

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
    LoadStringW(hInstance, IDC_TEST1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEST1);
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
            MoveToEx(hdc, 100, 400, NULL);
            LineTo(hdc, 250, 250);
            LineTo(hdc, 400, 400);
            MoveToEx(hdc, 100, 400, NULL);
            Rectangle(hdc, 150, 350, 350, 525 );
            Rectangle(hdc, 200, 400, 300, 475);
            


            hPen = CreatePen(PS_SOLID, 2, RGB(0, 127, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 10, 525, NULL);
            LineTo(hdc, 100, 525);
            LineTo(hdc, 50, 500);
            LineTo(hdc, 10, 525);
            MoveToEx(hdc, 20, 500, NULL);
            LineTo(hdc, 80, 500);
            LineTo(hdc, 50, 480);
            LineTo(hdc, 20, 500);
            MoveToEx(hdc, 30, 480, NULL);
            LineTo(hdc, 70, 480);
            LineTo(hdc, 50, 465);
            LineTo(hdc, 30, 480);
            DeleteObject(hPen);


            hPen = CreatePen(PS_SOLID, 20, RGB(125, 77, 29));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 500, 525, NULL);
            LineTo(hdc, 500, 300);

            hPen = CreatePen(PS_SOLID, 40, RGB(0, 127, 0));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 450, 250, 550, 350);
            DeleteObject(hPen);

            hBrush = CreateHatchBrush(HS_CROSS, RGB(254, 254, 34));
            SelectObject(hdc, hBrush);

            hPen = CreatePen(PS_SOLID, 1, RGB(254, 254, 34));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 10, 10, 110, 110);
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 127, 0));
            SelectObject(hdc, hPen);

            DeleteObject(hPen);
            DeleteObject(hBrush);
            {
                int con = 0;
                int x = 0;
                int y = 525;

                hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
                SelectObject(hdc, hPen);
                while (con < 30) {
                    MoveToEx(hdc, x, y, NULL);
                    LineTo(hdc, x, y-75);
                    LineTo(hdc, x+25, y - 100);
                    LineTo(hdc, x + 50, y - 75);
                    LineTo(hdc, x + 50, y);
                    LineTo(hdc, x, y);
                    x = x + 50;
                    con++;
                }
            }

            hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 255));
            SelectObject(hdc, hBrush);
            hPen = CreatePen(PS_SOLID, 20, RGB(192, 192, 192));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 100, 150, NULL);
            LineTo(hdc, 75, 200);
            LineTo(hdc, 100, 250);
            LineTo(hdc, 125, 200);
            LineTo(hdc, 100, 150);

            DeleteObject(hPen);
            DeleteObject(hBrush);


            hBrush = CreateSolidBrush(RGB(134, 240, 241));
            SelectObject(hdc, hBrush);
            hPen = CreatePen(PS_SOLID, 1, RGB(134, 240, 241));
            SelectObject(hdc, hPen);
            Ellipse(hdc, 200, 20, 500, 100);

            Ellipse(hdc, 225, 18, 250, 35);

            {
                int con = 0;
                int x1 = 225;
                int y1 = 18;
                int x2 = 287;
                int y2 = 47;

                while (con < 6) {
                    Ellipse(hdc, x1, y1, x2, y2);
                    x1 = x1 + 40;
                    x2 = x2 + 40;
                    con++;
                }
            }
            {
                int con = 0;
                int x1 = 225;
                int y1 = 80;
                int x2 = 287;
                int y2 = 110;

                while (con < 5) {
                    Ellipse(hdc, x1, y1, x2, y2);
                    x1 = x1 + 40;
                    x2 = x2 + 40;
                    con++;
                }
            }



















            hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            
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
