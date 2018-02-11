class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // space O(1) computatoin O(n)
        int n = nums.size();
        if(n==0) return 0;
        int l=0,r= 1;
        while(r<n){
            if(nums[r]!=nums[r-1])
                nums[++l]=nums[r++];
            else
                ++r;
        }
        return l+1;   
    }
};