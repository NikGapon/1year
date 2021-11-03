// lab8.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab8.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <stdlib.h>
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

#define N 10
#define M 15

int a[N][M] = {
{ 3, 0, 1, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   0, 0, 0, 0, 0,   0, 0, 0, 4, 0 },
{ 0, 0, 0, 0, 2,   0, 0, 0, 0, 0,   0, 2, 0, 0, 0 },
{ 0, 0, 0, 0, 2,   2, 2, 2, 2, 2,   0, 2, 0, 0, 0 },

{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 2,   0, 2, 2, 0, 0 },
{ 0, 0, 1, 0, 0,   0, 0, 0, 0, 2,   0, 2, 0, 0, 0 },
{ 0, 0, 0, 0, 0,   0, 1, 0, 0, 0,   0, 2, 4, 2, 0 },
{ 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 2, 2, 2, 0 },
{ 0, 0, 1, 0, 1,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0 }
};

int steps = 0;
int gold = 0;

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
    LoadStringW(hInstance, IDC_LAB8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB8));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void moveToLeft() {
    int i, j;
    i = 0;
    while (i < N) {
        j = 1;
        while (j < M) {
            if (a[i][j] == 3) {
                if (a[i][j - 1] == 0) {
                    a[i][j - 1] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i][j - 1] == 1) {
                    a[i][j - 1] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
            j++;
        }
        i++;
    }
}
void moveToRight() {
    int i = 0;
    while (i < N) {
        int j = M - 2;
        while (j >= 0) {
            if (a[i][j] == 3) {
                if (a[i][j + 1] == 0) {
                    a[i][j + 1] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i][j + 1] == 1) {
                    a[i][j + 1] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
            j--;
        }
        i++;
    }
}

void moveUp() {
    int i = 1;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (a[i - 1][j] == 0) {
                    a[i - 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i - 1][j] == 1) {
                    a[i - 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
            j++;
        }
        i++;
    }
}
void UPST() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                a[i - 1][j] = 2;
                steps++;
            }

        j++;
        }
    i++;
    }
}

void UPST_0() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                a[i - 1][j] = 0;
                steps++;
            }

            j++;
        }
        i++;
    }
}

void MoveMonsters() {
    int i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 4) {
                int di = rand() % 3 - 1; // от -1 до +1
                int dj = 0;

                if (di == 0) {
                    dj = rand() % 3 - 1; // от -1 до +1
                }

                if (di != 0 || dj != 0) {
                    if (i + di >= 0 && i + di < N
                        && j + dj >= 0 && j + dj < M)
                    {
                        a[i][j] = 0;
                        a[i + di][j + dj] = -4;
                    }
                }
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == -4) {
                a[i][j] = 4;
            }
            j++;
        }
        i++;
    }

}
void generateLevel() {
    // Коды ячеек
    // 0 - свободно
    // 1 - золото
    // 2 - стена
    // 3 - игрок
    // 4 - МОНСТР!

    // всё заново!
    steps = 0;
    gold = 0;

    // все ячейки делаем свободными
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] = 0;
        }
    }
    // в часть ячеек помещаем много ЗОЛОТА
    int k;
    for (k = 0; k < (N * M) / 2; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 1;
    }
    for (k = 0; k < (N * M) / 5; k++) {
        i = rand() % N;
        j = rand() % M;
        a[i][j] = 2;
    }
    // в одну из ячеек помещаем игрока
    i = rand() % N;
    j = rand() % M;
    a[i][j] = 3;

}


void moveDown() {
    int i = N;
    while (i >= 0) {
        int j = 0;
        while (j < M) {
            if (a[i][j] == 3) {
                if (a[i + 1][j] == 0) {
                    a[i + 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                }
                else if (a[i + 1][j] == 1) {
                    a[i + 1][j] = 3;
                    a[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
            j++;
        }
        i--;
    }
}
int sizeX = 36;
int sizeY = 30;

void DrawField(HDC hdc) {

    HBRUSH hBrushEmptyCell; //создаём кисть для пустого поля
    hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // серый

    HBRUSH hBrushGold; //создаём кисть для поля с золотом
    hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // желтый

    HBRUSH hBrushWall; //создаём кисть для стены
    hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // черный

    HBRUSH hBrushMan; //создаём кисть для игрока
    hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // синий
    HBRUSH hBrushMONSTR;
    hBrushMONSTR = CreateSolidBrush(RGB(255, 0, 0));
    int i, j;
    i = 0;
    while (i < N) {
        j = 0;
        while (j < M) {
            RECT rect = { j * sizeX,i * sizeY,  (j + 1) * sizeX,(i + 1) * sizeY };
            if (a[i][j] == 0) {
                FillRect(hdc, &rect, hBrushEmptyCell);
            }
            else if (a[i][j] == 1) {
                FillRect(hdc, &rect, hBrushGold);
            }
            else if (a[i][j] == 2) {
                FillRect(hdc, &rect, hBrushWall);
            }
            else if (a[i][j] == 3) {
                FillRect(hdc, &rect, hBrushMan);
            }
            else if (a[i][j] == 4) {
                FillRect(hdc, &rect, hBrushMONSTR);
            }
            else {
                // тут никогда не должны оказаться
            }
            j++;
        }
        i++;
    }
    


    HFONT hFont;
    hFont = CreateFont(20,
        0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET,
        0, 0, 0, 0,
        L"Courier New"
    );
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(0, 128, 128));

    TCHAR  string1[] = _T("сделано ходов:");
    TCHAR  string2[] = _T("собрано золота:");
    TextOut(hdc, 10, sizeY * (N + 1), (LPCWSTR)string1, _tcslen(string1));
    TextOut(hdc, 10, sizeY * (N + 1) + 20, (LPCWSTR)string2, _tcslen(string2));








    char sSteps[5];
    TCHAR  tsSteps[5];
    sprintf(sSteps, "%d", steps);
    OemToChar(sSteps, tsSteps);
    TextOut(hdc, 220, sizeY * (N + 1), (LPCWSTR)tsSteps, _tcslen(tsSteps));

    char sGold[5];
    TCHAR  tsGold[5];
    sprintf(sGold, "%d", gold);
    OemToChar(sGold, tsGold);
    TextOut(hdc, 220, sizeY * (N + 1) + 20, (LPCWSTR)tsGold, _tcslen(tsGold));

    DeleteObject(hFont);
    DeleteObject(hBrushEmptyCell);
    DeleteObject(hBrushGold);
    DeleteObject(hBrushWall);
    DeleteObject(hBrushMan);

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
    case WM_CREATE:
        SetTimer(hWnd, 1, 500, 0); // Запускаем таймер
        // srand(time(NULL)); // Перезапуск генератора случайных чисел
        break;

    case WM_TIMER:
        MoveMonsters(); // перемещаем монстров
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        DrawField(hdc);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_DOWN:
            moveDown();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            moveToLeft();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            moveUp();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            moveToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_TAB:
            UPST();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_CAPITAL:
            UPST_0();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4e: // N - New  
            generateLevel();
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
