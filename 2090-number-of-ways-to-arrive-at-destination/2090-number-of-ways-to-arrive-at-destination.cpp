class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // build adj
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            int src = it[0];
            int dst = it[1];
            int time = it[2];
            adj[src].push_back({dst,time});
            adj[dst].push_back({src,time});
        }

        // Initialize distance and path count vectors
        vector<pair<long long, long long>> distAndPath(n, {LLONG_MAX, 0}); // Use long long to avoid overflow
        set<pair<long long, int>> st;
        distAndPath[0] = {0, 1}; // Start node: distance = 0, paths = 1
        st.insert({0, 0});

        int MOD = 1e9 + 7;

        while(!st.empty()){
            auto it = *(st.begin());
            long long srcDist = it.first;
            int src = it.second;
            st.erase(it);

            for(auto& edge : adj[src]){
                int dst = edge.first;
                long long dstDist = edge.second;

                if(srcDist + dstDist < distAndPath[dst].first){
                    // When a shorter path is found, update distance and path count
                    if(distAndPath[dst].first != LLONG_MAX){
                        st.erase({distAndPath[dst].first, dst});
                    }
                    distAndPath[dst] = {srcDist + dstDist, distAndPath[src].second}; // Correctly carry over path count
                    st.insert({distAndPath[dst].first, dst});
                }
                else if(srcDist + dstDist == distAndPath[dst].first){
                    // When another shortest path is found, update path count
                    distAndPath[dst].second += distAndPath[src].second;
                    distAndPath[dst].second %= MOD; // Apply modulo operation to avoid overflow
                }
            }
        }

        return distAndPath.back().second % MOD;
    }
};
