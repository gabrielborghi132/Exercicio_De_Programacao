/**************************************************/
//         1318 - Bilhetes Falsos
//https://judge.beecrowd.com/pt/problems/view/1318*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n, m;
    while (cin >> n >> m, n)
    {

        vector<int> a(n + 1, -1);

        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            if(a[x]+1>1){
                continue;
            }
            a[x]++;
        }

        int soma = 0;
        for (auto &b : a)
        {
            if (b >= 1)
            {
                soma += b;
            }
        }
        cout << soma << endl;
    }
}