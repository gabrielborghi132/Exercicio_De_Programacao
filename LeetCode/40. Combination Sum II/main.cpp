#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void backtrack(vector<vector<int>> &resposta, int start, int alvo, vector<int> &opcoes, vector<int> &atual, int soma)
{
    if (soma == alvo)
    {
        resposta.push_back(atual);
        return;
    }

    for (int i = start; i < (int)opcoes.size(); i++)
    {
        if (soma + opcoes[i] > alvo)
            break;
        int resto = 0;
        for (int j = i; j < opcoes.size(); j++)
            resto += opcoes[j];
        if (soma + resto < alvo)
            break;
        if (i > start && opcoes[i] == opcoes[i - 1])
            continue;
        atual.push_back(opcoes[i]);
        backtrack(resposta, i + 1, alvo, opcoes, atual, soma + opcoes[i]);
        atual.pop_back();
    }
}

int main()
{
    vector<vector<int>> resposta;
    int start = 0;
    int alvo = 8;
    vector<int> opcoes = {10, 1, 2, 7, 6, 1, 5};
    sort(opcoes.begin(), opcoes.end());
    vector<int> atual;
    int soma = 0;

    backtrack(resposta, start, alvo, opcoes, atual, soma);

    cout << "=== Resultados ===" << endl;
    for (auto &v : resposta)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}