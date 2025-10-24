#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 1e9;
const int MAXN = 505;

int n, m;
int dist[MAXN][MAXN];

void floyd_warshall(){
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1){
        cin>>n>>m;
        if(!n&&!m)break;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dist[i][j] = (i==j?0:INF);
            }
        }
        for(int i = 0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(dist[b][a]!=INF){
                dist[a][b] = 0;
                dist[b][a] = 0;
            }else{
                dist[a][b] = c;
            }
        }
        floyd_warshall();
        int k;
        cin>>k;
        for(int i = 0;i<k;i++){
            int a,b;
            cin>>a>>b;
            if(dist[a][b]!=INF){
                cout<<dist[a][b]<<endl;
            }else{
                cout<<"Nao e possivel entregar a carta"<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}