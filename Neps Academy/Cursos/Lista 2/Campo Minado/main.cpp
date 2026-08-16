#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    vector<ll> vet(x);
    vector<ll> res(x);
    res.assign(x, 0);
    for (ll i = 0; i < x; i++)
    {
        cin >> vet[i];
    }
    for (ll i = 0; i < x; i++)
    {
        if (i == 0)
        {
            res[i] = vet[i] + vet[i + 1];
        }
        else if (i == (x - 1))
        {
            res[i] = vet[i] + vet[i - 1];
        }
        else
        {
            res[i] = vet[i] + vet[i + 1] + vet[i - 1];
        }
    }
    for (ll i = 0; i < x; i++)
    {
        cout << res[i] << endl;
    }
}