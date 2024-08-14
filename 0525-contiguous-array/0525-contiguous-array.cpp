class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        int count = 0;
        int maxLength = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) count--;
            else count++;
            if(count == 0) maxLength = i+1;
            else if(mpp[count] == 0) mpp[count] = i+1;
            else maxLength = max(maxLength,i - mpp[count] + 1);
        }
        return maxLength;
    }
};