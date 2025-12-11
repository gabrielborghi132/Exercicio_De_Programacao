/**************************************************/
//         1437 - Esquerda, Volver!
//https://judge.beecrowd.com/pt/problems/view/1437*/
/**************************************************/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        string s;
        cin >> s;

        char local = 'N';

        for (char c : s)
        {
            if (local == 'N')
            {
                if (c == 'D')
                    local = 'L';
                else
                    local = 'O';
            }
            else if (local == 'L')
            {
                if (c == 'D')
                    local = 'S';
                else
                    local = 'N';
            }
            else if (local == 'S')
            {
                if (c == 'D')
                    local = 'O';
                else
                    local = 'L';
            }
            else if (local == 'O')
            {
                if (c == 'D')
                    local = 'N';
                else
                    local = 'S';
            }
        }

        cout << local << '\n';
    }
}
