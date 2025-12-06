#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> par;
    vector<int> impar;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            par.push_back(x);
        }
        else
        {
            impar.push_back(x);
        }
    }
    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end(), greater<int>());

    for(auto &a:par){
        cout<<a<<endl;
    }
    for(auto &a:impar){
        cout<<a<<endl;
    }
}