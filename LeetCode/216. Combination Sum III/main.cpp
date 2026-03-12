#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void backtrack(vector<vector<int>> &resposta, int start, int alvo, int tam, vector<int> &opcoes, vector<int> &atual, int soma)
{
    if ((int)atual.size() == tam)
    {
        if (soma == alvo)
            resposta.push_back(atual);
        return;
    }
    for (int i = start; i < (int)opcoes.size(); i++)
    {
        if (soma + opcoes[i] > alvo)
            break;
        int resto = 0;
        for (int j = i; j < (int)opcoes.size(); j++)
            resto += opcoes[j];
        if (soma + resto < alvo)
            break;
        if (i > start && opcoes[i] == opcoes[i - 1])
            continue;
        atual.push_back(opcoes[i]);
        backtrack(resposta, i + 1, alvo, tam, opcoes, atual, soma + opcoes[i]);
        atual.pop_back();
    }
}
int main()
{
    vector<vector<int>> resposta;
    int start = 0;
    int alvo = 9;
    vector<int> opcoes = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> atual;
    int soma = 0;
    int tam = 3;
    backtrack(resposta, start, alvo, tam, opcoes, atual, soma);

    cout << "=== Resultados ===" << endl;
    for (auto &v : resposta)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}