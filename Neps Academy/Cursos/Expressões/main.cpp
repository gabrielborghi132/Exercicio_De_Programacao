#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
bool valido(string str)
{
    stack<char> st;
    for (auto &x : str)
    {
        if (x == '{' || x == '[' || x == '(')
            st.push(x);
        else if (!st.empty())
        {
            if (x == '}' && st.top() == '{')
                st.pop();
            else if (x == ']' && st.top() == '[')
                st.pop();
            else if (x == ')' && st.top() == '(')
                st.pop();
            else
                return false;
        }
        else
            return false;
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str;
        getline(cin, str);
        if (valido(str))
            cout << 'S' << endl;
        else
            cout << 'N' << endl;
    }
    return 0;
}