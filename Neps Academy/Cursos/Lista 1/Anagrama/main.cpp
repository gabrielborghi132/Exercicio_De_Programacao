#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    string s;
    string s2;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    getline(cin, s2);

    vector<ll> vt(26, 0);
    vector<ll> vt2(26, 0);

    for (auto &x : s)
    {
        if (x >= 'a' && x <= 'z')
        {
            vt[x - 'a']++;
        }
    }
    for (auto &x : s2)
    {
        if (x >= 'a' && x <= 'z')
        {
            vt2[x - 'a']++;
        }
    }
    bool passou = true;
    for (ll i = 0; i < 26; i++)
    {
        if (vt[i] != vt2[i])
        {
            passou = false;
            break;
        }
    }
    if (passou)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}