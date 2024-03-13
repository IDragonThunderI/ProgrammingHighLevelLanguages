#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int n;
	double sum = 0;

	cout << "Enter size of the array: ";
	cin >> n;

	double *a = new double [n];

	srand(time(NULL));
	cout << "\na = {";
	for (int i = 0; i < n; i++) {
		a[i] = double(rand()) / RAND_MAX * (9.9 - (-9.9)) + (-9.9);
		cout << setprecision(2) << a[i] << "\t";
	}
	cout << "}" << endl << endl;

	for (int i = 0; i < n; i++) {
		if (abs(a[i]) > 2.5) { 
			sum += pow(a[i], 2.0);
		}
	}
	cout << "Sum of squares of numbers with modulus greater than 2.5 = " << fixed << sum << endl << endl;

	delete[] a;
	return 0;
}
