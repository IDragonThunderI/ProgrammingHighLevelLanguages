#include <iostream>
using namespace std;

int main() {
	// Массивы строк в С++. Строки типа string
	// Поиск строки в массиве строк

	// 1. Объявление переменных
	string* AS; // Массив строк
	int count; // Колличество элементов в массиве
	string s; // Искомая строка
	char buf[80]; // Буфер для ввода строк

	// 2. Ввести количество элементов в массиве
	cout << "count = ";
	cin >> count;

	// 3. Проверка, корректно ли значение count
	if (count < 0) {
		cout << "Incorrect input.";
		return 1;
	}

	// 4. Выделить память для count строк
	AS = new string[count];

	// 5. Цикл ввода строк в массив
	cout << "Enter strings:\n";
	cin.ignore(4096, '\n');

	for (int i = 0; i < count; i++) {
		// Строки вводятся с пробелами
		cout << "=> ";
		cin.getline(buf, 80, '\n');
		AS[i] = buf; // Скопировать строку
	}

	// 6. Вывод введённого массива для проверки
	cout << "\nArray AS:" << endl;
	for (int i = 0; i < count; i++) {
		cout << "AS[" << i << "] = " << AS[i] << endl;
	}

	// 7. Ввод искомой строки
	cout << endl << "Enter string:" << endl;
	cin.getline(buf, 80, '\n');
	s = buf; // В переменной s - введённая строка

	// 8. Поиск строки s в массиве AS
	bool f_is = false;
	for (int i = 0; i < count; i++) {
		if (s == AS[i]) {
			// Если строка найдена,
			f_is = true;
			break; // то выйти из цикла
		}
	}

	// 9. Вывод результата
	if (f_is) {
		cout << "String \"" << s << "\" is in the array AS." << endl;
	} else {
		cout << "String \"" << s << "\" is not in the array AS." << endl;
	}

	// 10. Освобождение памяти, выделенной для массива AS
	delete[] AS;
	return 0;
}
