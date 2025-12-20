#include <bits/stdc++.h>
using namespace std;
void Gerar_SubConjunto(vector<int> &conjunto, vector<int> &subSet, int indice)
{
    if (indice == conjunto.size())
    {
        cout << "{ ";
        for (auto &a : subSet)
        {
            cout << a << " ";
        }
        cout << "}" << endl;
        return;
    }
    Gerar_SubConjunto(conjunto, subSet, indice + 1);
    subSet.push_back(conjunto[indice]);

    Gerar_SubConjunto(conjunto, subSet, indice + 1);
    subSet.pop_back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> meuConjunto = {1, 2, 3};
    vector<int> atual;
    cout << "Gerando subconjuntos:\n";
    Gerar_SubConjunto(meuConjunto, atual, 0);
    return 0;

    return 0;
}
