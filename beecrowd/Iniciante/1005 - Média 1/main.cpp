/**************************************************/
//               1005 - Média 1
// https://judge.beecrowd.com/pt/problems/view/1005*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(5) << "MEDIA = " << (a * 3.5 + b * 7.5) / 11.0 << endl;
}