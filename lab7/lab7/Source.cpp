#include "framework.h"
#include "Header.h"
void OlympicEmblem(HDC hdc) {
	//  исть - прозрачна€
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	// верхний р€д колец
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 20, 40, 60, 80);

	hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 70, 40, 110, 80);

	hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	Ellipse(hdc, 120, 40, 160, 80);

	// нижний р€д колец
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