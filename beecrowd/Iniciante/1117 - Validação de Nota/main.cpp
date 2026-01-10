#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    double soma = 0;
    int t = 0;
    while (cin >> n, t != 2)
    {
        if (n >= 0 && n <= 10)
        {
            soma += n;
            t++;
        }
        else
        {
            cout << "nota invalida" << endl;
        }
    }
    cout << fixed << setprecision(2) << "media = " << (double)soma / t << endl;
}