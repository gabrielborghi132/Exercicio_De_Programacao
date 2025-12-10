/**************************************************/
//         1024 - Criptografia
// https://judge.beecrowd.com/pt/problems/view/1024*/
//
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
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        for (auto &a : s)
        {
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
            {
                a += 3;
            }
        }
        reverse(s.begin(), s.end());
        int tam = s.size() / 2;
        string s2 = s.substr(0, tam);
        string s3 = s.substr(tam, s.size());
        for (auto &a : s3)
        {
            a-=1;
        }

        s = s2 + s3;
        cout << s << endl;
    }
    return 0;
}