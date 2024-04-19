class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int oddSubArr = 0;
        int l = 0, r = 0;
        int odds = 0;
        while (r < n) {
            if (nums[r] % 2 != 0)
                odds++;
            while (odds > k) {
                if (nums[l] % 2 != 0)
                    odds--;
                l++;
            }
            if (odds <= k)
                oddSubArr += (r - l + 1);
            r++;
        }
        return oddSubArr;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};