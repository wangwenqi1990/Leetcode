class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // storage: O(n) computation: O(klogk+kn)
        vector<int> dp(target+1, 0);    dp[0]=1;    // dp[i]: number of combinaitons for target sum i
        sort(nums.begin(), nums.end());
        for(int i=1; i<=target; ++i){
            for(auto num: nums){
                if(i-num>=0)   dp[i]+=dp[i-num];
            }
        }
        return dp[target];
    }
};
