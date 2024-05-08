class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthestJump = 0;
        int jump = 0;
        int lastJump = 0;
        if(n ==1 ) return 0;
        for (int i = 0; i < n; i++) {
            farthestJump = max(farthestJump, nums[i] + i);
            if (lastJump == i) {
                jump++;
                lastJump = farthestJump;
                if (farthestJump >= n - 1) {
                    break;
                }
            }
        }
        return jump;
    }
};