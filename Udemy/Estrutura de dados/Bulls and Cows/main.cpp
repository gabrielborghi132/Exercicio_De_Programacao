#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

string getHint(string secret, string guess)
{
    int n = int(secret.size());
    int bulls = 0, cows = 0;
    vector<int> countSecret(10, 0);
    vector<int> countGuess(10, 0);

    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
            bulls++;
        else
        {
            countSecret[secret[i] - '0']++;
            countGuess[guess[i] - '0']++;
        }
    }

    for (int d = 0; d < 10; d++)
    {
        cows += min(countSecret[d], countGuess[d]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
int main()
{
    cout << getHint("1123", "0111") << endl;
}