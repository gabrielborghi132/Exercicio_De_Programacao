#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<tuple<int, int, double>> edge_list; 
    
    vector<double> prob; 

    void bellman_ford_max_prob(int s) {
        prob.assign(n, 0.0);
        prob[s] = 1.0;

        for (int i = 1; i <= n - 1; i++) {
            bool atualizado = false;
            
            for (auto& [u, v, w] : edge_list) {
                
                if (prob[u] > 0.0 && prob[v] < prob[u] * w) {
                    prob[v] = prob[u] * w;
                    atualizado = true;
                }
            }
            if (!atualizado) break;
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        this->n = n;
        this->edge_list.clear(); 

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            this->edge_list.emplace_back(u, v, w);
            this->edge_list.emplace_back(v, u, w);
        }

        bellman_ford_max_prob(start_node);

        return prob[end_node];
    }
};