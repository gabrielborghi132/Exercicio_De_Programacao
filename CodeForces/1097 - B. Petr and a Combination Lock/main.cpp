#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> vt(n, 0);
    bool res = false;
    for (ll i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    for (ll mask = 0; mask < (1LL << n); mask++)
    {
        ll soma = 0;
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1LL << i))
                soma += vt[i];
            else
                soma -= vt[i];
        }
        if (soma == 0 || soma % 360 == 0)
        {
            res = true;
            break;
        }
    }
    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}