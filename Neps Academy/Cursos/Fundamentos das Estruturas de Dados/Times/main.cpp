#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    ll a, b;
    cin >> a >> b;
    cin.ignore();
    priority_queue<pair<ll, string>> pq;
    vector<vector<string>> vt(b);
    while (a--)
    {
        string str;
        ll c;
        cin >> str >> c;
        pq.push({c, str});
    }
    while (!pq.empty())
    {
        for (ll j = 0; j < b; j++)
        {
            if (!pq.empty())
            {
                vt[j].push_back(pq.top().second);
                pq.pop();
            }
        }
    }
    for (ll j = 0; j < b; j++)
    {
        sort(vt[j].begin(), vt[j].end());
    }
    for (ll i = 0; i < b; i++)
    {
        cout << "Time " << i + 1 << endl;
        for (ll j = 0; j < vt[i].size(); j++)
        {
            cout << vt[i][j] << endl;
        }
        if (i + 1 < b)
            cout << endl;
    }
    return 0;
}