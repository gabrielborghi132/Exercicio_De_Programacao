#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    ll conta = 0;
    cin >> a >> b;
    vector<vector<char>> vt;
    vt.assign(a + 2, vector<char>(b + 2, '.'));
    for (ll i = 1; i <= a; i++)
    {
        for (ll j = 1; j <= b; j++)
        {
            cin >> vt[i][j];
        }
    }

    for (ll i = 1; i <= a; i++)
    {
        for (ll j = 1; j <= b; j++)
        {
            if (vt[i][j] == '#')
                if (vt[i - 1][j] == '.' || vt[i + 1][j] == '.' || vt[i][j - 1] == '.' || vt[i][j + 1] == '.')
                    conta++;
        }
    }
    cout << conta << endl;
}