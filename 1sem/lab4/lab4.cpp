// lab4.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab4.h"

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
    LoadStringW(hInstance, IDC_LAB4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB4));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB4);
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

void im1(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy - size;
    int x3 = cx;
    int y3 = cy + size;
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x1, y1);
}
void recurklim1_1(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim1_1(hdc, cx - size, cy - size, size / 2);
}

void recurklim1_2(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim1_2(hdc, cx - size, cy - size, size / 2);
    recurklim1_2(hdc, cx + size, cy - size, size / 2);
}

void recurklim1_3(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim1_3(hdc, cx - size, cy - size, size / 2);
    recurklim1_3(hdc, cx, cy + size, size / 2);
}


void recurklim1_4(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim1_4(hdc, cx - size, cy - size, size / 2);
    recurklim1_4(hdc, cx + size, cy - size, size / 2);
    recurklim1_4(hdc, cx, cy + size, size / 2);
}

void recurklim1_5(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    
    recurklim1_5(hdc, cx, cy - size, size / 2);
}


void recurklim1_6(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }

    recurklim1_6(hdc, cx + size, cy, size / 2);
}

void recurklim1_7(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }

    recurklim1_7(hdc, cx - size, cy, size / 2);
}

void recurklim1_8(HDC hdc, int cx, int cy, int size) {
    im1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim1_8(hdc, cx - size, cy, size / 2);
    recurklim1_8(hdc, cx + size, cy, size / 2);
    recurklim1_8(hdc, cx, cy - size, size / 2);
}






void im2(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
}
void recurklim2_1(HDC hdc, int cx, int cy, int size) {
    im2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recurklim2_1(hdc, cx - size, cy + size, size / 2);
}

void recurklim2_2(HDC hdc, int cx, int cy, int size) {
    im2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recurklim2_2(hdc, cx - size /2 , cy - size, size / 2);
}

void recurklim2_3(HDC hdc, int cx, int cy, int size) {
    im2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim2_3(hdc, cx - size / 2, cy - size, size / 2);
    recurklim2_3(hdc, cx + size / 2, cy - size, size / 2);
}

void recurklim2_4(HDC hdc, int cx, int cy, int size) {
    im2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim2_4(hdc, cx - size, cy + size, size / 2);
    recurklim2_4(hdc, cx + size, cy + size, size / 2);
}


void recurklim2_5(HDC hdc, int cx, int cy, int size) {
    im2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurklim2_3(hdc, cx - size / 2, cy - size, size / 2);
    recurklim2_3(hdc, cx + size / 2, cy - size, size / 2);
    recurklim2_5(hdc, cx - size, cy + size, size / 2);
    recurklim2_5(hdc, cx + size, cy + size, size / 2);
}

void im3(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;

    int x2 = cx + size;
    int y2 = cy;

    int x3 = cx;
    int y3 = cy + size;

    int x4 = cx - size;
    int y4 = cy;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
}
void recurs_troi(HDC hdc, int cx, int cy, int size) {
    im3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_troi(hdc, cx + size, cy, size / 2);
}


void recurs_troi2(HDC hdc, int cx, int cy, int size) {
    im3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_troi2(hdc, cx + size, cy, size / 2);
    recurs_troi2(hdc, cx - size, cy, size / 2);
}
void recurs_troi3(HDC hdc, int cx, int cy, int size) {
    im3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_troi3(hdc, cx + size, cy, size / 2);
    recurs_troi3(hdc, cx - size, cy, size / 2);
    recurs_troi3(hdc, cx, cy - size, size / 2);
    recurs_troi3(hdc, cx, cy + size, size / 2);
}
void im4(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;

    int x2 = cx + size / 4;
    int y2 = cy - size / 4;

    int x3 = cx + size;
    int y3 = cy;

    int x4 = cx + size / 4;
    int y4 = cy + size / 4;

    int x5 = cx;
    int y5 = cy + size;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
}
void im5(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy;

    int x2 = cx - size;
    int y2 = cy + size / 2;

    int x3 = cx + size / 2;
    int y3 = cy + size / 2;

    int x4 = cx + size;
    int y4 = cy;

    int x5 = cx;
    int y5 = cy + size;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
}


void recurs_kvadr(HDC hdc, int cx, int cy, int size) {
    im5(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_kvadr(hdc, cx + size, cy, size / 2);
}

void recurs_kvadr2(HDC hdc, int cx, int cy, int size) {
    im5(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_kvadr2(hdc, cx + size / 2, cy + size / 2, size / 2);
    recurs_kvadr2(hdc, cx - size / 2, cy + size / 2, size / 2);
    recurs_kvadr2(hdc, cx + size / 2, cy - size / 2, size / 2);
    recurs_kvadr2(hdc, cx - size / 2, cy - size / 2, size / 2);
}

void im6(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy + size;
    Ellipse(hdc, x1, y1, x2, y2);
}

void recurs_krug(HDC hdc, int cx, int cy, int size) {
    im6(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_krug(hdc, cx + size, cy, size / 2);

}
void recurs_krug2(HDC hdc, int cx, int cy, int size) {
    im6(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_krug2(hdc, cx + size, cy, size / 2);
    recurs_krug2(hdc, cx - size, cy, size / 2);
    recurs_krug2(hdc, cx, cy - size, size / 2);
    recurs_krug2(hdc, cx, cy + size, size / 2);
}

void recurs_krug3(HDC hdc, int cx, int cy, int size) {
    im6(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recurs_krug3(hdc, cx + size, cy, size / 2);
    recurs_krug3(hdc, cx - size, cy, size / 2);
    recurs_krug3(hdc, cx, cy - size, size / 2);
    recurs_krug3(hdc, cx, cy + size, size / 2);

    recurs_krug3(hdc, cx + size / 2, cy + size / 2, size / 2);
    recurs_krug3(hdc, cx - size / 2, cy + size / 2, size / 2);
    recurs_krug3(hdc, cx + size / 2, cy - size / 2, size / 2);
    recurs_krug3(hdc, cx - size / 2, cy - size / 2, size / 2);
}


void im7(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy + size /2 ;

    int x2 = cx - size;
    int y2 = cy;

    int x3 = cx;
    int y3 = cy;

    int x4 = cx;
    int y4 = cy + size;

    int x5 = cx;
    int y5 = cy + size;

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);
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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            SelectObject(hdc, hPen);



            //recurklim1_1(hdc, 200, 160, 80);
            //recurklim1_2(hdc, 200, 160, 80);
            //recurklim1_3(hdc, 200, 160, 80);
            //recurklim1_4(hdc, 200, 160, 80);
            //recurklim1_5(hdc, 200, 160, 80);
            //recurklim1_6(hdc, 200, 160, 80);
            //recurklim1_7(hdc, 200, 160, 80);
            //recurklim1_8(hdc, 200, 160, 80);
            // 
            // 
            // 
            // 
            //im2(hdc, 200, 160, 80);
            //recurklim2_1(hdc, 200, 200, 100);
            //recurklim2_2(hdc, 200, 200, 100);
            //recurklim2_3(hdc, 200, 200, 100);
            //recurklim2_4(hdc, 200, 200, 100);
            //recurklim2_5(hdc, 200, 200, 100);

            //recurs_troi(hdc, 200, 200, 100);
            //recurs_troi2(hdc, 200, 200, 100);
            //recurs_troi3(hdc, 200, 200, 100);

            //recurs_kvadr(hdc, 200, 200, 100);
            //recurs_kvadr2(hdc, 200, 200, 100);
            //recurs_krug(hdc, 200, 200, 100);
            //recurs_krug2(hdc, 200, 200, 100);

            //recurs_krug3(hdc, 200, 200, 100);
            //im7(hdc, 200, 200, 100);

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
