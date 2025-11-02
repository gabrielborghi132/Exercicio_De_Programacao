#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1005;

int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dentro(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sx, int sy) {
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
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int sx, sy; // posição inicial
    cin >> sx >> sy;

    bfs(sx, sy);

    cout << "Mapa de distâncias (-1 = inalcançável):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') cout << '#';
            else if (vis[i][j]) cout << dist[i][j] % 10; // mostra distância (módulo 10 p/ caber)
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}
