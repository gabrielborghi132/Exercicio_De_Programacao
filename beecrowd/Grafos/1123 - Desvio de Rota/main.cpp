#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 1e9;
const int MAX = 250;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m,c,k;
    while(cin>>n>>m>>c>>k,n&&m&&c&&k){
        vector<pair<int,int>> grafo[MAX+1];
        vector<int>dist;
        for(int i = 0;i<m;i++){
            int a,b,w;
            cin>>a>>b>>w;
            grafo[a].push_back({b,w});
            grafo[b].push_back({a,w});
        }
        auto dijkstra = [&](int s){
            dist.assign(n+1,INF);
            priority_queue<pair<int,int>> pq;
            dist[s] = 0;
            pq.push({0,s});

            while(!pq.empty()){
                auto[d,u] = pq.top();
                pq.pop();

                if(-d>dist[u])continue;
                for(auto [v,w]:grafo[u]){
                    if(u<c-1&&v!=u+1){
                        continue;
                    }
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({-dist[v], v});
                    }
                }
            }
        };
        dijkstra(k);
        cout<<dist[c-1]<<endl;
    }

    return 0;
}