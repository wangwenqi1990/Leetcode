class Solution {
public:
    int numSquares(int n) {
        // dp[i]: the minimum number of square number for number i
        vector<int> dp(n+1, INT_MAX); dp[0]=0;
        for(int i=0; i<=n; i++){
            for(int j=1; i+ j*j <=n; j++){
                dp[i+j*j] = min(dp[i]+1, dp[i+j*j]);
            }
        }
        return dp[n];
    }
};