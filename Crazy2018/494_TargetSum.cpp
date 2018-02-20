class Solution {
public:
    int findTargetSumWays1(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        // updating harsh table, which is map from target value to #times
        for (int num : nums) {
            unordered_map<int, int> t;
            for (auto a : dp) {
                int sum = a.first, cnt = a.second;
                t[sum + num] += cnt;
                t[sum - num] += cnt;
            }
            dp = t;
        }
        return dp[S];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0, start = 0;
        helper(nums, S, start, res);
        return res;
    }
    void helper(vector<int>& nums, int S, int start, int& res) {
        if (start >= nums.size()) {
            if (S == 0) ++res;
            return;
        }
        helper(nums, S - nums[start], start + 1, res);
        helper(nums, S + nums[start], start + 1, res);
    }
};