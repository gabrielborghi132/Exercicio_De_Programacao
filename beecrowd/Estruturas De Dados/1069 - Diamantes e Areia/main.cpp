/**************************************************/
//         1069 - Diamantes e Areia
//https://judge.beecrowd.com/pt/problems/view/1069*/
//
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        stack<char> st;
        string s;
        cin >> s;
        int conta = 0;
        for (auto &a : s)
        {
            if(a=='<'){
                st.push(a);
            }else if(a =='>'){
                if(st.empty()){
                    continue;
                }
                st.pop();
                conta++;
            }
        }
        cout<<conta<<endl;
    }
}