#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> vt(10, 0);
    for (ll i = 0; i < 10; i++)
    {
        cin >> vt[i];
    }
    reverse(vt.begin(), vt.end());
    for (ll i = 0; i < 10; i++)
    {
        cout << vt[i] << endl;
    }
}