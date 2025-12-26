/**************************************************/
//        2663 - Fase
// https://judge.beecrowd.com/pt/problems/view/2663
/**************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> vt(n);
    for(int i = 0; i < n; i++) {
        cin >> vt[i];
    }

    sort(vt.begin(), vt.end(), greater<int>());

    int conta = 0;
    int vagas_originais = k;

    for(int i = 0; i < n; i++) {
        if(vagas_originais > 0) {
            conta++;
            vagas_originais--;
        } 
        else if(i > 0 && vt[i] == vt[i-1]) {
            conta++;
        } 
        else {
            break; 
        }
    }

    cout << conta << endl;

    return 0;
}