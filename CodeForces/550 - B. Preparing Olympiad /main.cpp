#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<ll> vt(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> vt[i];

    ll res = 0;

    for (ll mask = 0; mask < (1LL << n); mask++)
    {
        ll soma = 0;
        ll maior = LLONG_MIN;
        ll menor = LLONG_MAX;
        if (__builtin_popcountll(mask) < 2)
            continue;
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                soma += vt[i];
                menor = min(vt[i], menor);
                maior = max(vt[i], maior);
            }
        }
        if (((maior - menor) >= x) && soma >= l && soma <= r)
        {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}