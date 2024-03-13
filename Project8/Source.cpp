#include <iostream>
using namespace std;

int main() {
	const int n = 4;
	const int m = 4;
	int a[n][m];
	int sum = 0;
	
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 41 - 20;
			cout << a[i][j] << "\t";
		}
	}
	cout << endl << endl;

	int b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i <= j) {
				for (int k = 1; k < n; k++) {
					for (int l = 0; l < (m - 1); l++) {
						if (k > l) {
							if (a[i][j] < a[k][l]) {
								b += 1;
							}
						}
					}
				}

				if (b == 0) {
					sum += a[i][j];
				} else {
					b = 0;
				}
			}
		}
	}

	if (sum == 0) {
		cout << "No items match the conditions (sum = 0)";
	} else {
		cout << "sum = " << sum;
	}
	cout << endl << endl;

	return 0;
}
