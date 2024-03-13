#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void moveCircle(HDC hdc, HRGN rgnBall, HBRUSH bkBrush, HBRUSH fBrush, int right);

int main() {
	AllocConsole();
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	HWND hwnd = GetConsoleWindow(); // Берём ориентир на консольное окно (в нём будем рисовать)
	HDC hdc = GetDC(hwnd); // Цепляемся к консольному окну (дескриптор консоли)
	RECT WinCoord; // Массив координат окна
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); // Задаём полноэкранный размер окна
	GetWindowRect(hwnd, &WinCoord); // Получаем координаты окна
	Sleep(100); // Задержка для перехода в полноэкранный режим ДО создания рисунка

	int x, y, r;
	COORD coord = { 60, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "###!!! To stop the animation, press Esc !!!###" << endl;
	cout << "\nEnter the coordinates of the center of the circle and its radius (x, y, r): ";
	cin >> x >> y >> r;
	system("cls");
	Sleep(100);

	HBRUSH bkBrush = CreateSolidBrush(RGB(255, 255, 255)); // Создаём кисть определённого стиля и цвета
	HRGN bgRgn = CreateRectRgnIndirect(&WinCoord); // "Выделяем" область всего окна консоли
	FillRgn(hdc, bgRgn, bkBrush); // Заливаем фон консоли

	HBRUSH circleBrush = CreateSolidBrush(RGB(255, 0, 0));
	HRGN rgnCircle = CreateEllipticRgn(x - r, y - r, x + r, y + r); // "Выделяем" область круга в указанных координатах
	FillRgn(hdc, rgnCircle, circleBrush); // Заливаем область круга цветом
	
	int ikey = 67, i = 0, t = 50, acceleration = 1;
	while (ikey != 27) { // Выход по нажатию Esc
		if (_kbhit()) {
			ikey = _getch();
		}

		if (i % 10 == 0 && t > 1) {
			t--;
			if (acceleration < 10) {
				acceleration++;
			}
		}

		if (i < WinCoord.right - x - r) {
			moveCircle(hdc, rgnCircle, bkBrush, circleBrush, acceleration);
			Sleep(t);
			i += acceleration;
		} else {
			Sleep(1000);
			break;
		}
	}

	coord = { 60, 25 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	system("Pause");
	DeleteObject(bkBrush);
	DeleteObject(circleBrush);
	DeleteObject(bgRgn);
	DeleteObject(rgnCircle);
	ReleaseDC(hwnd, hdc); // Освобождаем дескрипторы консоли
	FreeConsole();
	return 0;
}

void moveCircle(HDC hdc, HRGN rgnCircle, HBRUSH bkBrush, HBRUSH circleBrush, int right) {
	FillRgn(hdc, rgnCircle, bkBrush);
	OffsetRgn(rgnCircle, right, 0);
	FillRgn(hdc, rgnCircle, circleBrush);
}
