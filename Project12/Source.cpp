#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, k = -1;
	float s = 0;
	char name[30];
	struct Tovar {
		char name[30]; // Наименование
		int amount; // Количество
		float price; // Цена
	} mas[100]{}; // Массив структур

	cout << "Enter amount of product n: ";
	cin >> n;

	// Ввод значений полей стуктуры
	for (int i = 0; i < n; i++) {
		cout << "\nName: ";
		cin >> mas[i].name;
		cout << "\nAmount: ";
		cin >> mas[i].amount;
		cout << "\nPrice: ";
		cin >> mas[i].price;
	}

	cout << "\nEnter the name of the desired product: ";
	cin >> name; // Искомый товар

	for (int i = 0; i < n; i++) {
		// Поиск номера искомого товара
		if (strcmp(name, mas[i].name) == 0) {
			k = i;
		}
		// Подсчёт общей стоимости товаров на складе
		s += mas[i].amount * mas[i].price;

		if (k != -1) {
			cout << "\n" << mas[k].name << " " << mas[k].amount << " " << mas[k].price << endl;
			break;
		}
	}

	if (k == -1) {
		cout << "\nProduct not found" << endl;
	}

	cout << "\nTotal price of products = " << s << endl;

	return 0;
}
