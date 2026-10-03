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

    vector<ll> vt(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vt[i];
    }

    ll n1 = n / 2;
    ll n2 = n - n1;

    vector<ll> valores;
    vector<bool> alcancaN2(360, false);

    for (ll mask = 0; mask < (1LL << n1); mask++)
    {
        ll soma = 0;
        for (ll i = 0; i < n1; i++)
        {
            if (mask & (1LL << i))
                soma += vt[i];
            else
                soma -= vt[i];
        }
        valores.push_back(((soma % 360) + 360) % 360);
    }

    for (ll mask = 0; mask < (1LL << n2); mask++)
    {
        ll soma = 0;
        for (ll i = 0; i < n2; i++)
        {
            if (mask & (1LL << i))
                soma += vt[n1 + i];
            else
                soma -= vt[n1 + i];
        }
        alcancaN2[((soma % 360) + 360) % 360] = true;
    }

    bool achou = false;
    for (ll val : valores)
    {
        ll falta = (360 - val) % 360;
        if (alcancaN2[falta])
        {
            achou = true;
            break;
        }
    }

    if (achou)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}