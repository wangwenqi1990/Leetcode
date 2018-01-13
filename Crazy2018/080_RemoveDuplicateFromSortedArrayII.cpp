class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1, count = 1, n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        // assmue length >=2
        for(int l=0, r=1; r<n;){
            if(nums[r-1]==nums[r]){
                if(count<2){
                    res++;
                    count++;
                    nums[++l]=nums[r++];
                }
                else{
                    r++;
                }
            }
            else{
                count=1;
                res++;
                nums[++l] = nums[r++];
            }
        }
        return res;
    }
};