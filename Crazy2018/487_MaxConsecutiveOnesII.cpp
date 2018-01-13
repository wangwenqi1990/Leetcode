class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pre = 0, cur =0, res = 0, exist = 0;
        // exist counts if 0 ever exist
        // computation: O(n) space: O(1)
        for(int i=0; i< nums.size(); i++){
            if(nums[i]!=0)
                cur++;
            else{
                exist = 1;
                res = max(res, pre+cur+exist);
                pre = cur;
                cur =0;
            }
        }
        return max(res, pre+cur+exist);
    }
};