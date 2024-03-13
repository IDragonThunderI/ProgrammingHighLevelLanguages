#include <iostream>
using namespace std;

int main() {
	// Массивы строк в С++. Строки типа string
	// Сортировка массива строк методом вставки

	// 1. Объявление переменных
	string* AS; // Массив строк, который нужно отсортировать
	int count; // Количество элементов в массиве
	string s; // Дополнительная переменная-строка
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
		cout << "A[" << i << "] = " << AS[i] << endl;
	}

	// 7. Сортировка массива AS по возрастанию
	for (int i = 0; i < count - 1; i++) {
		for (int j = i; j >= 0; j--) {
			if (AS[j] > AS[j + 1]) {
				// Поменять местами строки
				s = AS[j];
				AS[j] = AS[j + 1];
				AS[j + 1] = s;
			}
		}
	}

	// 8. Вывод посортированного массива AS
	cout << "\nSorted array AS:\n";
	for (int i = 0; i < count; i++) {
		cout << "AS[" << i << "] = " << AS[i] << endl;
	}

	// 9. Освобождение памяти, выделенной для массива AS
	delete[] AS;
	return 0;
}
