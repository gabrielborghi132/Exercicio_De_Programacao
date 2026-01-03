/**************************************************/
//         1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=problem-list-v2&envId=backtracking*/
//
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll soma = 0;
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int somaResultado = 0;
        vector<bool> usados(nums.size(), false);

        resolver(nums, somaResultado, usados, 0, 0);

        return somaResultado;
    }

private:
    void resolver(vector<int> &opcoes, int &somaResultado, vector<bool> &usados, int soma, int start)
    {
        somaResultado += soma;

        for (int i = start; i < opcoes.size(); i++)
        {
            if (usados[i])
                continue;

            usados[i] = true;
            soma ^= opcoes[i];

            resolver(opcoes, somaResultado, usados, soma, i + 1);

            soma ^= opcoes[i];
            usados[i] = false;
        }
    }
};