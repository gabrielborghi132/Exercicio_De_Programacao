#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == c || b == d)
        cout << "V" << endl;
    else
        cout << "F" << endl;
}