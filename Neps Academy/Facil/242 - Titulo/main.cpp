#include <bits/stdc++.h>
using namespace std;

int main()
{
    string F, palavra;
    getline(cin, F);
    istringstream iss(F);
    while (iss >> palavra)
    {
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        palavra[0] = toupper(palavra[0]);
        cout << palavra << " ";
    }
    cout << endl;
}