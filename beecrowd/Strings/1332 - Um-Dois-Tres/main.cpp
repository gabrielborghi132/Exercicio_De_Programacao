/**************************************************/
//         1332 - Um-Dois-Três
// https://judge.beecrowd.com/pt/problems/view/1332
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
    while (n--)
    {
        string s;
        cin >> s;
        int coincidencias = 0;
        if (s.size() > 3)
        {
            cout << 3 << endl;
        }
        else
        {
            if (s[0] == 'o')
                coincidencias++;
            if (s[1] == 'n')
                coincidencias++;
            if (s[2] == 'e')
                coincidencias++;


            if (coincidencias >= 2)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
}