#include "framework.h"
#include "Header.h"
void OlympicEmblem(HDC hdc) {
	// Кисть - прозрачная
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	// верхний ряд колец
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 20, 40, 60, 80);

	hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 70, 40, 110, 80);

	hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 120, 40, 160, 80);

	// нижний ряд колец
	hPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 45, 60, 85, 100);

	hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 95, 60, 135, 100);
}

void budiln(HDC hdc){
    Ellipse(hdc, 375, 375, 425, 425);
    Ellipse(hdc, 475, 375, 525, 425);
    Ellipse(hdc, 400, 400, 500, 500);
    MoveToEx(hdc, 400, 400, NULL);
    LineTo(hdc, 500, 400);

}


void oblaka(HDC  hdc) {
    HPEN hPen;
    HBRUSH hBrush;
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

}

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


void first_house(HDC hdc) {
    HPEN hPen;
    HBRUSH hBrush;
    MoveToEx(hdc, 100, 400, NULL);
    LineTo(hdc, 250, 250);
    LineTo(hdc, 400, 400);
    MoveToEx(hdc, 100, 400, NULL);
    Rectangle(hdc, 150, 350, 350, 525);
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
            LineTo(hdc, x, y - 75);
            LineTo(hdc, x + 25, y - 100);
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






    hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 255));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);






    {
        int con = 0;
        int x1 = 600;
        int y1 = 275;
        int x2 = 650;
        int y2 = 150;

        while (con < 60) {
            MoveToEx(hdc, x1, y1, NULL);

            LineTo(hdc, x2, y2);
            x1 = x1 + 1;
            x2 = x2 + 1;
            y1 = y1 + 1;
            y2 = y2 + 1;
            con++;
        }
    }
    {
        int con = 0;
        int x1 = 665;
        int y1 = 165;
        int x2 = 715;
        int y2 = 40;

        while (con < 30) {
            MoveToEx(hdc, x1, y1, NULL);

            LineTo(hdc, x2, y2);
            x1 = x1 + 1;
            x2 = x2 + 1;
            y1 = y1 + 1;
            y2 = y2 + 1;
            con++;
        }
    }

    hPen = CreatePen(PS_SOLID, 7, RGB(226, 88, 34));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 630, 305, NULL);
    LineTo(hdc, 600, 300);
    MoveToEx(hdc, 630, 305, NULL);
    LineTo(hdc, 600, 315);
    MoveToEx(hdc, 630, 305, NULL);
    LineTo(hdc, 600, 330);
    MoveToEx(hdc, 630, 305, NULL);
    LineTo(hdc, 610, 345);
    MoveToEx(hdc, 630, 305, NULL);
    LineTo(hdc, 630, 340);

    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 715, 40, NULL);
    LineTo(hdc, 745, 40);
    LineTo(hdc, 745, 70);


    Ellipse(hdc, 715, 55, 735, 80);
}

int i = 0;
int j1 = 0;
int j2 = 0;

int x = 800;
int y = 100;

void Big_PIC(HDC hdc){
    i = 0;
    j1 = 0;
    j2 = 0;
    x = 800;
    y = 100;
    HPEN hPen;
    HBRUSH hBrush;

    //hPen = CreatePen(PS_SOLID, 7, RGB(241, 25, 71));
    hBrush = CreateSolidBrush(RGB(27, 177, 255));
    //SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 50, 50, 550, 550);

    hPen = CreatePen(PS_SOLID, 7, RGB(241, 25, 71));
    hBrush = CreateSolidBrush(RGB(255, 255, 5));
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);
    
    Pie(hdc, 100, 100, 500, 500, 500, 350, 100, 350);

    DeleteObject(hPen);
    DeleteObject(hBrush);

    while (i < 10) {
        while (j1 < 11) {
              
            if (j1 > 5) {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x - 10;
            }
            else
            {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x + 10;
            }
            y = y + 10;
            j1++;
        }
        while (j2 < 11) {
            if (j2 > 5) {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x + 10;
            }
            else
            {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x - 10;
            }
            y = y + 10;
            j2++;
        }
        j1 = 0;
        j2 = 0;
        i++;
    }


    i = 0;
    j1 = 0;
    j2 = 0;
    x = 800;
    y = 100;
    while (i < 10) {
        while (j1 < 11) {

            if (j1 > 5) {
                TextOutA(hdc, x, y, "СЫР", strlen("100"));
                x = x + 10;
            }
            else
            {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x - 10;
            }
            y = y + 10;
            j1++;
        }
        while (j2 < 11) {
            if (j2 > 5) {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x - 10;
            }
            else
            {
                TextOutA(hdc, x, y, "СЫРР", strlen("100"));
                x = x + 10;
            }
            y = y + 10;
            j2++;
        }
        j1 = 0;
        j2 = 0;
        i++;

    }
    
}