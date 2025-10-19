#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
bool visitado[MAX+1][MAX+1];
int grafo[MAX+1][MAX+1];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin>>grafo[i][j];
        }
    }
    auto bfs = [&](int inicioX,int inicioY){
        queue<pair<int,int>> fila;
        fila.push({inicioX,inicioY});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!fila.empty()){
            auto [x,y] = fila.front();
            fila.pop();
            for(int dir = 0; dir < 4; ++dir){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(!visitado[nx][ny] && grafo[nx][ny] == 1){
                        fila.push({nx,ny});
                        visitado[nx][ny] = true;
                    }
                }
            }
        }
    };
    int componentes = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grafo[i][j] == 1 && !visitado[i][j]){
                bfs(i,j);
                componentes++;
            }
        }
    }
    cout<<componentes<<'\n';
}