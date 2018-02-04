class Solution {
public:
    int numDecodings(string s) {
        int res = 0, n = s.size();
        vector<int> dp(n+1, 1);
        if(n==0) return res;
        if(s[0]=='0') return res;
        for(int i=1; i< n; i++){
            if(s[i]=='0'){
                if(s[i-1]!='1' && s[i-1]!='2')  return 0;
                else dp[i+1]=dp[i-1];
            }
            else if(s[i]>='1' && s[i]<='6'){
                dp[i+1]=dp[i];
                if(s[i-1]=='1' || s[i-1]=='2')  dp[i+1]+=dp[i-1];
            }
            else{
                dp[i+1]=dp[i];
                if(s[i-1]=='1') dp[i+1]+=dp[i-1];
            }
        }
        return dp[n];
    }
};