#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct node
{
    int next[26];
    int degree;
    int terminal_count;
    int prefix_count;

    node()
    {
        fill(next, next + 26, -1);
        degree = 0;
        terminal_count = 0;
        prefix_count = 0;
    }
};
vector<node> trie(1);

void add_string(const string &s)
{
    int v = 0;

    for (auto ch : s)
    {
        int c = ch - 'a';

        if (trie[v].next[c] == -1)
        {

            trie[v].next[c] = trie.size();

            trie.emplace_back();

            trie[v].degree++;
        }

        v = trie[v].next[c];

        trie[v].prefix_count++;
    }

    trie[v].terminal_count++;
}
int main()
{
    int n;
    while (cin >> n, n)
    {
        string s;
        trie.clear();
        trie.emplace_back(1);
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            add_string(s);
        }
        bool ved = true;
        for (auto &a : trie)
        {
            if (a.prefix_count > 1)
            {
                cout << "Conjunto Ruim" << endl;
                ved = false;
            }
        }
        if (ved)
        {
            cout << "Conjunto Bom" << endl;
        }
    }
}