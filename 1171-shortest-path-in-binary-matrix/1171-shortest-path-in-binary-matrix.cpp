class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Check if the starting point is blocked
        if(grid[0][0] != 0) return -1;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Initialize distance matrix with infinity, except the starting point (0,0)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 1;

        // Define all 8 possible directions
        vector<pair<int, int>> directions = {
            {1, 0},   // Right
            {-1, 0},  // Left
            {0, 1},   // Down
            {0, -1},  // Up
            {1, 1},   // Down-Right
            {1, -1},  // Up-Right
            {-1, 1},  // Down-Left
            {-1, -1}  // Up-Left
        };
        
        // Use a set to act as a priority queue for BFS; stores the distance and coordinates
        set<pair<int, pair<int, int>>> s;
        s.insert({1, {0, 0}});

        while(!s.empty()) {
            auto it = s.begin();
            int currentDist = it->first;
            int i = it->second.first;
            int j = it->second.second;
            s.erase(it);

            for(auto& direction : directions) {
                int ni = i + direction.first;
                int nj = j + direction.second;

                // Check if the new position is within bounds and is not blocked
                if(ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 0) {
                    if(currentDist + 1 < dist[ni][nj]) {
                        // If there's a better path, update the distance and insert into the set
                        if(dist[ni][nj] != INT_MAX) {
                            s.erase({dist[ni][nj], {ni, nj}});
                        }
                        dist[ni][nj] = currentDist + 1;
                        s.insert({dist[ni][nj], {ni, nj}});
                    }
                }
            }
        }
        
        // If the destination is still at maximum distance, return -1
        if(dist[rows-1][cols-1] == INT_MAX) return -1;
        
        // Return the distance to the bottom-right corner
        return dist[rows-1][cols-1];
    }
};