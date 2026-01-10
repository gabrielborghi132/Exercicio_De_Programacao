#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll x;
    cin >> x;
    while (x--)
    {
        double a, b, c;
        cin >> a >> b >> c;
        cout << fixed << setprecision(1) << (a * 2 + b * 3 + c * 5) / 10 << endl;
    }
}