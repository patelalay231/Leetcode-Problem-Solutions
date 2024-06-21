class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size(); 
        int n = grid.size();    
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        // initialize the dp array for the last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                // If both people are at the same column, only one can pick cherries
                if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
                else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8; // Initialize with a very small value
                    // Explore all possible movements for both people
                    for (int k = -1; k <= 1; k++) {
                        for (int h = -1; h <= 1; h++) {
                            int value = 0;
                            // If both people are at the same column, only one can pick cherries
                            if (j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            // Check if both people stay within the grid boundaries
                            if (j1 + k >= 0 && j1 + k < m && j2 + h >= 0 && j2 + h < m)
                                value += dp[i + 1][j1 + k][j2 + h]; // Add the cherries from the next row
                            else 
                                value += -1e8; // Penalize if out of bounds
                            maxi = max(maxi, value); // Update the maximum cherries
                        }
                    }
                    dp[i][j1][j2] = maxi; // Store the maximum cherries for the current configuration
                }
            }
        }
        // Return the maximum cherries that can be picked from the top row
        return dp[0][0][m - 1];
    }
};

