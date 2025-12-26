/**************************************************/
//        2867 - Dígitos
// https://judge.beecrowd.com/pt/problems/view/2867
/**************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        double log_resultado = m * log10(n);

        int resposta = floor(log_resultado) + 1;
        
        cout << resposta << endl;
    }

    return 0;
}