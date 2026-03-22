#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    // {-ouro, -prata, -bronze, id} — negativos para inverter a ordem
    vector<pair<array<ll, 3>, ll>> posicao;

    for (ll i = 1; i <= n; i++)
        posicao.push_back({{0, 0, 0}, i});

    for (ll i = 0; i < m; i++)
    {
        ll o, p, b;
        cin >> o >> p >> b;

        posicao[o - 1].first[0] += 1; // ouro
        posicao[p - 1].first[1] += 1; // prata
        posicao[b - 1].first[2] += 1; // bronze
    }

    sort(posicao.begin(), posicao.end(), [](auto &x, auto &y)
         {
             if (x.first[0] != y.first[0])
                 return x.first[0] > y.first[0];
             if (x.first[1] != y.first[1])
                 return x.first[1] > y.first[1];
             if (x.first[2] != y.first[2])
                 return x.first[2] > y.first[2];
             return x.second < y.second; });

    for (ll i = 0; i < n; i++)
        cout << posicao[i].second << " \n"[i == n - 1];

    return 0;
}