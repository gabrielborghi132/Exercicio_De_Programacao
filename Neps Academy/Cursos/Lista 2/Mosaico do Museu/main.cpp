#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<ll> counting(1e6, 0);
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> vt(n + 2, vector<ll>(m + 2, 0));
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                cin >> vt[i][j];
                counting[vt[i][j]] = 1;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (vt[i][j] == vt[i - 1][j] || vt[i][j] == vt[i + 1][j] || vt[i][j] == vt[i][j - 1] || vt[i][j] == vt[i][j + 1])
                {
                    counting[vt[i][j]] = 2;
                }
            }
        }
        ll conta = 0;
        ll maior = -INT_MAX;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (counting[vt[i][j]] != 0)
                {
                    conta += counting[vt[i][j]];
                    maior = max(maior, counting[vt[i][j]]);
                    counting[vt[i][j]] = 0;
                }
            }
        }
        conta -= maior;
        cout << conta << endl;
    }
}