class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int stop_point = -1;
        /* finding breaking point where condition fails that right side of
        that ele is smaller than that element */
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                stop_point = i;
                break;
            }
        }
        if (stop_point == -1) {
            // reverse the whole array:
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i > stop_point; i--) {
                if (nums[i] > nums[stop_point]) {
                    swap(nums[i], nums[stop_point]);
                    break;
                }
            }
            reverse(nums.begin() + stop_point + 1, nums.end());
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums(n,0);
        for(int i=0;i<n;i++){
            nums[i] = i+1;
        }
        for(int i=0;i<k-1;i++){
            nextPermutation(nums);
        }
        string ans = "";
        for(auto it : nums){
            ans += to_string(it);
        }
        return ans;
    }
};