#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    ll in = 0;
    ll out = 0;
    while (t--)
    {
        ll x;
        cin >> x;
        if (x >= 10 && x <= 20)
            in++;
        else
            out++;
    }
    cout << in << " in" << endl;
    cout << out << " out" << endl;
}