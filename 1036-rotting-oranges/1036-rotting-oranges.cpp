class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        queue<pair<int, int>> q;
        
        // Storing rotten oranges at time 0 
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int minutes = 0;
        
        // Directions for the four possible movements (left, right, up, down)
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        
        // Rotting neighbor fresh oranges
        while (!q.empty()) {
            int n = q.size();
            bool rotten = false;
            
            for (int i = 0; i < n; i++) {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();
                
                for (auto dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = column + dir.second;
                    
                    if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        rotten = true;
                    }
                }
            }
            
            if (rotten) {
                minutes++;
            }
        }
        
        // Check if there are any fresh oranges left
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return minutes;
    }
};
