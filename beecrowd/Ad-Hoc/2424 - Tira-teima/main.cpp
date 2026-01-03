/**************************************************/
//         2424 - Tira-teima
// https://judge.beecrowd.com/pt/problems/view/2424*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    int x, y;
    cin >> x >> y;
    if ((x >= 0 && x <= 432) && (y <= 468 && y >= 0))
        cout << "dentro" << endl;
    else
        cout << "fora" << endl;
}