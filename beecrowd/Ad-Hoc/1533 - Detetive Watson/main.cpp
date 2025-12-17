/**************************************************/
//        1533 - Detetive Watson
// https://judge.beecrowd.com/pt/problems/view/1533
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n)
    {
        ll i = 0;
        vector<pair<ll, ll>> a;
        for (ll j = 0; j < n; j++)
        {
            ll x;
            cin >> x;
            a.push_back({x, i});
            i++;
        }
        sort(a.begin(), a.end());
        cout << a[n - 2].second + 1 << endl;
    }
}