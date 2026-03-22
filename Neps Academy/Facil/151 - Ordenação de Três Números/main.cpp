#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> vt(3, 0);
    cin >> vt[0] >> vt[1] >> vt[2];
    sort(vt.begin(), vt.end());
    cout << vt[0] << endl;
    cout << vt[1] << endl;
    cout << vt[2] << endl;

    return 0;
}