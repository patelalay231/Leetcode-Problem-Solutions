class Solution {
public:


    int helper(vector<int>& arr, int n, int k, int idx,vector<int>& dp) {
        // If there are no partitions left to do or the array is over
        if (idx == n) {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int maxi = 0;
        int result = 0;

        for (int i = idx; i < min(idx + k, n); ++i) {
            maxi = max(arr[i], maxi);
            int cost = maxi * (i - idx + 1) + helper(arr, n, k, i + 1,dp);
            result = max(result, cost);
        }

        return dp[idx] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return helper(arr, n, k, 0,dp);;
    }
};
