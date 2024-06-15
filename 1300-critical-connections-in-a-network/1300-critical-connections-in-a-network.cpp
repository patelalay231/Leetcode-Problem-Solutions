class Solution {
public:
    int timer = 1;
    void dfs(int node,int parent,int tin[],int low[],vector<vector<int>>& adj,vector<int>& vis,vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,tin,low,adj,vis,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int tin[n];
        int low[n];

        vector<int> vis(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,tin,low,adj,vis,bridges);
        
        return bridges;
    }
};