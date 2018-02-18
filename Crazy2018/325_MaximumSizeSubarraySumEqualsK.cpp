class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // updating res
            if (sum == k) 
                res = i + 1;
            else if (m.count(sum - k)) 
                res = max(res, i - m[sum - k]);
            // update hash by keep the most left results
            if (!m.count(sum)) 
                m[sum] = i;
        }
        return res;
    }
};