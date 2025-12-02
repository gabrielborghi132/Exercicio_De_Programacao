/**************************************************/
//         1171 - Frequência de Números
//https://judge.beecrowd.com/pt/problems/view/1171*/
/**************************************************/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vt(2005, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vt[x]++;
    }

    for (int i = 0; i <= 2000; i++) {
        if (vt[i] > 0) {
            cout << i << " aparece " << vt[i] << " vez(es)" << endl;
        }
    }

    return 0;
}