class Solution {
public:
    int numDistinct(string str, string sub) {
    int mod = (int)1e9+7;
	int n=str.size();
	int m=sub.size();
	vector<int>prev(m+1,0);
	prev[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(str[i-1]==sub[j-1]){
				prev[j]=(prev[j]+prev[j-1])%mod;
			}
		}
	}
	return prev[m]%mod;
    }
};