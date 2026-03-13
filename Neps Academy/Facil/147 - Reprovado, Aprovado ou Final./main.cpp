#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b;
    cin >> a >> b;
    double nota = (a * 2 + b * 3) / 5;
    if (nota >= 7)
        cout << "Aprovado" << endl;
    else if (nota < 3)
        cout << "Reprovado" << endl;
    else
        cout << "Final" << endl;
}