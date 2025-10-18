#include <bits/stdc++.h>
using namespace std;
int const MAX = 15;
int grafo[MAX+1][MAX+1];
int visitado[MAX+1][MAX+1];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int num = 0;
    while(t--){
        int q;
        cin>>q;
        bool passou = false;
        memset(visitado,0,sizeof(visitado));
        memset(grafo,0,sizeof(grafo));
        num = 0;
        for(int i = 0;i<q;++i){
            for(int j = 0;j<q;++j){
                cin>>grafo[i][j];
                if(grafo[i][j] == 1){
                    ++num;
                }
            }
        }
        
        auto bfs = [&](int x,int y){
            queue<pair<int,int>> fila;
            fila.push({x,y});
            visitado[x][y] = true;
            while(!fila.empty()){
                int u = fila.front().first;
                int v = fila.front().second;
                fila.pop();
                for(int i = 0;i<4;++i){
                    int nx = u + dx[i];
                    int ny = v + dy[i];

                    if(nx >= 0 && nx < q && ny >= 0 && ny < q){
                        if(!visitado[nx][ny]&&grafo[nx][ny] == 0){
                            visitado[nx][ny] = true;
                            fila.push({nx,ny});
                        }
                    }
                }
            }
        };
        for(int i = 0;i<q;i++){
            if(!visitado[0][i]){
                bfs(0,i);
            }
            if(!visitado[q-1][i]){
                bfs(q-1,i);
            }
            if(!visitado[i][0]){
                bfs(i,0);
            }
            if(!visitado[i][q-1]){
                bfs(i,q-1);
            }
        }
        for (int i = 0; i < q; ++i)
            for (int j = 0; j < q; ++j)
                if (grafo[i][j] == 0 && !visitado[i][j])
                    num++;
        double area = num / 2.0;
        cout << fixed << setprecision(2) << area << "\n";
    }
}