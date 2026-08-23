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
    vector<pair<ll, ll>> vt(n);
    ll s, e;
    for (ll i = 0; i < n; i++)
    {
        cin >> s >> e;
        vt[i] = {s, e};
    }
    sort(vt.begin(), vt.end());
    ll ini;
    ll fim;
    string res = "NO";
    for (ll i = 0; i < n - 1; i++)
    {
        ini = vt[i].second;
        fim = vt[i + 1].first;
        if (ini > fim)
            res = "YES";
    }
    cout << res << endl;
    return 0;
}