/**************************************************/
//        3040 - A Árvore de Natal
// https://judge.beecrowd.com/pt/problems/view/3040
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a>=200&&a<=300){
            if(b>=50){
                if(c>=150){
                    cout<<"Sim"<<endl;
                }else{
                    cout<<"Nao"<<endl;
                }
            }else{
                cout<<"Nao"<<endl;
            }
        }else{
            cout<<"Nao"<<endl;
        }
    }
    return 0;
}