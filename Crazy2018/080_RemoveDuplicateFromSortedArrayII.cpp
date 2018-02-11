class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)  return nums.size();
        int res=1, l =0, r=1, cnt = 1;
        while(r<nums.size()){
            // nums[r]==nums[r-1] and cnt contrals repeatance monitoring
            // nums[++l]=nums[r++] updating the array
            if(nums[r]==nums[r-1]){
                if(cnt<2){++res;++cnt;nums[++l]=nums[r++];}
                else{r++;}
            }
            else{
                cnt = 1;++res;nums[++l]=nums[r++];
            }
        }
        return res;
    }
};
