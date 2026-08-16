#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll mdc(ll a, ll b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    while (cin >> t && t > 0)
    {
        ll maior = -INT_MAX;
        ll menor = INT_MAX;
        ll x = 0;
        cin >> x;
        maior = x;
        menor = x;
        for (ll i = 0; i < t - 1; i++)
        {
            cin >> x;
            maior = max(maior, x);
            menor = min(menor, x);
        }
        cout << mdc(maior, menor) << endl;
    }
}