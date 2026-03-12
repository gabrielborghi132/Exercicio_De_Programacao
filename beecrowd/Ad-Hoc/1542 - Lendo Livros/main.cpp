#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ll a, b, c;
    while (cin >> a, a)
    {
        cin >> b >> c;
        double x = abs(c - a);
        x = (b * c) / x;

        int sum = floor(c * (x - b));
        if (sum == 1)
            cout << sum << " pagina" << endl;
        else
            cout << sum << " paginas" << endl;
    }
    return 0;
}