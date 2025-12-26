#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()

{

    int n, m;

    cin >> n >> m;

    vector<vector<int>> vt(n, vector<int>(m));

    int ultimo_Zero_X = -1;
    bool mudou = false;
    int cont_zero = 0;
    int i,j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vt[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        cont_zero = 0;
        mudou = false;
        for (j = 0; j < m; j++)
        {
            if (vt[i][j] != 0)
            {
                if (ultimo_Zero_X >= j)
                {
                    cout << "N" << endl;
                    return 0;
                }
                ultimo_Zero_X = j;
                mudou = true;
                break;
            }
            if (vt[i][j] == 0)
            {
                cont_zero++;
            }
        }
        if (cont_zero >= m)
        {
            break;
        }
        if (!mudou && i >= 1)
        {
            cout << "N" << endl;
            return 0;
        }
    }
    if(cont_zero >= m){
        for (i; i < n; i++)
        {
            for (j=0; j < m; j++)
            {
                if(vt[i][j]!= 0){
                    cout << "N" << endl;
                    return 0;
                }
            }
        }
    }        
    cout << "S" << endl;
    return 0;
}
