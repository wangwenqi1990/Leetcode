class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res =0;
        for(int l=-1, r=0; r<nums.size(); ){
            if(nums[r]==val){
                r++;
            }
            else{
                nums[++l]=nums[r++];
                res++;
            }
        }
        return res;
    }
};