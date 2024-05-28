class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> distanceMat(r,vector<int> (c,0));
        vector<vector<int>> visitedMat(r,vector<int> (c,0));

        // Pushl all the indices of zeros
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    visitedMat[i][j] = 1;
                }
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        // pop front element from queue
        // push all the it's neighbours 1's

        while(!q.empty()){
            auto ele = q.front();
            int row = ele.first.first;
            int col = ele.first.second;
            int dist = ele.second;
            q.pop();
            for(auto d : dir){
                int nr = d.first + row;
                int nc = d.second + col;

                if(nr >= 0 && nr < r && nc >=0 && nc < c && !visitedMat[nr][nc] && mat[nr][nc]){
                    visitedMat[nr][nc] = 1;
                    distanceMat[nr][nc] = dist + 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }  
        return distanceMat;
    }
};