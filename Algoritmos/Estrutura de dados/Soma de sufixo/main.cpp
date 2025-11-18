#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    vector<long long>pref(n+1,0);
    for(int i = 0;i<n;i++){
        pref[i+1]=pref[i]+a[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pref[r+1]-pref[l];
    }
    return 0;
}