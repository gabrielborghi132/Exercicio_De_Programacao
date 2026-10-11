#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n = 0;
    cin >> n;
    while (n--)
    {
        ll t = 0;
        cin >> t;
        vector<ll> vt(t, 0);
        unordered_set<ll> st;
        for (ll i = 0; i < t; i++)
        {
            cin >> vt[i];
            st.insert(vt[i]);
        }
        for (ll i = 0; i < vt.size(); i++)
        {
            ll conta = 0;
            bool res = false;
            for (ll j = 0; j < vt.size(); j++)
            {
                if (j == i)
                    continue;
                conta ^= vt[j];
                if (st.find(conta) != st.end())
                {
                    cout << conta << endl;
                    res = true;
                    break;
                }
            }
            if (res)
                break;
        }
    }
    return 0;
}