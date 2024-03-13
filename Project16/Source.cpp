#include <iostream>
using namespace std;

int main() {
	int n, p = -1;
	cout << "Enter amount of numbers in the string: ";
	cin >> n;
	char* a = new char[n];
	char* b = new char[n];
	char c[] = ".,,,,,1234567890";

	srand(time(NULL));
	cout << "a = {";
	for (int i = 0; i < n; i++) {
		a[i] = c[rand() % ((15) - (0) + 1) + (0)];
		if (i == n - 1) {
			a[i] = c[0];
		}
		cout << a[i];
	}
	cout << "}" << "\n\n";

	cout << "b = {";
	for (int i = 0; i < n; i++) {
		if (a[i] == c[0]) {
			break;
		} else if (a[i] != c[1]) {
			b[i] = a[i];
			cout << b[i];
		}
		p = i;
	}

	for (int i = p + 1; i < n; i++) {
		b[i] = a[i];
		cout << b[i];
	}
	cout << "}" << "\n\n";

	delete[] a;
	delete[] b;
	return 0;
}
