#include <iostream>
using namespace std;

int main() {
	int code;
	struct Employees {
		int number; // Табельный номер
		char name[30]; // ФИО
		int year; // Год рождения
		char gender[7]; // Пол
		int code; // Код отдела
	};

	int n;
	Employees st[30]{}; // Описан массив структур

	cout << "Enter the number of employees: ";
	cin >> n;

	// Ввод значений полей структуры
	for (int i = 0; i < n; i++) {
		cout << "\nPersonnel number: ";
		cin >> st[i].number;
		cout << "\nFull name: ";
		cin >> st[i].name;
		cout << "\nYear of birth: ";
		cin >> st[i].year;
		cout << "\nGender: ";
		cin >> st[i].gender;
		cout << "\nDepartment code: ";
		cin >> st[i].code;
	}

	cout << "\nEnter the department code: ";
	cin >> code;
	cout << "\nFound employees: " << endl;

	for (int i = 0, k = -1; i < n; i++) {
		// Поиск искомых сотрудников
		if (code == st[i].code) {
			k = i;
		}

		if (k != -1) {
			cout << "\n " << st[i].number << endl;
			cout << "\n " << st[i].name << endl;
			cout << "\n " << st[i].year << endl;
			cout << "\n " << st[i].gender << endl;
			cout << "\n " << st[i].code << endl;
			cout << "\n-----------------------------" << endl;
			k = -1;
		}
	}

	return 0;
}
