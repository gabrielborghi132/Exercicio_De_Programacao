#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
    unordered_map<string,int> mp;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string nome;
        int nota;
        cin>>nome>>nota;
        mp[nome] = nota;
    }
    for(int i = 0;i<n;i++){
        string nome;
        int nota;
        cin>>nome>>nota;
        if(mp[nome] == nota){
            cout<<nome<<endl;
            return 0;
        }
        mp[nome] = nota;
    }
    cout<<"NONE"<<endl;
    return 0;
}