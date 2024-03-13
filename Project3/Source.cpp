#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, d;
	double x = 0;
	
	cout << "Enter a, b, c, d: ";
	cin >> a >> b >> c >> d;
	
	if (a < b && b < c && c < d) {
		x = max(max(a, b), max(c, d));
	} else if (a > b && b > c && c > d) {
		x = 0;
	} else {
		a = pow(a, 2), b = pow(b, 2), c = pow(c, 2), d = pow(d, 2);
	}
	
	if (x != 0) {
		a = x, b = x, c = x, d = x;
	}

	cout << "a = " << a << "\tb = " << b << "\tc = " << c << "\td = " << d << endl;

	return 0;
}
