class Solution {
public:
    string removeOuterParentheses(string s) {
        string newS = "";
        int cnt = 0;
        for(auto c : s){
            if(c == '('){
                if(cnt != 0){
                    newS += c;
                }
                cnt++;
            }
            else{
                if(cnt != 1){
                    newS += c;
                }
                cnt--;
            }
        }
        return newS;
    }
};