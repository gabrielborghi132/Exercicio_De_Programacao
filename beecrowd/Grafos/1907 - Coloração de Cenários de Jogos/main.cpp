#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1024;
int n, m; 
char grid[MAX+1][MAX+1];
bool visitado[MAX+1][MAX+1];
stack<int> st;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y){
    stack<pair<int,int>> pilha;
    pilha.push({x,y});
    visitado[x][y] = true;
    while(!pilha.empty()){
        auto [cx, cy] = pilha.top();
        pilha.pop();
        for(int i=0;i<4;++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx>=0 && nx<n && ny>=0 &&ny<m ){
                if(!visitado[nx][ny]&&grid[nx][ny] == '.'){
                    visitado[nx][ny] = true;
                    pilha.push({nx,ny});
                }

            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int contagem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j] == '.'&&!visitado[i][j]){
                contagem++;
                dfs(i,j);
            }
        }
    }
    cout<<contagem<<endl;
    return 0;
}