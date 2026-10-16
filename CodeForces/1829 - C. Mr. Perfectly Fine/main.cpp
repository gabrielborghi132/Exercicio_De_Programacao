#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

struct Comparador
{
    bool operator()(const pair<ll, ll> &pa, const pair<ll, ll> &pb) const
    {
        if (pa.first != pb.first)
            return pa.first > pb.first;
        return pa.second > pb.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 0;
    cin >> n;
    while (n--)
    {
        ll t = 0;
        cin >> t;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Comparador> pq;

        for (ll i = 0; i < t; i++)
        {
            pair<ll, ll> pa;
            cin >> pa.first >> pa.second;
            pq.push(pa);
        }

        ll mask = 3;
        ll conta = 0;

        while (!pq.empty())
        {
            auto topo = pq.top();
            pq.pop();

            if (mask & topo.second)
            {
                mask &= ~(topo.second);
                conta += topo.first;
            }

            if (mask == 0)
                break;
        }

        if (mask == 0)
            cout << conta << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}