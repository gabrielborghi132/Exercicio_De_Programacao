#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
bool verifica(const vector<vector<ll>> &atual, ll i, ll j, ll num)
{
    // Verifica coluna
    for (int l = 0; l < 9; l++)
    {
        if (atual[l][j] == num)
        {
            return true;
        }
    }

    // Verifica linha
    for (int l = 0; l < 9; l++)
    {
        if (atual[i][l] == num)
        {
            return true;
        }
    }

    // Verifica bloco 3x3
    int inicioLinha = (i / 3) * 3;
    int inicioColuna = (j / 3) * 3;

    for (int l = inicioLinha; l < inicioLinha + 3; l++)
    {
        for (int k = inicioColuna; k < inicioColuna + 3; k++)
        {
            if (atual[l][k] == num)
            {
                return true;
            }
        }
    }

    return false;
}
void sudoku(vector<vector<ll>> &grid, vector<vector<vector<ll>>> &resposta, vector<vector<ll>> &atual, ll mudancas)
{
    if (mudancas == 81)
        resposta.push_back(atual);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!verifica(atual, i, j, j) && grid[i][j] == 0)
            {
                grid[i][j] = j;
                sudoku(grid, resposta, atual, mudancas + 1);
                grid[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<ll>> grid;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            ll x;
            cin >> x;
            grid[i].push_back(x);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}