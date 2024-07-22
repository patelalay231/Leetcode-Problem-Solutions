// Striver Intuition
// DP - Tabulation Approach
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]){
                    if(i==0 || j==0) dp[i][j] = 1;
                    // Check its surrounding neighbor for minimum value of square
                    else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1], dp[i-1][j]));
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};