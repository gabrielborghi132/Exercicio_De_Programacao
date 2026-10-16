#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll mini = LLONG_MAX;
        vector<ll> vt(n, 0);
        ll conta = 0;
        for (ll i = 0; i < n; i++)
        {

            cin >> vt[i];
            mini = min(vt[i], mini);
        }
        for (auto &x : vt)
        {
            if (x != mini)
                conta++;
        }
        cout << conta << endl;
    }
    return 0;
}