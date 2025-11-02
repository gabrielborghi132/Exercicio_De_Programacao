#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 501;

int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maiorDist = 0;
int sx3, sy3;

bool dentro(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sx, int sy) {
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    queue<pair<int,int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (dentro(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '#') {
                vis[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                if (dist[nx][ny] > maiorDist) {
                    maiorDist = dist[nx][ny];
                    sx3 = nx;
                    sy3 = ny;
                }
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m, n || m) {
        maiorDist = 0;
        int sx = -1, sy = -1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '.') {
                    sx = i;
                    sy = j;
                }
            }

        if (sx == -1) {
            cout << 0 << endl;
            continue;
        }

        bfs(sx, sy);
        maiorDist = 0;
        bfs(sx3, sy3);

        cout << maiorDist << endl;
    }

    return 0;
}
