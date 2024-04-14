class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            st.push(asteroids[i]);

            while (st.size() > 1) {
                int astr1 = st.top();
                st.pop();
                int astr2 = st.top();
                st.pop();
                if (astr1 < 0 && astr2 > 0) {
                    if (astr2 > abs(astr1)) {
                        st.push(astr2);
                    } else if (astr2 != abs(astr1)) {
                        st.push(astr1);
                    }
                } else {
                    st.push(astr2);
                    st.push(astr1);
                    break;
                }
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};