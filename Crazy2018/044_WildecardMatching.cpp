class Solution {
public:
    bool isMatch(string s, string p) {
        // space: O(ps), can be reduced to O(p)
        // computation: O(ps)
        int ns = s.size(), np = p.size();
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, false));
        dp[0][0]=true;for(int i=1; i<=np;++i) {if(p[i-1]=='*') dp[0][i]=dp[0][i-1];}  // initializa first row
        for(int i=1;i<=ns;++i){
            for(int j=1; j<=np; ++j){
                if(p[j-1]==s[i-1] || p[j-1]=='?')       dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')                    dp[i][j]=dp[i-1][j-1]|| dp[i-1][j] || dp[i][j-1];// match 1 or >=1 or 0
            }
        }
        return dp[ns][np];
    }
};
