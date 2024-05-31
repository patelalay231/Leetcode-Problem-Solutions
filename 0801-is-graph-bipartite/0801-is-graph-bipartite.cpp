class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,vector<int>& color,int col){
        color[node] = col;

        for(auto it: graph[node]){
            if(color[it] == -1){
                if(dfs(graph,it,color,!col) == false) return false;;
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i] == -1){
                if(!dfs(graph,i,color,0)){
                    return false;
                }
            }
        }
        return true;
    }
};