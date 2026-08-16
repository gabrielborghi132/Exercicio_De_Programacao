#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll m;
    cin >> m;
    ll h = m / 60;
    m = m % 60;
    cout << h << endl;
    cout << m << endl;
    return 0;
}