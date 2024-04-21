class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        vector<int> mp(n+1,0);
        int diff = 0;
        while (r < n) {
            if(mp[nums[r]] == 0){
                diff++;
            }
            mp[nums[r]]++;
            while (diff > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) diff--;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};