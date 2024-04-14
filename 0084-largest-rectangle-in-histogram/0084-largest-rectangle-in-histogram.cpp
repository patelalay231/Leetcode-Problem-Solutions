class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right_smaller(n);
        vector<int> left_smaller(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left_smaller[i] = st.top() + 1;
            } else {
                left_smaller[i] = 0;
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                right_smaller[i] = n - 1;
            else
                right_smaller[i] = st.top() - 1;

            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (right_smaller[i] - left_smaller[i] + 1));
        }
        return maxA;
    }
};