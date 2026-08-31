#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    getline(cin, str);
    vector<ll> vt(26, 0);
    for (auto &x : str)
    {
        vt[x - 'a']++;
    }
    ll res = -1;
    ll i = 0;
    for (auto &x : str)
    {
        if (vt[x - 'a'] == 1)
        {
            res = i;
            break;
        }
        ++i;
    }
    cout << res << endl;
}