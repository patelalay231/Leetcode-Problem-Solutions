class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    long closestSum = INT_MAX;
    for(int i=0;i<n;i++){
        int j = i+1;
        int k = n-1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == target){
                return target;
            } 
            else if(abs(sum - target) <= abs(closestSum - target)){
                closestSum = sum;
            }
            if(sum > target){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return closestSum;
}
};