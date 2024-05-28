class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        q.push({sr,sc});
        // Directions for the four possible movements (left, right, up, down)
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int startColor = grid[sr][sc];
        grid[sr][sc] = color;
        // Rotting neighbor fresh oranges
        while (!q.empty()) {
            
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
                
            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = column + dir.second;
                
                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && grid[newRow][newCol] == startColor && grid[newRow][newCol] != color) {
                    grid[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
    
        return grid;
    }
};