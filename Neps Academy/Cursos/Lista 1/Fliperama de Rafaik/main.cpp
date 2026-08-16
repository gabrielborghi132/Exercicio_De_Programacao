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
    vector<ll> vt(n, 0LL);
    ll soma = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> vt[i];
        soma += vt[i];
    }
    if (soma % 2 != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    ll l = 0, r = n - 1;
    ll conta = 0;
    while (l < r)
    {
        ll step = min(vt[l], vt[r]);
        vt[l] -= step;
        vt[r] -= step;
        conta += step;

        if (vt[l] == 0 && vt[r] == 0)
        {
            if (r - l == 1)
                break;
            r--;
            l++;
            conta += 2;
        }
        else if (vt[l] == 0)
        {
            l++;
            conta++;
        }
        else
        {
            r--;
            conta++;
        }
    }
    if (l == r)
    {
        conta += vt[l] / 2;
    }
    cout << conta << endl;
    return 0;
}