// lab6.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab6.h"

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
    LoadStringW(hInstance, IDC_LAB6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB6));

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

int KArtin = 5;

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB6);
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
void cor_gor(HDC hdc) {
    {
        int r = 0;
        int x = 50;
        int sizex = 10;
        while (x < 2100) {
            Cor(hdc, x, 50, sizex, 20, RGB(r, 0, 0));
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
void f_p(HDC hdc) {
    {
        int r = 0;
        int x = 50;
        int sizex = 10;
        int y = 50;
        int sizey = 0;
        while (y < 2100) {
            MyFigure(hdc, x, y, sizex, sizey, RGB(r, 0, 0));
            y = y + 100;
            x = x + 100;
            sizex = sizex + 1;
            sizey = sizey + 1;



            r += 20;
        }
    }
}

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
void el(HDC hdc) {
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

void was(HDC hdc) {
    {
        int y = 0;
        int x = 500;

        int p = 0;
        int k = 1;
        int l = 0;
        while (y < 500) {
            p = (x - 50 * (k / 3));

            while (l < k) {

                Claus(hdc, p, y);
                p = p + 50;
                l = l + 1;

            }
            l = 0;
            k = k * 3;
            y = y + 80;
            x = 500;

        }
    }
}

void centr(HDC hdc) {
    Claus(hdc, 0, 0);
    Claus(hdc, 1380, 0);
    Claus(hdc, 0, 620);
    Claus(hdc, 1380, 620);
    Claus(hdc, 700, 310);
}
void line(HDC hdc) {
    {
        int x = 0;
        while (x < 1100) {
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
    LineTo(hdc, 25 + x, 0 + y);

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
    recurklim2_2(hdc, cx - size / 2, cy - size, size / 2);
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
    int y1 = cy + size / 2;

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
        f_p(hdc);
    }
    if (KArtin == 6) {
        el(hdc);
    }
    if (KArtin == 7) {
        was(hdc);
    }
    if (KArtin == 8) {
        centr(hdc);
    }
    if (KArtin == 9) {
        line(hdc);
    }
    if (KArtin == 10) {
        linever(hdc);
    }
    if (KArtin == 11) {
        diag(hdc);
    }
    if (KArtin == 12) {
        riad(hdc);
    }
    if (KArtin == 13) {
        centr_logo(hdc);
    }
    if (KArtin == 14) {
        line_logo(hdc);
    }
    if (KArtin == 15) {
        linever_Logo(hdc);
    }
    if (KArtin == 16) {
        diag_Logo(hdc);
    }
    if (KArtin == 17) {
        riad_Logo(hdc);
    }
    if (KArtin == 18) {
        recurklim1_1(hdc, 200, 160, 80);
    }
    if (KArtin == 19) {
        recurklim1_1(hdc, 200, 160, 80);
    }
    if (KArtin == 20) {
        recurklim1_2(hdc, 200, 160, 80);
    }
    if (KArtin == 21) {
        recurklim1_3(hdc, 200, 160, 80);
    }
    if (KArtin == 22) {
        recurklim1_4(hdc, 200, 160, 80);
    }
    if (KArtin == 23) {
        recurklim1_5(hdc, 200, 160, 80);
    }
    if (KArtin == 24) {
        recurklim1_6(hdc, 200, 160, 80);
    }
    if (KArtin == 25) {
        recurklim1_7(hdc, 200, 160, 80);
    }
    if (KArtin == 26) {
        recurklim1_8(hdc, 200, 160, 80);
    }
    if (KArtin == 27) {
        im7(hdc, 200, 200, 100);
    }
    if (KArtin == 28) {
        recurs_krug3(hdc, 200, 200, 100);
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
            if (KArtin == 5) {

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