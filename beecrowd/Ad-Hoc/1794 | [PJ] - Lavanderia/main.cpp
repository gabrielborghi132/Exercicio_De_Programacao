/**************************************************/
//         1794 | [PJ] - Lavanderia
//https://judge.beecrowd.com/pt/problems/view/1794
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, la, lb, sa, sb;
    cin >> n >> la >> lb >> sa >> sb;
    if (n < la || n > lb)
    {
        cout << "impossivel" << endl;
    }
    else if (n < sa || n > sb)
    {
        cout << "impossivel" << endl;
    }
    else
    {
        cout << "possivel" << endl;
    }
}