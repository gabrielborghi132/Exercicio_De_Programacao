#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int distributeCandies(vector<int> candies)
{
    unordered_set<int> st;
    for (auto &x : candies)
        st.insert(x);
    if (st.size() < (candies.size() / 2))
        return int(st.size());
    else
        return int(candies.size() / 2);
}
int main()
{
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    cout << distributeCandies(candyType) << endl;
    return 0;
}