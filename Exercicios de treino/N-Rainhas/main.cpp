#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

bool verifica_posicao(const vector<vector<ll>> &tabuleiro, ll linha, ll coluna, ll n)
{
    // Verifica a linha
    for (ll j = 0; j < n; j++)
    {
        if (tabuleiro[linha][j] == 1)
            return false;
    }

    // Verifica a coluna
    for (ll i = 0; i < n; i++)
    {
        if (tabuleiro[i][coluna] == 1)
            return false;
    }

    // Verifica diagonal principal superior esquerda
    for (ll i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
    {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    // Verifica diagonal principal inferior direita
    for (ll i = linha, j = coluna; i < n && j < n; i++, j++)
    {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    // Verifica diagonal secundária superior direita
    for (ll i = linha, j = coluna; i >= 0 && j < n; i--, j++)
    {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    // Verifica diagonal secundária inferior esquerda
    for (ll i = linha, j = coluna; i < n && j >= 0; i++, j--)
    {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    return true;
}
void backtracking(vector<vector<vector<ll>>> &respostas, ll i, vector<vector<ll>> &atual, vector<vector<ll>> opcoes)
{
    if (i == (int)opcoes.size())
    {
        respostas.push_back(atual);
        return;
    }

    for (int q = 0; q < (int)opcoes.size(); q++)
    {
        if (verifica_posicao(atual, i, q, (ll)opcoes.size()))
        {
            atual[i][q] = 1;
            backtracking(respostas, i + 1, atual, opcoes);
            atual[i][q] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<ll>>> respostas;
    vector<vector<ll>> opcoes(4, vector<ll>(4, 0));
    vector<vector<ll>> atual(4, vector<ll>(4, 0));

    backtracking(respostas, 0, atual, opcoes);

    for (auto i : respostas)
    {
        for (auto j : i)
        {
            cout << "{ ";
            for (auto q : j)
            {
                cout << q << " ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }
}