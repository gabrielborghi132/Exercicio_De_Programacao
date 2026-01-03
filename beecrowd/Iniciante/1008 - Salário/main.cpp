/**************************************************/
//               1008 - Salário
// https://judge.beecrowd.com/pt/problems/view/1008*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b, c;
    cin >> a >> b >> c;
    cout << "NUMBER = " << a << endl;
    cout << "SALARY = U$ " << fixed << setprecision(2) << b * c << endl;
}