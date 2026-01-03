/**************************************************/
//               1010 - Cálculo Simples
// https://judge.beecrowd.com/pt/problems/view/1010*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    double c;
    cin >> a >> b >> c;
    double soma = b * c;
    cin >> a >> b >> c;
    soma += b * c;
    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << soma << endl;
}