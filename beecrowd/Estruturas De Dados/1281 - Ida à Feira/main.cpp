/**************************************************/
//        1281 - Ida à Feira
// https://judge.beecrowd.com/pt/problems/view/1281
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
        unordered_map<string, double> mp;
        
        int t;
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            string s;
            double preco;
            cin >> s >> preco;
            mp[s] = preco;
        }

        cin >> t;
        double compra = 0.0;
        for (int i = 0; i < t; i++)
        {
            string s;
            int qtd;
            cin >> s >> qtd;
            
            compra += mp[s] * qtd;
        }

        cout << fixed << setprecision(2);
        cout << "R$ " << compra << endl; 
    }

    return 0;
}