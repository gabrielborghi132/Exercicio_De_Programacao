#include <bits/stdc++.h>
using namespace std;

void backtrack(string &opcoes, string atual, vector<string> &respostas, int start, int soma)
{
    // Se encontramos 4 segmentos e processamos toda a string de entrada
    if (soma == 4)
    {
        if (start == (int)opcoes.size())
        {
            // Removemos o último ponto antes de guardar a resposta
            atual.pop_back();
            respostas.push_back(atual);
        }
        return;
    }

    for (int tam = 1; tam <= 3; tam++)
    {
        // Evita ultrapassar o tamanho da string original
        if (start + tam > (int)opcoes.size())
            break;

        string s = opcoes.substr(start, tam);

        // Regra: Sem zeros à esquerda (exceto o próprio 0)
        if (s.size() > 1 && s[0] == '0')
            break;

        // Regra: Valor entre 0 e 255
        int num = stoi(s);
        if (num >= 0 && num <= 255)
        {
            // Chamada recursiva adicionando o segmento e um ponto
            backtrack(opcoes, atual + s + ".", respostas, start + tam, soma + 1);
        }
    }
}

int main()
{
    string opcoes = "25525511135";
    vector<string> resposta;
    backtrack(opcoes, "", resposta, 0, 0);

    cout << "IPs validos encontrados:" << endl;
    for (const string &ip : resposta)
    {
        cout << ip << endl;
    }

    return 0;
}