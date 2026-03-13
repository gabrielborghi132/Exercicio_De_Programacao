#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    ll copos = 0;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (b < a)
            copos += b;
    }
    cout << copos << endl;
}