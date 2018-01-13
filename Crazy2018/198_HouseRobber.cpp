class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        // dp[i] represents till nums[i-1] the maximum profit
        int dp[n+1]={0};
        dp[1]=nums[0];
        for(int i=2; i<n+1; i++)
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);// maximum(not steal the ith, steal the ith)
        return dp[n];
    }
};