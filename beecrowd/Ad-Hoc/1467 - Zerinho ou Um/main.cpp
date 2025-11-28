#include <bits/stdc++.h>
using ll = long long;
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a != b && a != c)
        {
            cout<<"A"<<endl;
        }else if(b!=a&&b!=c){
            cout<<"B"<<endl;
        }else if(c!=a&&c!=b){
            cout<<"C"<<endl;
        }else{
            cout<<"*"<<endl;
        }
    }
    return 0;
}