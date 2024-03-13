#include <iostream>
#include <cmath>
using namespace std;

double power(double a, double b);

int main() {
	double z = 0;

	for (double x = -1.1; x <= 0.3; x += 0.2) {
		for (double m = 1.0; m <= 5.0; m++) {
			z = power(x, m) * power(sin(x * m), m);
			cout << "z(" << x << ", " << m << ") = " << z << ";   ";
		}
		cout << endl << endl;
	}

	return 0;
}

double power(double a, double b) {
	double r = 1.0;

	for (int i = 0; i < b; i++) {
		r *= a;
	}

	return r;
}
