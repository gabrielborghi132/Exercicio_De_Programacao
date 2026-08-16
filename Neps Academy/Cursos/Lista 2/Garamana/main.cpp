#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string p, a;
    cin >> p >> a;
    vector<ll> vt(1e6, 0);
    ll conta = 0;
    for (auto &x : a)
    {
        if (x != '*')
        {
            vt[x] += 1;
            conta++;
        }
    }
    for (auto &x : p)
    {
        if (x != '*' && vt[x] - 1 >= 0)
        {
            vt[x] -= 1;
            conta--;
        }
    }
    if (conta == 0)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}