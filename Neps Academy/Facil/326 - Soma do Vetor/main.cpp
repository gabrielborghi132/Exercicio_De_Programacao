#include <bits/stdc++.h>
using namespace std;

int soma_vetor(int n, vector<int> &vt)
{
    return accumulate(vt.begin(), vt.end(), 0);
}

int main()
{

    int n;
    cin >> n;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
        cin >> vt[i];

    cout << soma_vetor(n, vt) << "\n";
}
