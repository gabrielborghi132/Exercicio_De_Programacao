#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> vt(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    ll maior = vt[n - 1] * vt[n - 2] * vt[n - 3];
    ll maior2 = vt[0] * vt[1] * vt[n - 1];
    cout << max(maior, maior2) << endl;
}