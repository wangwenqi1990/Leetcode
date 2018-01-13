class Solution {
public:
    void sortColors(vector<int>& nums) {
        // trip-partition solution
        // Computation: O(n)
        // Space: O(1)
        for(int l=0, m=0, r=nums.size()-1; r>=m;){
            if(nums[m]==1)
                m++;
            else if(nums[m]>1)
                swap(nums[m], nums[r--]);
            else
                swap(nums[l++], nums[m++]);
        }   
    }
};