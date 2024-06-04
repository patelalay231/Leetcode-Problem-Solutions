class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> travelTime(n+1,INT_MAX);

        // Build adj;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            int src = it[0];
            int dest = it[1];
            int time = it[2];
            adj[src].push_back({dest,time});
        }
        // Initialize queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        travelTime[k] = 0;

        while(!pq.empty()){
            int src = pq.top().second;
            int srcTime = pq.top().first;
            pq.pop();
            for(auto it : adj[src]){
                int dst = it.first;
                int dstTime = it.second;
                if(srcTime + dstTime < travelTime[dst]){
                    travelTime[dst] = srcTime + dstTime;
                    pq.push({travelTime[dst],dst});
                }
            }           
        }

        int maxTime = INT_MIN;
        for(int i=1;i<=n;i++){
            maxTime = max(maxTime,travelTime[i]);
        }

        if(maxTime == INT_MAX) return -1;
        return maxTime;

    }
};