#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    ll x = 2;
    for (ll i = 0; x <= t; i++)
    {
        cout << fixed << setprecision(0) << x << "^2 = " << pow(x, 2) << endl;
        x += 2;
    }
}