#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 5000;

int n;
unordered_map<string, int> id;
unordered_map<int, string> idReverso;
unordered_map<string, int> idPalavras;
unordered_map<int, string> idPalavrasReverso;

using tiii = tuple<int, int, int>;
vector<tiii> g[MAXN];
int dist[MAXN][27];
void dijkstra(int s, char letra)
{
    priority_queue<tiii> pq;
    dist[s][letra] = 0;
    pq.push({0, s, letra});

    while (!pq.empty())
    {
        auto [d, u, last] = pq.top();
        pq.pop();
        if (-d > dist[u][last])
            continue;

        for (auto [v, w, c] : g[u])
        {
            if (c == last)
                continue;
            if (dist[v][c] > dist[u][last] + w)
            {
                dist[v][c] = dist[u][last] + w;
                pq.push({-dist[v][c], v, c});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n)
    {
        id.clear();
        idReverso.clear();
        idPalavras.clear();
        idPalavrasReverso.clear();
        for (int i = 0; i < MAXN; i++)
        {
            g[i].clear();
            for (int j = 0; j < 27; j++)
            {
                dist[i][j] = INF;
            }
        }
        string inicio, fim;
        cin >> inicio >> fim;
        int counter = 0;
        int idx = 0;
        id[inicio] = idx++;
        id[fim] = idx++;
        for (int i = 0; i < n; i++)
        {
            string s, s2, s3;
            cin >> s >> s2 >> s3;

            if (!id.count(s))
                id[s] = idx++;
            if (!id.count(s2))
                id[s2] = idx++;
            if (!id.count(s3))
            {
                idPalavras[s3] = counter++;
            }
            idReverso[id[s]] = s;
            idReverso[id[s2]] = s2;
            idReverso[idPalavras[s3]] = s3;
            g[id[s]].push_back({id[s2], s3.size(), s3[0] - 'a'});
            g[id[s2]].push_back({id[s], s3.size(), s3[0] - 'a'});
        }

        dijkstra(id[inicio], 26);
        int ans = INF;
        for (int c = 0; c < 27; c++)
        {
            ans = min(ans, dist[id[fim]][c]);
        }

        if (ans == INF)
            cout << "impossivel" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}