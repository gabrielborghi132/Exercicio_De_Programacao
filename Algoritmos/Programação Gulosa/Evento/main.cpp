#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Evento
{
    int inicio;
    int fim;
    string nome;
};

// Função para ajudar o C++ a ordenar pelo horário de FIM
bool compararPeloFim(Evento a, Evento b)
{
    return a.fim < b.fim;
}

void agendarEventos(vector<Evento> &eventos)
{
    // 1. Ordenar eventos pelo horário de término
    sort(eventos.begin(), eventos.end(), compararPeloFim);

    cout << "Eventos selecionados:" << endl;

    // 2. O primeiro evento (que termina mais cedo) sempre é escolhido
    Evento atual = eventos[0];
    cout << "- " << atual.nome << " (" << atual.inicio << "h - " << atual.fim << "h)" << endl;

    // 3. Percorrer os demais
    for (size_t i = 1; i < eventos.size(); i++)
    {
        // Se o início do próximo for depois do fim do atual, podemos agendar!
        if (eventos[i].inicio >= atual.fim)
        {
            atual = eventos[i];
            cout << "- " << atual.nome << " (" << atual.inicio << "h - " << atual.fim << "h)" << endl;
        }
    }
}

int main()
{
    vector<Evento> lista = {
        {8, 11, "Evento A"},
        {9, 10, "Evento B"},
        {10, 12, "Evento C"}};

    agendarEventos(lista);
    return 0;
}