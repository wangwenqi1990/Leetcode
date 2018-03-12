class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, false));
        dp[0][0]=true;
        for(int i=0; i<=ns; ++i){
            for(int j=1; j<=np; ++j){
                if(j>1 && p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2] || (i>0 && dp[i-1][j] && (s[i-1]==p[j-2]|| p[j-2]=='.') );    // mathching 0 or >=1 previous letters
                }
                else
                    dp[i][j] = (i>0) && dp[i-1][j-1] && (p[j-1]=='.'||p[j-1]==s[i-1]);
            }
        }
        return dp[ns][np];
        
    }
};
