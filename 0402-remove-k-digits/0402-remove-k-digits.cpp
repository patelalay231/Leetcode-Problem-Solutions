class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            while (k != 0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k--)
            st.pop();
        num = "";
        while (!st.empty()) {
            num += st.top();
            st.pop();
        }
        reverse(num.begin(), num.end());
        int i = 0;
        n = num.size();
        // if we have leading zeroes handle it by using this
        //  take for example 1000000000 k=1 we remove 1 but all we are left with
        //  leading zeroes.
        while (i < n && num[i] == '0')
            i++;
        if (i == n)
            return "0"; // means all leading zeroes
        return num.substr(i, n - i);
    }
};