#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void backtrack(vector<vector<int>> &respostas, vector<int> &atual, vector<bool> &visited, vector<int> &opcoes)
{
    if (atual.size() == opcoes.size())
    {
        respostas.push_back(atual);
        return;
    }
    for (int i = 0; i < (int)opcoes.size(); i++)
    {
        if (visited[i])
            continue;
        if (i > 0 && opcoes[i] == opcoes[i - 1] && !visited[i - 1])
            continue;
        visited[i] = true;
        atual.push_back(opcoes[i]);
        backtrack(respostas, atual, visited, opcoes);
        atual.pop_back();
        visited[i] = false;
    }
}

int main()
{
    vector<int> opcoes = {1, 1, 2};
    int n = opcoes.size();
    vector<vector<int>> resposta;
    vector<int> atual;
    vector<bool> visited(opcoes.size(), false);
    sort(opcoes.begin(), opcoes.end());
    backtrack(resposta, atual, visited, opcoes);

    for (auto &v : resposta)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
}