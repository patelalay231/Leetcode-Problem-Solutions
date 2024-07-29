class Solution {
public:
    string countAndSay(int n) {
    string s ="1";
    for(int i=1;i<n;i++){
        int len = s.size();
        int cnt = 0;
        string newS;
        for(int j=0;j<len;j++){
            if(j == 0 || s[j] == s[j-1]){
                cnt++;
            }
            else{
                newS += to_string(cnt) + s[j-1];
                cnt = 1;
            }
        }
        newS += to_string(cnt) + s[len-1];
        s = newS;
    }
    return s;
}
};