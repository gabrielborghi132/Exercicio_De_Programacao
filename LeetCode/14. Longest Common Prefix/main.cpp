#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
class Solution
{
private:
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

    vector<node> trie;

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        trie.emplace_back();
        for (auto s : strs)
        {
            add_string(s);
        }
        string s = "";
        int v = 0;
        while (trie[v].degree == 1 && trie[v].terminal_count == 0)
        {
            for (int c = 0; c < 26; c++)
            {
                if (trie[v].next[c] != -1)
                {
                    s.push_back('a' + c);
                    v = trie[v].next[c];
                    break;
                }
            }
        }
        cout << s << endl;
    }
};