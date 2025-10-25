#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int inv(int x) {
    int i = 0;
    while (x) {
        i = i * 10 + x % 10;
        x /= 10;
    }
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    int dist[MAX + 1];
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int vis[MAX + 1] = {};
        queue<int> q;

        q.push(a);
        vis[a] = 1;
        dist[a] = 0;

        while (!vis[b]) {
            int x = q.front();
            q.pop();

            int nxt[2] = {x + 1, inv(x)};
            for (auto k : nxt) {
                if (k > MAX) continue;
                if (!vis[k]) {
                    vis[k] = 1;
                    dist[k] = dist[x] + 1;
                    q.push(k);
                }
            }
        }
        cout << dist[b] << "\n";
    }

    return 0;
}