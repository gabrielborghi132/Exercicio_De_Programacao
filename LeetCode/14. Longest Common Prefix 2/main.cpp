#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
class solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        bool terminou = false;
        int minTam = 0;
        for (auto s : strs)
        {
            minTam = max(minTam, (int)s.length());
        }
        string res;
        int j = 1;
        int u = 0;
        for (int i = 0; i < minTam; i++)
        {
            char c = strs[0][i];

            for (int j = 1; j < n; j++)
            {
                if (strs[j][i] != c)
                {
                    return res;
                }
            }
            res.push_back(c);
        }

        return res;
    }
};
