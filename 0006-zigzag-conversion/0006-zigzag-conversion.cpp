class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
        return s;
        }
    
        vector<vector<char>> ans(numRows);
        int row = 0;
        int step = 1;
    
        for(int i = 0; i < s.length(); i++) {
            ans[row].push_back(s[i]);
            if (row == 0) {
                step = 1;
            }
            else if (row == numRows - 1) {
            step = -1;
            }
            row += step;
        }
    
        string res="";
        for(int i=0;i<numRows;i++){
           for(auto x:ans[i])   
                res+=x;
        }
        return res;
    }
};