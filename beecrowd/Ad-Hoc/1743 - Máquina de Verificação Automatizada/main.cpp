/**************************************************/
//         1743 - Máquina de Verificação Automatizada
// https://judge.beecrowd.com/pt/problems/view/1743*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    string s;
    getline(cin,s);
    string s2;
    getline(cin,s2);
    
    for(int i = 0;i<s.size();i++){
        if(s[i]==' '||s2[i]==' '){
            continue;
        }
        if(s[i]==s2[i]){
            cout<<'N'<<endl;
            return 0;
        }
    }
    cout<<'Y'<<endl;
    return 0;
}