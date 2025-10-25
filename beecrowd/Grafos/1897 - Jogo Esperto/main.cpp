#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 100000;

unordered_map<int,int> dist;

void bfs(int inicio, int alvo) {
    queue<int> q;
    q.push(inicio);
    dist[inicio] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == alvo) return;

        vector<int> vizinhos = {u*2, u*3, u/2, u/3, u+7, u-7};

        for (int &v : vizinhos) {
            if (v <= MAX && dist.find(v) == dist.end()) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int inicio, alvo;
    cin >> inicio >> alvo;
    bfs(inicio, alvo);
    cout << dist[alvo] << endl;
    return 0;
}