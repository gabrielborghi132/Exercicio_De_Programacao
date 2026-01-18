#include <bits/stdc++.h>
using namespace std;

struct node
{
    int next[26];
    bool end;

    node()
    {
        fill(next, next + 26, -1);
        end = false;
    }
};

vector<node> trie;
bool bad;

void add(const string &s)
{
    int v = 0;

    for (char ch : s)
    {
        if (trie[v].end)
            bad = true;

        int c = ch - 'a';
        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = (int)trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }

    for (int c = 0; c < 26; c++)
        if (trie[v].next[c] != -1)
            bad = true;

    if (trie[v].end)
        bad = true;

    trie[v].end = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n)
    {
        trie.clear();
        trie.emplace_back();
        bad = false;

        while (n--)
        {
            string s;
            cin >> s;
            if (!bad)
                add(s);
        }

        cout << (bad ? "Conjunto Ruim\n" : "Conjunto Bom\n");
    }
    return 0;
}
