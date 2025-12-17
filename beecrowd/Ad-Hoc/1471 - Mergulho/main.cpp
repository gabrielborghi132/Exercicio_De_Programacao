/**************************************************/
//        1471 - Mergulho
// https://judge.beecrowd.com/pt/problems/view/1471
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    while (cin >> n >> r)
    {
        vector<int> vt(n + 1, 0);
        for (int i = 1; i <= r; i++)
        {
            int x;
            cin >> x;
            vt[x] = 1;
        }
        bool Printou = false;
        for (int i = 1; i <= n; i++)
        {
            if (vt[i] == 0)
            {
                Printou = true;
                cout << i << " ";
            }
        }
        if (!Printou)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}