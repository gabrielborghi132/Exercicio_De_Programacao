#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int const MAX = 1000;
int grafo[MAX+1][MAX+1];
bool visitado[MAX+1][MAX+1];
int distancia[MAX+1][MAX+1];
int v, e;
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>v>>e;
    pair<int,int> inicio = {0, 0};
    pair<int,int> fim = {0, 0};
    for(int i = 0;i<v;++i){
        for(int j = 0;j<e;++j){
            int x;
            cin>>x;
            grafo[i][j] = x;
            if(x == 2){
                inicio = {i, j};
            }
            if(x == 3){
                fim = {i, j};
            }
        }
    }
    auto dfs_iterativa = [&](pair<int,int> inicio){
        queue<pair<int,int>> fila;
        visitado[inicio.first][inicio.second] = true;
        fila.push(inicio);
        distancia[inicio.first][inicio.second] = 1;
        while(!fila.empty()){
            pair<int,int> inicio = fila.front();
            fila.pop();
            if(inicio == fim){
                return;
            }
            for(int i = 0;i<4;++i){
                int nx = inicio.first + x[i];
                int ny = inicio.second + y[i];
                if(nx >= 0 && nx < v && ny >= 0 && ny < e && grafo[nx][ny] != 0){
                    if(!visitado[nx][ny]&&(grafo[nx][ny] == 1 || grafo[nx][ny] == 3||grafo[nx][ny] == 2)){
                        visitado[nx][ny] = true;
                        distancia[nx][ny] = distancia[inicio.first][inicio.second] + 1;
                        fila.push({nx, ny});
                    }
                }
            }
        }
    };
    dfs_iterativa(inicio);
    cout<<distancia[fim.first][fim.second]<<endl;
}