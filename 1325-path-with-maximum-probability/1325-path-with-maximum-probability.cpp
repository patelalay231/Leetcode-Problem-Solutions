#include <queue>

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build adjacency list
        vector<vector<pair<int, double>>> adjacency_mat(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjacency_mat[u].emplace_back(v, succProb[i]);
            adjacency_mat[v].emplace_back(u, succProb[i]);
        }
        
        // Priority queue for BFS (max-heap), stores {probability, node}
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        // Vector to track maximum probability to reach each node
        vector<double> max_prob(n, 0.0);
        max_prob[start_node] = 1.0;
        
        while (!pq.empty()) {
            auto [current_prob, curr_node] = pq.top();
            pq.pop();
            
            // If we reached the end node, return the probability
            if (curr_node == end_node) {
                return current_prob;
            }
            
            // Process neighbors
            for (auto& neighbor : adjacency_mat[curr_node]) {
                int next_node = neighbor.first;
                double edge_prob = neighbor.second;
                
                // Update the maximum probability for the next node if a higher one is found
                if (current_prob * edge_prob > max_prob[next_node]) {
                    max_prob[next_node] = current_prob * edge_prob;
                    pq.push({max_prob[next_node], next_node});
                }
            }
        }
        
        // If the end node is not reachable, return 0
        return 0.0;
    }
};
