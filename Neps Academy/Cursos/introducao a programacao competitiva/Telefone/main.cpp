#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string mapa = "22233344455566677778889999";
    for (auto &a : s)
    {
        if (a >= 'A' && a <= 'Z')
        {
            cout << mapa[a-'A'];
        }else {
            cout<<a;
        }
    }
    cout<<endl;
    return 0;
}