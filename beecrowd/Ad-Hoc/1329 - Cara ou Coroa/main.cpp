#include <bits/stdc++.h>
using ll = long long;
#define endl '\n'
using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n, n)
    {
        vector<int> vt(2);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                vt[0]++;
            }
            else
            {
                vt[1]++;
            }
        }
        cout << "Mary won " << vt[0] << " times and John won " << vt[1] << " times" << endl;
    }
}
