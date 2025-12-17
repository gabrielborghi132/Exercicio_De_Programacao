/**************************************************/
//        1323 - Feynman
// https://judge.beecrowd.com/pt/problems/view/1323
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n)
    {
        cout << (n * (n + 1) * (2 * n + 1)) / 6 << endl;
    }
    return 0;
}