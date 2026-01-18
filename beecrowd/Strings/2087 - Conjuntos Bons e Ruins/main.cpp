#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct node
{
    int next[26];
    int degree;
    int terminal_count;

    node()
    {
        fill(next, next + 26, -1);
        degree = 0;
        terminal_count = 0;
    }
};

vector<node> trie(1);

bool add_string(const string &s)
{
    int v = 0;

    for (char ch : s)
    {
        if (trie[v].terminal_count > 0)
            return true;

        int c = ch - 'a';
        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = (int)trie.size();
            trie.emplace_back();
            trie[v].degree++;
        }
        v = trie[v].next[c];
    }

    if (trie[v].terminal_count > 0)
        return true;
    if (trie[v].degree > 0)
        return true;

    trie[v].terminal_count++;
    return false;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        trie.clear();
        trie.emplace_back();

        bool ruim = false;
        string s;

        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (!ruim)
                ruim = add_string(s);
            else
                add_string(s);
        }

        cout << (ruim ? "Conjunto Ruim" : "Conjunto Bom") << endl;
    }
    return 0;
}
