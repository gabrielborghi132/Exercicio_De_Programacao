#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n, m, s, f;
vector<pair<int, int>> g[MAXN];
int dist[MAXN][2];

// algoritmo de dijkstra
void dijkstra(int s)
{
    dist[s][0] = 0;
    priority_queue<tiii> pq;

    pq.push({0, s, 0});
    while (!pq.empty())
    {
        auto [d, u, p] = pq.top();
        pq.pop();
        if (-d > dist[u][p])
            continue;
        for (auto [v, w] : g[u]) {
            int np = 1 - p;
            if (dist[u][p] + w < dist[v][np]) {
                dist[v][np] = dist[u][p] + w;
                pq.push({-dist[v][np], v, np});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, INF, sizeof(dist));
    
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dijkstra(1);

    if (dist[n][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n][0] << endl;
    }

    return 0;
}