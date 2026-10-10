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
        ll a, b;
        cin >> a >> b;
        cout << (a ^ b) << endl;
    }
    return 0;
}