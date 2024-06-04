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
        set<pair<int,int>> st;
        st.insert({0,k});
        travelTime[k] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int src = it.second;
            int srcTime = it.first;
            st.erase(it);
            for(auto it : adj[src]){
                int dst = it.first;
                int dstTime = it.second;
                if(srcTime + dstTime < travelTime[dst]){
                    if(travelTime[dst] != INT_MAX){
                        st.erase({travelTime[dst],dst});
                    }
                    travelTime[dst] = srcTime + dstTime;
                    st.insert({travelTime[dst],dst});
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