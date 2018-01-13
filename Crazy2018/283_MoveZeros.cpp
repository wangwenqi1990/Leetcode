class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // computation: O(n) space: O(1)
        int n = nums.size(),l=0, r=0;
        for(;r<n;){
            if(nums[r]!=0)
                nums[l++]=nums[r++];
            else
                r++;
        }
        for(;l<n;l++)
            nums[l]=0;
    }
};