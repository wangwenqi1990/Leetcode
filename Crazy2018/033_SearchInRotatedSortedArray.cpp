class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search
        // computation: O(log(n)) space O(1)
        // check which branch does the mid belongs to first, then update left, right
        int left = 0, right = nums.size()-1;       
        while(left <= right){
            int mid = left + (right-left)/2; 
            if(nums[mid]==target) return mid;
            else if(nums[mid] < nums[right]){
                if(nums[mid]<target && nums[right]>=target) left = mid+1;
                else right = mid-1;
            }
            else{
                if(nums[mid]>target && nums[left]<=target) right = mid-1;
                else left = mid+1;
            }
        }
        return -1;
    }
};