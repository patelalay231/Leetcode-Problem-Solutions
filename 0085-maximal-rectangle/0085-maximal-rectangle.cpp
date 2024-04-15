class Solution {
public:
    int largestAreaHistogram(vector<int> &heights){
        int n = heights.size();
        vector<int> left_smaller(n,0);
        vector<int> right_smaller(n,n-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                left_smaller[i] = st.top() + 1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right_smaller[i] = st.top() - 1;
            }
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,heights[i] * (right_smaller[i] - left_smaller[i] + 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowHistogram(m, 0);
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    rowHistogram[j]++;
                } else {
                    rowHistogram[j] = 0;
                }
            }
            // now I have created the histogram for the particular level
            // now find the largest area in that level
            area = max(area, largestAreaHistogram(rowHistogram));
        }
        return area;
    }
};