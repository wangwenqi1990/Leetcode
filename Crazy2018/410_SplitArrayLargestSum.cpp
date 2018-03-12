class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // computation: O(mn^2)
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    int val = max(dp[i - 1][k], sums[j] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
private:
    bool doable (const vector<int>& nums, int cuts, long long max) {
        // goup nums into cuts group, check if every group sum is less or equal to max;
        int acc = 0;
        for (auto num : nums) {
            if (num > max) return false;
            else if (acc + num <= max) acc += num;
            else {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        // assuming each num is k in value, the n numbers in total
        // computationL O(n+nlog(kn))
        
        // left: the maximum value; right: the accumulated sum
        // group sum should be in the range [left, right)
        long long left = 0, right = 0;
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;  // if m-1 cuts make it, then mid is too large
            else left = mid + 1;
        }
        return left;
    }
};
