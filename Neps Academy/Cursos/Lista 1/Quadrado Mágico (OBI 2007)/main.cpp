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
    vector<ll> coluna(n, 0);
    vector<ll> linha(n, 0);
    ll diagonal_esq = 0;
    ll diagonal_dir = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> vt[i][j];
            linha[i] += vt[i][j];
            coluna[j] += vt[i][j];
            if (i == j)
                diagonal_dir += vt[i][j];
            if ((i + j) == (n - 1))
                diagonal_esq += vt[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (diagonal_esq == diagonal_dir && diagonal_esq == linha[i] && diagonal_esq == coluna[i])
        {
            continue;
        }
        cout << -1 << endl;
        return 0;
    }
    cout << linha[0] << endl;
    return 0;
}