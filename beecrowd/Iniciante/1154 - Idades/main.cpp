#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int soma = 0;
    int t = 0;
    while (cin >> n, n >= 0)
    {
        soma += n;
        t++;
    }
    cout << fixed << setprecision(2) << (double)soma / t << endl;
}