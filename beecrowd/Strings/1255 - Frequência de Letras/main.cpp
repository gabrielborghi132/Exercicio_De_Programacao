/**************************************************/
//        1255 - Frequência de Letras
// https://judge.beecrowd.com/pt/problems/view/1255
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        vector<int> vt(27, 0);
        int maior = 0;
        for (auto &a : s)
        {
            if (isalpha(a))
            {
                a = tolower(a);
                vt[a - 'a']++;
                maior = max(maior, vt[a - 'a']);
            }
        }

        for (int i = 0; i < 27; i++)
        {
            if (vt[i] == maior)
            {
                cout << (char)(i + 'a');
            }
        }
        cout << endl;
    }
}