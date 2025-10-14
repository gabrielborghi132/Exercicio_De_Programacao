#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 100;
char grafo[MAX+1][MAX+1];
bool visitado[MAX+1][MAX+1];
int v,e;
int x[] = {1, 0 , -1, 0};
int y[] = {0 , 1 ,0 ,-1};
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>v>>e;
    pair<int,int> inicio;
    pair<int,int>fim;
    for(int i = 0;i<v;++i){
        for(int j = 0;j<e;++j){
            cin>>grafo[i][j];
            if(grafo[i][j] == 'o'){
                inicio.first = i;inicio.second = j;
            }
        }
    }
    auto bfs = [&](pair<int,int> inicio){
        queue<pair<int,int>> fila;
        fila.push(inicio);
        visitado[inicio.first][inicio.second] = true;
        while(!fila.empty()){
            pair<int,int> u = fila.front();
            fim = u;
            fila.pop();
            for(int i = 0;i<4;++i){
                int nx = u.first+x[i];
                int ny = u.second+y[i];
                if(nx>=0&&nx<v&&ny>=0&&ny<e&&grafo[nx][ny]!='.'){
                    if(!visitado[nx][ny]){
                        visitado[nx][ny] = true;
                        fila.push({nx,ny});
                    }
                }
            }
        }
    };
    bfs(inicio);
    cout<<fim.first+1<<" "<<fim.second+1<<endl;
}