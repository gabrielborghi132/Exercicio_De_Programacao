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
    vector<vector<ll>> vt(n, vector<ll>(n, 0));
    vector<ll> linha(n, 0);
    vector<ll> coluna(n, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> vt[i][j];
            linha[i] += vt[i][j];
            coluna[j] += vt[i][j];
        }
    }
    ll maior = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            maior = max(maior, coluna[j] + linha[i] - 2 * vt[i][j]);
        }
    }
    cout << maior << endl;
}