// saper_Minesweeper.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "saper_Minesweeper.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//#define WM_LBUTTONDOWN       

#include <windowsx.h>
#define MAX_LOADSTRING 100
#include <time.h>
#define N 9
#define M 9
int win = 0;
int x, y;
int ser[N][M] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int ser_pr[N][M] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int vis[N][M] = { 
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2},   
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2}, 
{-2, -2, -2, -2, -2, -2, -2, -2, -2} };
int i = 0;
int j = 0;
int prov_genr = 0;
int min = 10;   

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
    LoadStringW(hInstance, IDC_SAPERMINESWEEPER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SAPERMINESWEEPER));

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

int sizeX = 30;
int sizeY = 30;

int cur_x, cur_y;
void draw(HDC hdc) {
    i = 0;
    j = 0;
    HBRUSH hBrushEmptyNO_VIS; //создаём кисть для пустого поля
    hBrushEmptyNO_VIS = CreateSolidBrush(RGB(200, 200, 200)); // закрытое поле
    HBRUSH hBrushEmptyOpen_0;
    hBrushEmptyOpen_0 = CreateSolidBrush(RGB(255, 255, 255));// открытое без мин в радиусе поле
    HBRUSH hBrushEmptyFLAG;
    hBrushEmptyFLAG = CreateSolidBrush(RGB(150, 200, 200)); // флагнутое поле
    HBRUSH hBrushEmptyBoom;
    hBrushEmptyBoom = CreateSolidBrush(RGB(0, 0, 0)); // бомба
    while (i < 9)
    {
        while (j < 9)
        {
            RECT rect = { j * sizeX + 1,i * sizeY + 1,  (j + 1) * sizeX, (i + 1) * sizeY };
            if (vis[i][j] == -2) {
                FillRect(hdc, &rect, hBrushEmptyNO_VIS);
            }
            if (vis[i][j] == 0) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
            }
            if (vis[i][j] == -3) {
                FillRect(hdc, &rect, hBrushEmptyFLAG);
            }
            if (vis[i][j] == 1) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "1", strlen("1"));
            }
            if (vis[i][j] == 2) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "2", strlen("2"));
            }
            if (vis[i][j] == 3) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "3", strlen("3"));
            }
            if (vis[i][j] == 4) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "4", strlen("4"));
            }
            if (vis[i][j] == 5) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "5", strlen("5"));
            }
            if (vis[i][j] == 6) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "6", strlen("6"));
            }
            if (vis[i][j] == 7) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "7", strlen("7"));
            }
            if (vis[i][j] == 8) {
                FillRect(hdc, &rect, hBrushEmptyOpen_0);
                TextOutA(hdc, j * sizeX + 11, i * sizeY + 8, "8", strlen("8"));
            }
            if (vis[i][j] == -1) {
                FillRect(hdc, &rect, hBrushEmptyBoom);
                
            }
            j++;
        }
        j = 0;
        i++;
    }
    DeleteObject(TextOutA);
    DeleteObject(hBrushEmptyOpen_0);
    DeleteObject(hBrushEmptyNO_VIS);
    DeleteObject(hBrushEmptyFLAG);
    DeleteObject(hBrushEmptyBoom);


}
int minazdes;
int chek_1, chek_2, chek_3, chek_4, chek_5, chek_6, chek_7, chek_8;
int chek_aoe;
void gener(){
    i = 0;
    j = 0;

    srand(time(NULL));
    while (i < 9)
    {
        while (j < 9)
        {
            if ((ser[i][j] == 0) and (min > 0)) {

                //srand(time(NULL));
                minazdes = rand();
                if ((minazdes / 100) < 10) {
                    ser[i][j] = -1;
                    min--;
                }
            }

            j++;
        }
        j = 0;
        i++;
    }

    i = 0;
    j = 0;
    if (min > 0) {
        gener();
    }
    else {
        

        while (i < 9)
        {
            while (j < 9)
            {
                ser_pr[i][j] = ser[i][j];
                
                j++;
            }
            j = 0;
            i++;
        }
        
        i = 0;
        j = 0;
        while (i < 9)
        {
            while (j < 9)
            {
                if ((ser[i][j] == 0) and (ser_pr[i][j] == 0)) {
                    
                    chek_1 = ser[i-1][j-1];
                    chek_2 = ser[i-1][j];
                    chek_3 = ser[i-1][j+1];
                    chek_4 = ser[i][j-1];
                    chek_5 = ser[i][j+1];
                    chek_6 = ser[i+1][j-1];
                    chek_7 = ser[i+1][j];
                    chek_8 = ser[i+1][j+1];
                    chek_aoe = (chek_1 + chek_2 + chek_3 + chek_4 + chek_5 + chek_6 + chek_7 + chek_8) / -1;
                    if (chek_aoe > 0) {
                        ser_pr[i][j] = chek_aoe;
                    }
                }

                j++;
            }
            j = 0;
            i++;
        }
        i = 0;
        j = 0;
        while (i < 9)
        {
            while (j < 9)
            {
                ser[i][j] = ser_pr[i][j];

                j++;
            }
            j = 0;
            i++;
        }
        i = 0;
        j = 0;

    }
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SAPERMINESWEEPER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SAPERMINESWEEPER);
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
void otkritie(int cur_y, int cur_x) {
    if (ser[cur_y][cur_x] == -1) {
        win = -1;
        vis[cur_y][cur_x] = ser[cur_y][cur_x];
    }
    else
    {


        while (ser[cur_y][cur_x] != -1 && vis[cur_y][cur_x] == -2) {


            vis[cur_y][cur_x] = ser[cur_y][cur_x];
            if (cur_y != 0) {
                otkritie(cur_y - 1, cur_x);
            }
            if (cur_y != 8) {
                otkritie(cur_y + 1, cur_x);
            }
            if (cur_x != 8) {
                otkritie(cur_y, cur_x + 1);
            }
            if (cur_x != 0) {
                otkritie(cur_y, cur_x - 1);
            }
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
        if (prov_genr == 0) {
            gener();
            prov_genr = 1;
        }
        // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
        draw(hdc);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);



    case WM_LBUTTONDOWN:
        x = GET_X_LPARAM(lParam);
        y = GET_Y_LPARAM(lParam);
        cur_x = x / 31;
        cur_y = y / 31;
        
            //vis[cur_y][cur_x] = ser[cur_y][cur_x];
        otkritie(cur_y, cur_x);
            
        
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_RBUTTONDOWN:
        x = GET_X_LPARAM(lParam);
        y = GET_Y_LPARAM(lParam);
        cur_x = x / 31;
        cur_y = y / 31;

        if (vis[cur_y][cur_x] == -2){
            vis[cur_y][cur_x] = -3;
        }
        else {
            if (vis[cur_y][cur_x] == -3) {
                vis[cur_y][cur_x] = -2;
            }
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_TAB:
            gener();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        
        }
        break;
        
    return 0;
    }
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
