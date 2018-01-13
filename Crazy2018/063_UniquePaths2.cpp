class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0)   return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[n]={0},tp = 1;
        // initialization
        for(int i=0; i<n;i++){
            if(obstacleGrid[0][i]==1)
                tp = 0;
            dp[i]=tp;
        }
        // iteration
        for(int r=1; r<m; r++ ){
            dp[0] = obstacleGrid[r][0]==1?0:dp[0];
            for(int c=1; c<n; c++){
                if(obstacleGrid[r][c]==1) {
                    dp[c]=0; continue;
                }
                dp[c] = dp[c-1]+ dp[c];
            }
        }
        return dp[n-1];     
    }
};