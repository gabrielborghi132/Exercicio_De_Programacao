/**************************************************/
//        3301 - Sobrinho do Meio
// https://judge.beecrowd.com/pt/problems/view/3301
/**************************************************/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    if ((a > b && a < c) || (a > c && a < b))
    {
        cout << "huguinho" << endl;
    }
    else if ((b > a && b < c) || (b > c && b < a))
    {
        cout << "zezinho" << endl;
    }
    else
    {
        cout << "luisinho" << endl;
    }
    return 0;
}