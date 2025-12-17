/**************************************************/
//        1025 - Onde está o Mármore?
// https://judge.beecrowd.com/pt/problems/view/1025
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    int caseNum = 1;

    while (cin >> n >> q, (n || q))
    {
        vector<int> vt;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vt.push_back(x);
        }

        sort(vt.begin(), vt.end());

        cout << "CASE# " << caseNum++ << ":" << endl;

        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            
            auto it = lower_bound(vt.begin(), vt.end(), x);

            if (it != vt.end() && *it == x)
            {
                int index = (it - vt.begin()) + 1;
                cout << x << " found at " << index << endl;
            }
            else
            {
                cout << x << " not found" << endl;
            }
        }
    }
    return 0;
}