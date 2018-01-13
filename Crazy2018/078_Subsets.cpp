class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // backtracking
        vector<vector<int>> tp;
        vector<int> tp1;
        tp.push_back(tp1);
        vector<vector<int>> res = subsets_index(nums, tp, nums.size());
        return res;
    }
    vector<vector<int>> subsets_index(vector<int> &nums, vector<vector<int>> &tp, int n){
        if(n==0) return tp;
        int k = tp.size();
        for(int i=0; i<k;i++){
            vector<int> tmp = tp[i];
            tmp.push_back(nums[n-1]);
            tp.push_back(tmp);
        }
        return subsets_index(nums, tp, n-1);
    }
};