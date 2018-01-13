class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // space O(1) computation O(n)
        int n=nums.size();
        if(n==1 || n==0) return n;
        int res=1;
        for(int l=0, r=1; r<nums.size(); ){
            if(nums[r] == nums[l])
                r++;
            else{
                res++;
                nums[++l]=nums[r++];
            }
        }
        return res;
    }
};