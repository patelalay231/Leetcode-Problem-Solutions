class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mpMail;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string it = accounts[i][j];
                if(mpMail.find(it) != mpMail.end()){
                    ds.unionByRank(i,mpMail[it]);
                }
                else{
                    mpMail[it] = i;
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it : mpMail){
            string mail = it.first;
            int mailIdx = ds.findUPar(it.second);
            mergedMail[mailIdx].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0;i<mergedMail.size();i++){
            if(mergedMail[i].size() != 0){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(mergedMail[i].begin(),mergedMail[i].end());
                for(auto it : mergedMail[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;

    }
};