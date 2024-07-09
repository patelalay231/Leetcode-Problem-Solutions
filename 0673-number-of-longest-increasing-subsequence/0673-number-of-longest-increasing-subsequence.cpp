class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(nums[prev]<nums[i] && dp[i]==1+dp[prev]){
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) count+=cnt[i];
        }
        return count;
    }
};