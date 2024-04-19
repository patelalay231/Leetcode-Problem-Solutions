class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = n - 1;
        int maxSum = 0;
        int sum = 0;
        while (l < k) {
            sum += cardPoints[l];
            l++;
            maxSum = max(maxSum, sum);
        }
        l--;
        while (l >= 0) {
            sum += cardPoints[r];
            sum -= cardPoints[l];
            r--;
            l--;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};