/**************************************************/
//        2721 - Indecisão das Renas
// https://judge.beecrowd.com/pt/problems/view/2721
/**************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vt = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

    int soma = 0;
    for(int i = 0;i<9;i++){
        int x = 0;
        cin>>x;
        soma += x;
    }

    int t = (soma - 1) % vt.size();
    cout<<vt[t]<<endl;
}