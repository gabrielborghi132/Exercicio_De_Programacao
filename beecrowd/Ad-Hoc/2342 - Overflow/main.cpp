/**************************************************/
//         2342 - Overflow
//https://judge.beecrowd.com/pt/problems/view/2342
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    char c;
    cin >> n >> a >> c >> b;
    if (c == '+')
    {
        if (a + b > n)
        {
            cout << "OVERFLOW" << endl;
        }else{
            cout<<"OK"<<endl;
        }
    }else{
        if (a * b > n)
        {
            cout << "OVERFLOW" << endl;
        }else{
            cout<<"OK"<<endl;
        }
    }
    return 0;
}