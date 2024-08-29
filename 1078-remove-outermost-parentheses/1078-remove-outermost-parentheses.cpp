class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int len = s.length();
        string newS = "";
        for (auto c : s) {
            if (st.empty()) {
                st.push(c);
            } else {
                if (st.top() == '(' && c == ')')
                    st.pop();
                else
                    st.push(c);
                if (!st.empty()) {
                    newS += c;
                }
            }
        }
        return newS;
    }
};