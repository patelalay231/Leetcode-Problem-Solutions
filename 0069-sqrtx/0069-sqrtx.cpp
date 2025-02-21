class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // Handle edge cases

        int low = 0, high = x, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;

            if (sq == x) {
                return mid;
            } 
            else if (sq > x) {
                high = mid - 1;
            } 
            else {
                ans = mid; // Store the potential answer
                low = mid + 1;
            }
        }
        return ans; // Return the floored square root
    }
};
