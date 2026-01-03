/**************************************************/
//         1217 - Getline Two - Frutas
// https://judge.beecrowd.com/pt/problems/view/1217*/
/**************************************************/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    int t;
    cin >> t;

    double total_kg = 0;
    double total_frutas = 0;
    int dia = 1;

    for (int i = 0; i < t; i++)
    {
        double x;
        cin >> x;
        total_kg += x;

        cin.ignore();

        string linha;
        getline(cin, linha);

        stringstream ss(linha);
        string fruta;
        int conta_dia = 0;
        while (ss >> fruta)
        {
            conta_dia++;
        }

        total_frutas += conta_dia;
        cout << "day " << dia << ": " << conta_dia << " kg" << endl;
        dia++;
    }

    cout << fixed << setprecision(2);
    cout << total_frutas / t << " kg by day" << endl;
    cout << "R$ " << total_kg / t << " by day" << endl;

    return 0;
}