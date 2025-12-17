/**************************************************/
//         1796 | [PJ] - Economia Brasileira
// https://judge.beecrowd.com/pt/problems/view/1796
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vt(2);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vt[x]++;
    }
    if (vt[1] < vt[0])
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    return 0;
}