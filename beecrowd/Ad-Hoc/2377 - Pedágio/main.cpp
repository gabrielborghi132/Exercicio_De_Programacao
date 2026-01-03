/**************************************************/
//         2377 - Pedágio
// https://judge.beecrowd.com/pt/problems/view/2377
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ull = unsigned long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull l, d;
    ull k, p;
    cin >> l >> d >> k >> p;
    ull qtde_Ped = l / d;
    ull valor_Ped = p * qtde_Ped;
    valor_Ped += l * k;
    cout << valor_Ped << endl;
}