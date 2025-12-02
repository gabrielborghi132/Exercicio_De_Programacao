/**************************************************/
//         1397 - Jogo do Maior
//https://judge.beecrowd.com/pt/problems/view/1397*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n, n)
    {
        int jog1 = 0, jog2 = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
            {
                jog1++;
            }
            else if (b > a)
            {
                jog2++;
            }
        }
        cout << jog1 << " " << jog2 << endl;
    }
}