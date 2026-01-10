#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 205;

int n, m;
vector<vector<pair<int, string>>> dist;
bool floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j].first < INF && dist[k][j].first < INF)
                    dist[i][j].first = min(dist[i][j].first, dist[i][k].first + dist[k][j].first);
            }
        }
    }
}
int main()
{
    int t;
    while (cin >> t)
    {
        int a, b;
        string s;
        while (cin >> a >> b >> s, a)
        {
            dist[a].push_back({b, s});
        }
        floyd_warshall();
    }
}