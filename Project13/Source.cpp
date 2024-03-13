#include <iostream>
using namespace std;

int main() {
	struct Student {
		char name[30]; // ФИО
		int year; // Год рождения
		int bal[3]; // Оценки, массив
	};

	int n;
	Student st[30]{}; // Описан массив структур

	cout << "Enter numbers of students: ";
	cin >> n;

	// Ввод значений полей структуры
	for (int i = 0; i < n; i++) {
		cout << "\nFull name: ";
		cin >> st[i].name;
		cout << "\nYear of birth: ";
		cin >> st[i].year;
		cout << "\nGrades: ";
		for (int j = 0; j < 3; j++)
			cin >> st[i].bal[j];
	}

	// Сортировка элементов массива по полю ФИО
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n - 1; i++) {
			if (st[i].name[0] > st[i + 1].name[0]) {
				swap(st[i], st[i + 1]);
			}
		}
	}

	cout << "\nSorted array:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "\n" << st[i].name << endl;
		cout << "\n" << st[i].year << endl << endl;
		for (int j = 0; j < 3; j++) {
			cout << st[i].bal[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
