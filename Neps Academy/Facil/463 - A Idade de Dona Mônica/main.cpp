#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = a - b - c;
    cout << max(b, max(c, d)) << endl;
}