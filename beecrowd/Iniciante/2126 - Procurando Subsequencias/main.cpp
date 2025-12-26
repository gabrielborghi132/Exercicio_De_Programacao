/**************************************************/
//        2126 - Procurando Subsequências
// https://judge.beecrowd.com/pt/problems/view/2126
/**************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, s2;
    int caso = 1;

    while (cin >> s >> s2) {
        int qtd = 0;
        long long lastPos = -1;

        auto pos = s2.find(s);
        while (pos != string::npos) {
            qtd++;
            lastPos = (long long)pos;
            pos = s2.find(s, pos + 1); 
        }

        cout << "Caso #" << caso++ << ":\n";

        if (qtd == 0) {
            cout << "Nao existe subsequencia\n";
        } else {
            cout << "Qtd.Subsequencias: " << qtd << "\n";
            cout << "Pos: " << (lastPos + 1) << "\n";
        }
        cout<<endl;
    }
    return 0;
}
