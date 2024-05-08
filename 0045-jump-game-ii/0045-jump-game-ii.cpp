class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> miniJump(n, n);
        miniJump[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = 0; j <= nums[i] && j+i<n; j++) {
                mini = min(mini, miniJump[i + j] + 1);
            }
            miniJump[i] = mini;
        }
        return miniJump[0];
    }
};