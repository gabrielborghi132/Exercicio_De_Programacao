#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
    vector<pair<int, string>> vt;
    int n;
    cin>>n;
    string nome;
    int pos;
    for(int i = 0;i<n;i++){
        cin>>nome>>pos;
        vt.push_back({pos,nome});
    }
    sort(vt.begin(), vt.end(), [](auto &a, auto &b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    for(auto &[x,y]:vt){
        cout<<y<<endl;
    }
    return 0;
}