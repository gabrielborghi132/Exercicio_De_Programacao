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
    int v;
    for (auto ch : s)
    {
        int c = ch - 'a';

        if (trie[v].next[c] == -1)
        {
            trie[v].next[c] = trie.size();

            trie.emplace_back();

            trie[v].degree++;
            v = trie[v].next[c];

            trie[v].prefix_count++;
        }
        trie[v].terminal_count++;
    }
}
int main()
{
    vector<string> vt = {"flower", "flow", "flight"};
    for (auto s : vt)
    {
        add_string(s);
    }
}