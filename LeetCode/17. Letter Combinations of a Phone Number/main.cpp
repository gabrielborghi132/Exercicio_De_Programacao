/**************************************************/
//         17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=problem-list-v2&envId=backtracking*/
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
    vector<string> letterCombinations(string digits)
    {
        vector<string> opcoes = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> respostas;
        resolver("", 0, respostas, digits, opcoes);
        return respostas;
    }

private:
    void resolver(string atual, int start, vector<string> &resposta, string digits, vector<string> opcoes)
    {
        if (start == digits.size())
        {
            resposta.push_back(atual);
            return;
        }

        string letras = opcoes[digits[start] - '0'];
        for (auto &letra : letras)
        {
            atual.push_back(letra);
            resolver(atual, start + 1, resposta, digits, opcoes);
            atual.pop_back();
        }
    }
};