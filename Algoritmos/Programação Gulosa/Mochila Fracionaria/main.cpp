#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Função de comparação para ordenar os itens pela "densidade de valor"
// Queremos os itens que valem mais por cada unidade de peso (valor/peso)
bool comparar(pair<ll, ll> &a, pair<ll, ll> &b)
{
    // Calculamos a razão: valor (second) / peso (first)
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2; // Retorna verdadeiro se o primeiro item for mais valioso por quilo
}

double mochilaFracionaria(ll &pesoRestante, vector<pair<ll, ll>> &itens)
{
    double valorTotal = 0;

    for (auto &[peso, valor] : itens)
    {
        // Se o item inteiro cabe na mochila, pegamos ele todo
        if (pesoRestante >= peso)
        {
            valorTotal += valor;
            pesoRestante -= peso;
        }
        // Se não couber inteiro, pegamos apenas a "fatia" que cabe
        else
        {
            double densidade = (double)valor / peso;
            valorTotal += densidade * pesoRestante; // Valor proporcional ao espaço que sobrou
            pesoRestante = 0;                       // A mochila ficou cheia
            break;
        }
    }
    return valorTotal;
}

int main()
{
    ll capacidade = 50;
    // Itens representados como {peso, valor}
    vector<pair<ll, ll>> itens = {{10, 60}, {20, 100}, {30, 120}};

    // PASSO CRUCIAL: Ordenar os itens pela melhor densidade antes de processar
    sort(itens.begin(), itens.end(), comparar);

    double resultado = mochilaFracionaria(capacidade, itens);
    cout << "Valor maximo na mochila: " << resultado << endl;

    return 0;
}