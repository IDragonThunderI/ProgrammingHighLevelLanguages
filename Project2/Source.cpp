#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double a, b, x;
    const double e = exp(1.0);
    const double pi = atan(1.0) * 4;

    cout << "\nEnter a, b, x:" << endl;
    cin >> a >> b >> x;

    double y = (log(b)) * (a + 1 / sin(x * pi / 180)) * 1 / pow(e, (-b));

    cout << "\ny = " << y << endl;

    return 0;
}
