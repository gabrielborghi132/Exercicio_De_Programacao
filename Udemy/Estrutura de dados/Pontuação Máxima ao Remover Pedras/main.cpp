#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> vt(3, 0);
    cin >> vt[0] >> vt[1] >> vt[2];
    sort(vt.begin(), vt.end());
    if (vt[0] + vt[1] <= vt[2])
        cout << vt[0] + vt[1] << endl;
    else
        cout << (vt[0] + vt[1] + vt[2]) / 2 << endl;
}