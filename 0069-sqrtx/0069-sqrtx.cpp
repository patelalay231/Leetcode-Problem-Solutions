class Solution {
public:
    int mySqrt(int x) {
         if (x == 0 || x == 1) return x; // Handle edge cases
        int low = 0;
        int high = x;
        int ans = -1;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long sq = mid * mid;
            if(sq == x){
                return mid;
            }
            else if(sq > x){
                high = mid - 1;  
            }
            else{
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};

/* 

4 = 

*/