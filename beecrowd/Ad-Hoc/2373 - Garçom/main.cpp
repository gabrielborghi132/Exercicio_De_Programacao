/**************************************************/
//         2373 - Garçom
// https://judge.beecrowd.com/pt/problems/view/2373*/
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
    int conta = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            conta += b;
        }
    }
    cout << conta << endl;
}