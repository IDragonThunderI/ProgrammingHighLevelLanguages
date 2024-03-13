#include <iostream>
using namespace std;

int main() {
	int n, len = 0, maxlen = 0, maxp = 0, bp = 0;
	cout << "Enter amount of letters in the string: ";
	cin >> n;
	char* a = new char[n];
	char c[] = ".abcdefghijklmnopqrstuvwxyz";

	srand(time(NULL));
	cout << "\na = {";
	for (int i = 0; i < n; i++) {
		a[i] = c[rand() % ((26) - (0) + 1) + (0)];
		if (i == n - 1) {
			a[i] = c[0];
		}
		cout << a[i];
	}
	cout << "}" << "\n\n";
	
	cout << "b = {";
	for (int i = 0; i < n; i++) {
		if (a[i] == c[0]) {
			if (len > maxlen) {
				maxlen = len;
				maxp = i;
			}
			len = 0;
		} else {
			len++;
		}
	}

	for (int i = maxp - 1; i >= 0; i--) {
		if (a[i] == c[0]) {
			bp = i + 1;
			break;
		}

		if (i == 0) {
			bp = i;
			break;
		}
	}

	for (int i = bp; i <= maxp; i++) {
		cout << a[i];
	}
	cout << "}" << "\n\n";

	delete[] a;
	return 0;
}
