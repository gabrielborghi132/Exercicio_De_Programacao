#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1005;

int n;             
char grid[MAX][MAX];  
bool vis[MAX][MAX];  

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dentro(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dentro(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '1') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(vis, false, sizeof(vis));
        memset(grid, 0, sizeof(grid));

        int count1 = 0, count0 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '1') count1++;
            }
        }

        // Explorar as bordas
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == '0') dfs(0, j);
            if (grid[n-1][j] == '0') dfs(n-1, j);
            if (grid[j][0] == '0') dfs(j, 0);
            if (grid[j][n-1] == '0') dfs(j, n-1);
        }

        // Contar zeros não visitados (fechados)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' && !vis[i][j]) {
                    count0++;
                }
            }
        }

        double result = (count1 + count0) / 2.0;
        cout << fixed << setprecision(2) << result << endl;
    }
    return 0;
}
