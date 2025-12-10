/**************************************************/
//         1234 - Sentença Dançante
// https://judge.beecrowd.com/pt/problems/view/1234
/**************************************************/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s))
    {

        bool ok = true;
        for (auto &a : s)
        {
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
            {
                if (ok)
                {
                    a = toupper(a);
                    ok = false;
                }else{
                    a = tolower(a);
                    ok = true;
                }
            }
        }
        cout << s << endl;
    }
}