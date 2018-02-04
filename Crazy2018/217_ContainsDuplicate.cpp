class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	// harsh table, or sorting
        unordered_set<int> S;
        for(int i=0; i<nums.size(); i++){
            if(S.find(nums[i])!=S.end())
                return true;
            S.emplace(nums[i]);
        }
        return false;
    }
};