/**************************************************/
//         1120 - Revisão de Contrato
// https://judge.beecrowd.com/pt/problems/view/1120
/**************************************************/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char n;
    string s;
    while (cin >> n >> s, n != '0')
    {
        string res = "";
        for (auto &a : s)
        {
            if (a != n)
            {
                res.push_back(a);
            }
        }
        bool imprimiu_algo = false;

        for (auto &c : res)
        {
            if (c != '0')
                imprimiu_algo = true;

            if (imprimiu_algo)
                cout << c;
        }
        if (!imprimiu_algo)
            cout << 0;
        cout << endl;
    }
}