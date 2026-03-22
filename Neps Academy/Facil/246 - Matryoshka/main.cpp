#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vt;
    vector<ll> vt2;
    vector<ll> respostas;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vt.push_back(x);
        vt2.push_back(x);
    }

    sort(vt.begin(), vt.end());

    for (ll i = 0; i < n; i++)
    {
        if (vt[i] != vt2[i])
            respostas.push_back(vt[i]);
    }

    if (respostas.size() <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << respostas.size() << endl;
    for (ll i = 0; i < respostas.size() - 1; i++)
    {
        cout << respostas[i] << " ";
    }
    cout << respostas[respostas.size() - 1] << endl;
    return 0;
}