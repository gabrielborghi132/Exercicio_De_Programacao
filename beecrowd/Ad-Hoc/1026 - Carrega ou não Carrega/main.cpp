/**************************************************/
//         1026 - Carrega ou não Carrega?
//https://judge.beecrowd.com/pt/problems/view/1026*/
/**************************************************/

#include <bits/stdc++.h>
using ll = long long;
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b;
    while (cin >> a >> b)
    {
        cout << (a ^ b) << endl;
    }
}