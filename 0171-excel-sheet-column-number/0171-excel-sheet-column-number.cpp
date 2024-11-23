class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        long long ans = columnTitle[n-1]-'A'+1;
        int mul = 1;
        for(int i=n-2;i>=0;i--){
            ans += (columnTitle[i]-'A'+1)*pow(26,mul);
            mul++;
        }
        return ans;
    }
};