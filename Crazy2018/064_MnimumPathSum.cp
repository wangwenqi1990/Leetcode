class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // computation: O(mn)   space: O(min(m, n))å 
        if(grid.size()==0 || grid[0].size()==0 )
            return 0;
        int m = grid.size(), n = grid[0].size();
        int dp[n]={grid[0][0]};
        for(int i=1;i<n; i++)
            dp[i]= dp[i-1]+ grid[0][i];
        
        for(int j=1; j<m; j++){
            dp[0]=dp[0]+grid[j][0];
            for(int i=1; i<n; i++)
                dp[i]=min(dp[i-1], dp[i])+grid[j][i];
        }
        return dp[n-1];
    }
};