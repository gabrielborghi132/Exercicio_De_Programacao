#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 16;

    list<char> vt;

    char x = 'A';

    for (ll i = 0; i < n; i++)
    {
        vt.push_back(x);
        x++;
    }

    ll a, b;
    auto pt = vt.begin();

    while (vt.size() > 1)
    {
        cin >> a >> b;

        if (a > b)
        {
            ++pt;
            pt = vt.erase(pt);
        }
        else
        {
            pt = vt.erase(pt);
            ++pt;
        }

        if (pt == vt.end())
            pt = vt.begin();
    }

    cout << vt.back() << endl;
}