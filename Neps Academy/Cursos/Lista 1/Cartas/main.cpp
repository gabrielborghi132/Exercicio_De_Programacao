#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b)
        cout << c << endl;
    else if (a == c)
        cout << b << endl;
    else
        cout << a << endl;
    return 0;
}