class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // similar to 142 Linked List Cycle II
        // Computation: O(n)
        // Space: O(1)
        int s = nums[0];
        int f = nums[s];
        while(s!=f){
            s=nums[s];
            f=nums[nums[f]];
        }
        f=0;
        while(s!=f){
            s=nums[s];
            f=nums[f];
        }
        return s;
    }
};