// lab5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab5.h"


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int KArtin = 0;

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
    LoadStringW(hInstance, IDC_LAB5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB5));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB5);
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

void Cor(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {
    POINT p[] = {
        cx, cy - sizeY,
        cx + sizeX / 2, cy,
        cx + sizeX, cy - sizeY,
        cx + sizeX, cy + sizeY,
        cx - sizeX, cy + sizeY,
        cx - sizeX, cy - sizeY,
        cx - sizeX / 2, cy,
        cx, cy - sizeY
    };
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 8);
    DeleteObject(hPen);

}
void cor_gor(HDC hdc){
    {
        int r = 0;
        int x = 50;
        int sizex = 10;
        while (x < 2100) {
            Cor(hdc, x, 50, sizex,20, RGB(r, 0, 0));
            x = x + 100;
            sizex = sizex + 3;
            r += 20;
        }
    }
}

void cor_ver(HDC hdc) {
    {
        int r = 0;
        int x = 100;
        int sizex = 10;
        int y = 50;
        int sizey = 10;
        while (y < 2100) {
            Cor(hdc, x, y, sizex, sizey, RGB(r, 0, 0));
            y = y + 100;
            sizey = sizey + 3;



            r += 20;
        }
    }
}
void cor_riad(HDC hdc) {
    {
        int r = 0;
        int x = 100;
        int sizex = 10;
        int y = 50;
        int sizey = 10;
        int b = 0;
        while (y < 2100) {
            
            
            while (x < 2100) {
                x = x + 100;
                sizex = sizex + 1;
                b += 1;
                Cor(hdc, x, y, sizex, sizey, RGB(r, 0, b));
            }
            
            x = 100;
            y = y + 100;
            sizey = sizey + 1;
            r += 20;
        }
    }
}

void cor_diag(HDC hdc) {
    {
        int r = 0;
        int x = 100;
        int sizex = 10;
        int y = 50;
        int sizey = 10;
        while (y < 2100) {
            Cor(hdc, x, y, sizex, sizey, RGB(r, 0, 0));
            y = y + 100;
            sizey = sizey + 3;
            x = x + 100;
            sizex = sizex + 3;


            r += 20;
        }
    }
}
void MyFigure(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {
    POINT l[] = {
        cx, cy,
        cx + sizeX, cy + sizeY,
        cx, cy + sizeY * 2,
        cx - sizeX, cy + sizeY,
        cx, cy
        
    };
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, l, 5);
    DeleteObject(hPen);

}
void f_gor(HDC hdc) {
    {
        int r = 0;
        int x = 50;
        int sizex = 10;
        while (x < 2100) {
            MyFigure(hdc, x, 50, sizex, 20, RGB(r, 0, 0));
            x = x + 100;
            sizex = sizex + 3;
            r += 20;
        }
    }
}
void f_riad(HDC hdc) {
    {
        int r = 0;
        int x = 100;
        int sizex = 10;
        int y = 50;
        int sizey = 10;
        int b = 0;
        while (y < 2100) {


            while (x < 2100) {
                x = x + 100;
                sizex = sizex + 1;
                b += 1;
                MyFigure(hdc, x, y, sizex, sizey, RGB(r, 0, b));
            }

            x = 100;
            y = y + 100;
            sizey = sizey + 1;
            r += 20;
        }
    }
}

void f_diag(HDC hdc) {
    {
        int r = 0;
        int x = 100;
        int sizex = 10;
        int y = 50;
        int sizey = 10;
        while (y < 2100) {
            MyFigure(hdc, x, y, sizex, sizey, RGB(r, 0, 0));
            y = y + 100;
            sizey = sizey + 3;
            x = x + 100;
            sizex = sizex + 3;


            r += 20;
        }
    }
}
void f_ver(HDC hdc) {
    {
        int r = 0;
        int x = 100;
        int sizex = 10;
        int y = 50;
        int sizey = 10;
        while (y < 2100) {
            MyFigure(hdc, x, y, sizex, sizey, RGB(r, 0, 0));
            y = y + 100;
            sizey = sizey + 3;



            r += 20;
        }
    }
}
void j(HDC hdc) {
    if (KArtin == 0) {
        f_gor(hdc);
    }
    if (KArtin == 2) {
        f_ver(hdc);
    }
    if (KArtin == 3) {
        f_diag(hdc);
    }
    if (KArtin == 4) {
        f_riad(hdc);
    }
    if (KArtin == 5) {
        return j(hdc);
    }
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_DOWN:
            KArtin += 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            KArtin -= 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RETURN:
            if (KArtin == 5){
                
            }
            break;
        }
        break;
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
            
            //Cor(hdc, 400, 300, 200, 100, RGB(0, 255, 255));
            // 
            //cor_gor(hdc);
            //cor_ver(hdc);
            //cor_diag(hdc);
            //cor_riad(hdc);
            
            //MyFigure(hdc, 400, 400, 100, 100, RGB(0, 0, 0));
            // 
            //f_gor(hdc);
            //f_ver(hdc);
            //f_diag(hdc);
            //f_riad(hdc);
            
            j(hdc);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            
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
