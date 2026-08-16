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
    ll conta = 0;
    for (ll i = 0; i < n; i++)
    {
        ll l, c;
        cin >> l >> c;
        if (l > c)
            conta += c;
    }
    cout << conta << endl;
    return 0;
}