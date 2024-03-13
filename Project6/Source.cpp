#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int n = 10;
	const int m = 10;
	double a[n];
	double b[m];

	srand(time(NULL));
	cout << "a = {";
	for (int i = 0; i < n; i++) {
		a[i] = double(rand()) / RAND_MAX * (9.9 - (-9.9)) + (-9.9);
		cout << setprecision(2) << a[i] << "\t";
	}
	cout << "}" << endl << endl << "b = {";

	for (int j = 0; j < m; j++) {
		b[j] = double(rand()) / RAND_MAX * (9.9 - (-9.9)) + (-9.9);
		cout << setprecision(2) << b[j] << "\t";
	}
	cout << "}" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				a[i] = 0;
			}
		}
	}

	double min = 10;
	for (int i = 0; i < n; i++) {
		if (a[i] < min && a[i] != 0) {
			min = a[i];
		}
	}

	cout << endl << setprecision(2) << "min = " << min << endl;

	return 0;
}
