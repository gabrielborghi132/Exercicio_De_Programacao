#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> vt(200, false);

    for (ll i = 0; i < 10; i++)
    {
        ll x;
        cin >> x;
        if (vt[x] == false)
            vt[x] = true;
    }
    ll n;
    cin >> n;
    if (vt[n])
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;
}