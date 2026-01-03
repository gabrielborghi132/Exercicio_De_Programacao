/**************************************************/
//         1609 - Contando Carneirinhos
// https://judge.beecrowd.com/pt/problems/view/1609*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll t;
        cin >> t;
        unordered_set<ll> st;
        for (int i = 0; i < t; i++)
        {
            ll x;
            cin >> x;
            st.insert(x);
        }
        cout << st.size() << endl;
    }
}