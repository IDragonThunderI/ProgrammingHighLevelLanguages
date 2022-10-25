#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double a, b, x;
    double e = exp(1.0);

    cout << "\n Enter a, b, x" << endl;
    cin >> a >> b >> x;

    double y = (a + tan(x * 3.14 / 180)) * (b + log(a)) * pow(e, (-b));

    cout << "\n y=" << y << endl;

    system("pause");
    return 0;
}
