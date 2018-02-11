class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tp;
        res.push_back(tp);
        for(int i=0; i< nums.size(); i++){
            int res_tp_size = res.size();
            for(int j=0; j< res_tp_size; j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
