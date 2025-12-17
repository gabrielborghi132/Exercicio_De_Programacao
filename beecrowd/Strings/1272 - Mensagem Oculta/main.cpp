/**************************************************/
//        1272 - Mensagem Oculta
// https://judge.beecrowd.com/pt/problems/view/1272
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

        for(auto &a:vt){
            cout<<a[0];
        }
        cout<<endl;
    }

    return 0;
}
