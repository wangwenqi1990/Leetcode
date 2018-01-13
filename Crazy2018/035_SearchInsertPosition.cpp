class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 0,1,2 -> mid = 1
        // 0,1   -> mid = 0
        if (nums.back()<target)     return nums.size(); // important corner case    
        int left = 0, right = nums.size()-1, mid=0;
        while(left<right){
            mid = (right+left)/2;                       // update mid
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;                           // update left
            else
                right= mid;                            // update right
        }
        return right;
    }
};