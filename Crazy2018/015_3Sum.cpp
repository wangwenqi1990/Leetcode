class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Computation: O(n^2) Space: O(1)
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        int i=0, n = nums.size();
        while(i<n-2){
            int l = i+1, r = n-1;
            int target = -nums[i];
            // two pointer
            while(l < r){
                int tp = nums[l] + nums[r];
                if(tp == target){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[l++]);
                    tmp.push_back(nums[r--]);
                    res.push_back(tmp);
                    while(l<r && nums[l]==tmp[1])
                        l++;
                    while(l<r && nums[r]==tmp[2])
                        r--;
                }
                else if(tp > target){
                    r--;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else{
                    l++;
                    while(l<r && nums[l] == nums[l-1])
                        l++;
                }
            }
            i++;
            while(i< nums.size()-2 && nums[i] == nums[i-1])
                i++;
        }
        return res;
    }
};