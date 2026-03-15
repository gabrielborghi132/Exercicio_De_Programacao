#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> vt(9, vector<ll>(9, 0));
    ll col_1 = 0;
    ll col_2 = 0;
    ll col_3 = 0;
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            ll x = 0;
            cin >> x;
            if (j == 0)
                col_1 += x;
            else if (j == 1)
                col_2 += x;
            else
                col_3 += x;
        }
    }
    cout << "Coluna 0: " << col_1 << endl;
    cout << "Coluna 1: " << col_2 << endl;
    cout << "Coluna 2: " << col_3 << endl;
}