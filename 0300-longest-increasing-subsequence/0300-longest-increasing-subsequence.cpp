class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=n-1;i>=0;i--){
            int maxCount = 0;
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i]){
                    maxCount = max(maxCount,dp[j]);
                }
            }
            dp[i] = 1 + maxCount;
        }
        int maxi = 0;
        for(auto it:dp){
            maxi = max(maxi,it);
        } 
        return maxi;
    }
};