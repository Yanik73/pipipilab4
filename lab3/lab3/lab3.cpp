// lab3.cpp : Определяет точку входа для приложения.
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
    // bebebebebebeb
    //hfhf
    //cxfgbxcgbcvgncvghnjcgjhcjghjc
    // d fhfjfgjvimvgium vvnkuyk
    // 
    // х
    // у
    // й
    // сс
    // 1488
    // 
    // 
    // yfkfykykykyk45686875773275947193575716751391657951793157197777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
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

int numImage = 0;
void drawHome(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(123, 63, 0));
    SelectObject(hdc, hPen);
    //крыша
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);

    //Дом
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    //Окно
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);

    //Рама
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
    {
        int x1 = 150, y1 = 350;
        int x2 = 400, y2 = 350;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            y1 += 25;
            y2 += 25;
        } while (y1 <= 400);
    }
    {
        int x1 = 150, y1 = 400;
        int x2 = 225, y2 = 400;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            y1 += 25;
            y2 += 25;
        } while (y1 <= 475);
    }
    {
        int x1 = 325, y1 = 400;
        int x2 = 400, y2 = 400;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            y1 += 25;
            y2 += 25;
        } while (y1 <= 475);
    }
    {
        int x1 = 150, y1 = 475;
        int x2 = 400, y2 = 475;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            y1 += 25;
            y2 += 25;
        } while (y1 <= 525);
    }
}

void drawCar(HDC hdc) {
    //машина
        //Основа
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
    SelectObject(hdc, hPen);

    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(0, 128, 67));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 1050, 700, 800, 750);

    //Окно
    MoveToEx(hdc, 1000, 650, NULL);
    LineTo(hdc, 1050, 700);
    LineTo(hdc, 850, 700);
    LineTo(hdc, 900, 650);
    LineTo(hdc, 1000, 650);

    hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
    SelectObject(hdc, hBrush);
    //колесо 1
    Ellipse(hdc, 825, 725, 875, 775);

    hPen = CreatePen(PS_SOLID, 7, RGB(0, 128, 0));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 0));
    SelectObject(hdc, hBrush);

    //колесо 2
    Ellipse(hdc, 975, 725, 1025, 775);
    DeleteObject(hBrush);
}
void DrawTree(HDC hdc) {
    {
        HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 125, 0));
        SelectObject(hdc, hPen);
        int x1 = 0, y1 = 250;
        int x2 = 100, y2 = 250;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            x1 += 5;
            y1 -= 10;
        } while (x1 <= 100);
        x1 = 100;
        y1 = 50;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            x1 += 5;
            y1 += 10;
        } while (x1 <= 200);
    }
}

void DrawTree2(HDC hdc) {
    //Нижний тругольник
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 4, RGB(0, 255, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);

    //Средний тругольник
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 480, 450, NULL);
    LineTo(hdc, 570, 450);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 480, 450);

    //Верхний труугольник
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 500, 400, NULL);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 525, 370);
    LineTo(hdc, 500, 400);
}
void DrawTree3(HDC hdc) {
    //дерево 2
    HPEN hPen = CreatePen(PS_SOLID, 4, RGB(0, 128, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 700, 550, NULL);
    LineTo(hdc, 700, 390);
    MoveToEx(hdc, 700, 530, NULL);
    LineTo(hdc, 750, 480);
    MoveToEx(hdc, 700, 520, NULL);
    LineTo(hdc, 650, 470);
    MoveToEx(hdc, 700, 500, NULL);
    LineTo(hdc, 760, 440);
    MoveToEx(hdc, 700, 490, NULL);
    LineTo(hdc, 650, 440);
    MoveToEx(hdc, 700, 470, NULL);
    LineTo(hdc, 740, 430);
    MoveToEx(hdc, 700, 450, NULL);
    LineTo(hdc, 660, 410);
    MoveToEx(hdc, 700, 440, NULL);
    LineTo(hdc, 740, 400);
    MoveToEx(hdc, 700, 420, NULL);
    LineTo(hdc, 680, 400);
    MoveToEx(hdc, 700, 410, NULL);
    LineTo(hdc, 720, 390);
}
void motorbike(HDC hdc) {
    //мотоцикл 
    HPEN hPen = CreatePen(PS_SOLID, 8, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    Ellipse(hdc, 800, 475, 850, 525);
    Ellipse(hdc, 990, 475, 1050, 525);

    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 825, 500, NULL);
    LineTo(hdc, 950, 500);
    LineTo(hdc, 985, 450);
    LineTo(hdc, 1020, 500);
    MoveToEx(hdc, 985, 450, NULL);
    LineTo(hdc, 970, 425);

    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 980, 460, 910, 440);

    MoveToEx(hdc, 915, 455, NULL);
    LineTo(hdc, 825, 455);
    LineTo(hdc, 875, 480);
    LineTo(hdc, 890, 500);
    MoveToEx(hdc, 875, 480, NULL);
    LineTo(hdc, 825, 500);
    MoveToEx(hdc, 825, 455, NULL);
    LineTo(hdc, 880, 440);
    LineTo(hdc, 885, 445);
    LineTo(hdc, 915, 445);
    MoveToEx(hdc, 970, 425, NULL);
    LineTo(hdc, 969, 430);
}
void Bush(HDC hdc) {
    //куст 1
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 125, 0));
    SelectObject(hdc, hPen);
    int x1 = 400, y1 = 150;

    int x2 = 500, y2 = 250;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 15;
    } while (x1 <= 600);
}
void ladder(HDC hdc) {
    //Лестница

    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(123, 56, 0));
    SelectObject(hdc, hPen);
    {
        int x1 = 150, y1 = 0;
        int x2 = 150, y2 = 100;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);
            x1 += 25;
            x2 += 25;
        } while (x1 <= 450);
    }

    MoveToEx(hdc, 1160, 280, NULL);
    LineTo(hdc, 1170, 280);
    LineTo(hdc, 1170, 490);
    LineTo(hdc, 1160, 490);
    LineTo(hdc, 1160, 280);

    MoveToEx(hdc, 1090, 280, NULL);
    LineTo(hdc, 1100, 280);
    LineTo(hdc, 1100, 490);
    LineTo(hdc, 1090, 490);
    LineTo(hdc, 1090, 280);
    {
        int x1 = 1100, y1 = 320;
        int x2 = 1160, y2 = 320;
        do {
            MoveToEx(hdc, x1, y1, NULL);
            LineTo(hdc, x2, y2);

            y1 += 20;
            y2 += 20;
        } while (y1 <= 440);
    }
}
void Picture1(HDC hdc) {
    drawHome(hdc);
    drawCar(hdc);
    DrawTree(hdc);
    DrawTree2(hdc);
    DrawTree3(hdc);
    motorbike(hdc);
    Bush(hdc);
    ladder(hdc);

} 

void DrawHerringbone(HDC hdc, int x, int y)
{
    HPEN hPenGreen;
    hPenGreen = CreatePen(PS_DASH, 2, RGB(0, 128, 0));
    SelectObject(hdc, hPenGreen);

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
void DrawHerringbonePentagon(HDC hdc)
{
    DrawHerringbone(hdc, 0, 0);
    DrawHerringbone(hdc, 200, 200);
    DrawHerringbone(hdc, 100, 100);
    DrawHerringbone(hdc, 0, 200);
    DrawHerringbone(hdc, 200, 0);
}
void DrawHerringboneHorizontalLine(HDC hdc, int x = 0)
{
    do
    {
        DrawHerringbone(hdc, x, 0);
        x += 50;
    } while (x <= 400);
}
void DrawHerringboneVerticalLine(HDC hdc, int y = 0)
{
    do
    {
        DrawHerringbone(hdc, 0, y);
        y += 90;
    } while (y <= 360);
}
void DrawHerringboneDiagonalLine(HDC hdc, int x = 0, int y = 0)
{
    do
    {
        DrawHerringbone(hdc, x, y);
        x += 50;
        y += 90;
    } while (y <= 360);
}
void DrawTruck(HDC hdc, int x, int y)
{
    HPEN hPenBlueTrack = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPenBlueTrack);
    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);

    HPEN hPenRedTruck = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPenRedTruck);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);
}
void DrawTruckPentagon(HDC hdc)
{
    DrawTruck(hdc, 10, 10);
    DrawTruck(hdc, 10, 310);
    DrawTruck(hdc, 310, 10);
    DrawTruck(hdc, 310, 310);
    DrawTruck(hdc, 160, 160);
}
void DrawTruckHorizontalLine(HDC hdc, int x = 0)
{
    do
    {
        DrawTruck(hdc, x, 0);
        x += 150;
    } while (x <= 750);
}
void DrawTruckVerticalLine(HDC hdc, int y = 0)
{
    do
    {
        DrawTruck(hdc, 0, y);
        y += 90;
    } while (y <= 360);
}
void DrawTruckDiagonalLine(HDC hdc, int x = 0, int y = 0)
{
    do
    {
        DrawTruck(hdc, x, y);
        x += 50;
        y += 90;
    } while (y <= 360);
}
void Michu(HDC hdc,int x , int y)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 128, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 100+x, 250+y, NULL);
    LineTo(hdc, 150+x, 250+y);
    LineTo(hdc, 175+x, 200+y);
    LineTo(hdc, 125+x, 200+y);
    LineTo(hdc, 100+x, 250+y);
    MoveToEx(hdc, 175+x, 200+y, NULL);
    LineTo(hdc, 150+x, 150+y);
    LineTo(hdc, 175+x, 100+y);
    LineTo(hdc, 200+x, 150+y);
    LineTo(hdc, 175+x, 200+y);
    MoveToEx(hdc, 175+x, 200+y, NULL);
    LineTo(hdc, 225+x, 200+y);
    LineTo(hdc, 250+x, 250+y);
    LineTo(hdc, 200+x, 250+y);
    LineTo(hdc, 175+x, 200+y);

}
void DrawRenoPentagon(HDC hdc) {
    Michu(hdc, 10, 10);
    Michu(hdc, 10, 310);
    Michu(hdc, 310, 10);
    Michu(hdc, 310, 310);
    Michu(hdc, 160, 160);
}
void DrawRenoHorizontalLine(HDC hdc, int x = 0) {
    do {
        Michu(hdc, x, 0);
        x += 150;
    } while (x < 610);
}
void DrawRenoVerticalLine(HDC hdc, int y = 0) {
    do {
        Michu(hdc, 0, y);
        y += 170;
    } while (y < 710);
}
void DrawRenoDiagonalLine(HDC hdc, int x = 0, int y = 0) {
    do
    {
        Michu(hdc, x, y);
        x += 150;
        y += 170;
    } while (y <= 710);
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
            if (numImage == 0)
                //Дом из 3 Лабораторной работы
                Picture1(hdc);
            if (numImage == 1)
                DrawHerringbonePentagon(hdc);
            if (numImage == 2)
                DrawHerringboneHorizontalLine(hdc);
            if (numImage == 3)
                DrawHerringboneVerticalLine(hdc);
            if (numImage == 4)
                DrawHerringboneDiagonalLine(hdc);
            if (numImage == 5)
                DrawTruckPentagon(hdc);
            if (numImage == 6)
                DrawTruckHorizontalLine(hdc);
            if (numImage == 7)
                DrawTruckVerticalLine(hdc);
            if (numImage == 8)
                DrawTruckDiagonalLine(hdc);
            if (numImage == 9)
                DrawRenoPentagon(hdc);
            if (numImage == 10)
                DrawRenoHorizontalLine(hdc);
            if (numImage == 11)
                DrawRenoVerticalLine(hdc);
            if (numImage == 12)
                DrawRenoDiagonalLine(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        numImage++;
        if (numImage >= 13) numImage = 0;
        InvalidateRect(hWnd, NULL, TRUE);
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
