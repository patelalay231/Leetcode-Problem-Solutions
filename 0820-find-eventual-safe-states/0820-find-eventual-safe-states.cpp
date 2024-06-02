class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        
        // Reverse the graph
        vector<vector<int>> revGraph(v);
        for(int i=0;i<v;i++){
            for(auto it: graph[i]){
                revGraph[it].push_back(i);
            }
        }
       
        vector<int> incomingEdges(v,0);
        for(int i=0;i<v;i++){
            for(auto it: revGraph[i]){
                incomingEdges[it]++;
            }
        }
        // Push all nodes with 0 incoming edges in reverse graph 
        queue<int> q;
        for(int i=0;i<v;i++){
            if(incomingEdges[i] == 0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            safeNodes.push_back(ele);
            // remove outgoing edges of ele.
            // for that just decrease it's neighnour incoming edges.
            for(auto it: revGraph[ele]){
                incomingEdges[it]--;
                if(incomingEdges[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};