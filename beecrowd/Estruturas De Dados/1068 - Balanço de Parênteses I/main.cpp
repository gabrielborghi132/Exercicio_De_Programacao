/**************************************************/
//         1068 - Balanço de Parênteses I
//https://judge.beecrowd.com/pt/problems/view/1068*/
//
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s)
    {
        stack<char> st;
        bool ok = true;
        for (auto &a : s)
        {
            if (a == '(')
            {
                st.push(a);
            }
            else if (a == ')')
            {
                if (st.empty())
                {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }
        if (st.empty() && ok)
            cout << "correct" << endl;
        else
            cout << "incorrect" << endl;
    }
    return 0;
}
