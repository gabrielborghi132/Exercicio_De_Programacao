/**************************************************/
//        2547 - Montanha-Russa
// https://judge.beecrowd.com/pt/problems/view/2547
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    while(cin >> a >> b >> c){
        int soma = 0;
        for (int i = 0; i < a; i++)
        {
            int x;
            cin >> x;
            if (x >= b && x <= c)
            {
                soma++;
            }
        }
        cout << soma << endl;

    }
}