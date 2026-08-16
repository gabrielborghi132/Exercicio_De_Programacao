#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    stack<ll> qu;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        if (x != 0)
            qu.push(x);
        else if (!qu.empty())
            qu.pop();
    }
    ll conta = 0;
    while (!qu.empty())
    {
        conta += qu.top();
        qu.pop();
    }
    cout << conta << endl;
    return 0;
}