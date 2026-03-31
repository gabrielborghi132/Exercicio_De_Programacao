#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    // Intervalos representados como {início, fim}
    vector<pair<ll, ll>> itens = {{0, 4}, {1, 6}, {3, 8}, {5, 10}, {7, 10}, {11, 15}};

    // 1. Ordenar pelo início para garantir que seguimos a sequência da "ponte"
    sort(itens.begin(), itens.end());

    ll ate_final = 0;  // Até onde nossa cobertura "confirmada" vai
    ll melhor_ate = 0; // O ponto mais longe que conseguimos alcançar com os intervalos atuais
    ll count = 0;      // Número de intervalos escolhidos

    for (auto &[de, ate] : itens)
    {
        // Se este intervalo começa depois da nossa cobertura confirmada...
        if (de > ate_final)
        {
            // ...precisamos usar o melhor intervalo que vimos para pular adiante
            count++;
            ate_final = melhor_ate;

            // Verificação de segurança: se o novo intervalo ainda começa depois do pulo,
            // existe um buraco impossível de cobrir.
            if (de > ate_final)
                break;
        }

        // Atualizamos o potencial alcance máximo
        melhor_ate = max(ate, melhor_ate);
    }

    // Se o último intervalo processado nos levou além, precisamos contar o último salto
    if (ate_final < melhor_ate)
        count++;

    cout << "Minimo de intervalos: " << count << endl;
    return 0;
}