#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maior = INT_MIN;
    maior = max(a, b);
    maior = max(maior, c);
    cout << maior << " eh o maior" << endl;
}