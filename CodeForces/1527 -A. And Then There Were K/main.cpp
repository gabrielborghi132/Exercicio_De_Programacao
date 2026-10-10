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
        ll bit = 0;
        cin >> bit;
        cout << __bit_floor((unsigned ll)bit) - 1 << endl;
    }
    return 0;
}