class Solution {
public:
    int dfs(vector<vector<int>>& adjacency_mat, int node, int parent) {
        int cnt = 1; // Count the current node
        for (auto it : adjacency_mat[node]) {
            if (it != parent) {
                cnt += dfs(adjacency_mat, it, node);
            }
        }
        return cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // Convert restricted to an unordered set for efficient lookup
        unordered_set<int> restricted_set(restricted.begin(), restricted.end());

        // Build adjacency list
        vector<vector<int>> adjacency_mat(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Ignore edges connected to restricted nodes
            if (restricted_set.find(u) != restricted_set.end() || restricted_set.find(v) != restricted_set.end()) {
                continue;
            }

            adjacency_mat[u].push_back(v);
            adjacency_mat[v].push_back(u);
        }

        // Start DFS from node 0 (assumes node 0 is not restricted)
        return dfs(adjacency_mat, 0, -1);
    }
};
