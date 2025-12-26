/**************************************************/
//        2143 - A Volta do Radar
// https://judge.beecrowd.com/pt/problems/view/2143
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n,n){
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            if(a%2==0){
                cout<<(((a-2)*2)+2)<<endl;
            }else{
                cout<<(((a-1)*2)+1)<<endl;
            }
        }
    }
    return 0;
}