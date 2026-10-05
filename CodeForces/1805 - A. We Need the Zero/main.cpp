#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n = 0;
    cin >> n;
    while (n--)
    {
        ll t = 0;
        cin >> t;
        ll res = 0;
        for (ll i = 0; i < t; i++)
        {
            ll x = 0;
            cin >> x;
            res ^= x;
        }
        if (t & 1)
            cout << res << endl;
        else if (res == 0)
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}