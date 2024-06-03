class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            int src = it[0];
            int desti = it[1];
            int cost = it[2];
            adj[src].push_back({desti, cost});
        }

        // define distance vector
        vector<int> dist(n, INT_MAX);

        // priority queue: {cost, {current node, stops taken}}
        queue<pair<int, pair<int, int>>> pq;
        
        // insert src and its distance from src. {stop, {src, cost}}
        pq.push({0, {src, 0}});
        dist[src] = 0;

        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();
            int currDist = it.second.second;
            int source = it.second.first;
            int currStops = it.first;

            if(currStops > k) continue;
            for (auto adjNode : adj[source]) {
                int adjDest = adjNode.first;
                int adjCost = adjNode.second;

                if (adjCost + currDist < dist[adjDest] && currStops <= k) {
                    dist[adjDest] = currDist + adjCost;
                    pq.push({currStops+1, {adjDest, dist[adjDest]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};