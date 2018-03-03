class Solution {
public:
    void sortColors(vector<int>& nums) {
        // trip-partition solution
        // Computation: O(n)
        // Space: O(1)
        for(int l=0, m=0, r= nums.size()-1; m<=r;){
            if(nums[m]==0)      swap(nums[m++], nums[l++]); // m++ is important
            else if(nums[m]==2) swap(nums[m], nums[r--]);
            else                ++m;
        }
    }
};
