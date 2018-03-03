class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> e;
        res.push_back(e);
        sort(nums.begin(), nums.end());
        
        int pre = INT_MAX, pre_cnt=0;
        for(auto num: nums){
            int n = res.size();
            if(num!=pre){
                // if not duplicated, update all the terms
                for(int j=0; j<n; ++j){
                    res.push_back(res[j]);
                    res.back().push_back(num);
                }
                pre_cnt = n;
            }
            else{
                // if duplicated, only update the most recent updated term
                for(int j=n-pre_cnt; j<n; ++j){
                    res.push_back(res[j]);
                    res.back().push_back(num);
                }
            }
            pre = num;
        }
        return res;
    }
};
