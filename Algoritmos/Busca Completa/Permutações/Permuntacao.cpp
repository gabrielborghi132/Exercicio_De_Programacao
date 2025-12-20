#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dados = {2, 3, 1};
    sort(dados.begin(), dados.end()); // Essencial começar ordenado
    do
    {
        // Processa a permutação atual
        cout << "{ ";
        for (auto &a : dados)
        {
            cout<< a << " ";
        }
        cout<<"}"<<endl;
    } while (next_permutation(dados.begin(), dados.end()));
}
