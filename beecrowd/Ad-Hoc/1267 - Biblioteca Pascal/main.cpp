#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while (cin >> a >> b, a)
    {
        vector<vector<int>> vt(b, vector<int>(a, 0));
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cin >> vt[i][j];
            }
        }
        bool passou = true;
        for (int i = 0; i < a; i++)
        {
            passou = true;
            for (int j = 0; j < b; j++)
            {
                if (vt[j][i] == 1)
                {
                    continue;
                }
                else
                {
                    passou = false;
                    break;
                }
            }
            if (passou)
            {
                cout << "yes" << endl;
                break;
            }
        }
        if (passou == false)
        {
            cout << "no" << endl;
        }
    }
    return 0;
}