class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n==0) return 0;
        int dp[n][3]={0};       // dp[i][j]:the minimum cost for painting house 0->i with last one being color j
        for(int i=0;i<3;i++)
            dp[0][i]=costs[0][i];
        for(int i=1;i<n;i++){
            dp[i][0] = costs[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = costs[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = costs[i][2]+min(dp[i-1][0],dp[i-1][1]);
        }
        return min(min(dp[n-1][0],dp[n-1][1]), dp[n-1][2]);
    }
};