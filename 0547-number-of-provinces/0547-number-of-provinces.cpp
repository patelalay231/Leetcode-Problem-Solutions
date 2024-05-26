class Solution {
public:

    void traversal(int node,vector<int>& isVisited,vector<vector<int>>& isConnected){
        stack<int> s;
        s.push(node);
        isVisited[node] = 1;
        while(!s.empty()){
            int ele = s.top();
            s.pop();
            int n = isConnected[ele].size();
            for(int i=0;i<n;i++){
                if(isConnected[ele][i] && !isVisited[i]){
                    s.push(i);
                    isVisited[i] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> isVisited(v,0);
        int connectedComp = 0;
        for(int i=0;i<v;i++){
            if(!isVisited[i]){
                traversal(i,isVisited,isConnected);
                connectedComp++;
            }
        }
        return connectedComp;
    }
};