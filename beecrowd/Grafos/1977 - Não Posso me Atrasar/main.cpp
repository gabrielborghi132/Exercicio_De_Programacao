#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;
const  int MAXN = 1e5+5;

#define endl '\n'

int n,m,s,f;

vector<pair<int,int>> g[MAXN];
vector<int> dist;
unordered_map<string, int> id;
unordered_map<int, string>id_Rev;

void dijkstra(int s){
    dist.assign(n+1,INF);
    priority_queue<pair<int,int>>pq;

    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        auto [d,u] = pq.top();pq.pop();
        if(-d>dist[u])continue;

        for(auto [v,w]:g[u]){
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({-dist[v],v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while(cin>>x>>m>>n,x&&n&&m){
        id.clear();
        id_Rev.clear();
        for(int i = 0; i <= m; i++){
            g[i].clear();
        }
        int count = 0;
        for(int i = 0;i<m;i++){
            string a,b;
            int q;
            cin>>a>>b>>q;
            if(!id.count(a)){
                id[a] = count;
                id_Rev[count] = a;
                count++;
            }
            if(!id.count(b)){
                id[b] = count;
                id_Rev[count] = b;
                count++;
            }
            g[id[a]].push_back({id[b],q});
        }
        dijkstra(id["varzea"]);
        int tempoMin = 1020;
        tempoMin +=dist[id["alto"]];
        if(x>30){
            tempoMin += 50;
        }else{
            tempoMin += 30;
        }
        int tempoHora = tempoMin/60;
        tempoMin %= 60;

        cout << tempoHora << ":";
        if(tempoMin < 10) cout << "0";
        cout << tempoMin << endl;

        if(tempoHora > 18 || (tempoHora == 18 && tempoMin > 0)){
            cout << "Ira se atrasar" << endl;
        } else {
            cout << "Nao ira se atrasar" << endl;
        }
    }
}