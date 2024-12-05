class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int pre=nums[0],pos=nums[n-1];
        for(int i=1;i<n;i++){
            ans[i] = pre;
            pre = pre * nums[i];
        }
        for(int i=n-2;i>=0;i--){
            ans[i] = ans[i] * pos;
            pos = pos * nums[i];
        }
        return ans;
    }
};