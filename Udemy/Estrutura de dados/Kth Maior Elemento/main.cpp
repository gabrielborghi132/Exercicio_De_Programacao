#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> vt = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    sort(vt.begin(), vt.end());
    cout << vt[vt.size() - n] << endl;
}