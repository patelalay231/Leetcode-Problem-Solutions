class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int mul = 1;  // To store the product of non-zero elements
        int zeros = 0;  // Count of zeros in the array
        
        // Step 1: Calculate the product of all non-zero elements and count zeros
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) 
                zeros++;
            else 
                mul *= nums[i];
        }
        
        vector<int> ans(n, 0); 
        if (zeros > 1) {
            
            return ans;
        }
        
        for (int i = 0; i < n; i++) {
            if (zeros == 1) {
                if (nums[i] == 0) {
                    ans[i] = mul;
                }
            } else {
                ans[i] = mul / nums[i];
            }
        }
        
        return ans;
    }
};
