#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll escolha, a, b;
    set<pair<ll, ll>> st;
    for (ll i = 0; i < m; i++)
    {
        cin >> escolha >> a >> b;
        if (b < a)
            swap(a, b);
        if (escolha == 1)
        {
            st.insert({a, b});
        }
        else
        {
            cout << st.count({a, b}) << endl;
        }
    }
}