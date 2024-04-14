class Solution {
public:
    void leftLesser(vector<int> &res,vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!st.empty() && st.top().first > heights[i]){
                cnt += st.top().second;
                st.pop();
            }
            res[i] = cnt;
            st.push({heights[i],cnt});
        }
    }
    void rightLesser(vector<int> &res,vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!st.empty() && st.top().first >= heights[i]){
                cnt += st.top().second;
                st.pop();
            }
            res[i] = cnt;
            st.push({heights[i],cnt});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightLesserArr(n);
        vector<int> leftLesserArr(n);
        rightLesser(rightLesserArr,heights);
        leftLesser(leftLesserArr,heights);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int area = heights[i] * (rightLesserArr[i] + leftLesserArr[i] - 1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};