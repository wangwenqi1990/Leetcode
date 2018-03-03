class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // cmoputation: O(n^2) Space: O(1)
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i=0, n= nums.size();
        while(i<n-2){
            int l = i+1, r = n-1, t = - nums[i];
            while(l<r){
                int s = nums[l] + nums[r];
                if(s==t){
                    vector<int> tba;
                    tba.push_back(nums[i]);
                    tba.push_back(nums[l]);
                    tba.push_back(nums[r]);
                    res.push_back(tba);
                    while(l<r && nums[l+1]==nums[l]) ++l;   ++l;
                    while(l<r && nums[r-1]==nums[r]) --r;   --r;
                }
                else if(s<t){
                    while(l<r && nums[l+1]==nums[l]) ++l;   ++l;
                }
                else{
                    while(l<r && nums[r-1]==nums[r]) --r;   --r;
                }
            }
            while(i<n-2 && nums[i+1]==nums[i]) ++i;     ++i;
        }
        return res;
    }
};
