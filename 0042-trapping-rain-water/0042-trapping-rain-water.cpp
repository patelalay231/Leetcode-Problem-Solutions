class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]); 
            right[n-i-1] = max(right[n-i],height[n-i-1]);
        }
        int totalTrapped = 0;
        for(int i=0;i<n;i++){
            totalTrapped += min(right[i],left[i]) - height[i];
        }
        return totalTrapped;
    }
};