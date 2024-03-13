#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int n = 10;
	double a[n];
	double b[n];

	srand(time(NULL));
	cout << "a = {";
	for (int i = 0; i < n; i++) {
		a[i] = double(rand()) / RAND_MAX * (9.9 - (-9.9)) + (-9.9);
		cout << setprecision(2) << a[i] << "\t";
		b[i] = 0;
	}
	cout << "}" << endl << endl << "b = {";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != i) {
				b[i] += a[j];
			}
		}
		
		b[i] /= n - 1;
		cout << setprecision(2) << b[i] << "\t";
	}
	cout << "}" << endl;

	return 0;
}
