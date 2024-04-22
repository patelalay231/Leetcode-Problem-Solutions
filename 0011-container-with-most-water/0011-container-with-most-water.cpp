class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxContainer = 0;
        int n = height.size();
        int l = 0, r = n-1;
        while(l < r){
            maxContainer = max(maxContainer,min(height[l],height[r])*(r-l));
            if(height[r] > height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxContainer;
    }
};