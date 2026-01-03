/**************************************************/
//         2679 - Sucessor Par
// https://judge.beecrowd.com/pt/problems/view/2679
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x;
    cin >> x;
    if (x % 2 == 0)
        cout << x + 2 << endl;
    else
        cout << x + 1 << endl;
}