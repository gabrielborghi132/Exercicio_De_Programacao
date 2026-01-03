/**************************************************/
//         2375 - Sedex
// https://judge.beecrowd.com/pt/problems/view/2375
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    if (a >= n && b >= n && c >= n)
        cout << "S" << endl;
    else
        cout << "N" << endl;
}