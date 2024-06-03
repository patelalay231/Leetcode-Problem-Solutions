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
        vector<int> stops(n, -1);

        // priority queue: {cost, {current node, stops taken}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // insert src and its distance from src. {cost, {src, stops}}
        pq.push({0, {src, 0}});
        dist[src] = 0;
        stops[src] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int currDist = it.first;
            int source = it.second.first;
            int currStops = it.second.second;

            if (source == dst && currStops <= k + 1) return currDist;

            if (currStops > k) continue;

            for (auto adjNode : adj[source]) {
                int adjDest = adjNode.first;
                int adjCost = adjNode.second;

                if (currDist + adjCost < dist[adjDest] || currStops + 1 < stops[adjDest]) {
                    dist[adjDest] = currDist + adjCost;
                    stops[adjDest] = currStops + 1;
                    pq.push({dist[adjDest], {adjDest, currStops + 1}});
                }
            }
        }
        return -1;
    }
};