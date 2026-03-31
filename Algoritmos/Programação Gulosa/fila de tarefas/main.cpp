#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Tempos de execução de cada tarefa (em segundos/minutos)
    vector<double> tarefas = {15, 4, 20, 2, 8};

    // Ordenamos para minimizar o tempo de espera (SJF)
    sort(tarefas.begin(), tarefas.end());

    double tempo_de_espera_acumulado = 0;
    double soma_total_espera = 0;

    cout << "Ordem de execucao: ";
    for (int i = 0; i < (int)tarefas.size(); i++)
    {
        cout << tarefas[i] << " ";

        // A tarefa atual espera o tempo acumulado das anteriores
        soma_total_espera += tempo_de_espera_acumulado;

        // Atualizamos o tempo acumulado com a tarefa que acabou de rodar
        tempo_de_espera_acumulado += tarefas[i];
    }

    double media = soma_total_espera / tarefas.size();

    cout << "\nTempo total de espera: " << soma_total_espera << endl;
    cout << "Tempo medio de espera: " << media << endl;

    return 0;
}