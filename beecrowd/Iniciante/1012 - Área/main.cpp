#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(3) << "TRIANGULO: " << double(a * c) / 2 << endl;
    cout << fixed << setprecision(3) << "CIRCULO: " << (double)3.14159 * pow(c, 2) << endl;
    cout << fixed << setprecision(3) << "TRAPEZIO: " << (double)((a + b) * c) / 2 << endl;
    cout << fixed << setprecision(3) << "QUADRADO: " << (double)(b * b) << endl;
    cout << fixed << setprecision(3) << "RETANGULO: " << (double)(a * b) << endl;
}