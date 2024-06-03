class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        int rows = grid.size();
        int cols = grid[0].size();
        // step 1 intialize distance infinite except (0,0);
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 1;

        // step 2 declare moving directions
        vector<pair<int, int>> directions = {
            {1, 0},  // Right
            {-1, 0}, // Left
            {0, 1},  // Down
            {0, -1}, // Up
            {1, 1},  // Down-Right
            {1, -1}, // Up-Right
            {-1, 1}, // Down-Left
            {-1, -1} // Up-Left
        };
        
        // step 3 run dijkstra algo in all 8 direction and cell is 0.
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int i = ele.second.first;
            int j = ele.second.second;
            int srcDist = ele.first;

            for(auto d : directions){
                int ni = i + d.first;
                int nj = j + d.second;

                if(ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 0){
                    if(srcDist + 1 < dist[ni][nj]){
                        dist[ni][nj] = srcDist + 1;
                        q.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        if(dist[rows-1][cols-1] == INT_MAX) return -1;
        return dist[rows-1][cols-1];
    }
};