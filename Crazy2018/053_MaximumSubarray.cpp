class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // space: O(1) computation: O(n)
        // can not track the start and the end
        int res = INT_MIN, cur = 0;
        for(int i=0; i< nums.size(); i++){
            cur = max(cur+nums[i], nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};