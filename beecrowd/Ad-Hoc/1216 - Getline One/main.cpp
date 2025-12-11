/**************************************************/
//         1216 - Getline One
//https://judge.beecrowd.com/pt/problems/view/1216*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main()
{
    int x;
    string s;
    double soma = 0;
    int cont = 0;
    while (getline(cin, s)&&cin >> x)
    {
        soma += x;
        cont++;
        cin.ignore();
    }
    cout << fixed << setprecision(1) << soma / cont << endl;
}