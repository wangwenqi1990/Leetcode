class Solution {
public:
    // recursion, which is slow
    // computation: O(2^n), Space:       O(2^n)
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTS(nums, 0, nums.size(), S);
    }
    int findTS(vector<int>&nums, int i, int j, int S){
        if(i==j)    return S==0? 1 : 0;
        return findTS(nums, i+1, j, S+nums[i]) + findTS(nums, i+1, j, S-nums[i]);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // dp solution
        // Space: O(n^2) Computation: O(n)
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n+1);
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(auto a: dp[i-1]){
                int s = a.first, cnt = a.second;
                dp[i][s+nums[i-1]]+=cnt;
                dp[i][s-nums[i-1]]+=cnt;
            }
        }
        return dp[n][S];
    }
};