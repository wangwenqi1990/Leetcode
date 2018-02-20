class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        vector<int> res_tp; res.push_back(res_tp);
        sort(nums.begin(), nums.end());
        int pre=INT_MAX, pre_size = 0, n = nums.size();
        for(int i=0; i< n; ++i){
            // pre_size is the length that does not need to update
            if(nums[i]!=pre){
                pre = nums[i];
                pre_size = res.size();
            }
            // for each qualified results added, append nums[i]
            int tot_size = res.size();
            for(int j=tot_size-pre_size; j< tot_size; ++j ){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};