#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll res = LLONG_MIN;
        for (ll i = 0; i < n; i++)
        {
            ll a = 0;
            cin >> a;
            res = max(res, a);
        }
        cout << res << endl;
    }
}
