#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 1e9;
const int MAX = 500;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,e;
    while(cin>>n>>e,n&&e){
        vector<pair<int,int>> grafo[MAX+1];
        vector<int>dist(n+1,INF);
        for(int i = 0;i<e;i++){
            int a,b,w;
            cin>>a>>b>>w;
            grafo[a].push_back({b,w});
        }
        auto dijkstra = [&](int s){
            dist[s] = 0;
            priority_queue<pair<int,int>> pq;
            pq.push({0,s});
            while(!pq.empty()){
                auto[d,u] = pq.top();
                pq.pop();
                if(-d>dist[u])continue;
                for(auto [v,w]:grafo[u]){
                    if(dist[v]>dist[u]+w){
                        dist[v] = dist[u]+w;
                        pq.push({-dist[v],v});
                    }
                }
            }
        };
        int k;
        cin>>k;
        for(int i = 0;i<k;i++){
            int x,y;
            cin>>x>>y;
            dijkstra(x);
            if(dist[y]==INF)cout<<"Nao e possivel entregar a carta"<<endl;
            else cout<<dist[y]<<endl;
            dist.assign(n+1,INF);
        }
        cout<<endl;
    }
}