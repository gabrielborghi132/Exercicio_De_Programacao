/**************************************************/
//        2765 - Entrada e Saída com Virgula
// https://judge.beecrowd.com/pt/problems/view/2765
/**************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string linha, word;
    getline(cin, linha);

    stringstream ss(linha);
    vector<string> vt;

    while (getline(ss, word, ',')) {
        vt.push_back(word);
    }

    for(auto &a : vt){
        cout << a << endl;
    }

    return 0;
}