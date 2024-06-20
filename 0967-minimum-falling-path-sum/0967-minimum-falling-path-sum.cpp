class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        if(n==1) return nums[0][0];
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<n && j>1) dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])) + nums[i-1][j-1];
                if(j==n) dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + nums[i-1][j-1];
                if(j==1) dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]) + nums[i-1][j-1];
            }
        }
        int mini = INT_MAX;

        for(int i=1;i<=n;i++) mini = min(mini,dp[n][i]);
        return mini;
    }
};