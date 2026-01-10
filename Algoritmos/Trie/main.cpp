#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct node
{
    int next[26];
    // vetor que guarda os índices dos filhos do nó
    // cada posição representa uma letra de 'a' a 'z'
    // valor -1 significa que não existe filho naquela letra

    int degree;
    // quantidade de filhos que esse nó possui
    // não é essencial para o funcionamento da trie, mas pode ser útil

    int terminal_count;
    // indica quantas palavras terminam exatamente neste nó
    // se for maior que zero, este nó representa o fim de uma palavra válida

    int prefix_count;
    // quantidade de palavras que passam por este nó
    // ou seja, quantas palavras têm o prefixo representado por este nó

    node()
    {
        // inicializa todos os filhos como inexistentes
        fill(next, next + 26, -1);

        // nenhum filho inicialmente
        degree = 0;

        // nenhuma palavra termina aqui no início
        terminal_count = 0;

        // nenhuma palavra passa por este nó no início
        prefix_count = 0;
    }
};

// a trie é representada por um vetor de nós
// cada posição do vetor é um nó da trie
vector<node> trie(1);
// começa com um único nó, que é a raiz da trie (índice 0)

void add_string(const string &s)
{
    // função para inserir uma string na trie

    int v = 0;
    // começa pela raiz da trie

    for (auto ch : s)
    {
        // percorre cada caractere da string

        int c = ch - 'a';
        // converte o caractere para um índice entre 0 e 25

        if (trie[v].next[c] == -1)
        {
            // se não existe filho para essa letra

            trie[v].next[c] = trie.size();
            // cria a ligação para um novo nó

            trie.emplace_back();
            // adiciona um novo nó ao vetor da trie

            trie[v].degree++;
            // incrementa o número de filhos do nó atual
        }

        v = trie[v].next[c];
        // avança para o nó filho correspondente à letra atual

        trie[v].prefix_count++;
        // incrementa a contagem de prefixos que passam por esse nó
    }

    trie[v].terminal_count++;
    // marca que uma palavra termina neste nó
}

bool search_word(const string &s)
{
    // função que verifica se uma palavra existe exatamente na trie

    int v = 0;
    // começa pela raiz

    for (char ch : s)
    {
        // percorre cada caractere da palavra

        int c = ch - 'a';
        // converte o caractere para índice

        if (trie[v].next[c] == -1)
            // se não existe caminho para essa letra
            return false;

        v = trie[v].next[c];
        // avança para o próximo nó
    }

    // retorna true apenas se alguma palavra termina neste nó
    return trie[v].terminal_count > 0;
}

bool search_prefix(const string &s)
{
    // função que verifica se a string é prefixo de alguma palavra na trie

    int v = 0;
    // começa pela raiz

    for (char ch : s)
    {
        // percorre cada caractere do prefixo

        int c = ch - 'a';
        // converte o caractere para índice

        if (trie[v].next[c] == -1)
            // se não existe caminho, o prefixo não existe
            return false;

        v = trie[v].next[c];
        // avança para o próximo nó
    }

    // se conseguiu percorrer tudo, o prefixo existe
    return true;
}

void dfs_autocomplete(int v, string &cur, vector<string> &res)
{
    // função recursiva para gerar todas as palavras a partir de um nó

    if (trie[v].terminal_count > 0)
        // se alguma palavra termina neste nó
        res.push_back(cur);
    // adiciona a palavra atual ao resultado

    for (int c = 0; c < 26; c++)
    {
        // percorre todas as letras possíveis

        if (trie[v].next[c] != -1)
        {
            // se existe filho para essa letra

            cur.push_back('a' + c);
            // adiciona a letra atual à string em construção

            dfs_autocomplete(trie[v].next[c], cur, res);
            // chama recursivamente para o nó filho

            cur.pop_back();
            // remove a última letra ao voltar da recursão
        }
    }
}

vector<string> autocomplete(const string &prefix)
{
    // função que retorna todas as palavras que começam com o prefixo dado

    int v = 0;
    // começa pela raiz

    for (char ch : prefix)
    {
        // percorre cada caractere do prefixo

        int c = ch - 'a';
        // converte o caractere para índice

        if (trie[v].next[c] == -1)
            // se não existe caminho, não há palavras com esse prefixo
            return {};

        v = trie[v].next[c];
        // avança para o próximo nó
    }

    string cur = prefix;
    // string que vai sendo construída durante o dfs

    vector<string> res;
    // vetor que armazenará todas as palavras encontradas

    dfs_autocomplete(v, cur, res);
    // chama a busca em profundidade a partir do nó do prefixo

    return res;
    // retorna todas as palavras que possuem o prefixo
}