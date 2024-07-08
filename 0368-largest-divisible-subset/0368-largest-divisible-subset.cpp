class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        sort(nums.begin(),nums.end());
        int maxi=0,lastindex=0;
        hash[0]=0;
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }

            }

            if(dp[i]>maxi)
            {
                lastindex=i;
                maxi=dp[i];
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
              lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
          
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};