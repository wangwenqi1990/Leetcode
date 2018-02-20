class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // sum results
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        // dp[i][j]表示将数组中前j个数字分成i组所能得到的最小的各个子数组中最大值
        // O(mn^2)
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sums[j] - sums[k]));
                }
            }
        }
        return dp[m][n];
    }
};