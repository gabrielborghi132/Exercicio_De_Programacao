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
    vector<ll> vt(13, 0);
    ll x;
    ll maior = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        vt[x]++;
        maior = max(vt[x], maior);
    }
    for (ll i = 0; i < 13; i++)
    {
        if (vt[i] == maior)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}