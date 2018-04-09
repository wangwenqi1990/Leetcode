class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // compuation: O(n) space: O(1)
        // the algorithm is implemented via swaping
        int i=0;
        while(i<nums.size()){
            // swap to make array satisfies nums[i] = i+1;
            // swap && guarantee can swap && avoid infinite same swap
            if(nums[i]!=i+1 && nums[i]>=1 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                ++i;        
        }
        for(int i=0; i<nums.size();++i){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};