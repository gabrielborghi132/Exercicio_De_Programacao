#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ll pos = INT_MAX;
    ll n;
    cin >> n;
    vector<ll> vet(n);
    vector<ll> res(n);
    vet.assign(n, 0);
    res.assign(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if (vet[i] == 0)
        {
            pos = 1;
            continue;
        }
        res[i] = max(vet[i], pos);
        if (res[i] > 9)
            res[i] = 9;
        pos++;
    }
    pos = INT_MAX;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (vet[i] == 0)
        {
            pos = 1;
            continue;
        }
        res[i] = min(res[i], pos);
        if (res[i] > 9)
            res[i] = 9;
        pos++;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        cout << res[i] << " ";
    }
    cout << res[n - 1] << endl;
}