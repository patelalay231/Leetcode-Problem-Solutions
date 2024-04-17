class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int zeros = 0;
        int sum = 0;
        int maxSum = 0;
        int left = 0, right = 0;
        while (right < n) {
            if (arr[right] == 0)
                zeros++;
            if (zeros > k) {
               if(arr[left] == 0) zeros--;
               left++;
            }
            maxSum = max(maxSum, right - left + 1);
            right++;
        }
        return maxSum;
    }
};