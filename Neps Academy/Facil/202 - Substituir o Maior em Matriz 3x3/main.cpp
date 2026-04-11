#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    vector<vector<ll>> vt(3, vector<ll>(3));
    ll maior = LONG_MIN;
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            cin >> vt[i][j];
            maior = max(maior, vt[i][j]);
        }
    }

    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            if (vt[i][j] == maior)
            {
                vt[i][j] = -1;
            }
        }
    }

    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            cout << vt[i][j] << " ";
        }
        cout << vt[i][2] << endl;
    }
}