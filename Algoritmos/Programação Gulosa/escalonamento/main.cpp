#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Comparamos apenas pelo lucro (second), do maior para o menor
bool comparar(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second > b.second;
}

int main()
{
    // {Prazo, Lucro}
    vector<pair<ll, ll>> itens = {{1, 50}, {3, 100}, {3, 200}};

    // Vetor para marcar quais dias já têm tarefas agendadas
    // Iniciamos com 'false' (livre)
    vector<bool> dias_ocupados(1e6, false);

    // 1. Priorizamos as tarefas que dão mais dinheiro
    sort(itens.begin(), itens.end(), comparar);

    ll lucro_total = 0;

    for (auto &[prazo, lucro] : itens)
    {
        // 2. Tentamos encaixar a tarefa o mais tarde possível (no dia do prazo)
        // Isso "economiza" os dias anteriores para tarefas com prazos menores
        for (ll i = prazo; i > 0; i--)
        {
            if (!dias_ocupados[i])
            {
                dias_ocupados[i] = true; // Marca o dia como ocupado
                lucro_total += lucro;
                break; // Tarefa agendada, passamos para a próxima
            }
        }
    }

    cout << "Lucro maximo: " << lucro_total << endl;
    return 0;
}