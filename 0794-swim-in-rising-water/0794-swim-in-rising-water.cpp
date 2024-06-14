typedef pair<int,pair<int,int>> triplet;
class Solution {
private:
    bool isValid(int r,int c,int rows,int cols,vector<vector<int>> vis){
        return r >= 0 && r < rows && c >= 0 && c < cols && vis[r][c] != 1;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows,vector<int> (cols,0));
        priority_queue<triplet,vector<triplet>,greater<triplet>> pq;
        pq.push({grid[0][0],{0,0}});
        int rd[] = {-1,0,1,0};
        int cd[] = {0,1,0,-1};

        while(!pq.empty()){
            int depth = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == rows-1 && c == cols-1){
                return depth;
            }
            if (vis[r][c]) continue;
            vis[r][c] = 1;
            for(int i=0;i<4;i++){
                int nr = rd[i] + r;
                int nc = cd[i] + c;
                if(isValid(nr,nc,rows,cols,vis)){
                    pq.push({max(grid[nr][nc],depth),{nr,nc}});
                }
            }
        }
        return -1;
    }
};