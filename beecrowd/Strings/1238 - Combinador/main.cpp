/**************************************************/
//         1238 - Combinador
// https://judge.beecrowd.com/pt/problems/view/1238
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
        string s, s2, word;
        string linha;

        getline(cin, linha);
        stringstream ss(linha);
        vector<string> vt;

        while (ss >> word)
            vt.push_back(word);

        s = vt[0];
        s2 = vt[1];

        string s3;
        int tam = min(s.size(), s2.size());

        for (int i = 0; i < tam; i++)
        {
            s3 += s[i];
            s3 += s2[i];
        }

        if (s.size() > s2.size())
        {
            for (int i = tam; i < (int)s.size(); i++)
                s3 += s[i];
        }
        else if (s2.size() > s.size())
        {
            for (int i = tam; i < (int)s2.size(); i++)
                s3 += s2[i];
        }

        cout << s3 << endl;
    }

    return 0;
}
