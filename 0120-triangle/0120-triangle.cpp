class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        // Base case: if we are at the last row, return the value of that cell
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        
        // If the result is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Recursive calls for the next row
        int d = helper(triangle, i + 1, j, dp);
        int dg = helper(triangle, i + 1, j + 1, dp);
        
        // Compute the minimum path sum for the current cell and store it in dp
        dp[i][j] = triangle[i][j] + min(d, dg);
        
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Initialize the dp array with -1 to indicate uncomputed cells
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(triangle, 0, 0, dp);
    }
};
